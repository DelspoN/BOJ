#include <iostream>
#include <queue>

using namespace std;

struct card {
    int val;
    int idx;
};

int main() {
    int total, n, m, turn;
    struct card input;
    queue<struct card> q;
    priority_queue<int, vector<int>, less<int>> pq;

    cin >> total;

    for(int i=0; i<total; i++){
        cin >> n;
        cin >> m;
        turn = 0;

        while(!pq.empty())
            pq.pop();
        while(!q.empty())
            q.pop();

        for (int j=0; j<n; j++) {
            cin >> input.val;
            input.idx = j;
            q.push(input);
            pq.push(input.val);
        }


        while(!q.empty()) {
            struct card data = q.front();
            if (data.val == pq.top()) {
                if (data.idx == m)
                    break;
                pq.pop();
                turn++;
            }
            else
                q.push(data);
            q.pop();
        }

        cout << turn+1 << endl;
    }
}