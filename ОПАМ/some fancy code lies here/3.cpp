#include <iostream>
#include <cstdlib>  
#include <ctime>  
#include <vector>
using namespace std;
int main() 
{
    srand(time(0)); 
    int number = 100 + rand() % 899;

    // Створюємо масив для зберігання цифр числа
    vector<int> digits;

    // Розбиваємо число на цифри і зберігаємо їх у масив
    while (number > 0) {
        int digit = number % 10; // Отримуємо останню цифру
        cout<<digit<<endl;
        digits.push_back(digit); // Додаємо цифру до масиву
        number /= 10; // Видаляємо останню цифру з числа
    }
    
    int guessed, on_place = 0;
    while(true) {
        int n;
        cout<<"Ваш варіант";
        cin>>n;
        
        // робимо масив
        vector<int> customer_dig;
        while (n > 0) { 
            int cs_digit = n % 10; // Отримуємо останню цифру 456 -> 6
            customer_dig.push_back(cs_digit); // Додаємо цифру до масиву
            n /= 10; // Видаляємо останню цифру з числа
        }
        
        //перевірити скільки вгаданих
        for(int i = 0; i < digits.size(); i++) {            
        
            for(int j = 0; j < customer_dig.size(); j++) {
                if(digits[i] == customer_dig[j]) { 
                    
                    guessed++;
                    if(i==j) on_place++;
                    break;
                }
            }
        }
        
        cout<< endl <<"Вгадано: " << guessed << ". На своїх місцях: " << on_place << endl;
        if (on_place == digits.size()) {
            cout << "Ви вгадали число!" << endl;
            break;
        }
    }
        

    return 0;
}