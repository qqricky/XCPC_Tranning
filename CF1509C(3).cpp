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
    int n;
    cin>>n;
    if(n==1){
        cout<<"1";
    }
    else if(n==2){
        cout<<"1 2";
    }
    else if(n==3){
        cout<<"1 1 3";
    }
    else{
        for(int i=1;i<=(n+1)/2;i++)cout<<1<<' ';
        int tot=n-(n+1)/2;
        int ans=2;
        while(tot>0){
            if(tot==3){
                cout<<ans<<' '<<ans<<' '<<ans*3;
                break;
            }
            for(int i=1;i<=(tot+1)/2;i++){
                 cout<<ans<<" ";
            }
            ans*=2;
            tot-=(tot+1)/2;
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}