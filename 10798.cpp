#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int main() {
    char input[5][15] = {0,};
    priority_queue<int,vector<int>,less<int> > size_q;

    for(int i=0;i<5;i++) {
        scanf("%s",input[i]);
        size_q.push(strlen(input[i]));
    }

    int max_size = size_q.top();

    for(int i=0;i<max_size;i++) {
        for(int j=0;j<5;j++) {
    		if(input[j][i])
        	    printf("%c",input[j][i]);
        }
    }

    return 0;
}