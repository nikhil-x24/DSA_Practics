/*

1         
1 2       
1   3     
1     4   
1 2 3 4 5 

*/
#include<iostream>
using namespace std;
int main(){
      int n=5;
      int i,j;
      for(i=1;i<=n;i++)
      {
          for(j=1;j<=i;j++)
          {
              if( j==1 || i==n || j==i)
              cout<<j<<" ";

              else
              cout<<"  ";
          }
          cout<<endl;
      }
    return 0;
}