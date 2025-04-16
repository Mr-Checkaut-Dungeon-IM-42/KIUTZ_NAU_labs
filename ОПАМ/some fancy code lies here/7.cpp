#include <iostream>
#include <string>
int main()
{
    std::string str;
    getline(std::cin, str);
    
    
    for(int i = 0; i < str.length(); i++) {
        int ascii_code = int(str[i]); // перевів умовний ! в 33, це код по таблиці ASCII 
        // останній елем таблиці це delete під кодом 127. тобто 127 + 3 дасть 130, і результат не той. 
        // отже ми мусимо почати з початку, з 32 елементу (пробілу). 
        if(ascii_code + 3 > 127) ascii_code = 127 - (ascii_code + 3) + 32; 
        char result = char(ascii_code + 3); // перевів назад у символ, але зсунув на три одиниці вперед
        std::cout<<result<<std::endl;
    }

    return 0;
}
