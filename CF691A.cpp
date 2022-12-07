#include <bits/stdc++.h>
using namespace std;

char r[1002]={};
char b[1002]={};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int x=0;
        int y=0;
        int d=0;
        int z=0;
        for(int i=1;i<=n;i++)cin>>r[i];
        for(int i=1;i<=n;i++){
            cin>>b[i];
            if(r[i]>b[i])x++;
            else if(r[i]<b[i])y++;
            else d++;
        }
        if(x>y)cout<<"RED"<<endl;
        else if(x<y)cout<<"BLUE"<<endl;
        else cout<<"EQUAL"<<endl;
    }
    return 0;
}