//
// Created by fenglin on 2018/12/29.
//

#include "IteratorImpl.h"

storage::IteratorImpl::IteratorImpl(rocksdb::Iterator* iter) : Iterator() {
    assert(iter);
    iter_ = iter;
}

storage::IteratorImpl::~IteratorImpl() {
    if(iter_) {
        delete iter_;
    }
}

bool storage::IteratorImpl::IsValid() {
    assert(iter_);
    return iter_->Valid();
}

//todo 优化copy
std::string storage::IteratorImpl::GetKey() {
    assert(iter_);
    return iter_->key().ToString();
}

std::string storage::IteratorImpl::GetValue() {
    assert(iter_);
    return iter_->value().ToString();
}

void storage::IteratorImpl::Next() {
    assert(iter_);
    iter_->Next();
}

void storage::IteratorImpl::Seek(const std::string &target) {
    assert(iter_);
    iter_->Seek(target);
}

void storage::IteratorImpl::SeekToFirst() {
    assert(iter_);
    iter_->SeekToFirst();
}

void storage::IteratorImpl::SeekToLast() {
    assert(iter_);
    iter_->SeekToLast();
}
