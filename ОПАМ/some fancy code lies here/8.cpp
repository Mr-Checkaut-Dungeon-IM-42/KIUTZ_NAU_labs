#include <iostream>
#include <string>
using namespace std;
int main() {
    // 27-25 = 2
    // Ввести довільний текст. У даному тексті знищити всі символи «,» і
    // підрахувати довжину утвореного тексту.
    cout<<"Введіть якийсь текст:"<<endl;
    string sometext;
    getline(cin, sometext);
    
    for(int i = 0; i < sometext.length(); i++) {
        if(sometext[i] == ',') sometext.erase(i, 1);
    }
    
    cout<<sometext<<endl;
    cout<<"Довжина утвореного тексту: "<<sometext.length()<<" символи."<<endl;
    
    return 0;
}
