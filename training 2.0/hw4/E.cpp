#include <bits/stdc++.h>
#include <sstream>
using namespace std;

/* Неизвестный водитель совершил ДТП и скрылся с места происшествия. Полиция опрашивает свидетелей.
 * Каждый из них говорит, что запомнил какие-то буквы и цифры номера.
 * Но при этом свидетели не помнят порядок этих цифр и букв. Полиция хочет
 * проверить несколько подозреваемых автомобилей. Будем говорить, что номер
 * согласуется с показанием свидетеля, если все символы, которые назвал свидетель,
 * присутствуют в этом номере (не важно, сколько раз).*/

bool in(const set<char> &witness, const string &number) {
    //every char should be in set
    set<char> num;

    for (auto elem : number) {
        num.insert(elem);
    }

    for (auto elem : witness) {
        if (num.find(elem) == num.end())
            return false;
    }

    return true;
}

int count(const vector<set<char>> &witnesses, string number) {
    int cnt = 0;

    for (auto witness : witnesses)
        if (in(witness, number))
            ++cnt;
    return cnt;
}


int main() {
    set<char> tmp;
    vector<set<char>> witnesses;
    int m, n, max = 0;
    char ch;
    string number, line, res;
    vector<string> ans;

    cin >> m;
    for(int i = 0; i < m + 1; ++i) {
        getline(std::cin, line);
        std::istringstream iss(line);

        while (iss >> ch)
            tmp.insert(ch);

        witnesses.push_back(tmp);
        tmp.clear();
    }


    cin >> n;

    for(int i = 0; i < n + 1; ++i) {
        getline(std::cin, number);

        if (count(witnesses, number) > max) {
            ans.clear();
            ans.push_back(number);
            max = count(witnesses, number);
        } else if (count(witnesses, number) == max) {
            ans.push_back(number);
        }

    }

    for (auto elem : ans)
        cout << elem << "\n";

    return 0;
}

