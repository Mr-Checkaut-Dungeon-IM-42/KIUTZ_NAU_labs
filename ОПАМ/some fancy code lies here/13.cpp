#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Структура, що представляє запис про об'єкт
struct ObjectRecord {
    string name;
    string description;
};

int main() {
    // Відкриття файлу для запису
    ofstream outputFile("objects.txt");

    if (!outputFile) {
        cerr << "Помилка відкриття файлу для запису." << endl;
        return 1;
    }

    // Масив записів про об'єкти
    ObjectRecord records[] = {
        {"Машина", "Транспортний засіб на колесах."},
        {"Літак", "Повітряний транспортний засіб."},
        {"Птах", "Тварина з перомистим покривом і здатністю літати."},
        {"Квітка", "Рослина з привабливим квітком."},
        {"Країна", "Суверенна територіальна громада."}
    };

    // Запис об'єктів у файл
    for (const auto& record : records) {
        outputFile << record.name << ": " << record.description << endl;
    }

    // Закриття файлу
    outputFile.close();

    // Відкриття файлу для читання та виведення вмісту на екран
    ifstream inputFile("objects.txt");

    if (!inputFile) {
        cerr << "Помилка відкриття файлу для читання." << endl;
        return 1;
    }

    cout << "Вміст файлу objects.txt:" << endl;
    cout << inputFile.rdbuf(); // Виведення вмісту файла
    inputFile.close();

    return 0;
}