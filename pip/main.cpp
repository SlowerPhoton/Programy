#include <iostream>
#include <ctime>


using namespace std;

int main()
{ int t; cin>>t; int a;
int puvodni = time(NULL);
    while(puvodni!=0)
    {
        a = time(NULL);
        if(puvodni+t<a){unsigned char i = 7;
    cout << i << endl;
    puvodni=0;}

    }


    return 0;
}
