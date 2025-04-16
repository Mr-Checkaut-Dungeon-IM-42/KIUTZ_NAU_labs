#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() 
{
    setlocale(LC_CTYPE, "ukr");

    map<string, int> months = {
        {"Січень", 1},
        {"Лютий", 1},
        {"Березень", 1},
        {"Квітень", 2},
        {"Травень", 2},
        {"Червень", 2},
        {"Липень", 3},
        {"Серпень", 3},
        {"Вересень", 3},
        {"Жовтень", 4},
        {"Листопад", 4},
        {"Грудень", 4}
    };

    string myMonth;
    cin >> myMonth;

    if (months.find(myMonth) != months.end()) {
        int quarter = months[myMonth];
        string quarterName;
        switch (quarter) {
            case 1: quarterName = "перший"; break;
            case 2: quarterName = "другий"; break;
            case 3: quarterName = "третій"; break;
            case 4: quarterName = "четвертий"; break;
        }
        cout << myMonth << ", " << quarterName << " квартал";
    } else {
        cout << "Вашого місяця не знайдено";
    }
    
    return 0;
}
