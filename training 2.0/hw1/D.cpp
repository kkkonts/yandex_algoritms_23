#include <bits/stdc++.h>


using namespace std;

int Median(vector<int> &a) {
    if (a.size() == 1)
        return a[0];
    if (a.size() == 2)
        return (a[0] + a[1]) / 2;
    else {
        a.pop_back();
        a.erase(a.begin());
        return Median(a);
    }
    
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    
    cout << Median(a);


    return 0;
}
