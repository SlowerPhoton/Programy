#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inp;
    inp.open("3D.txt");

    ofstream out;
    out.open("3Dout.txt");

    string slovo;
    out << "<b>";
    while (inp >> slovo){
        if (slovo[0] == '('){
            out << "</b>";
        }
        out << slovo << " ";
        if (slovo[slovo.length()-1] == ')'){
            out << "<b>";
        }
    }
    out << "</b>";

    inp.close();
    out.close();

    return 0;
}
