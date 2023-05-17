#include <bits/stdc++.h>
#include <sstream>

/*Даны два списка чисел, которые могут содержать до 100000 чисел каждый. Посчитайте, сколько чисел содержится одновременно как в первом списке, так и во втором. Примечание. Эту задачу на Питоне можно решить в одну строчку.*/

using namespace std;

int main() {
    unordered_set<int> set;
    string line;
    int num;

    getline(std::cin, line);
    istringstream iss(line);

    while (iss >> num) {
        set.insert(num);
    }

    getline(std::cin, line);
    iss.str(line);
    iss.clear();

    int count = 0;

    while (iss >> num) {
        if(set.find(num) != set.end())
            ++count;
    }

    cout << count;

    return 0;
}


