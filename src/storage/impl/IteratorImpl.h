//
// Created by fenglin on 2018/12/29.
//

#pragma once

#include "../include/StorageEngine.h"
#include <rocksdb/iterator.h>

namespace storage {
    class IteratorImpl : public Iterator {
    public:
        IteratorImpl(rocksdb::Iterator* iter);

        ~IteratorImpl() override;

        bool IsValid() override;

        string GetKey() override;

        string GetValue() override;

        void Next() override;

        void Seek(const string &target) override;

        void SeekToFirst() override;

        void SeekToLast() override;
    private:
        rocksdb::Iterator* iter_;
    };
}


