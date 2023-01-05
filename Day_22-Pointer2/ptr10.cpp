#include <iostream>
using namespace std;
void Q(int z)
{
  z += z;   //7+7
  cout<<z << " ";
}

void P(int *y) 
{
  int x = *y + 2;
  //cout << x << endl;
  Q(x);
  *y = x - 1; 
  cout<<x << " ";
}

int main()
{
  int x = 5;
  //function calling P
  P(&x);
  cout <<endl;
  cout<<x;
  return 0;
}