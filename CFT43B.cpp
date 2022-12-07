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
int num[20];
int nu[20];
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
        ll n,k;
        cin>>n>>k;
        int val=k;
        int ncnt=0;
        while(n){
            num[++ncnt]=n%10;
            n/=10;
        }
        for(int i=1;i<=ncnt;i++){
            nu[i]=num[ncnt-i+1];
        }
        for(int i=1;i<=ncnt;i++){
            num[i]=nu[i];
        }
        int pos;
        for(int i=1;i<=ncnt;i++){
            if(k<=0)break;
            int ma=0;
            for(int j=i+1;j<=ncnt;j++){
                if(num[j]>=ma){
                    ma=num[j];
                    pos=j;
                }
            }
            if(num[i]>=ma)continue;
            k--;
            swap(num[i],num[pos]);
        }
        k=val;
        for(int i=1;i<=ncnt;i++){
            if(k<=0)break;
            int mi=114514;
            for(int j=i+1;j<=ncnt;j++){
                if(nu[j]<=mi){
                    mi=nu[j];
                    pos=j;
                }
            }
            if(nu[i]<=mi)continue;
            k--;
            swap(nu[i],nu[pos]);
        }
        for(int i=1;i<=ncnt;i++)cout<<nu[i];
        cout<<' ';
        for(int i=1;i<=ncnt;i++)cout<<num[i];
        cout<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}