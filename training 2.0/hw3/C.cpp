#include <bits/stdc++.h>
#include <sstream>

/* Дан список. Выведите те его элементы,
 * которые встречаются в списке только один раз.
 * Элементы нужно выводить в том порядке, в котором они встречаются в списке.*/

using namespace std;

int main() {
    set<int> set, dublicate;
    vector<int> vec;
    int num;
    string line;

    getline(std::cin, line);
    istringstream iss(line);

    while (iss >> num) {
        if (set.contains(num))  //if were in set
            dublicate.insert(num);
        else
            set.insert(num);
        vec.push_back(num);
    }

    for (auto elem : vec) {
        if (dublicate.count(elem) == 0)
            cout << elem << " ";
    }

    return 0;
}

