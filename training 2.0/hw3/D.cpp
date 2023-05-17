#include <bits/stdc++.h>
#include <sstream>

/* Август и Беатриса играют в игру.
 * Август загадал натуральное число от 1 до n.
 * Беатриса пытается угадать это число, для этого она называет
 * некоторые множества натуральных чисел. Август отвечает Беатрисе YES,
 * если среди названных ей чисел есть задуманное или NO в противном случае.
 * После нескольких заданных вопросов Беатриса запуталась в том, какие
 * вопросы она задавала и какие ответы получила и просит вас помочь ей определить,
 * какие числа мог задумать Август.*/

//so sad to be a c++ coder right now *_*

using namespace std;

void intersection(set<int> &ans, set<int> &cur) {
    for (auto it = ans.begin(); it != ans.end();) {
        if (cur.find(*it) == cur.end())
            it = ans.erase(it);
        else
            ++it;
    }
}

void difference(set<int> &ans, set<int> &cur) {
    for (auto elem : cur) {
            ans.erase(elem);
    }
}

//int main() {
//    std::set<int> ans;
//    std::set<int> cur;
//    std::string line;
//    int n = -1;
//
//    while(std::getline(std::cin, line)){
//        if(line == "HELP") {
//            break;
//        } else if (line == "YES") {
//            intersection(ans, cur);
//        } else if (line == "NO") {
//            difference(ans, cur);
//        } else {
//            std::istringstream iss(line);
//            if (n < 0) {
//                iss >> n;
//                for(int i = 1; i <= n; ++i)
//                    ans.insert(i);
//            } else {
//                cur.clear();
//                int num;
//                while(iss >> num){
//                    cur.insert(num);
//                }
//            }
//        }
//    }
//    for (auto elem : ans)
//        cout << elem << " ";
//    return 0;
//}

int main() {
    set<int> cur;
    set<int> ans;
    int n, num;
    string line;

    //possible answer – intersection of yes sets without no sets
    getline(std::cin, line);
    istringstream iss(line);
    iss >> n;

    for (int i = 1; i <= n; ++i)
        ans.insert(i);

    getline(std::cin, line);
    iss.str(line);
    iss.clear();

    while (line != "HELP") {
        while (iss >> num) {
            cur.insert(num);
        }

        getline(std::cin, line);
        iss.str(line);
        iss.clear();

        if (line == "HELP") {
            break;
        }

        else if (line == "YES") {
            intersection(ans, cur);
        }

        else  if (line == "NO") {
            difference(ans, cur);
        }

        getline(std::cin, line);
        iss.str(line);
        cur.clear();
    }

    for (auto elem : ans)
        cout << elem << " ";

    return 0;
}
