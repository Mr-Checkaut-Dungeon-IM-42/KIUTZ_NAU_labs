
#include <iostream>

using namespace std;

int main()
{
    cout<<"Введіть проміжок"<<endl;
    
    int n, k;
    
    cin>>n>>k;

    int sum = 0;
    for(; n < k; n++){ 
        
        if(n % 2 != 0) {

            sum+=n;
        }
        
    }

    cout<<"Сума непарних елементів у проміжку: "<<sum;
    return 0;
}
