// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: server.proto
#ifndef GRPC_server_2eproto__INCLUDED
#define GRPC_server_2eproto__INCLUDED

#include "server.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

namespace proto {

class KvStore final {
 public:
  static constexpr char const* service_full_name() {
    return "proto.KvStore";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status Get(::grpc::ClientContext* context, const ::proto::Key& request, ::proto::GetResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::proto::GetResponse>> AsyncGet(::grpc::ClientContext* context, const ::proto::Key& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::proto::GetResponse>>(AsyncGetRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::proto::GetResponse>> PrepareAsyncGet(::grpc::ClientContext* context, const ::proto::Key& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::proto::GetResponse>>(PrepareAsyncGetRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientReaderInterface< ::proto::KVPair>> Scan(::grpc::ClientContext* context, const ::proto::Key& request) {
      return std::unique_ptr< ::grpc::ClientReaderInterface< ::proto::KVPair>>(ScanRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::proto::KVPair>> AsyncScan(::grpc::ClientContext* context, const ::proto::Key& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::proto::KVPair>>(AsyncScanRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::proto::KVPair>> PrepareAsyncScan(::grpc::ClientContext* context, const ::proto::Key& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::proto::KVPair>>(PrepareAsyncScanRaw(context, request, cq));
    }
    virtual ::grpc::Status Put(::grpc::ClientContext* context, const ::proto::KVPair& request, ::proto::BaseResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::proto::BaseResponse>> AsyncPut(::grpc::ClientContext* context, const ::proto::KVPair& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::proto::BaseResponse>>(AsyncPutRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::proto::BaseResponse>> PrepareAsyncPut(::grpc::ClientContext* context, const ::proto::KVPair& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::proto::BaseResponse>>(PrepareAsyncPutRaw(context, request, cq));
    }
    virtual ::grpc::Status Del(::grpc::ClientContext* context, const ::proto::Key& request, ::proto::BaseResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::proto::BaseResponse>> AsyncDel(::grpc::ClientContext* context, const ::proto::Key& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::proto::BaseResponse>>(AsyncDelRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::proto::BaseResponse>> PrepareAsyncDel(::grpc::ClientContext* context, const ::proto::Key& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::proto::BaseResponse>>(PrepareAsyncDelRaw(context, request, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      virtual void Get(::grpc::ClientContext* context, const ::proto::Key* request, ::proto::GetResponse* response, std::function<void(::grpc::Status)>) = 0;
      virtual void Put(::grpc::ClientContext* context, const ::proto::KVPair* request, ::proto::BaseResponse* response, std::function<void(::grpc::Status)>) = 0;
      virtual void Del(::grpc::ClientContext* context, const ::proto::Key* request, ::proto::BaseResponse* response, std::function<void(::grpc::Status)>) = 0;
    };
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::proto::GetResponse>* AsyncGetRaw(::grpc::ClientContext* context, const ::proto::Key& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::proto::GetResponse>* PrepareAsyncGetRaw(::grpc::ClientContext* context, const ::proto::Key& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientReaderInterface< ::proto::KVPair>* ScanRaw(::grpc::ClientContext* context, const ::proto::Key& request) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::proto::KVPair>* AsyncScanRaw(::grpc::ClientContext* context, const ::proto::Key& request, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::proto::KVPair>* PrepareAsyncScanRaw(::grpc::ClientContext* context, const ::proto::Key& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::proto::BaseResponse>* AsyncPutRaw(::grpc::ClientContext* context, const ::proto::KVPair& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::proto::BaseResponse>* PrepareAsyncPutRaw(::grpc::ClientContext* context, const ::proto::KVPair& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::proto::BaseResponse>* AsyncDelRaw(::grpc::ClientContext* context, const ::proto::Key& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::proto::BaseResponse>* PrepareAsyncDelRaw(::grpc::ClientContext* context, const ::proto::Key& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status Get(::grpc::ClientContext* context, const ::proto::Key& request, ::proto::GetResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::proto::GetResponse>> AsyncGet(::grpc::ClientContext* context, const ::proto::Key& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::proto::GetResponse>>(AsyncGetRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::proto::GetResponse>> PrepareAsyncGet(::grpc::ClientContext* context, const ::proto::Key& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::proto::GetResponse>>(PrepareAsyncGetRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientReader< ::proto::KVPair>> Scan(::grpc::ClientContext* context, const ::proto::Key& request) {
      return std::unique_ptr< ::grpc::ClientReader< ::proto::KVPair>>(ScanRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::proto::KVPair>> AsyncScan(::grpc::ClientContext* context, const ::proto::Key& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::proto::KVPair>>(AsyncScanRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::proto::KVPair>> PrepareAsyncScan(::grpc::ClientContext* context, const ::proto::Key& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::proto::KVPair>>(PrepareAsyncScanRaw(context, request, cq));
    }
    ::grpc::Status Put(::grpc::ClientContext* context, const ::proto::KVPair& request, ::proto::BaseResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::proto::BaseResponse>> AsyncPut(::grpc::ClientContext* context, const ::proto::KVPair& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::proto::BaseResponse>>(AsyncPutRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::proto::BaseResponse>> PrepareAsyncPut(::grpc::ClientContext* context, const ::proto::KVPair& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::proto::BaseResponse>>(PrepareAsyncPutRaw(context, request, cq));
    }
    ::grpc::Status Del(::grpc::ClientContext* context, const ::proto::Key& request, ::proto::BaseResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::proto::BaseResponse>> AsyncDel(::grpc::ClientContext* context, const ::proto::Key& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::proto::BaseResponse>>(AsyncDelRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::proto::BaseResponse>> PrepareAsyncDel(::grpc::ClientContext* context, const ::proto::Key& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::proto::BaseResponse>>(PrepareAsyncDelRaw(context, request, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      void Get(::grpc::ClientContext* context, const ::proto::Key* request, ::proto::GetResponse* response, std::function<void(::grpc::Status)>) override;
      void Put(::grpc::ClientContext* context, const ::proto::KVPair* request, ::proto::BaseResponse* response, std::function<void(::grpc::Status)>) override;
      void Del(::grpc::ClientContext* context, const ::proto::Key* request, ::proto::BaseResponse* response, std::function<void(::grpc::Status)>) override;
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::proto::GetResponse>* AsyncGetRaw(::grpc::ClientContext* context, const ::proto::Key& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::proto::GetResponse>* PrepareAsyncGetRaw(::grpc::ClientContext* context, const ::proto::Key& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientReader< ::proto::KVPair>* ScanRaw(::grpc::ClientContext* context, const ::proto::Key& request) override;
    ::grpc::ClientAsyncReader< ::proto::KVPair>* AsyncScanRaw(::grpc::ClientContext* context, const ::proto::Key& request, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncReader< ::proto::KVPair>* PrepareAsyncScanRaw(::grpc::ClientContext* context, const ::proto::Key& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::proto::BaseResponse>* AsyncPutRaw(::grpc::ClientContext* context, const ::proto::KVPair& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::proto::BaseResponse>* PrepareAsyncPutRaw(::grpc::ClientContext* context, const ::proto::KVPair& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::proto::BaseResponse>* AsyncDelRaw(::grpc::ClientContext* context, const ::proto::Key& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::proto::BaseResponse>* PrepareAsyncDelRaw(::grpc::ClientContext* context, const ::proto::Key& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_Get_;
    const ::grpc::internal::RpcMethod rpcmethod_Scan_;
    const ::grpc::internal::RpcMethod rpcmethod_Put_;
    const ::grpc::internal::RpcMethod rpcmethod_Del_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status Get(::grpc::ServerContext* context, const ::proto::Key* request, ::proto::GetResponse* response);
    virtual ::grpc::Status Scan(::grpc::ServerContext* context, const ::proto::Key* request, ::grpc::ServerWriter< ::proto::KVPair>* writer);
    virtual ::grpc::Status Put(::grpc::ServerContext* context, const ::proto::KVPair* request, ::proto::BaseResponse* response);
    virtual ::grpc::Status Del(::grpc::ServerContext* context, const ::proto::Key* request, ::proto::BaseResponse* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_Get : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_Get() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_Get() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Get(::grpc::ServerContext* context, const ::proto::Key* request, ::proto::GetResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGet(::grpc::ServerContext* context, ::proto::Key* request, ::grpc::ServerAsyncResponseWriter< ::proto::GetResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_Scan : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_Scan() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_Scan() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Scan(::grpc::ServerContext* context, const ::proto::Key* request, ::grpc::ServerWriter< ::proto::KVPair>* writer) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestScan(::grpc::ServerContext* context, ::proto::Key* request, ::grpc::ServerAsyncWriter< ::proto::KVPair>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncServerStreaming(1, context, request, writer, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_Put : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_Put() {
      ::grpc::Service::MarkMethodAsync(2);
    }
    ~WithAsyncMethod_Put() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Put(::grpc::ServerContext* context, const ::proto::KVPair* request, ::proto::BaseResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestPut(::grpc::ServerContext* context, ::proto::KVPair* request, ::grpc::ServerAsyncResponseWriter< ::proto::BaseResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(2, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_Del : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_Del() {
      ::grpc::Service::MarkMethodAsync(3);
    }
    ~WithAsyncMethod_Del() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Del(::grpc::ServerContext* context, const ::proto::Key* request, ::proto::BaseResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestDel(::grpc::ServerContext* context, ::proto::Key* request, ::grpc::ServerAsyncResponseWriter< ::proto::BaseResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(3, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_Get<WithAsyncMethod_Scan<WithAsyncMethod_Put<WithAsyncMethod_Del<Service > > > > AsyncService;
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_Get : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithCallbackMethod_Get() {
      ::grpc::Service::experimental().MarkMethodCallback(0,
        new ::grpc::internal::CallbackUnaryHandler< ExperimentalWithCallbackMethod_Get<BaseClass>, ::proto::Key, ::proto::GetResponse>(
          [this](::grpc::ServerContext* context,
                 const ::proto::Key* request,
                 ::proto::GetResponse* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   this->Get(context, request, response, controller);
                 }, this));
    }
    ~ExperimentalWithCallbackMethod_Get() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Get(::grpc::ServerContext* context, const ::proto::Key* request, ::proto::GetResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void Get(::grpc::ServerContext* context, const ::proto::Key* request, ::proto::GetResponse* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_Scan : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithCallbackMethod_Scan() {
    }
    ~ExperimentalWithCallbackMethod_Scan() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Scan(::grpc::ServerContext* context, const ::proto::Key* request, ::grpc::ServerWriter< ::proto::KVPair>* writer) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_Put : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithCallbackMethod_Put() {
      ::grpc::Service::experimental().MarkMethodCallback(2,
        new ::grpc::internal::CallbackUnaryHandler< ExperimentalWithCallbackMethod_Put<BaseClass>, ::proto::KVPair, ::proto::BaseResponse>(
          [this](::grpc::ServerContext* context,
                 const ::proto::KVPair* request,
                 ::proto::BaseResponse* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   this->Put(context, request, response, controller);
                 }, this));
    }
    ~ExperimentalWithCallbackMethod_Put() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Put(::grpc::ServerContext* context, const ::proto::KVPair* request, ::proto::BaseResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void Put(::grpc::ServerContext* context, const ::proto::KVPair* request, ::proto::BaseResponse* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_Del : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithCallbackMethod_Del() {
      ::grpc::Service::experimental().MarkMethodCallback(3,
        new ::grpc::internal::CallbackUnaryHandler< ExperimentalWithCallbackMethod_Del<BaseClass>, ::proto::Key, ::proto::BaseResponse>(
          [this](::grpc::ServerContext* context,
                 const ::proto::Key* request,
                 ::proto::BaseResponse* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   this->Del(context, request, response, controller);
                 }, this));
    }
    ~ExperimentalWithCallbackMethod_Del() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Del(::grpc::ServerContext* context, const ::proto::Key* request, ::proto::BaseResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void Del(::grpc::ServerContext* context, const ::proto::Key* request, ::proto::BaseResponse* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  typedef ExperimentalWithCallbackMethod_Get<ExperimentalWithCallbackMethod_Scan<ExperimentalWithCallbackMethod_Put<ExperimentalWithCallbackMethod_Del<Service > > > > ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_Get : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_Get() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_Get() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Get(::grpc::ServerContext* context, const ::proto::Key* request, ::proto::GetResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_Scan : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_Scan() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_Scan() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Scan(::grpc::ServerContext* context, const ::proto::Key* request, ::grpc::ServerWriter< ::proto::KVPair>* writer) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_Put : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_Put() {
      ::grpc::Service::MarkMethodGeneric(2);
    }
    ~WithGenericMethod_Put() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Put(::grpc::ServerContext* context, const ::proto::KVPair* request, ::proto::BaseResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_Del : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_Del() {
      ::grpc::Service::MarkMethodGeneric(3);
    }
    ~WithGenericMethod_Del() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Del(::grpc::ServerContext* context, const ::proto::Key* request, ::proto::BaseResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_Get : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithRawMethod_Get() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_Get() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Get(::grpc::ServerContext* context, const ::proto::Key* request, ::proto::GetResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGet(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_Scan : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithRawMethod_Scan() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_Scan() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Scan(::grpc::ServerContext* context, const ::proto::Key* request, ::grpc::ServerWriter< ::proto::KVPair>* writer) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestScan(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncWriter< ::grpc::ByteBuffer>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncServerStreaming(1, context, request, writer, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_Put : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithRawMethod_Put() {
      ::grpc::Service::MarkMethodRaw(2);
    }
    ~WithRawMethod_Put() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Put(::grpc::ServerContext* context, const ::proto::KVPair* request, ::proto::BaseResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestPut(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(2, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_Del : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithRawMethod_Del() {
      ::grpc::Service::MarkMethodRaw(3);
    }
    ~WithRawMethod_Del() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Del(::grpc::ServerContext* context, const ::proto::Key* request, ::proto::BaseResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestDel(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(3, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_Get : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithRawCallbackMethod_Get() {
      ::grpc::Service::experimental().MarkMethodRawCallback(0,
        new ::grpc::internal::CallbackUnaryHandler< ExperimentalWithRawCallbackMethod_Get<BaseClass>, ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
          [this](::grpc::ServerContext* context,
                 const ::grpc::ByteBuffer* request,
                 ::grpc::ByteBuffer* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   this->Get(context, request, response, controller);
                 }, this));
    }
    ~ExperimentalWithRawCallbackMethod_Get() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Get(::grpc::ServerContext* context, const ::proto::Key* request, ::proto::GetResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void Get(::grpc::ServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_Scan : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithRawCallbackMethod_Scan() {
    }
    ~ExperimentalWithRawCallbackMethod_Scan() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Scan(::grpc::ServerContext* context, const ::proto::Key* request, ::grpc::ServerWriter< ::proto::KVPair>* writer) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_Put : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithRawCallbackMethod_Put() {
      ::grpc::Service::experimental().MarkMethodRawCallback(2,
        new ::grpc::internal::CallbackUnaryHandler< ExperimentalWithRawCallbackMethod_Put<BaseClass>, ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
          [this](::grpc::ServerContext* context,
                 const ::grpc::ByteBuffer* request,
                 ::grpc::ByteBuffer* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   this->Put(context, request, response, controller);
                 }, this));
    }
    ~ExperimentalWithRawCallbackMethod_Put() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Put(::grpc::ServerContext* context, const ::proto::KVPair* request, ::proto::BaseResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void Put(::grpc::ServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_Del : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithRawCallbackMethod_Del() {
      ::grpc::Service::experimental().MarkMethodRawCallback(3,
        new ::grpc::internal::CallbackUnaryHandler< ExperimentalWithRawCallbackMethod_Del<BaseClass>, ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
          [this](::grpc::ServerContext* context,
                 const ::grpc::ByteBuffer* request,
                 ::grpc::ByteBuffer* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   this->Del(context, request, response, controller);
                 }, this));
    }
    ~ExperimentalWithRawCallbackMethod_Del() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Del(::grpc::ServerContext* context, const ::proto::Key* request, ::proto::BaseResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void Del(::grpc::ServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_Get : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_Get() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler< ::proto::Key, ::proto::GetResponse>(std::bind(&WithStreamedUnaryMethod_Get<BaseClass>::StreamedGet, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_Get() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status Get(::grpc::ServerContext* context, const ::proto::Key* request, ::proto::GetResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedGet(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::proto::Key,::proto::GetResponse>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_Put : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_Put() {
      ::grpc::Service::MarkMethodStreamed(2,
        new ::grpc::internal::StreamedUnaryHandler< ::proto::KVPair, ::proto::BaseResponse>(std::bind(&WithStreamedUnaryMethod_Put<BaseClass>::StreamedPut, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_Put() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status Put(::grpc::ServerContext* context, const ::proto::KVPair* request, ::proto::BaseResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedPut(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::proto::KVPair,::proto::BaseResponse>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_Del : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_Del() {
      ::grpc::Service::MarkMethodStreamed(3,
        new ::grpc::internal::StreamedUnaryHandler< ::proto::Key, ::proto::BaseResponse>(std::bind(&WithStreamedUnaryMethod_Del<BaseClass>::StreamedDel, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_Del() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status Del(::grpc::ServerContext* context, const ::proto::Key* request, ::proto::BaseResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedDel(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::proto::Key,::proto::BaseResponse>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_Get<WithStreamedUnaryMethod_Put<WithStreamedUnaryMethod_Del<Service > > > StreamedUnaryService;
  template <class BaseClass>
  class WithSplitStreamingMethod_Scan : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithSplitStreamingMethod_Scan() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::SplitServerStreamingHandler< ::proto::Key, ::proto::KVPair>(std::bind(&WithSplitStreamingMethod_Scan<BaseClass>::StreamedScan, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithSplitStreamingMethod_Scan() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status Scan(::grpc::ServerContext* context, const ::proto::Key* request, ::grpc::ServerWriter< ::proto::KVPair>* writer) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with split streamed
    virtual ::grpc::Status StreamedScan(::grpc::ServerContext* context, ::grpc::ServerSplitStreamer< ::proto::Key,::proto::KVPair>* server_split_streamer) = 0;
  };
  typedef WithSplitStreamingMethod_Scan<Service > SplitStreamedService;
  typedef WithStreamedUnaryMethod_Get<WithSplitStreamingMethod_Scan<WithStreamedUnaryMethod_Put<WithStreamedUnaryMethod_Del<Service > > > > StreamedService;
};

}  // namespace proto


#endif  // GRPC_server_2eproto__INCLUDED