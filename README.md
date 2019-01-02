# kvstore
基于rocksdb做持久化kvstore

### 1. 依赖

* rocksdb
* folly
* grpc
* boost

### 2. 目前要做的事情

* grpc

    * 安装grpc
    * 使用grpc构建service和client端的程序

* folly

    * 安装folly
    * 解决异步场景


### 3. 需求

    * 有序的kv存储
    * 提供Get、Put、Delete和Scan接口
    * Scan接口必须有序
    * 持久化存储，系统重启不会丢弃数据
    * 对异常有处理和单元测试
    * 优化性能

### 4. 技术点

    * 存储层: 用rocksdb来搞定存储的; 关于有序,rocksdb本身能保证
    * 网络层: 直接用grpc
    * 性能的话: 使用folly的future来做异步调用







