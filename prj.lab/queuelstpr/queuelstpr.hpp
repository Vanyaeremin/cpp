#pragma once
#ifndef QUEUELSTPR
#define QUEUELSTPR

#include <iostream>
#include <algorithm>
#include <cstddef>
#include <stdexcept>

class QueueLstPr {
public:
    QueueLstPr() = default;
    ~QueueLstPr();
    QueueLstPr(const QueueLstPr& rhs);
    QueueLstPr(QueueLstPr&& rhs) noexcept;
    QueueLstPr& operator=(const QueueLstPr& rhs);
    QueueLstPr& operator=(QueueLstPr&& rhs) noexcept;

    void Push(const float& f);
    void Pop() noexcept;
    void Clear() noexcept;
    bool IsEmpty() const noexcept;
    float& Top() &;
    const float& Top() const &;

private:
    struct Node {
        float f = 0;
        Node* next = nullptr;
        Node(const float& item) : f(item) {}
        Node() = default;
        ~Node() = default;
    };
    Node* head_ = nullptr;
};

#endif