#include <bits/stdc++.h>
#include <sstream>

/*Во входной строке записана последовательность чисел через пробел. Для каждого числа выведите слово YES (в отдельной строке), если это число ранее встречалось в последовательности или NO, если не встречалось.*/

using namespace std;

int main() {
    unordered_set<int> set;
    int num;

    while (cin >> num) {
        if (set.find(num) != set.end())
            cout << "YES\n";
        else
            cout << "NO\n";


        set.insert(num);
    }

    return 0;
}

