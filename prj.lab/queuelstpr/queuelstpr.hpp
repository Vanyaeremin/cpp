#pragma once
#ifndef QUEUELSTPR
#define QUEUELSTPR

#include <iostream>
#include <cstddef>

class QueueLstPr {
public:
    [[nodiscard]] QueueLstPr() = default;
    ~QueueLstPr();
    [[nodiscard]] QueueLstPr(const QueueLstPr& rhs);
    [[nodiscard]] QueueLstPr& operator=(const QueueLstPr& rhs);

    void Push(const float& f);
    void Pop() noexcept;
    void Clear() noexcept;
    bool IsEmpty() const noexcept;
    [[nodiscard]] float& Top();
    [[nodiscard]] const float& Top() const;

private:
    struct Node {
        float f;
        Node* next = nullptr;
        Node(const float& item) : f(item) {}
        ~Node() = default;
    };
    Node* head_ = nullptr;
};

#endif