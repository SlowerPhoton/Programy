#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <ctype.h>

#define SIZE 26
using namespace std;

int main()
{
    char fuck[256];
    cin >> fuck;
    cout << strlen(fuck) << endl;
    if (fuck[strlen(fuck)] == NULL) cout << 1;
    return 0;
}
