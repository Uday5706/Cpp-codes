#include <iostream>
#include <stack>
using namespace std;

class Queue {
    stack<int> s;

public:
    void enqueue(int x) {
        s.push(x);
    }

    void dequeue() {
        if (s.empty()) {
            cout << "Underflow\n";
            return;
        }

        int x = s.top();
        s.pop();

        if (s.empty()) {
            cout << "Dequeued: " << x << endl;
            return;
        }

        dequeue();
        s.push(x);  // push back after recursive removal
    }

    void front() {
        if (s.empty()) {
            cout << "Queue is empty\n";
            return;
        }

        int x = s.top();
        s.pop();

        if (s.empty()) {
            cout << "Front: " << x << endl;
            s.push(x); // restore
            return;
        }

        front();
        s.push(x); // restore
    }

    bool isEmpty() {
        return s.empty();
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.front();     // Should print 10
    q.dequeue();   // Removes 10
    q.front();     // Should print 20

    q.dequeue();   // Removes 20
    q.dequeue();   // Removes 30
    q.dequeue();   // Underflow

    return 0;
}
 