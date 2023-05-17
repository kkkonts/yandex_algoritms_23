#include <bits/stdc++.h>


using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    
    if (a > b)
        swap(a, b);
    // . . . a . . b . . n
    std::cout << min(b - a - 1, n - b + a - 1);
}
