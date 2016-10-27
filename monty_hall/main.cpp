#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    int b=0;
    srand(time(NULL));
for(int i=0;i<100;i++){
bool door1 = 0;
bool door2 = 0;
bool door3 = 0;

int c;
int a = rand()%3+1;
if (a==1) door1=1;
if (a==2) door2=1;
if (a==3) door3=1;

if(door2==0){c=door3;}
if(door3==0)c=door2;

b=b+c;


}
float vys=b;
    cout << vys << endl;
    return 0;
}
