#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}

int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.in","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int n=str.length();
        str=' '+str;
        int cnt1=0,cnt2=0;
        bool flag=1;
        for(char ch:str){
            if(ch=='(')cnt1++;
            else if(ch==')')cnt2++;
        }
        int num=n-cnt1-cnt2;
        int cnt=(num-abs(cnt1-cnt2))/2;
        if(cnt1<cnt2){
            cnt+=cnt2-cnt1;
        }
        if(num<abs(cnt1-cnt2)){
            cout<<"NO\n";
            continue;
        }else if(num==abs(cnt1-cnt2)){
            cout<<"YES\n";
            continue;
        }
        int x=0;
        int ncnt=0;
        for(int i=1;i<=n;i++){
            if(str[i]=='(')x++;
            else if(str[i]==')')x--;
            else{
                ncnt++;
            }
            if(x<0){
                ncnt--;
                x++;
                if(ncnt<0){
                    flag=0;
                    break;
                }
            }
            if(x==0&&ncnt==1){
                x++;
                ncnt--;
            }
        }
        if(abs(x)!=ncnt){
            flag=0;
        }
        // bool is=0;
        // int ncnt=0;
        // for(int i=1;i<=n;i++){
        //     if(str[i]=='(')x++;
        //     else if(str[i]==')')x--;
        //     else{
        //         if(is){
        //             flag=0;
        //         }
        //         if(x>0&&ncnt<cnt)is=1;
        //         if(ncnt<cnt){
        //             ncnt++;
        //             x++;
        //         }else{
        //             x--;
        //         }
        //     }
        //     if(x<=1)is=0;
        //     if(x<0)flag=0;
        // }
        if(flag)cout<<"YES\n";
        else cout<<"NO\n";
    }
    cout.flush();
    // system("pause");
    return 0;
}