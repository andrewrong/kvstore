//
// Created by fenglin on 2018/12/29.
//

#include "iteratorImpl.h"

storage::iteratorImpl::iteratorImpl(rocksdb::Iterator* iter) : Iterator() {
    assert(iter);
    iter_ = iter;
}

storage::iteratorImpl::~iteratorImpl() {
    if(iter_) {
        delete iter_;
    }
}

bool storage::iteratorImpl::IsValid() {
    assert(iter_);
    return iter_->Valid();
}

//todo 优化copy
std::string storage::iteratorImpl::GetKey() {
    assert(iter_);
    return iter_->key().ToString();
}

std::string storage::iteratorImpl::GetValue() {
    assert(iter_);
    return iter_->value().ToString();
}

void storage::iteratorImpl::Next() {
    assert(iter_);
    iter_->Next();
}

void storage::iteratorImpl::Seek(const std::string &target) {
    assert(iter_);
    iter_->Seek(target);
}

void storage::iteratorImpl::SeekToFirst() {
    assert(iter_);
    iter_->SeekToFirst();
}

void storage::iteratorImpl::SeekToLast() {
    assert(iter_);
    iter_->SeekToLast();
}
