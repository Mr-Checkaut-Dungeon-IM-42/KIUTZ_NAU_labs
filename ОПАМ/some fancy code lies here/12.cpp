#include<iostream>
using namespace std;

int sum(int start, int end, int s) {
    if (start == end) {
        return s;
    }
    if (start % 2 != 0 && start < end) {
        s += start;
    }
    return sum(start + 1, end, s);
}

int main() {
    int a = 0, b = 0, s = 0;
    cout << "Enter start and end values: ";
    cin >> a >> b;
    
    // Ensure that a is less than b before passing them to sum function
         cout << sum(a, b, s);
 
    return 0;
}