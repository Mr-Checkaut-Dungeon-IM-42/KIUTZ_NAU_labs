#include <iostream>
#include <set>

using namespace std;

int main() {
    const int LENGTH = 50;
    char inp[LENGTH];
    
    cin >> inp;
    multiset<char> letters;
    multiset<int> numbers;
    
    for(int i = 0; i < LENGTH; ++i) {
        if (isalpha(inp[i])) letters.insert(inp[i]);
        else if (isdigit(inp[i])) numbers.insert( inp[i] - '0' );
    }

    cout << "letters: " << endl;
    for(auto& l : letters) cout << l << " ";
    
    cout << "\n" << "numbers: " << endl;
    for(auto& n : numbers) cout << n << " ";
    
    return 0;
}
