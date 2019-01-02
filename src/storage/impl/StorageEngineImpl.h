//
// Created by fenglin on 2018/12/29.
//

#pragma once

#include "../include/StorageEngine.h"
#include <rocksdb/db.h>

namespace storage {

    class StorageEngineImpl : public StorageEngine {
    public:
        StorageEngineImpl(const string& dbPath);

        ~StorageEngineImpl() override;

        Status Set(const std::string &key, const std::string &value) override;

        Status Get(const std::string &key, std::string &value) override;

        Status Scan(const std::string& prefixKey, const std::function<bool(const std::string& key, const std::string& value)>& fn) override;

        Status Del(const std::string &key) override;

        Status MultiSet(const std::map<std::string, std::string> &kv_map) override;

        Status MultiGet(const std::vector<std::string> &keys, std::vector<std::string> &values) override;

        IteratorPtr NewIterator() override;

    private:
        rocksdb::DB* db_;
        static const int limit_ = 10000;
    };
}


