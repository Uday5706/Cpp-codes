#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id, priority;
};

void vectors()
{
    vector<int> v = {1, 2, 3, 4, 5};

    for (auto it1 = v.rend() - 1; it1 != v.rbegin() - 1; it1--)
    {
        cout << *(it1) << " ";
    }

    for (auto it1 = v.rbegin(); it1 != v.rend(); it1++)
    {
        cout << *(it1) << " ";
    }
}

void PQ()
{
    struct Compare
    {
        bool operator()(Job const &a, Job const &b)
        {
            return a.priority < b.priority; // max-heap by priority
        }
    };

    
    priority_queue<Job, vector<Job>, Compare> pq;

    pq.push({1, 30});
    pq.push({2, 50});
    pq.push({3, 10});

    while (!pq.empty()) {
        Job j = pq.top();
        cout << "Job ID: " << j.id << ", Priority: " << j.priority << endl;
        pq.pop();
    }
}

void ST(){
    set<int> st={1,2,4};
    auto it = st.end();
    st.insert(3);
    --it;
    cout<<*(it);
}

void srt(){
  vector<int> numbers = {1, 7, 3, 5, 9, 2};
  // Sort numbers numerically in reverse order
  sort(numbers.rbegin(), numbers.rend());

  for (int num : numbers) {
    cout << num << "\n";
  }
}

void customSrt(){
    vector<pair<int,int>> v = {{1, 5}, {3, 2}, {2, 5}, {4, 2}, {5, 7}};

    sort(v.begin(), v.end(), [](const pair<int,int> &a, const pair<int,int> &b) {
        if (a.second != b.second)
            return a.second > b.second;  // Descending on second
        else
            return a.first > b.first;    // Descending on first if seconds equal
    });

    for (auto &p : v) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
}

int main(){
    PQ();
    return 0;
}