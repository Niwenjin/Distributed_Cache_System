#ifndef CACHESERVICEIMPL_H
#define CACHESERVICEIMPL_H
#include "CacheClient.h"
#include "cache_service.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <memory>
#include <vector>

using grpc::ServerContext;
using grpc::Status;
using std::unique_ptr;
using std::vector;

class CacheServiceImpl final : public CacheService::Service {
  public:
    CacheServiceImpl(size_t no);
    ~CacheServiceImpl();

    Status Get(ServerContext *context, const Request *request,
               Reply *reply) override;

    Status Set(ServerContext *context, const Request *request,
               Reply *reply) override;

    Status Delete(ServerContext *context, const Request *request,
                  Reply *reply) override;

    Json::Value getCache(const string key);
    void setCache(const string key, const Json::Value value);
    int delCache(const string key);
    void print();

  private:
    size_t m_no;
    vector<unique_ptr<CacheClient>> client;
    Json::Value json_data; // 使用 JSONcpp 存储键值对
    size_t hash(string);
};
#endif