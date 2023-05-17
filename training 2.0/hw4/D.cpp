#include <bits/stdc++.h>
#include <sstream>
using namespace std;

/* Статья 83 закона “О выборах депутатов Государственной Думы Федерального Собрания Российской Федерации” определяет следующий алгоритм пропорционального распределения мест в парламенте.
Необходимо распределить 450 мест между партиями, участвовавших в выборах. Сначала подсчитывается сумма голосов избирателей, поданных за каждую партию и подсчитывается сумма голосов, поданных за все партии. Эта сумма делится на 450, получается величина, называемая “первое избирательное частное” (смысл первого избирательного частного - это количество голосов избирателей, которое необходимо набрать для получения одного места в парламенте).
Далее каждая партия получает столько мест в парламенте, чему равна целая часть от деления числа голосов за данную партию на первое избирательное частное.
Если после первого раунда распределения мест сумма количества мест, отданных партиям, меньше 450, то оставшиеся места передаются по одному партиям, в порядке убывания дробной части частного от деления числа голосов за данную партию на первое избирательное частное. Если же для двух партий эти дробные части равны, то преимущество отдается той партии, которая получила большее число голосов.*/

struct Party {
    string name;
    int votes;
    int index;
    int whole;
    double fraction;

};

bool cmp(const Party &a, const Party &b){
    return (a.fraction == b.fraction) ?
           (a.votes > b.votes) :
           (a.fraction  > b.fraction );
}

void res(vector<Party>  &parties, int k) {
    sort(parties.begin(), parties.end(), cmp);
    auto it = parties.begin();

    while (k > 0) {
        it->whole++;
        ++it;
        --k;
    }

    sort(parties.begin(), parties.end(), [](const Party &a, const Party &b)
                                                            {return a.index < b.index;});
}

int main() {
    vector<Party> parties;
    string line, party;
    int votes, votes_sum = 0, i = 0;

    while(getline(cin, line)){
        if(line == "")
            break;
        istringstream iss(line);
        vector<string> line_split;
        string word;

        while(getline(iss, word, ' ')){
            line_split.push_back(word);
        }

        string name;
        int size =  line_split.size();

        for(int i = 0; i < size - 1; ++i){
            name.append(line_split[i]);
            if(i < size - 2)
                name.append(" ");
        }

        int votes = stoi(line_split[size - 1]);
        parties.push_back({name, votes, i, 0, 0});
        ++i;
        votes_sum += votes;
    }

    double first_voting_div = votes_sum / 450.;
    int whole_sum = 0;

    for (auto it = parties.begin(); it != parties.end(); ++it) {
        it->whole = it->votes / first_voting_div;
        it->fraction = (it->votes / first_voting_div -
                         it->whole) ;
        whole_sum += it->whole;
    }

    res(parties, 450 - whole_sum);

    for(auto elem : parties)
        std::cout << elem.name << " " <<
                  elem.whole << "\n";

    return 0;
}

