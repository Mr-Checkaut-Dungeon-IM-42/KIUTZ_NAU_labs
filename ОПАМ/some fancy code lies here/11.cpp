#include <iostream>
using namespace std;
int main()
{
    cout<<"Hello World";
    int start = 0, end = 0, sum = 0;
    cout<<"Hi!! type some value here pleasee:"<<endl;
    cin>>start>>end;
    
    if(start == 0 || end == 0)
    {
        cout<<"i said PLEASEEE TYPE VALUE";
        cin>>start>>end;        
    }
    
    for(; start < end; start++) {
        if(start % 2 == 0) sum += start;
    }
    
    printf("The sum of all odd numbers in range (%d; %d) equals to %d", start, end, sum);
    
    return 0;
}
