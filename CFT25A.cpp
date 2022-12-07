#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#pragma GCC optimise(2)
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
    n*=2;
    int tot=0;
    vector<int>a(33);
    vector<int>p(33);
    vector<int>b(33);
    vector<int>anss(33);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        tot+=a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
    int num=n/2;
    do{
        int sum=0;
        for(int i=1;i<=n;i++){
            b[i]=a[p[i]];
        }
        for(int i=1;i<=num;i++){
            sum+=b[i];
        }
        for(int i=n+1;i<=2*n;i++){
            b[i]=b[i-n];
        }
        int ma=sum;
        for(int i=1;i<=n;i++){
            sum-=b[i];
            sum+=b[i+num];
            ma=max(ma,sum);
        }
        if(tot-ma>ans){
            ans=tot-ma;
            for(int i=1;i<=n;i++){
                anss[i]=b[i];
            }
        }
    }while(next_permutation(p.begin()+1,p.begin()+n+1));
    //cout<<ans<<endl;
    for(int i=1;i<=n;i++){
        cout<<anss[i]<<' ';
    }
    cout.flush();
    system("pause");
    return 0;
}