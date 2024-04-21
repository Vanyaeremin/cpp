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
    else {
        head_ = nullptr;
    }
}

StackLst::StackLst(StackLst&& rhs) noexcept{
    std::swap(head_, rhs.head_);
}

StackLst::~StackLst() {
    while (head_ != nullptr) {
        Node* delete_future = head_;
        head_ = head_->next;
        delete delete_future;
        delete_future = nullptr;
    }
}

StackLst& StackLst::operator=(StackLst&& rhs) noexcept {
    if (this != &rhs) {
        std::swap(head_, rhs.head_);
    }
    return *this;
}

StackLst& StackLst::operator=(const StackLst& rhs) noexcept {
    if (rhs.head_ == nullptr) {
        head_ = nullptr;
    }
    else {
        if (this != &rhs) {
            Node* rhs_cur = rhs.head_;
            Node* cur = head_;
            Node* tail = cur;
            if (cur == nullptr) {
                Node* newNode = new Node;
                cur = newNode;
                head_ = newNode;
                tail = cur;
            }
            while (rhs_cur != nullptr) {
                if (cur == nullptr) {
                    Node* newNode = new Node;
                    cur = newNode;
                    tail->next = newNode;
                    tail = newNode;
                }

                cur->v = rhs_cur->v;
                rhs_cur = rhs_cur->next;

                if (rhs_cur == nullptr) {
                    tail = cur;
                    tail->next = nullptr;
                }
                cur = cur->next;
            }
            while (cur != nullptr) {
                Node* temp = cur;
                cur = cur->next;
                delete temp;
            }
        }
    }
    return *this;
}

void StackLst::Push(const Complex& c) {
    Node* newNode = new Node(c);
    newNode->next = head_;
    head_ = newNode;
    newNode = nullptr;
}

void StackLst::Pop() noexcept {
    if (head_ != nullptr) {
        Node* delete_future = head_;
        head_ = head_->next;
        delete delete_future;
        delete_future = nullptr;
    }
}

bool StackLst::IsEmpty() const noexcept {
    return (head_ == nullptr) ? 1 : 0;
}

Complex& StackLst::Top() & {
    if (head_ == nullptr) {
        throw std::logic_error("Stack is empty!\n");
    }
    else {
        return head_->v;
    }
}

const Complex& StackLst::Top() const & {
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
        delete_future = nullptr;
    }
}