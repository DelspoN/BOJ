#include <iostream>
using namespace std;

int main() {
    int array[21];

    for (int i=1; i<=20; i++) {
        array[i] = i;
    }

    int start, end;
    int tmp;

    for (int cnt=0; cnt<10; cnt++) {
        cin >> start;
        cin >> end;

        for (int i=start, j=end; i<=start+(end-start)/2; i++, j--) {
            tmp = array[j];
            array[j] = array[i];
            array[i] = tmp;
        }
    }

    for (int i=1; i<=20; i++) {
        cout << array[i] << " ";
    }

    return 0;
}