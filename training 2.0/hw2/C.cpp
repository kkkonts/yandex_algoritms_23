#include <bits/stdc++.h>

/*В строкоремонтную мастерскую принесли строку, состоящую из строчных латинских букв. Заказчик хочет сделать из неё палиндром. В мастерской могут за 1 байтландский тугрик заменить произвольную букву в строке любой выбранной заказчиком буквой.
Какую минимальную сумму придётся заплатить заказчику за ремонт строки?
Напомним, что палиндромом называется строка, которая равна самой себе, прочитанной в обратном направлении.*/
using namespace std;

int main() {
    string s{};
    cin >> s;
    string::iterator bg = s.begin(), end = s.end() - 1;
    int cnt = 0;
   
    for (int i = 0; i < s.size() / 2 && bg != end; ++i) {
	    if (*bg != *end)
            ++cnt;
	    ++bg;
	    --end;
    }
    
    cout << cnt;


    return 0;
}
