#include <gtest/gtest.h>
#include "src/storage/include/StorageEngine.h"
#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;


class StorageEngineTest : public ::testing::Test {
protected:
    storage::StorageEnginePtr engine_{nullptr};
    virtual void SetUp() {
        engine_ = storage::createStorageEngine("./testCache");
    }
};


TEST_F(StorageEngineTest, Put) {
    string key = "key_1";
    string value = "value_1";

    auto res = engine_->Set(key, value);
    EXPECT_EQ(res.first, 0);
}

TEST_F(StorageEngineTest, Get) {
    string key = "key_1";
    string value;

    auto res = engine_->Get(key, value);
    EXPECT_EQ(res.first, 0);
    EXPECT_EQ(value, "value_1");

    key = "key_2xx";
    res = engine_->Get(key, value);
    EXPECT_NE(res.first, 0);
}

TEST_F(StorageEngineTest, Scan) {
    int i = 100000;
    for(; i >=0; --i) {
        engine_->Set("key_" + std::to_string(i), "value_" + std::to_string(i));
    }
    vector<string> result;
    engine_->Scan("key_", [this, &result](const string& key, const string& value){
        if(key.empty()) {
            return true;
        }
        result.push_back(key);
        return true;
    });

    bool isSort = true;
    string begin = "";
    for(auto& item : result) {
        if(begin == "") {
            begin = item;
            continue;
        }

        if(begin > item) {
            isSort = false;
            break;
        }
    }
    EXPECT_EQ(isSort, true);
}


TEST_F(StorageEngineTest, Del) {
    string key = "key_1";

    auto res = engine_->Del(key);
    EXPECT_EQ(res.first, 0);

    string value;
    res = engine_->Get(key, value);
    EXPECT_NE(res.first, 0);
}
