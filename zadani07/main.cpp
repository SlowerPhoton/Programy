#include <iostream>
#include <fstream>


using namespace std;

int main()
{
    ifstream vstup;
    vstup.open("VrahovaVypoved.txt");

    ofstream vystup;
    vystup.open("VrahovaVypovedPravda.txt");

    /*string inp;
    while (vstup >> inp){
        int pos = inp.find("ne");
        if (pos != -1);

    }*/
    char inp;
    while (vstup.get(inp))
    {
        if (inp == 'n')
        {
            vstup.get(inp);
            if (inp == 'e')
                continue;
            else
                vystup << 'n';
        }

        vystup << inp;
    }

    vystup.close();
    vstup.close();

    return 0;
}
