# 使用基础镜像
FROM ubuntu:20.04

# 设置工作目录
WORKDIR /app

# 设置环境变量
ENV DEBIAN_FRONTEND=noninteractive

# 安装依赖
RUN apt-get update && apt-get install -y \
    build-essential \
    tzdata \
    g++ \
    cmake \
    libjsoncpp-dev \
    protobuf-compiler \
    libprotobuf-dev \
    libgrpc++-dev \
    && rm -rf /var/lib/apt/lists/*

# 复制相关文件到容器中
COPY . /app

# 编译可执行文件
RUN mkdir build && \
    cd build && \
    cmake .. && \
    make

# 启动 gRPC 服务器
CMD ["./server", "--config=config.conf"]