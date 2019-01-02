//
// Created by fenglin on 2018/12/29.
//

#include "KvStoreService.h"
#include <string>
#include "../storage/impl/StorageEngineImpl.h"

using std::string;

kvservice::KvStoreService::KvStoreService() : Service() {
    storage_ = storage::createStorageEngine(path_);
    assert(storage_);
}

kvservice::KvStoreService::~KvStoreService() {}

::grpc::Status kvservice::KvStoreService::Get(::grpc::ServerContext *context, const ::proto::Key *request,
                                              ::proto::GetResponse *response) {
    std::string value = "";
    auto res = storage_->Get(request->key(), value);

    ::proto::BaseResponse baseResponse;
    ::proto::Value resValue;
    if(res.first == 0) {
        baseResponse.set_code(1001);
        baseResponse.set_msg("success");
        resValue.set_value(value);
    } else {
        baseResponse.set_code(4004);
        baseResponse.set_msg(res.second);
        resValue.set_value("");
    }
    response->mutable_status()->CopyFrom(baseResponse);
    response->mutable_value()->CopyFrom(resValue);

    return ::grpc::Status::OK;
}

::grpc::Status kvservice::KvStoreService::Scan(::grpc::ServerContext *context, const ::proto::Key *request,
                                               ::grpc::ServerWriter<proto::KVPair> *writer) {
    string prefix = request->key();

    storage_->Scan(prefix, [this, writer](const string& key, const string& value){
        ::proto::KVPair tmpPair;
        ::proto::Key tmpKey;
        tmpKey.set_key(key);

        ::proto::Value tmpValue;
        tmpValue.set_value(value);

        tmpPair.mutable_kkey()->CopyFrom(tmpKey);
        tmpPair.mutable_vvalue()->CopyFrom(tmpValue);
        writer->Write(tmpPair);
        return true;
    });

    return ::grpc::Status::OK;
}

::grpc::Status kvservice::KvStoreService::Put(::grpc::ServerContext *context, const ::proto::KVPair *request,
                                              ::proto::BaseResponse *response) {
    string key = request->kkey().key();
    string value = request->vvalue().value();

    auto res = storage_->Set(key, value);
    response->set_msg(res.second);

    if(res.first == 0) {
        response->set_code(1001);
    }else {
        response->set_code(4004);
    }
    return ::grpc::Status::OK;
}

::grpc::Status kvservice::KvStoreService::Del(::grpc::ServerContext *context, const ::proto::Key *request,
                                              ::proto::BaseResponse *response) {
    string key = request->key();
    auto res = storage_->Del(key);
    response->set_msg(res.second);

    if(res.first == 0) {
        response->set_code(1001);
    }else {
        response->set_code(4004);
    }
    return ::grpc::Status::OK;
}

void kvservice::RunServer(const std::string& addr) {
    if(addr.empty()) {
       fprintf(stderr, "ip and port is empty");
       return;
    }
    kvservice::KvStoreService service;

    grpc::ServerBuilder builder;
    builder.AddListeningPort(addr, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << addr << std::endl;
    server->Wait();
}

