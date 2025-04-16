#include <iostream>
#include <math.h>
using namespace std;

int main(){
    double t, a, x, b, y;
    cout << "Введіть b:";
    cin >> b;
    cout << "Введіть x:";
    cin >> x;
    cout << "Введіть a:";
    cin >> a;

    if( b * x < 1) {
        y = a*x + sin(b*x);
    } else if(b*x == 1) {
        y = 2;
    } else if(b*x > 1) {
        y = cos(x) - log10(b*x);
    }

    cout << "У дорівнює " << y;

    return 0;
}
