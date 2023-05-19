#include <bits/stdc++.h>
#include <sstream>
using namespace std;

/*Идёт 2163 год. Мишу, который работает в отделении таможни при космодроме города Нью-Питер, вызвал в кабинет шеф.
Как оказалось, недавно Министерство Налогов и Сборов выделило отделению определённую сумму денег на установку новых аппаратов для автоматического досмотра грузов. Естественно, средства были выделены с таким расчётом, чтобы грузы теперь находились на таможне ровно столько времени, сколько требуется непосредственно на их досмотр.
В руках шефа каким-то образом оказались сведения о надвигающейся ревизии – список из N грузов, которые будут контролироваться Министерством. Для каждого груза известны время его прибытия, отсчитываемое с некоторого момента, хранимого в большом секрете, и время, требуемое аппарату для обработки этого груза. Шеф дал Мише задание по этим данным определить, какое минимальное количество аппаратов необходимо заказать на заводе, чтобы все грузы Министерства начинали досматриваться сразу после прибытия. Необходимо учесть, что конструкция тех аппаратов, которые было решено установить, не позволяет обрабатывать два груза одновременно на одном аппарате. Напишите программу, которая поможет Мише справиться с его задачей.*/

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> events(2*n);
    //vector<pair<int, int>> r(n);

    for (int i = 0; i < 2*n; i += 2) {
        cin >> events[i].first >> events[i + 1].first;
        events[i + 1].first += events[i].first;
        events[i].second = 1;
        events[i + 1].second = -1;
    }

    sort(events.begin(), events.end(), [](pair<int, int> &a, pair<int, int> &b)
    {return a.first == b.first ? a.second < b.second : a.first < b.first;});


    //______     _______
    //  _____   ____       ____

    int max = 0, cur = 0;

//    for (int i = 0; i < 2*n; i += 1) {
//        cout << events[i].first << " " << events[i].second << "\n";
//    }

    for (int i = 0; i < 2*n; ++i) {
        if (events[i].second == 1)
            ++cur;
        else
            --cur;
        if (cur > max)
            max = cur;
    }

    cout << max;

    return 0;
}
