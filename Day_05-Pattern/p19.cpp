/*
A 
A B A
A B C B A
A B C D C B A
A B C D E D C B A
*/

#include<iostream>
using namespace std;
int main()
{
    char ch=65;
    int i,j,k;
    for(i=1; i<=5; i++)
    {   
        for(j=1; j<=i; j++)
            cout<<ch++<<" ";
            ch--;

        for(k=1;k<i;k++)
        cout<<--ch<<" ";

       cout<<endl;  
    }
    return 0;
}