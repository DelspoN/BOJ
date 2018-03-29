#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int> > q;
    int num, turn, cnt=0;

    scanf("%d %d", &num, &turn);


    for (int i=1; i<=num; i++) {
        if (num % i == 0){
            q.push(i);
            cnt++;
        }
    }

    if (cnt < turn){
        printf("%d", 0);
        return 0;
    }

    for (int i=0; i<turn-1; i++)
        q.pop();

    printf("%d", q.top());
    return 0;
}