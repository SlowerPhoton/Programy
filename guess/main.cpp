#include <iostream>

using namespace std;

int main()
{
    int top=101,bot=0;
    char a;
    int x;
    int attempt=0;

    while(a!='y')
    {  x=(top-bot)/2+bot;
        attempt++;
       cout<<x<<endl;
       cin>>a;
       if(a=='l'or a=='m')top=x;
       if(a=='h'or a=='v')bot=x;
    }
    cout<<"celkem pokusu: "<<attempt<<endl;
    cout<<"I always win!"<<endl;
    return 0;
}
