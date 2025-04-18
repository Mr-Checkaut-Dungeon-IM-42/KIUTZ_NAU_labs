#include<iostream>
#include<string>

using namespace std;
int main() {

  string text;
  int key;
  // Введення тексту
  cout << "Enter text(only alphabet):";
  getline(cin, text); 
  cout << "Ener key for encrypting(only integer)";
  cin >> key;
  
  string result = "";
  //алгоритм обрахування шифру
  for (char& c : text) {
    if (isalpha(c)) {
      char base = isupper(c) ? 'A' : 'a';
      result += static_cast<char>((c - base + key) % 26 + base);
    }
    else {
      result += c;
    }
  }
  //вивід шифру
  cout << "Encrypted text: " << result << endl;
  return 0;
}