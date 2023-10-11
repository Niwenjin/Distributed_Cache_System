#include "cache_service.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <string>
#include <unordered_map>

using grpc::ServerContext;
using grpc::Status;
using std::string;
using std::unordered_map;

class CacheServiceImpl final : public CacheService::Service {
  public:
    CacheServiceImpl(size_t no);
    ~CacheServiceImpl();

    Status Get(ServerContext *context, const GetRequest *request,
               GetReply *reply) override;

    Status Set(ServerContext *context, const SetRequest *request,
               SetReply *reply) override;

    Status Delete(ServerContext *context, const DelRequest *request,
                  DelReply *reply) override;

  private:
    size_t server_NO;
    unordered_map<string, string> map;
    string getCache(const string key);
    void setCache(const string key, const string value);
    int delCache(const string key);
    bool inthis(string key);
    size_t hash(string);
};
