#include <iostream>
#include <string>
using namespace std;
string decryption_string (string out) {
    string decrypto;
    for(int i=0; i<out.length(); ++i) {
        int ascii_code = out[i];
        if (ascii_code < 97 || ascii_code > 122) {
            ascii_code = ' ';
        } else if(ascii_code - 3 < 97) {
            ascii_code = 123 - (97 - (ascii_code - 3));
        } else {
            ascii_code -= 3;
        }
        decrypto += char(ascii_code);
    }
    return decrypto;
}
int main() {
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
        } else {
            ascii_code += 3;
        }

        out += char(ascii_code);
    }
    cout << "\n" << "Your crypto: " << out << "\n";
    
    string after_decrypto = decryption_string(out);
    cout<<"Your mom is so hot. Here the proof: "<<after_decrypto;
    
    return 0;
}
