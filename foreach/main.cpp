#include <iostream>
#include <string.h>

using namespace std;

int main()
{
  string a = "000110 110000 001011 101111 111111 000111 000001 110010";
  cout << a.length() << endl;

  string b = "011110 100001 010101 010101 011110 100001 010101 010101";
  cout << b.length() << endl;

  for(int i = 0; i < b.length() ; i++){
    if(a[i] == ' '){
        cout << " ";
        continue;
    }
    cout << (a[i] - '0' + b[i] - '0')%2;
  }
}
