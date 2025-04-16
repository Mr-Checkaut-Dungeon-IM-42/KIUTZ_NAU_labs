#include <iostream>
#include <algorithm>

int main() 
{
    int length = 5;
    int array[5] = {64, 25, 12, 22, 11};

    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j++) {
            if(array[j] > array[j+1]) std::swap(array[j], array[j+1]);
        }
    }

    for(int i=0; i<length; i++) std::cout << array[i] << " ";
    return 0;
}