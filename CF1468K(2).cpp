#include <bits/stdc++.h>
using namespace std;
string s;
int go(int x,int y)
{
    int len=s.length();
    long long a=0,b=0;
    for(int i=1;i<=len;i++){
        if(s[i]=='L'&& !(a-1==x&&b==y))a--;
        else if(s[i]=='R'&& !(a+1==x&&b==y))a++;
        else if(s[i]=='D'&& !(a==x&&b-1==y))b--;
        else if(s[i]=='U'&&!(a==x&&b+1==y))b++;
    }
    //cout<<'Q'<<a<<' '<<b<<endl;
    if(a==0&&b==0){cout<<x<<' '<<y<<endl;return 1;}
    else return 0;
}
int  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {   
        cin>>s;
        int len=s.length();
        s=' '+s;
        long long x=0;
        long long y=0;
        int flag=0;
        for(int i=1;i<=len;i++){
            if(s[i]=='L'){x--;if(go(x,y)){flag=1;break;}}
            else if(s[i]=='R'){x++;if(go(x,y)){flag=1;break;}}
            else if(s[i]=='D'){y--;if(go(x,y)){flag=1;break;}}
            else {y++;if(go(x,y)){flag=1;break;}}
        }
        if(!flag)cout<<0<<' '<<0<<endl;
    }
    //system("pause");
    return 0;
}