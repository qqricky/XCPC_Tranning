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
ll a[N];
vector<ll>anss;
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
        ll st=1;
        a[1]=st;
        anss.clear();
        for(int i=1;i<n;i++){
            int x;
            cin>>x;
            st+=x;
            a[i+1]=st;
        }
        anss.push_back(0);
        ll dis=a[n]-a[1];
        anss.push_back(dis);
        int l=1;
        int r=n;
        ll ans=dis;
        for(int i=3;i<=n;i++){
            if(i&1){
                ans+=dis;
                l++;
                anss.push_back(ans);
            }
            else{
                r--;
                dis+=a[r]-a[l];
                ans+=dis;
                anss.push_back(ans);
            }
        }
        for(int i=0;i<anss.size()-1;i++){
            cout<<anss[i]<<' ';
        }
        cout<<anss[anss.size()-1]<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}