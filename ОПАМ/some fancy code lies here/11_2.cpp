#include <iostream>
using namespace std;

int sumOddNumbInRange(int a, int b) {
    int sum = 0;
    for(; a < b; a++) {
        if(a % 2 != 0) {
            sum += a;
        }
    }
    
    return sum;
}

int main()
{
    int start = 0, end = 0, sum = 0;
    cout<<"Hi!! type some value here pleasee:"<<endl;
    cin>>start>>end;
    
    if(start == 0 || end == 0)
    {
        cout<<"i said PLEASEEE TYPE VALUE";
        cin>>start>>end;        
    }
    
    sum = sumOddNumbInRange(start, end);
    
    printf("The sum of all odd numbers in range (%d; %d) equals to %d.", start, end, sum);
    
    return 0;
}
