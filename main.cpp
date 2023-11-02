#include "CacheServiceImpl.h"
#include "httplib.h"
#include <memory>
#include <string>

using grpc::InsecureServerCredentials;
using grpc::Server;
using grpc::ServerBuilder;
using httplib::Response;
using std::istringstream;
using std::stoi;
using std::to_string;
using std::unique_ptr;

CacheServiceImpl *service;

void httpget(const httplib::Request &req, Response &res);
void httppost(const httplib::Request &req, Response &res);
void httpdel(const httplib::Request &req, Response &res);

int main(int argc, char *argv[]) {
    size_t no = stoi(argv[1]);

    // 启动grpc服务
    const string server_address[3] = {"server1:8000", "server2:8001",
                                      "server3:8002"};

    service = new CacheServiceImpl(no);
    ServerBuilder builder;
    builder.AddListeningPort(server_address[no], InsecureServerCredentials());
    builder.RegisterService(service);

    unique_ptr<Server> server(builder.BuildAndStart());

    // 启动HTTP服务
    const int port[3] = {8080, 8081, 8082};
    httplib::Server httpsvr;
    httpsvr.Get("/:key", httpget);
    httpsvr.Post("/", httppost);
    httpsvr.Delete("/:key", httpdel);

    httpsvr.listen("0.0.0.0", port[no]);

    server->Wait();

    return 0;
}

void httpget(const httplib::Request &req, Response &res) {
    string key = req.path_params.at("key");
    std::cout << "recive httpget:" << key << std::endl;
    Json::Value value = service->getCache(key);
    if (value.isNull()) {
        res.status = 404;
        res.body = "";
    } else {
        res.status = 200;
        Json::Value kv;
        kv[key] = value;
        Json::StreamWriterBuilder writer;
        writer["indentation"] = "";
        string json_str = Json::writeString(writer, kv);
        res.set_content(json_str, "application/json");
    }
}

void httppost(const httplib::Request &req, Response &res) {
    std::cout << "recive httppost:" << req.body << std::endl;
    istringstream json_str(req.body);
    Json::CharReaderBuilder reader;
    Json::Value kv;
    JSONCPP_STRING errs;

    // 解析JSON数据
    Json::parseFromStream(reader, json_str, &kv, &errs);
    std::cout << kv << std::endl;
    string key = kv.getMemberNames()[0];
    Json::Value value = kv[key];

    service->setCache(key, value);
}

void httpdel(const httplib::Request &req, Response &res) {
    string key = req.path_params.at("key");
    std::cout << "recive httpdel:" << key << std::endl;
    res.status = 200;
    res.body = to_string(service->delCache(key));
}