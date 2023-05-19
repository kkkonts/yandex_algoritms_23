#include <bits/stdc++.h>
#include <sstream>
using namespace std;

/* Клуб Юных Хакеров организовал на своем сайте форум. Форум имеет следующую структуру: каждое сообщение либо начинает новую тему, либо является ответом на какое-либо предыдущее сообщение и принадлежит той же теме.
После нескольких месяцев использования своего форума юных хакеров заинтересовал вопрос - какая тема на их форуме наиболее популярна. Помогите им выяснить это..*/

struct Topic {
    int count;
    string name;
};

int main() {
    string line, topic, f;
    int n, parent, i = 1, k = 0;
    map<int, int> mes; // mes_num : topic_num
    map<int, Topic> topics; //index

    std::getline(std::cin, line);
    std::istringstream iss(line);
    iss >> n;

    for(int i = 1; i <= n; ++i){
        std::getline(std::cin, line);
        std::istringstream iss(line);
        iss >> parent;
        if(parent == 0){
            getline(cin, topic);
            topics[i].name = topic;
            getline(cin, line);
            mes[i]= i;
        } else {
            getline(cin, line);
            mes[i] = mes[parent];
            topics[mes[parent]].count++;
        }
    }

    int max = -1;
    string ans;

    for(auto elem : topics) {
        if (elem.second.count > max) {
            ans = elem.second.name;
            max = elem.second.count;
        }

//        std::cout << elem.second.name << " " <<
//                  elem.second.count << "\n";
    }

    cout << ans;

    return 0;
}
