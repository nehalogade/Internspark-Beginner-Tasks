#include <iostream>
using namespace std;

class Stack {
    int arr[5];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if(top == 4) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
        cout << x << " inserted\n";
    }

    void pop() {
        if(top == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << arr[top--] << " deleted\n";
    }

    void search(int x) {
        for(int i=0;i<=top;i++) {
            if(arr[i]==x) {
                cout << x << " Found\n";
                return;
            }
        }
        cout << x << " Not Found\n";
    }

    void display() {
        for(int i=0;i<=top;i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.search(20);

    s.pop();

    s.display();

    return 0;
}