#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e6+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
ll sum[N]={};
vector<pair<ll,ll> >v;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,w;
    cin>>n>>w;
    for(int i=1;i<=n;i++){
        int len;
        cin>>len;
        v.clear();
        v.resize(len);
        for(int j=0;j<len;j++){
            cin>>v[j].first;
            v[j].second=j+1;
        }
        int poss=0;
        sort(v.begin(),v.end());
        int pos=len-1;
        auto pr=v[pos];
        int lll=w-len;
        int rrr=len+1;
        if(pr.first<0){
            if(pr.second<=lll)pr.second=lll+1;
            if(w-(len-pr.second)>=rrr)pr.second=len-w+rrr-1;
        }
        int mi=pr.second;
        int mx=pr.second;
        int l=mi;
        int r=w-(len-mx);
        ll val=pr.first;
        sum[l]+=val;
        sum[r+1]-=val;
        if(pr.first<0){
            if(len*2<=w){
                sum[l]-=val;
                sum[r+1]+=val;
                continue;
            }
            else{
                sum[l]-=val;
                sum[r+1]+=val;
                l=len+1;
                r=w-len;
            }
        }
        trak:;
        for(int j=len-2;j>=0;j--){
            auto pr=v[j];
            if(pr.first<0){
                if(len*2<=w)break;
                else{
                    if(pr.second<=lll)pr.second=lll+1;
                    if(w-(len-pr.second)>=rrr)pr.second=len-w+rrr-1;
                }
            }
            if(pr.second<mx&&pr.second>mi)continue;
            if(pr.second>mx){
                mx=pr.second;
                int newr=max(r,(int)w-(len-mx));
                sum[r+1]+=pr.first;
                sum[newr+1]-=pr.first;
                r=newr;
            }
            else{
                mi=pr.second;
                int newl=min(l,mi);
                sum[newl]+=pr.first;
                sum[l]-=pr.first;
                l=newl;
            }
        }
        // for(int j=poss;j>=0;j--){
        //     auto pr=v[j];
        //     if(pr.second>r){
        //         int pos=w-(len-pr.second);
        //         sum[pos]+=pr.first;
        //         sum[pos+1]-=pr.first;
        //     }
        //     else if(pr.second<l){
        //         sum[pr.second]+=pr.first;
        //         sum[pr.second+1]-=pr.first;
        //     }
        // }
    }
    for(int i=1;i<=w;i++){
            sum[i]+=sum[i-1];
            cout<<sum[i]<<' ';
        }
    cout.flush();
    //system("pause");
    return 0;
}