#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
queue<int>q[4];
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        for(int i=1;i<=3;i++){
            while(q[i].size())q[i].pop();
        }
        string str;
        cin>>str;
        int n=str.length();
        int x,y,z;
        for(char ch:str){
            if(ch=='r'){
                x++;
            }else if(ch=='e'){
                y++;
            }else if(ch=='d'){
                z++;
            }
        }
        int sta=0;
        int num1=x,num2=y,num3=z;
        bool flag=1;
        if(n%3)flag=0;
        n/=3;
        int dis=max(0,y-x);
        
        // for(int i=0;i<str.length();i++){
        //     char ch=str[i];
        //     if(ch=='r'){
        //         q[1].push(i);
        //     }else if(ch=='e'){
        //         if(q[1].size()){
        //             q[1].pop();
        //             q[2].push(i);
        //         }else if(q[3].size()){
        //             q[2].push(i);
        //             q[3].pop();
        //         }else{
        //             flag=0;
        //             break;
        //         }
        //     }else if(ch=='d'){
        //         if(q[2].size()){
        //             q[2].pop();
        //         }else if(q[1].size()&&q[3].size()&&q[3].front()>q[1].front()){
        //             q[1].pop();
        //             q[3].pop();
        //         }else{
        //             flag=0;
        //             break;
        //         }
        //     }else{
        //         q[3].push(i);
        //     }
        // }
        if(flag)cout<<"Yes\n";
        else cout<<"No\n";
    }
    cout.flush();
    system("pause");
    return 0;
}