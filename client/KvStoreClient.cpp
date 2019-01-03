//
// Created by fenglin on 2019/1/2.
//

#include "KvStoreClient.h"

kvstore::KvStoreClient::KvStoreClient(const string &serverAddr) {
    if(serverAddr.empty()) {
        fprintf(stderr, "server addr is null\n");
        exit(-1);
    }

    stub_ = std::move(proto::KvStore::NewStub(grpc::CreateChannel(serverAddr, grpc::InsecureChannelCredentials())));
    assert(stub_);
}

bool kvstore::KvStoreClient::get(const string &key, string &value) {
    if(key.empty()) {
        fprintf(stderr, "key is empty\n");
        return false;
    }

    ClientContext context;
    proto::Key pKey;
    pKey.set_key(key);

    proto::GetResponse response;
    Status sts = stub_->Get(&context, pKey, &response);

    if(!sts.ok()) {
        fprintf(stderr, "grpc get is error\n");
        return false;
    }

    if(response.status().code() == 1001) {
        fprintf(stdout, "get rpc is ok\n");
        value = response.value().value();

        return true;
    } else {
        fprintf(stderr, "get key %s is error, msg:%s \n", key.c_str(), response.status().msg().c_str());
    }
    return false;
}

bool kvstore::KvStoreClient::put(const string &key, const string &value) {
    if(key.empty()) {
        fprintf(stderr, "key is empty\n");
        return false;
    }

    ClientContext context;
    proto::Key pKey;
    pKey.set_key(key);

    proto::Value pValue;
    pValue.set_value(value);

    proto::KVPair kvPair;
    kvPair.mutable_vvalue()->CopyFrom(pValue);
    kvPair.mutable_kkey()->CopyFrom(pKey);

    proto::BaseResponse response;

    Status sts = stub_->Put(&context, kvPair, &response);

    if(!sts.ok()) {
        fprintf(stderr, "grpc get is error\n");
        return false;
    }

    if(response.code() == 1001) {
        fprintf(stdout, "put rpc is ok\n");
        return true;
    } else {
        fprintf(stderr, "put key %s value %s is error, msg:%s \n", key.c_str(), value.c_str(), response.msg().c_str());
    }
    return false;
}

bool
kvstore::KvStoreClient::scan(const string &prefixKey, const std::function<void(const string &key, const string &value)> &fn) {
    ClientContext context;
    proto::Key pKey;
    pKey.set_key(prefixKey);

    std::unique_ptr<::grpc::ClientReader< ::proto::KVPair>> reader(stub_->Scan(&context, pKey));
    proto::KVPair kvPair;
    while(reader->Read(&kvPair)) {
        if(!fn) {
            continue;
        }
        fn(kvPair.kkey().key(), kvPair.vvalue().value());
    }

    Status sts = reader->Finish();
    if (sts.ok()) {
        fprintf(stdout, "scan is success\n");
        return true;
    } else {
        fprintf(stderr, "scan key %s is error\n", prefixKey.c_str());
        return false;
    }
}

bool kvstore::KvStoreClient::del(const string &key) {
    if(key.empty()) {
        fprintf(stderr, "key is empty");
        return false;
    }

    ClientContext context;
    proto::Key pKey;
    pKey.set_key(key);

    proto::BaseResponse response;
    Status sts = stub_->Del(&context, pKey, &response);

    if(!sts.ok()) {
        fprintf(stderr, "grpc del is error");
        return false;
    }

    if(response.code() == 1001) {
        fprintf(stdout, "del rpc is ok");
        return true;
    } else {
        fprintf(stderr, "del key %s is error, msg:%s \n", key.c_str(), response.msg().c_str());
    }
    return false;
}
