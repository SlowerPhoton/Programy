#include <iostream>

using namespace std;

int main() {
	int x = 0;
	int y = 1;
	int z = -1;

	int xx = 1 & (x ^= 1);
	int yy = 1 & (x ^= 1);
	int zz = 1 & (x ^= 1);

	cout<<"%d %d %d %d %d %d\n"<< x<< xx<< y<< yy<< z<< zz<<endl;

	return 0;
}
