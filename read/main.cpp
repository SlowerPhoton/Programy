#include <fstream>
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

// I could have done this better, but this code works.

int main()
{
 ifstream myfile("test.txt"); // opens a file that is between quotation marks.
 string line;
 string result;
 char c;
 bool running = true;

 // If space is pressed, loop again.
  while( running == true)
  {
      // Loop 8 lines from the file.
      for ( int i = 0; i < 8; i++)
     {
        getline (myfile, line );
         cout << line << '\n';


     }

  cout << "Press space to view 8 more lines." << endl;
  // Windows function to get spaces.
  _getch();
  // If that file has no more content, break the loop
  if (!myfile)  break;
   // If you get a space, run the loop
  if (_getch()) running = true;
  // Else, just stop the program.
  else running = false;


  }


 cout << endl;
 cout << "This is the end of the file.";

  myfile.close();
  return 0;

}
