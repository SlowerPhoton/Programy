#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x=1;
while(x!=0){

cin>>x;
int polozb;
int odmocnina;

polozb = 2;
int a=0, b=1;

while(b>a){a=(polozb*polozb)-x; if(a<0)a*=-1; b=((polozb-1)*(polozb-1))-x; if(b<0)b*=-1; polozb++;}
odmocnina=polozb-2;

cout << odmocnina << endl;
bool prime=true;
for(int i =odmocnina;i>1;i=i-1)
{
    if(x%i==0){prime=false;i=1;}

}
if(prime){cout<<"prime"<<endl;}
cout<<endl;
}

    return 0;
}
