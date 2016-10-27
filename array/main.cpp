#include <iostream>
using namespace std;

int Consecutive(int arr[]) {
  int a;
  int pocet=0;
  while(arr[pocet]<101){pocet++;}
  for(int b=0; b<pocet; b++){
    int i=0;
  for(i=0; i<pocet; i++)
 {if(arr[i]>arr[i+1]){a=arr[i];arr[i]=arr[i+1];arr[i+1]=a;} }
 }
int min=arr[0];
int max=arr[pocet-1];
  int misto=0;
  int vys[50];
  while(min<max){vys[misto]=min; min++; misto++;}
  for(int i=0;i<misto;i++){cout<<vys[i]<<" ";}

  return vys[0];
           }

int main() {

  // keep this function call here
  /* Note: In C++ you first have to initialize an array and set
     it equal to the stdin to test your code with arrays.
     To see how to enter arrays as arguments in C++ scroll down */

  int A[] = {1,8,9,4,3};
  cout << Consecutive(A);
  return 0;

}
