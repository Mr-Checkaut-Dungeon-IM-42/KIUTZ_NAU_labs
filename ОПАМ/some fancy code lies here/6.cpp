#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    srand(time(NULL));
    int k = 6; 
    int c = 5;
    int array[k][c];
    int sum_arr[k];
    int numbers_output[k];
    
    for(int i = 0; i < c; i++) {
        for(int j = 0; j < k; j++) {
            array[i][j] = rand() % (10*2+50);
            sum_arr[j] += array[i][j];
            
            cout<<array[i][j]<<"\t";
        }
        cout<<"\n";
    }
    
    cout<<"\n"<<"Сума з кожного населеного пункту: "<<"\n";
    int j = 0;
    for(int i = 0; i < k; i++) {
        cout<<sum_arr[i]<<"\t";
        if(sum_arr[i] > 150) {
            numbers_output[j] = i;
            j++;
        }
    }
    cout<<"\n"<<"Номери нас.пунктів, де сума голосів перевищила 150: "<<"\n";
    for(int i = 0; i < j; i++) cout<<numbers_output[i]+1<<"\t";
    return 0;
}
