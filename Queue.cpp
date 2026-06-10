#include <iostream>
using namespace std;

class Queue {
    int arr[5];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    void insert(int x) {
        if(rear == 4) {
            cout << "Queue Full\n";
            return;
        }
        arr[++rear] = x;
    }

    void deleteElement() {
        if(front > rear) {
            cout << "Queue Empty\n";
            return;
        }
        cout << arr[front++] << " deleted\n";
    }

    void search(int x) {
        for(int i=front;i<=rear;i++) {
            if(arr[i]==x) {
                cout << x << " Found\n";
                return;
            }
        }
        cout << x << " Not Found\n";
    }

    void display() {
        for(int i=front;i<=rear;i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;

    q.insert(5);
    q.insert(10);
    q.insert(15);

    q.display();

    q.search(10);

    q.deleteElement();

    q.display();

    return 0;
}