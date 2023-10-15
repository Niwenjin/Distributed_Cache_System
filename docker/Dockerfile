# 使用基础镜像
FROM ubuntu:20.04

# 安装依赖
RUN apt-get update && apt-get install -y libgrpc++-dev libabsl-dev

# 复制编译后的可执行文件和相关文件到容器中
COPY server /app/server

# 设置工作目录
WORKDIR /app

# 启动 gRPC 服务器
CMD ["./server", "--config=config.conf"]
