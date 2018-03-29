#include <iostream>

using namespace std;

int main() {
    int s;

    cin >> s;

    for(int i=1;i<s;i++) {
        for(int j=0;j<i;j++){
            cout << "*";
        }
        cout <<endl;
    }

    for(int i=s;i>0;i--) {
        for(int j=0;j<i;j++){
            cout << "*";
        }
        cout <<endl;
    }
    return 0;
}