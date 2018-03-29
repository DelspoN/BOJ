#include <iostream>

using namespace std;

int main() {
    int stat_cnt, bus_cnt;
    int src, dst, cost;
    int test_cost;

    scanf("%d", &stat_cnt);
    scanf("%d", &bus_cnt);

    int bus[100][100];

    for(int i=0;i<stat_cnt;i++) {
        for (int j = 0; j < stat_cnt; j++){
            bus[i][j] = 1000000;
        }
        bus[i][i] = 0;
    }

    for(int i=0;i<bus_cnt;i++) {
        scanf("%d %d %d", &src, &dst, &cost);
        src--;
        dst--;
        if (bus[src][dst] > cost)
            bus[src][dst] = cost;
    }

    for(int i=0;i<stat_cnt;i++) {
        for(int j=0;j<stat_cnt;j++) {
            for(int k=0;k<stat_cnt;k++){
                test_cost = bus[j][i]+bus[i][k];
                if(bus[j][k] > test_cost) {
                    bus[j][k] = test_cost;
                }
            }
        }
    }


    for(int i=0;i<stat_cnt;i++) {
        for (int j = 0; j <stat_cnt; j++) {
            printf("%d ", bus[i][j]);
        }
        puts("");
    }
}