#include <bits/stdc++.h>
#include <sstream>
using namespace std;

/*На числовой прямой окрасили N отрезков. Известны координаты левого и правого концов каждого отрезка (Li и Ri). Найти длину окрашенной части числовой прямой.*/

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> seg(n);

    for (int i = 0; i < n; ++i) {
        cin >> seg[i].first >> seg[i].second;
    }

    sort(seg.begin(), seg.end(), [](pair<int, int> &a, pair<int, int> &b)
                                                {return a.first < b.first;});
    int len = 0, curStart = seg[0].first, curEnd = seg[0].second;
    //______     _______
    //  _____   ____       ____

    for (int i = 1; i < n; ++i) {
         if (curEnd < seg[i].first) {
            len += curEnd - curStart;
            curStart = seg[i].first;
            curEnd = seg[i].second;
        }

        else if (seg[i].second > curEnd) {
            curEnd = seg[i].second;
        }
    }

    len += curEnd - curStart;
    cout << len;


    return 0;
}
