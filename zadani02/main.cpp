#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string targetDirectory;
    cin >> targetDirectory;
    targetDirectory += '\\';

    ifstream soubory;
    soubory.open("soubory.txt");

    string fileName;
    while (soubory >> fileName)
    {
        ifstream infile;
        infile.open(fileName.c_str(), ios::in | ios::binary);
        infile.seekg(0, ios::end);
        int fileSize = infile.tellg();
        infile.seekg(0, ios::beg);

        char inp[fileSize];
        infile.read(inp, fileSize);

        infile.close();
        ofstream outfile;
        outfile.open((targetDirectory+fileName).c_str());
        outfile << inp;
        outfile.close();

    }

    soubory.close();

    return 0;
}
