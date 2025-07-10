#include <iostream>
#include <stack>
using namespace std;

class Queue {
    stack<int> S1, S2;

public:
    void enqueue(int x) {
        S1.push(x);
    }

    void dequeue() {
        if (S1.empty() && S2.empty()) {
            cout << "Underflow\n";
            return;
        }
        if (S2.empty()) {
            while (!S1.empty()) {
                S2.push(S1.top());
                S1.pop();
            }
        }
        cout << "Dequeued: " << S2.top() << endl;
        S2.pop();
    }

    void front() {
        if (S1.empty() && S2.empty()) {
            cout << "Queue is empty\n";
            return;
        }
        if (S2.empty()) {
            while (!S1.empty()) {
                S2.push(S1.top());
                S1.pop();
            }
        }
        cout << "Front: " << S2.top() << endl;
    }

    bool isEmpty() {
        return S1.empty() && S2.empty();
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.front();      // Should print 10
    q.dequeue();    // Should remove 10
    q.front();      // Should print 20

    q.dequeue();    // Removes 20
    q.dequeue();    // Removes 30
    q.dequeue();    // Underflow

    return 0;
}
