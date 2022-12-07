#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
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
    while(t--)
    {
        string str;
        int n;
        cin>>n;
        cin>>str;
        for(int i=1;i<n;i++){
            if(str[i]=='?'&&str[i-1]=='B'){
                str[i]='R';
            }
            else if(str[i]=='?'&&str[i-1]=='R'){
                str[i]='B';
            }
        }
        for(int i=n-2;i>=0;i--){
            if(str[i]=='?'&&str[i+1]=='R'){
                str[i]='B';
            }
            else if(str[i]=='?'&&str[i+1]=='B'){
                str[i]='R';
            }
        }
        if(str[0]=='?'){
            for(int i=0;i<n;i++){
                if(i&1)str[i]='R';
                else str[i]='B';
            }
        }
        cout<<str<<'\n';
    }
    //cout.flush();
    //system("pause");
    return 0;
}