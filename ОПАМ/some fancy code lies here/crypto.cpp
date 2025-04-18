#include <iostream>
#include <string>
using namespace std;

int main()
{
    string inp, out;
    cout << "Enter a string: " << "\n";
    getline(cin, inp);
    for (int i = 0; i < inp.length(); ++i) inp[i] = tolower(inp[i]);

    for (int i = 0; i < inp.length(); i++)
    {
        int ascii_code = int(inp[i]);
        if (ascii_code < 97 || ascii_code > 122) {
            ascii_code = ' ';
        } // out of alphabet range
        else if (ascii_code + 3 > 122) {
            ascii_code = 97 + (ascii_code + 3 - 123); 
            // if z, ascii_code = 97 + (122 + 3 - 123) = 99 = c
            // if x, ascii_code = 97 + (120 + 3 - 123) = 97 = a 
        } else {
            ascii_code += 3;
        }

        out += char(ascii_code);
    }
    cout << "\n" << "Your crypto: " << out;
    return 0;
}
