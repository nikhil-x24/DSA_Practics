#include <iostream>
using namespace std;
int main ()
{
  int numbers[5];
  int * p;
  p = numbers; 
  //cout <<p <<endl;
  *p = 10;
  cout << *p <<endl;
  p = &numbers[2]; 
  *p = 20;
  p--; 
  *p = 30;
  p = numbers + 3;
  *p = 40;
  p = numbers;
  *(p+4) = 50;

  //print
  for (int n=0; n<5; n++) {
     cout << numbers[n] << ",";
  }
  return 0;
}
