#include <bits/stdc++.h>
using namespace std;
long long num[5]={};
string s;
int  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {   
        memset(num,0,sizeof(num));
        cin>>s;
        int len=s.length();
        s=' '+s;
        long long x=0;
        long long y=0;
        long long a=0,b=0,c=0,d=0;
        for(int i=1;i<=len;i++){
            if(s[i]=='L'){num[1]++;x--;a=min(a,x);}
            else if(s[i]=='R'){num[2]++;x++;b=max(b,x);}
            else if(s[i]=='D'){num[3]++;y--;c=min(c,y);}
            else {num[4]++;y++;d=max(d,y);}
        }
        if(num[1]==0&&num[2]>0||num[2]==0&&num[1]>0||num[3]==0&&num[4]>0||num[4]==0&&num[3]>0){
            cout<<"0 0"<<endl;
            continue;
        }
        long long minn=min(num[1],num[2]);
        num[1]-=minn;
        num[2]-=minn;
        minn=min(num[3],num[4]);
        num[3]-=minn;
        num[4]-=minn;
        x=0,y=0;
        for(int i=1;i<=len;i++){
            if(s[i]=='L'){
                x--;
                if(x==a&&num[1]>0){
                    num[1]--;
                    a++;
                    cout<<x<<' '<<y<<endl;
                    x++;
                }
            }
            else if(s[i]=='R'){
                x++;
                if(x==b&&num[2]>0){
                    num[2]--;
                    b--;
                    cout<<x<<' '<<y<<endl;
                    x--;
                }
            }
            else if(s[i]=='D'){
                y--;
                if(y==c&&num[3]>0){
                    num[3]--;
                    c++;
                    cout<<x<<' '<<y<<endl;
                    y++;
                }
            }
            else{
                y++;
                if(y==d&&num[4]>0){
                    num[4]--;
                    d--;
                    cout<<x<<' '<<y<<endl;
                    y--;
                }
            }
        }
    }
    system("pause");
    return 0;
}