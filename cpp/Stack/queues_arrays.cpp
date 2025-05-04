#include <bits/stdc++.h>
using namespace std;

// Implementation of Queues using Arrays

int frontIdx = -1; 
int rearIdx = -1;
int currSize = 0;
int* arr;

// PUSH
void push(int x){
    if (currSize == 99){
        cout << "Queue is Full can not PUSH \n";
        return;
    }

    if(frontIdx == -1){
        frontIdx = 0;
        rearIdx = 0;
    }
    else rearIdx++;

    arr[rearIdx] = x;
    cout << "New element is pushed to QUEUE : " << x << "\n";
    currSize++;
}

// POP
void pop(){
    if(frontIdx == -1){
        cout << "Queue is already EMPTY \n";
        return;
    }
    int popped = arr[frontIdx];

    if(currSize == 1){
        frontIdx = -1;
        rearIdx = -1;
    }
    else frontIdx++;

    currSize--;
    cout << "Popped Element = " << popped << "\n";
}

// PEEK
void peek(){
    if(frontIdx == -1){
        cout << "Queue is EMPTY \n";
        return;
    }
    int peeked = arr[frontIdx];
    cout << "Peek element  = " << peeked << "\n";
}

// isEmpty
void isEmpty(){
    if(frontIdx == -1 || currSize == 0 || frontIdx > rearIdx) {
        cout << "Queue is empty \n";
    }
    else cout << "Queue is NOT Empty \n";
}

int main(){
    arr = new int[100];
    string funCall[] = {"push", "pop", "peek", "isEmpty"};
    for(int i = 0; i < 10; i++){
        int random = rand() % 4;
        switch (random){
            case 0: 
                push(i);
                break;
            case 1: 
                pop();
                break;
            case 2: 
                peek();
                break;
            case 3: 
                isEmpty();
                break;
        }
    }
    delete[] arr;
    return 0;
}
