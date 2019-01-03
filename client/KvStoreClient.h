//
// Created by fenglin on 2019/1/2.
//

#pragma once

#include <string>
#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>
#include "client/proto/message.pb.h"
#include "client/proto/server.grpc.pb.h"

using std::string;
using std::shared_ptr;
using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientReaderWriter;
using grpc::ClientWriter;
using grpc::Status;

namespace kvstore {
    class KvStoreClient {
    public:
        KvStoreClient(const string& serverAddr);

        bool get(const string& key, string& value);
        bool put(const string& key, const string& value);
        bool scan(const string& prefixKey, const std::function<void(const string& key, const string& value)>& fn);
        bool del(const string& key);

    private:
        std::unique_ptr<proto::KvStore::Stub> stub_{nullptr};
    };
}


