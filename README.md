# 简易分布式缓存系统
## 依赖库
* grpc++
* protobuf
* httplib(head only)
* jsoncpp
## 功能
* Cache数据以Key-value形式（Json::Value）存储在缓存系统节点内存中
* Cache数据以hash方法分布在不同节点
* 服务至少启动3个节点，不考虑节点动态变化  
  * 所有节点均提供HTTP访问入口；
  * 客户端读写访问可从任意节点接入，每个请求只支持一个key存取；
  * 若数据所在存储服务器与接入服务器不同，接入服务器通过内部RPC从目标存储服务器获取数据，再返回至客户端。
* HTTP API约定
  * Content-type: application/json; charset=utf-8
  * 写入/更新缓存：POST /。使用HTTP POST方法，请求发送至根路径，请求体为JSON格式的KV内容，示例如下：
    ```
    curl -XPOST -H "Content-type: application/json" http://127.0.0.1:9527/ -d '{"myname": "电子科技大学@2023"}'
    curl -XPOST -H "Content-type: application/json" http://127.0.0.1:9528/ -d '{"tasks": ["task 1", "task 2", "task 3"]}'
    curl -XPOST -H "Content-type: application/json" http://127.0.0.1:9529/ -d '{"age": 123}'
    ```
  * 读取缓存 GET /{key}。使用HTTP GET方法，key直接拼接在根路径之后。为简化程序，对key格式不做要求。
    ```
    curl http://127.0.0.1:9527/key
    ```
      1. 正常：返回HTTP 200，body为JSON格式的KV结果；
      2. 错误：返回HTTP 404，body为空。
  * 删除缓存 DELETE /{key}。返回HTTP 200，body为删除的数量。
    ```
    curl -XDELETE http://127.0.0.1:9527/key
    ```
## 测试
docker-compose up运行