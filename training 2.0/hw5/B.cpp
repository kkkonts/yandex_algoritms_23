#include <bits/stdc++.h>
#include <sstream>
using namespace std;

/*В этой задаче вам требуется найти непустой отрезок массива с максимальной суммой.*/

int main() {
    int n;
    long long max, cur;
    cin >> n;

    vector<int> a(n);
    vector<long long> sum(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    max = a[0], cur = a[0];

    for (int i = 1; i < n; ++i) {
        cur = (a[i] + cur) > a[i] ? a[i] + cur : a[i];
        max = max > cur ? max : cur;
    }

    cout << max << "\n";

    return 0;
}
