#include<string.h>
#include<iostream>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class step{
public:
    int a[9][9];
    int flag;
    void judge();
    void showanswer();
    step(){
    int b[9][9];
    for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
    {
        cin>>b[i][j];
    }
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
    {
        a[i][j]=b[i][j];
    }
    }
};
void step::judge(){
    int t[10];
flag=1;
for(int i=0;i<9;i++)
    for(int j=0;j<8;j++)
        for(int m=j+1;m<9;m++)
{
    if(a[i][j]==a[i][m])
        {flag=0;cout<<"qqqqqq"<<endl;}
}
for(int i=0;i<9;i++)
    for(int j=0;j<8;j++)
        for(int m=j+1;m<9;m++)
        {
            if(a[j][i]==a[m][i])
                {flag=0;cout<<"WWWWW"<<endl;}
        }
        t[10]={0};
        for(int i=0;i<=9;i++)cout<<t[i]<<endl;
for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
{
    t[a[i][j]]++;
    if(t[a[i][j]]==2)
        {flag=0;cout<<a[i][j]<<'q'<<i<<'q'<<j<<endl;}
}
t[10]={0};
for(int i=3;i<6;i++)
    for(int j=3;j<6;j++)
{
    t[a[i][j]]++;
    if(t[a[i][j]]==2)
        flag=0;
}
t[10]={0};
for(int i=6;i<9;i++)
    for(int j=6;j<9;j++)
{
    t[a[i][j]]++;
    if(t[a[i][j]]==2)
        flag=0;
}
}


void step::showanswer(){
if(flag==1)
    cout<<"Yeah!\n"<<endl;
else if(flag==0)
    cout<<"Oh,No!\n"<<endl;
}
int main()
{
    int n;
    cin>>n;

        for(int k=0;k<n;k++)
        {
        step v;
        v.judge();
        v.showanswer();
        }
        system("pause");
    return 0;
}