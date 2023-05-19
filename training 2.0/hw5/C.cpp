#include <bits/stdc++.h>
#include <sstream>
using namespace std;

/*В новом учебном году на занятия в компьютерные классы Дворца Творчества Юных пришли учащиеся, которые были разбиты на N групп. В i-й группе оказалось Xi человек. Тут же перед директором встала серьезная проблема: как распределить группы по аудиториям. Во дворце имеется M ≥ N аудиторий, в j-й аудитории имеется Yj компьютеров. Для занятий необходимо, чтобы у каждого учащегося был компьютер и еще один компьютер был у преподавателя. Переносить компьютеры из одной аудитории в другую запрещается. Помогите директору!
Напишите программу, которая найдет, какое максимальное количество групп удастся одновременно распределить по аудиториям, чтобы всем учащимся в каждой группе хватило компьютеров, и при этом остался бы еще хотя бы один для учителя.*/

int main() {
    int n, m;

    cin >> n >> m;

    vector<pair<int, int>> x(n), y(m);
    vector<long long> sum(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        cin >> x[i].first;
        ++x[i].first;
        x[i].second = i + 1; //number of group
    }

    for (int i = 0; i < m; ++i) {
        cin >> y[i].first;
        y[i].second = i + 1; //number of audience
    }

    sort(x.begin(), x.end(), [](pair<int, int> a, pair<int, int> b)
    {return a.first < b.first;});

    sort(y.begin(), y.end(), [](pair<int, int> a, pair<int, int> b)
    {return a.first < b.first;});


    int i = 0, res = 0, j = 0;

    while (i < n) {

        while (j < m && x[i].first > y[j].first)
            j++;

        if (x[i].first <= y[j].first) {
            x[i].first = y[j].second;
            j++;
            ++res;
        }
        else
            x[i].first = 0;
        ++i;
    }

    sort(x.begin(), x.end(), [](pair<int, int> a, pair<int, int> b)
    {return a.second < b.second;});

    cout << res << "\n";

    for (auto elem : x) {
        cout << elem.first << " ";
    }

    return 0;
}
