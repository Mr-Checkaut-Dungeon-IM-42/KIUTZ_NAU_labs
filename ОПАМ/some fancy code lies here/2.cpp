#include <iostream>

using namespace std;

int main()
{

    int n, sum = 0;
    
    cout<<"Введіть початкове число";
    cin>>n;
    while(n < 50) {
        if(n <= 0) {
            cout<<"Введіть додатнє число";
            break;
        }
        
        if(n % 2 == 0) {
            // парне
            sum += n;
        }
    
        n+=1;
        
    }


cout<<sum;
    return 0;
}