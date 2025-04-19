#include <iostream>
using namespace std;
int main() {
    int birthDay, birthMonth, currentDay, currentMonth, currentYear;

    // Зчитуємо дані користувача
    cout << "Введіть ваш день народження (день місяць): ";
    cin >> birthDay >> birthMonth;

    cout << "Введіть поточний день (день місяць рік): ";
    cin >> currentDay >> currentMonth >> currentYear;

    // Обчислюємо кількість днів до дня народження
    int daysLeft = (birthMonth - currentMonth) * 30 + (birthDay - currentDay);

    if (daysLeft < 0) {
        daysLeft += 365; // Додаємо рік, якщо дата народження наступного року
    }

    // Виводимо результат
    cout << "До вашого наступного дня народження залишилось " << daysLeft << " днів." << endl;

    return 0;
}