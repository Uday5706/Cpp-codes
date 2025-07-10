#include <iostream>
#include <queue>
using namespace std;

class stack{
    int N;
    queue<int> q1;
    queue<int> q2;
public:
    stack(){
        N=0;
    }

    void push(int x){
        q2.push(x);
        N++;
        while (!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }

    void pop(){
        if (q1.empty()){
            cout<<"underflow"<<endl;
            return;
        }
        N--;
        q1.pop();
    }

    void top(){
        if (q1.empty()){
            cout<<"Stack empty"<<endl;
            return;
        }
        cout<<q1.front()<<endl;
    }
};

int main() {
    return 0;
}