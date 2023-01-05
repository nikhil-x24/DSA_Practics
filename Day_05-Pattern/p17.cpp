/*

1 2 3 4 5 
2     5
3   5
4 5
5

*/

#include<iostream>
using namespace std;

int main()
{
        int n=5;
        int i,j;
      for(i=1;i<=n;i++)
      {
          for(j=i;j<=n;j++)
          {
              if(i==1)
              cout<<j<<" ";

              else if(j==i)
              cout<<i<<" ";

              else if(j==n)
              cout<<n<<" ";

              else
              cout<<"  ";
          }
          cout<<endl;
      }
    return 0;
}