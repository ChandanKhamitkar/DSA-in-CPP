#include <bits/stdc++.h>
using namespace std;

struct stackNode {
    int data;
    stackNode *next;
    stackNode(int d) {
        data = d;
        next = nullptr;
    }
};

struct MyStack {
    stackNode *top;
    int size;

    MyStack() {
        top = nullptr;
        size = 0;
    }

    void stackPush(int x) {
        stackNode *newNode = new stackNode(x);
        newNode->next = top;
        top = newNode;
        cout << "Element pushed: " << x << "\n";
        size++;
    }

    int stackPop() {
        if (top == nullptr) {
            cout << "Stack is empty \n";
            return -1;
        }

        int popped = top->data;
        stackNode *delNode = top;
        top = top->next;
        delete delNode;
        size--;

        return popped;
    }

    int stackPeek() {
        if (top == nullptr) {
            cout << "Stack is empty \n";
            return -1;
        }
        return top->data;
    }

    bool stackIsEmpty() {
        return top == nullptr;
    }
};

int main() {
    MyStack s;
    s.stackPush(10);
    s.stackPush(20);
    s.stackPush(30);
    cout << "Element popped: " << s.stackPop() << "\n";
    cout << "Stack empty or not? " << (s.stackIsEmpty() ? "Yes" : "No") << "\n";
    cout << "Stack's top element: " << s.stackPeek() << "\n";

    return 0;
}
