#include <iostream>
struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head))
    {
    }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty();
    unsigned long Size();
    void PushFront(int value);
    void PushBack(int value);
    int PopFront();
    int PopBack();
    void Clear();

private:
    ListNode* extractPrev(ListNode* node);

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};