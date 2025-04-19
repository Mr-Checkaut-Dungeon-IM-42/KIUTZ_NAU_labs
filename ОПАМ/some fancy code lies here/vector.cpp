#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

// Функція для виділення цифр з числа і запису їх у множину
set<int> getDigits(int number) {
    set<int> digits;
    while (number > 0) {
        digits.insert(number % 10);
        number /= 10;
    }
    return digits;
}

int main() {
    int A, B, C;
    cout << "Введіть три числа (A, B, C): ";
    cin >> A >> B >> C;
    
    set<int> digitsA = getDigits(A);
    set<int> digitsB = getDigits(B);
    set<int> digitsC = getDigits(C);

    // Знаходження спільних цифр між A і B
    set<int> commonAB;
    set_intersection(digitsA.begin(), digitsA.end(), digitsB.begin(), digitsB.end(),
                     inserter(commonAB, commonAB.begin()));

    // Знаходження спільних цифр між A і C
    set<int> commonAC;
    set_intersection(digitsA.begin(), digitsA.end(), digitsC.begin(), digitsC.end(),
                     inserter(commonAC, commonAC.begin()));

    // Знаходження спільних цифр між B і C
    set<int> commonBC;
    set_intersection(digitsB.begin(), digitsB.end(), digitsC.begin(), digitsC.end(),
                     inserter(commonBC, commonBC.begin()));

    // Знаходження спільних цифр між (A і B) та C
    set<int> commonABC;
    set_intersection(commonAB.begin(), commonAB.end(), digitsC.begin(), digitsC.end(),
                     inserter(commonABC, commonABC.begin()));

    // Виведення результатів
    bool hasCommonInTwo = !commonAB.empty()  !commonAC.empty()  !commonBC.empty();
    bool hasCommonInAllThree = !commonABC.empty();

    if (hasCommonInTwo) {
        cout << "Цифри, які є спільними хоча б для двох множин: ";
        set<int> commonTwo;
        commonTwo.insert(commonAB.begin(), commonAB.end());
        commonTwo.insert(commonAC.begin(), commonAC.end());
        commonTwo.insert(commonBC.begin(), commonBC.end());

        for (int digit : commonTwo) {
            cout << digit << " ";
        }
        cout << endl;
    } else {
        cout << "Немає спільних цифр хоча б для двох множин." << endl;
    }

    if (hasCommonInAllThree) {
        cout << "Цифри, які є спільними для всіх трьох множин: ";
        for (int digit : commonABC) {
            cout << digit << " ";
        }
        cout << endl;
    } else {
        cout << "Немає спільних цифр для всіх трьох множин." << endl;
    }

    return 0;
}