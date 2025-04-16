#include <iostream>

using namespace std;

int main()
{
    float cabelt, meter, foot, step;
    unsigned int quantity; // не може бути дробовою
    cout<<"Введіть кількість кабельтів США, розмір кроку та кількість рядків таблиці:";
    cin>>cabelt>>step>>quantity;
    
    cout<<"-------------------------"<<endl;
    cout<<"Cabelt\t|Meters |Foot\t|"<<endl;
    
    for(int n=1; n<=quantity; n++) {
        
        meter = cabelt * 219.5;
        foot = cabelt * 720;
        
        cout<< cabelt << "\t|" << meter << "\t|" << foot << "\t|" <<endl;
        
        cabelt+=step;
    }
    cout<<"------------------------";

    return 0;
}