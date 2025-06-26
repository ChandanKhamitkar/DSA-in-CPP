#include <bits/stdc++.h>
using namespace std;

class BinaryHeap
{
public:
    int capacity;
    int size;
    int *arr;

    BinaryHeap(int cap)
    {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int left(int i)
    {
        return 2 * i + 1;
    }

    int right(int i)
    {
        return 2 * i + 2;
    }

    void swap(int *x, int *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    void insert(int val)
    {
        if (size == capacity)
        {
            cout << "Binary Heap Overflow \n";
            return;
        }

        arr[size] = val;
        int k = size; // store the index of new value
        size++;

        // Maintain Min-Heap Property
        // neglecting loop for root node
        while (k != 0 && arr[parent(k)] > arr[k])
        {
            swap(&arr[parent(k)], &arr[k]);
            k = parent(k);
        }
    }

    int getMin()
    {
        return arr[0];
    }

    void Heapify(int ind)
    {
        int ri = right(ind);
        int li = left(ind);
        int smallest = ind;

        if (li < size && arr[li] < arr[smallest])
            smallest = li;
        if (ri < size && arr[ri] < arr[smallest])
            smallest = ri;

        // Smallest variable will store the minValue index
        // stop recurisive call when root node is the minValue
        if (smallest != ind)
        {
            swap(&arr[ind], &arr[smallest]);
            Heapify(smallest);
        }
    }

    int ExtractMin()
    {
        if (size <= 0)
            return INT_MAX;
        if (size == 1)
        {
            size--;
            return arr[0];
        }

        int mini = arr[0];      // store the removing min node
        arr[0] = arr[size - 1]; // copy last node to root
        size--;
        Heapify(0);
        return mini;
    }

    void DecreaseKey(int i, int val)
    {
        arr[i] = val;
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(&arr[parent(i)], &arr[i]);
            i = parent(i);
        }
    }

    void Delete(int i)
    {
        DecreaseKey(i, INT_MIN);
        ExtractMin();
    }

    void print()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    BinaryHeap h(20);
    h.insert(4);
    h.insert(1);
    h.insert(2);
    h.insert(6);
    h.insert(7);
    h.insert(3);
    h.insert(8);
    h.insert(5);
    cout << "Min value is " << h.getMin() << endl;
    h.insert(-1);
    cout << "Min value is " << h.getMin() << endl;
    h.DecreaseKey(3, -2);
    h.print();
    cout << "Min value is " << h.getMin() << endl;
    h.ExtractMin();
    cout << "Min value is " << h.getMin() << endl;
    h.Delete(0);
    cout << "Min value is " << h.getMin() << endl;
    return 0;
}