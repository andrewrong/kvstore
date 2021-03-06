//
// Created by fenglin on 2018/12/29.
//

#include "StorageEngineImpl.h"
#include "IteratorImpl.h"

storage::StorageEngineImpl::StorageEngineImpl(const string& dbPath) {
    rocksdb::Status status;
    if(dbPath.empty()) {
        fprintf(stderr, "db path is empty");
        exit(-1);
    }

    rocksdb::Options options;
    options.IncreaseParallelism();
    options.OptimizeLevelStyleCompaction();
    options.create_if_missing = true;
    options.prefix_extractor = nullptr;

    status = rocksdb::DB::Open(options, dbPath, &db_);
    if(!status.ok()) {
        fprintf(stderr, "Open db failed: %s\n", status.ToString().c_str());
        exit(-1);
    }

    fprintf(stderr, "Open db %s success\n", dbPath.c_str());
}

storage::StorageEngineImpl::~StorageEngineImpl() {
    if(db_) {
        delete db_;
    }
}

storage::Status storage::StorageEngineImpl::Set(const std::string &key, const std::string &value) {
    if(key.empty()) {
        int code = static_cast<int>(Code::eParamError);
        return std::make_pair(code, CodeMsg[code]);
    }

    auto status = db_->Put(rocksdb::WriteOptions(), key, value);
    return std::make_pair(status.code(), CodeMsg[status.code()]);
}

storage::Status storage::StorageEngineImpl::Get(const std::string &key, std::string &value) {
    if(key.empty()) {
        int code = static_cast<int>(Code::eParamError);
        return std::make_pair(code, CodeMsg[code]);
    }

    auto status = db_->Get(rocksdb::ReadOptions(), key ,&value);
    return std::make_pair(status.code(), CodeMsg[status.code()]);
}

storage::Status storage::StorageEngineImpl::Del(const std::string &key) {
    if(key.empty()) {
        int code = static_cast<int>(Code::eParamError);
        return std::make_pair(code, CodeMsg[code]);
    }

    auto status = db_->Delete(rocksdb::WriteOptions(), key);
    return std::make_pair(status.code(), CodeMsg[status.code()]);
}

storage::Status storage::StorageEngineImpl::MultiSet(const std::map<std::string, std::string> &kv_map) {
    rocksdb::WriteBatch write_batch;
    for (auto it= kv_map.begin(); it != kv_map.end(); ++it) {
        if(it->first.empty()){
            continue;
        }
        write_batch.Put(it->first, it->second);
    }

    rocksdb::Status status = db_->Write(rocksdb::WriteOptions(), &write_batch);
    int code = status.code();
    return std::make_pair(code, CodeMsg[code]);
}

storage::Status
storage::StorageEngineImpl::MultiGet(const std::vector<std::string> &keys, std::vector<std::string> &values) {
    vector<rocksdb::Slice> rocksdbKeys;
    for(auto& key : keys) {
        if(key.empty()) {
            continue;
        }
        rocksdbKeys.push_back(key);
    }

    vector<rocksdb::Status> statusVec = db_->MultiGet(rocksdb::ReadOptions(), rocksdbKeys, &values);
    for(auto& item : statusVec) {
        if(!item.ok()) {
            return std::make_pair(item.code(), CodeMsg[item.code()]);
        }
    }
    return std::make_pair(0, CodeMsg[0]);
}

storage::IteratorPtr storage::StorageEngineImpl::NewIterator() {
    rocksdb::Iterator* iterator = db_->NewIterator(rocksdb::ReadOptions());
    if (!iterator) {
        return nullptr;
    }
    IteratorPtr iteratorPtr = std::dynamic_pointer_cast<Iterator>(std::make_shared<IteratorImpl>(iterator));
    return iteratorPtr;
}

storage::Status storage::StorageEngineImpl::Scan(const std::string &prefixKey,
                                                 const std::function<bool(const std::string &key,
                                                                          const std::string &value)> &fn) {
    if(!fn) {
        fprintf(stderr, "function is null");
        int code = 14;
        return std::make_pair(code, CodeMsg[code]);
    }

    storage::IteratorPtr iterator = NewIterator();
    if (!iterator) {
        fprintf(stderr, "iterator is null");
        int code = static_cast<int>(Code::eInnerUnknownError);
        return std::make_pair(code, CodeMsg[code]);
    }

    int limit = 0;
    if(prefixKey.empty()) {
        for(iterator->SeekToFirst(); iterator->IsValid(); iterator->Next()) {
            string tmpKey = iterator->GetKey();

            if(tmpKey.empty()) {
                continue;
            }
            if(!fn(tmpKey, iterator->GetValue())) {
                break;
            }

            if(++limit > limit_) {
                break;
            }
        }
    } else {
        iterator->Seek(prefixKey);
        string endStr = prefixKey;
        endStr.back() += 1;
        for(; iterator->IsValid(); iterator->Next()) {
            string tmpKey = iterator->GetKey();
            if(tmpKey.empty()) {
                continue;
            }

            if(tmpKey >= endStr) {
                break;
            }

            if(!fn(tmpKey, iterator->GetValue())) {
                break;
            }
            if(++limit > limit_) {
                break;
            }
        }
    }
    return std::make_pair(0, CodeMsg[0]);
}

storage::StorageEnginePtr storage::createStorageEngine(const std::string& dbPath) {
    storage::StorageEnginePtr enginePtr = std::dynamic_pointer_cast<storage::StorageEngine>(
            std::make_shared<storage::StorageEngineImpl>(dbPath));
    return enginePtr;
}
