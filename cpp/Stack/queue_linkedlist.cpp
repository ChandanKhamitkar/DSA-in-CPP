#include <bits/stdc++.h>
using namespace std;

struct queueNode
{
    int data;
    queueNode *next;

    queueNode(int x)
    {
        data = x;
        next = nullptr;
    }
};

struct Myqueue
{
    queueNode *l;
    queueNode *r;
    int size;

    Myqueue()
    {
        l = nullptr;
        r = nullptr;
        size = 0;
    }

    void queuePush(int x)
    {
        queueNode *newNode = new queueNode(x);

        if (r == nullptr)
        {
            l = r = newNode;
        }
        else
        {
            r->next = newNode;
            r = newNode;
        }

        cout << "Element pushed: " << x << "\n";
        size++;
    }

    int queuePop()
    {
        if (l == nullptr)
        {
            cout << "Queue is empty | Can't Pop \n";
            return -1;
        }

        int popped = l->data;
        queueNode *delNode = l;
        l = l->next;
        delete delNode;
        size--;

        return popped;
    }

    int queuePeek()
    {
        if (l == nullptr)
        {
            cout << "Queue is empty  Can't Peek \n";
            return -1;
        }
        return l->data;
    }

    bool queueIsEmpty()
    {
        return l == nullptr;
    }
};

int main()
{
    Myqueue q;
    q.queuePush(10);
    q.queuePush(20);
    q.queuePush(30);
    cout << "Element popped: " << q.queuePop() << "\n";
    cout << "Queue empty or not? " << (q.queueIsEmpty() ? "Yes" : "No") << "\n";
    cout << "Queue's top element: " << q.queuePeek() << "\n";

    return 0;
}