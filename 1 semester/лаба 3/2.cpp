#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() 
{
    setlocale(LC_CTYPE, "ukr");

    string myMonth;
    cin >> myMonth;

    if(myMonth == "Січень") {
        cout << "Січень, перший квартал";
    } else if(myMonth == "Лютий") {
        cout << "Лютий, перший квартал";
    } else if(myMonth == "Березень") {
        cout << "Березень, перший квартал";
    } else if(myMonth == "Квітень") {
        cout << "Квітень, другий квартал";
    } else if(myMonth == "Травень") {
        cout << "Травень, другий квартал";
    } else if(myMonth == "Червень") {
        cout << "Червень, другий квартал";
    } else if(myMonth == "Липень") {
        cout << "Липень, третій квартал";
    } else if(myMonth == "Серпень") {
        cout << "Серпень, третій квартал";
    } else if(myMonth == "Вересень") {
        cout << "Вересень, третій квартал";
    } else if(myMonth == "Жовтень") {
        cout << "Жовтень, четвертий квартал";
    } else if(myMonth == "Листопад") {
        cout << "Листопад, четвертий квартал";
    } else if(myMonth == "Грудень") {
        cout << "Грудень, четвертий квартал";
    } else {
        cout << "Вашого місяця не знайдено";
    }
    
    return 0;
}
