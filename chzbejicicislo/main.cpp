#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

int main()

{   ifstream zdroj("zdroj.txt");
    string prijem;
    int a=1;
    while(!zdroj.eof()){
    zdroj>>prijem;
    prijem.erase(prijem.length()-1,1);

    if (a!=atoi(prijem.c_str())){cout<<prijem<<" "<<a<<endl;}
    a++;
    cout<<a<<endl;
    }

    return 0;
}
