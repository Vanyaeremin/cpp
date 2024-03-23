#include "queuelstpr.hpp"

QueueLstPr::QueueLstPr(const QueueLstPr& rhs) {
    if (rhs.head_ != nullptr) {
        Node* newNode = new Node(rhs.head_->f);
        head_ = newNode;
        Node* next = rhs.head_->next;
        Node* cur = newNode;
        while (next != nullptr) {
            Node* newNode = new Node(next->f);
            cur->next = newNode;
            cur = newNode;
            next = next->next;
        }
    }
}

QueueLstPr::QueueLstPr(QueueLstPr&& rhs) noexcept {
    std::swap(head_, rhs.head_);
}

QueueLstPr& QueueLstPr::operator=(const QueueLstPr& rhs) {
    if (this != &rhs) {
        Node* cur = head_;
        Node* rh_cur = rhs.head_;
        Node* pr;
        while (rh_cur != nullptr) {
            if (cur == nullptr) {
                Node* newNode = new Node(rh_cur->f);
                cur = newNode;
                if (head_ != nullptr) {
                    pr->next = newNode;
                }
                else {
                    head_ = newNode;
                }
            }
            cur->f = rh_cur->f;
            pr = cur;
            cur = cur->next;
            rh_cur = rh_cur->next;
        }
        while (cur != nullptr) {
            Node* future_delete = cur;
            cur = cur->next;
            delete future_delete;
            future_delete = nullptr;
        }
        pr->next = nullptr;
    }
    return *this;
}

QueueLstPr& QueueLstPr::operator=(QueueLstPr&& rhs) noexcept{
    if (this != &rhs) {
        std::swap(head_, rhs.head_);
    }
    return *this;
}

void QueueLstPr::Push(const float& f) {
    Node* newNode = new Node(f);
    if (head_ == nullptr) {
        head_ = newNode;
    }
    else {
        if (newNode->f <= head_->f) {
            newNode->next = head_;
            head_ = newNode;
        }
        else {
            bool flag = 0;
            Node* pred = head_;
            Node* future = head_->next;
            while (future != nullptr) {
                if ((newNode->f >= pred->f) && (newNode->f <= future->f)) {
                    pred->next = newNode;
                    newNode->next = future;
                    flag = 1;
                    break;
                }
                pred = pred->next;
                future = future->next;
            }
            if (future == nullptr && flag == 0) {
                pred->next = newNode;
                flag = 1;
            }
        }
    }
}

void QueueLstPr::Pop() noexcept{
    if (head_ != nullptr) {
        Node* future_delete = head_;
        head_ = head_->next;
        delete future_delete;
        future_delete = nullptr;
    }
}

QueueLstPr::~QueueLstPr() {
    while (head_ != nullptr) {
        Node* future_delete = head_;
        head_ = head_->next;
        delete future_delete;
        future_delete = nullptr;
    }
}

void QueueLstPr::Clear() noexcept {
    while (head_ != nullptr) {
        Node* future_delete = head_;
        head_ = head_->next;
        delete future_delete;
        future_delete = nullptr;
    }
}

bool QueueLstPr::IsEmpty() const noexcept {
    return head_ == nullptr;
}

float& QueueLstPr::Top() {
    if (head_ == nullptr) {
        throw std::logic_error("QueueLstPr is empty!\n");
    }
    else {
        return head_->f;
    }
}

const float& QueueLstPr::Top() const {
    if (head_ == nullptr) {
        throw std::logic_error("QueueLstPr is empty!\n");
    }
    else {
        return head_->f;
    }
}