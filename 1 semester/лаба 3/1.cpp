#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int x;
    cin >> x;

    if(x >= -2 && x <= 2) {
        cout << pow(x, 2);
    } else if(x < -2 || x > 2){
        cout << 4;
    }

    return 0;
}
