//
// Created by fenglin on 2018/12/29.
//

#pragma once

/**
 * 提供的给外部的接口和类
 */

#include <string>
#include <map>
#include <vector>

namespace storage {
    using std::string;
    using std::map;
    using std::vector;

    //返回状态
    typedef std::pair<int, string> Status;

    enum class Code {
        kOk = 0,
        kNotFound = 1,
        kCorruption = 2,
        kNotSupported = 3,
        kInvalidArgument = 4,
        kIOError = 5,
        kMergeInProgress = 6,
        kIncomplete = 7,
        kShutdownInProgress = 8,
        kTimedOut = 9,
        kAborted = 10,
        kBusy = 11,
        kExpired = 12,
        kTryAgain = 13,


        //external error
        eParamError = 14,
        eInnerUnknownError = 15
    };

    const string CodeMsg[] = {
            "OK",
            "Not Found",
            "Corruption",
            "Not Supported",
            "Invalid Argument",
            "IO Error",
            "Merge In Progress",
            "Incomplete",
            "Shutdown In Progress",
            "TimedOut",
            "Aborted",
            "Busy",
            "Expired",
            "TryAgain",
            "Params is error",
            "unknown error"
    };

    class Iterator {
    public:
        Iterator() {}
        virtual ~Iterator() {}

        virtual bool IsValid() = 0;
        virtual std::string GetKey() = 0;
        virtual std::string GetValue() = 0;

        virtual void Next() = 0 ;
        virtual void Seek(const string& target) = 0;
        virtual void SeekToFirst() = 0;
        virtual void SeekToLast() = 0;

    };
    typedef std::shared_ptr<Iterator> IteratorPtr;

    class StorageEngine {
    public:
        StorageEngine() = default;
        virtual ~StorageEngine() = default;

        //设置value
        virtual Status Set(const std::string& key, const std::string& value) = 0;
        //获得value
        virtual Status Get(const std::string& key, std::string& value) = 0;
        virtual Status Scan(const std::string& prefixKey, const std::function<bool(const std::string& key, const std::string& value)>& fn) = 0;
        //删除key
        virtual Status Del(const std::string& key) = 0;
        virtual Status MultiSet(const std::map<std::string, std::string>& kv_map) = 0;
        virtual Status MultiGet(const std::vector<std::string>& keys, std::vector<std::string>& values) = 0;
        virtual IteratorPtr NewIterator() = 0;
    };

    typedef std::shared_ptr<StorageEngine> StorageEnginePtr;
    StorageEnginePtr createStorageEngine(const std::string& dbPath);
}