#include <iostream>

using namespace std;

int main()
{
    int number;
    cin>>number;

    int dva=0, pet=0;
    int a;

    for(int i=number; i>0; i--){
        a=i;
    while(a%2==0 or a%5==0){
    if(a%2==0){dva++; a=a/2;}
    if(a%5==0){pet++; a=a/5;}}}



    if(pet>dva) {cout<<dva;}
    else cout<<pet;
    return 0;
}
