#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    int x, y, d, min = 1e9, res;
    cin >> d >> x >> y;
    
    
    //C(0,d)
    //
    //A      B(d,0)

    if (x >= 0 && y >= 0 && y + x <= d)
        cout << 0;
    else {
        if (sqrt(pow(x, 2) + pow(y, 2)) < min) { 
            res = 1;
            min = sqrt(pow(x, 2) + pow(y, 2));
        }
        if (sqrt(pow(x - d, 2) + pow(y, 2)) < min) {
            res = 2;
            min = sqrt(pow(x - d, 2) + pow(y, 2));
        }
        if (sqrt(pow(x, 2) + pow(y - d, 2)) < min) {
            res = 3;
            min = sqrt(pow(x, 2) + pow(y - d, 2));
        }
        cout << res;
        
    }
    
    return 0;
}
