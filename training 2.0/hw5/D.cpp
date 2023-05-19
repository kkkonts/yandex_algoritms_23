#include <bits/stdc++.h>
#include <sstream>
using namespace std;

/*Если из правильного арифметического выражения вычеркнуть всё, кроме круглых скобок, то получится правильная скобочная последовательность. Проверьте, является ли введённая строка правильной скобочной последовательностью.*/

int main() {
    string line;
    getline(cin, line);

    if (line.size() % 2)
        cout << "NO";
    else {
        int open = 0;

        for(auto &sym : line) {
            if (sym == '(') {
                ++open;
            }
            else if (sym == ')') {
                --open;
            }
            if (open < 0)
                break;
        }

        if (open == 0)
            cout << "YES";
        else
            cout << "NO";
    }

    return 0;
}
