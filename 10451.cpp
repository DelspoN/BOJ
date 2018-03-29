#include <iostream>
#include <vector>
using namespace std;

struct Cycle {
    vector<int> permu, used;
    int max_size, cnt = 0;
    Cycle(int n) : permu(n), used(n) {
        max_size = n;
    }

    void loop(int idx) {
        if (used[idx])
            return;

//        cout << idx << " " << permu[idx] << endl;
        used[idx] = 1;
        loop(permu[idx]);
    }

    void start() {
        for(int i=0; i<max_size; i++) {
            if (used[i])
                continue;
//            cout << "===============" << endl;
            loop(i);
//            cout << "===============" << endl;
            cnt++;
        }
    }

};

int main() {
    int total;
    scanf("%d", &total);

    int data_size, value;
    for (int i=0; i<total; i++) {
        scanf("%d", &data_size);

        Cycle cycle(data_size);

        for (int j=0; j<data_size; j++){
            cin >> value;
            cycle.permu[j] = --value;

        }

        cycle.start();
        cout << cycle.cnt << endl;
    }
}