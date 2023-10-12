#include "CacheServiceImpl.h"
#include "httplib.h"
#include <json/json.h>
#include <json/value.h>
#include <memory>
#include <string>

using grpc::InsecureServerCredentials;
using grpc::Server;
using grpc::ServerBuilder;
using httplib::Request;
using httplib::Response;
using std::istringstream;
using std::stoi;
using std::to_string;
using std::unique_ptr;

CacheServiceImpl *service;

void httpget(const Request &req, Response &res);
void httppost(const Request &req, Response &res);
void httpdel(const Request &req, Response &res);

int main(int argc, char *argv[]) {
    size_t no = stoi(argv[1]);

    // 启动grpc服务
    const string server_address[3] = {"0.0.0.0:8080", "0.0.0.0:8081",
                                      "0.0.0.0:8082"};

    service = new CacheServiceImpl(no);
    ServerBuilder builder;
    builder.AddListeningPort(server_address[no], InsecureServerCredentials());
    builder.RegisterService(service);

    unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address[no] << std::endl;

    // 启动HTTP服务
    const int port[3] = {9527, 9528, 9529};
    httplib::Server httpsvr;
    httpsvr.Get("/", httpget);
    httpsvr.Post("/", httppost);
    httpsvr.Delete("/", httpdel);

    httpsvr.listen("127.0.0.1", port[no]);

    server->Wait();

    return 0;
}

void httpget(const Request &req, Response &res) {
    string key = req.matches[1];
    string value = service->getCache(key);
    if (value.empty()) {
        res.status = 404;
        res.body = nullptr;
    } else {
        res.status = 200;
        Json::Value kv;
        kv[key] = value;
        Json::StreamWriterBuilder writer;
        string json_str = Json::writeString(writer, kv);
        res.set_content(json_str, "application/json");
    }
}

void httppost(const Request &req, Response &res) {
    istringstream json_str(req.body);
    Json::CharReaderBuilder reader;
    Json::Value kv;
    JSONCPP_STRING errs;

    // 解析JSON数据
    Json::parseFromStream(reader, json_str, &kv, &errs);
    string key = kv.getMemberNames()[0];
    string value = kv[key].asString();

    service->setCache(key, value);
}

void httpdel(const Request &req, Response &res) {
    string key = req.matches[1];
    res.status = 200;
    res.body = to_string(service->delCache(key));
}