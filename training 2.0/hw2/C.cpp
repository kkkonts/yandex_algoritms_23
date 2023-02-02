#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    string s{};
    cin >> s;
    string::iterator bg = s.begin(), end = s.end() - 1;
    int cnt = 0;
   
    for (int i = 0; i < s.size() / 2 && bg != end; ++i) {
	    if (*bg != *end)
            ++cnt;
	    ++bg;
	    --end;
    }
    
    cout << cnt;


    return 0;
}

