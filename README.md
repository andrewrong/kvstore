# kvstore
基于rocksdb做持久化kvstore

### 1. 依赖

* rocksdb
* grpc
* gtest

### 3. 需求

   1. 有序的kv存储
   2. 提供Get、Put、Delete和Scan接口
   3. Scan接口必须有序
   4. 持久化存储，系统重启不会丢弃数据
   5. 对异常有处理和单元测试
   6. 优化性能

   分析:上面大部分的需求可以通过rocksdb本身来完成; 关于性能的影响可能集中在scan

### 4. 方案

   * 存储层: 用rocksdb来搞定存储的; 关于有序,rocksdb本身能保证
   * 网络层: 直接用grpc

### 5. 目录

    client: 客户端代码
    src: 服务端代码
    test: 测试代码

### 6. 编译

    * grpc
    * gtest
    * rocksdb

    需要编译; 如果编译目录不一样的话，可能需要修改一下cmakelists.txt









