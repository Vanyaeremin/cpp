#include "stacklst.hpp"

StackLst::StackLst(const StackLst& rhs) {
    if (rhs.head_ != nullptr) {
        Node* newNode = new Node(rhs.head_->v);
        head_ = newNode;
        Node* vs = rhs.head_->next;
        Node* pr = newNode;
        while (vs != nullptr) {
            Node* newNode = new Node(vs->v);
            pr->next = newNode;
            vs = vs->next;
            pr = newNode;
        }
    }
}

StackLst::~StackLst() {
    while (head_ != nullptr) {
        Node* delete_future = head_;
        head_ = head_->next;
        delete delete_future;
    }
}

StackLst& StackLst::operator=(const StackLst& rhs) noexcept {
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
                if (tvs != head_) {
                    pr->next = newNode;
                    tvs = newNode;
                }
                else {
                    head_ = newNode;
                    tvs = newNode;
                }
            }
            pr = tvs;
            vs = vs->next;
            tvs = tvs->next;
        }
        while (tvs != nullptr) {
            Node* delete_future = tvs;
            tvs = tvs->next;
            delete delete_future;
        }
        pr->next = nullptr;
    }
    return *this;
}

void StackLst::Push(const Complex& c) {
    Node* newNode = new Node(c);
    newNode->next = head_;
    head_ = newNode;
}

void StackLst::Pop() noexcept {
    if (head_ != nullptr) {
        Node* delete_future = head_;
        head_ = head_->next;
        delete delete_future;
    }
}

bool StackLst::IsEmpty() const noexcept {
    return (head_ == nullptr) ? 1 : 0;
}

Complex& StackLst::Top() {
    if (head_ == nullptr) {
        throw std::logic_error("Stack is empty!\n");
    }
    else {
        return head_->v;
    }
}

const Complex& StackLst::Top() const {
    if (head_ == nullptr) {
        throw std::logic_error("Stack is empty!\n");
    }
    else {
        return head_->v;
    }
}

void StackLst::Clear() noexcept {
    while (head_ != nullptr) {
        Node* delete_future = head_;
        head_ = head_->next;
        delete delete_future;
    }
}