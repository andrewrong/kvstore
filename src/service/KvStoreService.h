//
// Created by fenglin on 2018/12/29.
//

#pragma once

#include "../proto/server.grpc.pb.h"
#include "../storage/include/StorageEngine.h"
#include <grpc/grpc.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>
#include <grpcpp/security/server_credentials.h>

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReader;
using grpc::ServerReaderWriter;
using grpc::ServerWriter;
using grpc::Status;

namespace kvservice {
    class KvStoreService final : public proto::KvStore::Service {
    public:
        KvStoreService();

        ~KvStoreService() override;

        ::grpc::Status
        Get(::grpc::ServerContext *context, const ::proto::Key *request, ::proto::GetResponse *response) override;

        ::grpc::Status Scan(::grpc::ServerContext *context, const ::proto::Key *request,
                            ::grpc::ServerWriter<proto::KVPair> *writer) override;

        ::grpc::Status
        Put(::grpc::ServerContext *context, const ::proto::KVPair *request, ::proto::BaseResponse *response) override;

        ::grpc::Status
        Del(::grpc::ServerContext *context, const ::proto::Key *request, ::proto::BaseResponse *response) override;

    private:
        storage::StorageEnginePtr storage_{nullptr};
        const std::string path_ = "./cache";
    };

    void RunServer(const std::string& addr);
}


