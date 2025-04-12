#include <iostream>
using namespace std;

int main () {
    cout << "Таблиця квадратів:" <<"\n";
    cout << "------------------" <<"\n";
    cout<<"| Число | Квадрат|"<<"\n";

    for(int i = 1; i <= 5; i++) {
        cout << "| " << i << "\t | " << i * i << "\t |" << "\n";
    }

    cout<<  "------------------" <<"\n";
    return 0;
}