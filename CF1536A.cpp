#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
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
    while(t--){
        int n;
        cin>>n;
        int flag=1;
        int tmp;
        for(int i=1;i<=n;i++){
            cin>>tmp;
            if(tmp<0)flag=0;
        }
        if(flag){
            cout<<"YES"<<endl;
            cout<<101<<endl;
            for(int i=0;i<=100;i++){
                cout<<i<<' ';
            }
            cout<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    //system("pause");
    return 0;
}