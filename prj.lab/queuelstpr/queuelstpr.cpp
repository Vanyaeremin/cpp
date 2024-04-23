#include "queuelstpr.hpp"

QueueLstPr::QueueLstPr(const QueueLstPr& rhs) {
    if (rhs.head_ != nullptr) {
        if (this != &rhs) {
            Node* newNode = new Node(rhs.head_->f);
            Node* cur = newNode;
            head_ = newNode;
            Node* current = rhs.head_->next;
            while (current != nullptr) {
                Node* newNode = new Node(current->f);
                current = current->next;
                cur->next = newNode;
                cur = newNode;
            }
        }
    }
    else {
        head_ = nullptr;
    }
}

QueueLstPr::QueueLstPr(QueueLstPr&& rhs) noexcept {
    std::swap(head_, rhs.head_);
}

QueueLstPr& QueueLstPr::operator=(const QueueLstPr& rhs) {
    if (rhs.head_ == nullptr) {
        while (head_ != nullptr) {
            Pop();
        }
    }
    else {
        if (head_ == nullptr) {
            Node* new_node = new Node;
            head_ = new_node;
        }
        Node* cur = head_;
        Node* current = rhs.head_;
        Node* future_delete = nullptr;
        Node* future_delete_2 = nullptr;
        while (current != nullptr) {
            cur->f = current->f;
            if (cur->next == nullptr && current->next != nullptr) {
                Node* newNode = new Node;
                cur->next = newNode;
            }
            current = current->next;
            if (current == nullptr) {
                future_delete = cur->next;
                cur->next = nullptr;

            }
            cur = cur->next;
        }
        while (future_delete != nullptr) {
            future_delete_2 = future_delete;
            future_delete = future_delete->next;
            delete future_delete_2;
        }
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
    Node* new_node = new Node(f);
    Node* cur = head_;
    Node* prev = nullptr;

    if (cur == nullptr) {
        head_ = new_node;
    }
    else {
        while (cur != nullptr) {
            if (f > cur->f) {
                prev = cur;
                if (cur->next == nullptr) {
                    cur->next = new_node;
                    break;
                }
                cur = cur->next;
            }
            else {
                if (cur == head_) {
                    head_ = new_node;
                }
                else {
                    prev->next = new_node;
                }
                new_node->next = cur;
                break;
            }
        }
    }
}

void QueueLstPr::Pop() noexcept{
    if (head_ != nullptr) {
        Node* future_delete = head_;
        head_ = future_delete->next;
        delete future_delete;
        future_delete = nullptr;
    }
}

QueueLstPr::~QueueLstPr() {
    Node* future_delete = head_;
    while (future_delete != nullptr) {
        future_delete = head_->next;
        delete head_;
        head_ = future_delete;
    }
}

void QueueLstPr::Clear() noexcept {
    while (!IsEmpty()) {
        Pop();
    }
}

bool QueueLstPr::IsEmpty() const noexcept {
    return head_ == nullptr;
}

float& QueueLstPr::Top() & {
    if (head_ == nullptr) {
        throw std::logic_error("QueueLstPr is empty!\n");
    }
    else {
        return head_->f;
    }
}

const float& QueueLstPr::Top() const & {
    if (head_ == nullptr) {
        throw std::logic_error("QueueLstPr is empty!\n");
    }
    else {
        return head_->f;
    }
}