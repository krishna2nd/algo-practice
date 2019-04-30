#include <iostream>
using namespace std;

class Queue
{
private:
    int size, front, rear, *arr;

public:
    Queue(int size)
    {
        this->size = size;
        front = rear = -1;
        arr = new int[size];
    }
    void Add(int value)
    {
        if ((front == 0 && rear == size - 1) || rear == (front - 1) % (size - 1))
        {
            cout << "Full";
            return;
        }
        if (front == -1)
        {
            front = rear = 0;
            arr[front] = value;
            return;
        }
        if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = value;
            return;
        }
        arr[++rear] = value;
    }
    int Remove()
    {
        if (front == -1)
        {
            cout << "Empty";
            return -1;
        }
        int data = arr[front];
        arr[front] = -1;
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == rear - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return data;
    }
    void display()
    {
        int i = this->front;
        if (front == -1)
            cout << " ";
        if (rear >= front)
        {
            for (; i < rear; i++)
                cout << arr[i] << " ";
        }
        else
        {
            for (; i < size; i++)
                cout << arr[i] << " ";
            for (i = 0; i < rear; i++)
                cout << arr[i] << " ";
        }
    }
    ~Queue()
    {
        delete arr;
    }
};

int main()
{
    Queue q(5);

    // Inserting elements in Circular Queue
    q.Add(14);
    q.Add(22);
    q.Add(13);
    q.Add(-6);

    // Display elements present in Circular Queue
    q.display();

    // Deleting elements from Circular Queue
    printf("\nDeleted value = %d", q.Remove());
    printf("\nDeleted value = %d", q.Remove());

    q.display();

    q.Add(9);
    q.Add(20);
    q.Add(5);

    q.display();

    q.Add(20);
    return 0;
}
