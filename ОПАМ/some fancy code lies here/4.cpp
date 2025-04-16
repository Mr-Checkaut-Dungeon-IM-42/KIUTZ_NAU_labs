#include <iostream>

using namespace std;

int main()
{
    // Вивести добуток номерів двох найменших елементів серед додатних.
    
    int numbers[7] = {20, 2, 3, 4, -10, 5, 1}; 

    int min1 = numbers[0];
    int min2 = numbers[0];
    
    int length = sizeof(numbers) / sizeof(numbers[0]);
    for(int i = 0; i < length; i++) {
        if(numbers[i] < min1) {
            min1 = numbers[i];
        }
        
        if(numbers[i] < min2 && numbers[i] != min1) {
            min2 = numbers[i];
        }
        
        
    }
    
    int mul = 1;
    for(int j = 0; j < length; j++) {
        if(numbers[j] == min1) mul*=j;
        else if(numbers[j] == min2) mul*=j;
    }
    
    cout<<mul;
    
    
    
    return 0;
}