#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10; 
using namespace std;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //system("pause");
    int t;
    string str;
    cin>>t;
    while(t--)
    {
        int dir[5]={};
        int a,b;
        cin>>a>>b;
        cin>>str;
        int flag=0;
        int flag2=0;
        for(int i=0;i<str.length();i++){
              if(str[i]=='R')dir[1]++;
              else if(str[i]=='L')dir[2]--;
              else if(str[i]=='U')dir[3]++;
              else dir[4]--;
        }
        if(dir[1]>=a&&dir[2]<=a)flag=1;
        if(dir[3]>=b&&dir[4]<=b)flag2=1;
        //for(int i=1;i<=4;i++)cout<<dir[i]<<endl;
        if(flag&&flag2)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }   
    //system("pause");
    return 0;
}