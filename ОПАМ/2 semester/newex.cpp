#include <iostream>

void findAndZeroMax(int arr[], int size) {
    if (size <= 0) {
        std::cout << "Array is empty or invalid size." << std::endl;
        return;
    }
    
    int maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    
    std::cout << "Maximum element in the array is: " << arr[maxIndex] << std::endl;
    arr[maxIndex] = 0;
    std::cout << "The maximum element has been zeroed." << std::endl;
}

int main() {
    const int SIZE = 5;
    int array[SIZE] = {3, 8, 2, 10, 5};
    
    findAndZeroMax(array, SIZE);
    
    std::cout << "Array after modification:" << std::endl;
    for (int i = 0; i < SIZE; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}