#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    int max = -1e9, cur = 1;
    map<int, int> mp{};

    while (cur != 0) {
        cin >> cur;
        if (cur > max && cur != 0) {
            max = cur;
        }
        ++mp[cur];
    }
    
    cout << mp[max];


    return 0;
}
