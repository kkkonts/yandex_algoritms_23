#include <bits/stdc++.h>
#include <sstream>
using namespace std;
/*В этой задаче вам нужно будет много раз отвечать на запрос «Найдите сумму чисел на отрезке в массиве».*/

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    vector<long long> sum(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }

    int l, r;
    for (int i = 0; i < q; ++i) {
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << "\n";
    }


    return 0;
}
