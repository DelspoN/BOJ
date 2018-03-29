#include <iostream>

#define MAX_SIZE 64

using namespace std;

int data[MAX_SIZE][MAX_SIZE], n;

int is_min_block(int start_i, int start_j, int block) {
    int sum = 0;

    for (int i = start_i; i < start_i+block; i++)
        for (int j = start_j; j < start_j+block; j++)
            sum += data[i][j];

    if (sum == 0 || sum == block*block)
        return 1;
    return 0;
}

void print_block(int pos_i, int pos_j, int block_size) {
    if (block_size < 1)
        return;

    printf("(");
    //1
    if (is_min_block(pos_i,pos_j,block_size))
        printf("%d", data[pos_i][pos_j]);
    else
        print_block(pos_i, pos_j, block_size / 2);
    //2
    if (is_min_block(pos_i,pos_j + block_size,block_size))
        printf("%d", data[pos_i][pos_j + block_size]);
    else
        print_block(pos_i, pos_j + block_size, block_size / 2);
    //3
    if (is_min_block(pos_i + block_size,pos_j,block_size))
        printf("%d", data[pos_i + block_size][pos_j]);
    else
        print_block(pos_i + block_size, pos_j, block_size / 2);
    //4
    if (is_min_block(pos_i + block_size,pos_j + block_size,block_size))
        printf("%d", data[pos_i + block_size][pos_j + block_size]);
    else
        print_block(pos_i + block_size, pos_j + block_size, block_size / 2);
    printf(")");
}

int main() {
    for(int i=0;i<MAX_SIZE;i++)
        for(int j=0;j<MAX_SIZE;j++)
            data[i][j] = 0;

    scanf("%d", &n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%1d", &data[i][j]);
        }
    }

    if(is_min_block(0,0,n))
        printf("1");
    else
        print_block(0,0,n/2);

    return 0;
}