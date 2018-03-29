#include <iostream>
using namespace std;

int main() {
    int h, w, se_flag;
    double area;
    char line;

    cin >> h;
    cin >> w;

    for (int j=0; j<h; j++) {
        se_flag = 0;
        for (int i = 0; i < w; i++) {
            cin >> line;
            if ((line == '/') || (line == '\\')) {
                if (se_flag == 0)
                    se_flag = 1;
                else if (se_flag == 1)
                    se_flag = 0;
                area += 0.5;
            } else if ((line == '.') && (se_flag == 1))
                area += 1;
        }
    }

    cout << area;
    return 0;
}