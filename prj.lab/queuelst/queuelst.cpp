#include "queuelst.hpp"

QueueLst::QueueLst(const QueueLst& rhs) {
    if (rhs.head_ != nullptr) {
        Node* newNode = new Node(rhs.head_->v);
        head_ = newNode;
        tail_ = newNode;
        Node* next = rhs.head_->next;
        Node* cur = tail_;
        while (next != nullptr) {
            Node* newNode = new Node(next->v);
            if (head_->next == nullptr) {
                head_->next = newNode;
            }
            tail_ = newNode;
            cur->next = newNode;
            next = next->next;
            cur = cur->next;
        }
    }
}

QueueLst::~QueueLst() {
    while (head_ != nullptr) {
        Node* delete_future = head_;
        head_ = head_->next;
        delete delete_future;
    }
    tail_ = nullptr;
}

QueueLst& QueueLst::operator=(const QueueLst& rhs) {
    if (this != &rhs) {
        Node* vs = rhs.head_;
        Node* tvs = head_;
        Node* pr;
        while (vs != nullptr) {
            if (tvs != nullptr) {
                tvs->v = vs->v;
            }
            else {
                Node* newNode = new Node(vs->v);
                if (head_ == nullptr) {
                    head_ = newNode;
                    tail_ = newNode;
                }
                else {
                    tail_->next = newNode;
                    tail_ = tail_->next;
                }
                tvs = newNode;
            }
            pr = tvs;
            tvs = tvs->next;
            vs = vs->next;
        }
        while (tvs != nullptr) {
            Node* delete_future = tvs;
            tvs = tvs->next;
            delete delete_future;
        }
        tail_ = pr;
        tail_->next = nullptr;
    }
    return *this;
}

void QueueLst::Push(const Complex& c) {
    Node* newNode = new Node(c);
    if (head_ == nullptr) {
        head_ = newNode;
        tail_ = newNode;
    }
    else if (head_ != nullptr) {
        tail_->next = newNode;
        tail_ = newNode;
    }
}

void QueueLst::Pop() noexcept {
    if (head_ != nullptr) {
        Node* delete_future = head_;
        head_ = head_->next;
        delete delete_future;
    }
    if (head_ == nullptr) {
        tail_ = nullptr;
    }
}

bool QueueLst::IsEmpty() const noexcept {
    return (head_ == nullptr);
}

Complex& QueueLst::Top() {
    if (head_ == nullptr) {
        throw std::logic_error("Stack is empty!\n");
    }
    else {
        return head_->v;
    }
}
const Complex& QueueLst::Top() const {
    if (head_ == nullptr) {
        throw std::logic_error("Stack is empty!\n");
    }
    else {
        return head_->v;
    }
}

void QueueLst::Clear() noexcept {
    while (head_ != nullptr) {
        Node* delete_future = head_;
        head_ = head_->next;
        delete delete_future;
    }
    tail_ = nullptr;
}
