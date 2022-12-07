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
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int cnt1=0;
        int cnt2=0;
        string str;
        cin>>str;
        for(char ch:str){
            if(ch=='A')cnt1++;
            else cnt2++;
        }
        if(a+c+d!=cnt1||b+c+d!=cnt2){
            cout<<"NO\n";
            continue;
        }
        str=str+str[str.length()-1];
        int num=0;
        int cnt=0;
        int star=0;
        int c1=0;
        int d1=0;
        for(int i=1;i<str.length();i++){
            if(str[i]!=str[i-1]){
                cnt++;
            }else{
                num=cnt/2;
                cnt%=2;
                if(cnt&&num){
                    if(c>=2){
                        c-=2;
                        num--;
                    }else if(d>=2){
                        d-=2;
                        num--;
                    }
                    star+=num;
                }else if(cnt){
                    if(str[i]=='B'){
                        c1++;
                    }
                    else{
                        d1++;
                    }
                }else{
                    star+=num;
                }
                cnt=0;
            }
        }
        c-=min(c,c1);
        d-=min(d,d1);
        if(star<c+d){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }
    cout.flush();
    // system("pause");
    return 0;
}