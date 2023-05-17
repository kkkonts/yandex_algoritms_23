#include <bits/stdc++.h>
#include <sstream>
using namespace std;

/* Дан текст. Выведите все слова, встречающиеся в тексте, по одному на каждую строку. Слова должны быть отсортированы по убыванию их количества появления в тексте, а при одинаковой частоте появления — в лексикографическом порядке. Указание. После того, как вы создадите словарь всех слов, вам захочется отсортировать его по частоте встречаемости слова. Желаемого можно добиться, если создать список, элементами которого будут кортежи из двух элементов: частота встречаемости слова и само слово. Например, [(2, 'hi'), (1, 'what'), (3, 'is')]. Тогда стандартная сортировка будет сортировать список кортежей, при этом кортежи сравниваются по первому элементу, а если они равны — то по второму. Это почти то, что требуется в задаче.
*/

int main() {
    map<string, int> words;
    string line, word;

    while(getline(cin, line)){
        string person;
        istringstream iss(line);
        while (iss >> word)
            ++words[word];
    }
     vector<pair<string, int> > vec;
    
    for (auto& it : words) {
        vec.push_back(it);
    }
    
    sort(vec.begin(), vec.end(), [](pair<string, int>& a, pair<string, int>& b)
                                {return (a.second == b.second) ? 
                                     (a.first < b.first) : (a.second > b.second);});
    
    for(auto elem : vec)
        std::cout << elem.first << "\n";
    
    return 0;
}


