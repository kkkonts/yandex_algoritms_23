#include <bits/stdc++.h>


using namespace std;

int interactor(int r, int i, int c) {
     if (i == 0) {
        if (r != 0)
            return 3;
        else 
            return c;
    }
    
    if (i == 1) 
        return c;
    
    if (i == 4) {
        if (r != 0)
            return 3;
        else 
            return 4;
    }
    
    if (i == 6) 
        return 0;
    
    if (i == 7)
        return 1;
    
    return i;
}

int main() {
    int r, i, c;
    // r – код завершения задачи
    // i — вердикт интерактора
    // c — вердикт чекера.
    cin >> r >> i >> c;
    cout << interactor(r, i, c);
}
