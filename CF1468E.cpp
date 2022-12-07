#include <bits/stdc++.h>
using namespace std;
int a[5]={};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=1;i<=4;i++)cin>>a[i];
        sort(a+1,a+4+1);
        cout<<a[1]*a[3]<<endl;
    }
    //system("pause");
    return 0;
}