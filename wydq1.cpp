#include <bits/stdc++.h>
using namespace std;

int main()
{
    char ch;
    int h;
    while(cin>>ch>>h)
    {
        h/=2;
        for(int i=1;i<=h;i++){
            for(int j=1;j<=h-i+1;j++)cout<<' ';
            if(i==1)cout<<ch++<<endl;
            else{
                int num=2*(i-1)-1;//the NumSpace in the middle 2k-1 k is stagei-1
                cout<<ch;
                for(int i=1;i<=num;i++)cout<<' ';
                cout<<ch++<<endl;
            }
        }
        cout<<ch;
        for(int j=1;j<=2*h-1;j++)cout<<' ';
        cout<<ch--<<endl;
        for(int i=h;i>=1;i--){//do it again with the reversed way
            for(int j=1;j<=h-i+1;j++)cout<<' ';
            if(i==1)cout<<ch--<<endl;
            else{
                int num=2*(i-1)-1;//the NumSpace in the middle 2k-1 k is stagei-1
                cout<<ch;
                for(int i=1;i<=num;i++)cout<<' ';
                cout<<ch--<<endl;
            }
        }
    }
    system("pause");
    return 0;
}