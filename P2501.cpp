#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
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
int lev[N];
int firstpos[N];
ll f[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]-=i;
        firstpos[i]=n;
    }
    vector<int>arr;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(arr.empty()||a[i]>=arr[arr.size()-1]){
            arr.push_back(a[i]);
            lev[i]=arr.size();
            firstpos[arr.size()]=i;
            continue;
        }
        int pos=upper_bound(arr.begin(),arr.end(),a[i])-arr.begin();
        arr[pos]=a[i];
        lev[i]=pos+1;
    }
    memset(f,0x3f,sizeof(f));
    //scout<<f[0]<<endl;
    ans=arr.size();
    a[0]=-INF;
    lev[0]=0;
    lev[n+1]=ans+1;
    a[n+1]=INF;
    f[0]=0;firstpos[0]=0;
    for(int i=1;i<=n+1;i++){
        for(int j=firstpos[lev[i]-1];j<i;j++){
            if(lev[j]==lev[i]-1&&a[j]<=a[i]){
                ll sum=0,tmp;
                if(i==n+1){
                    for(int k=j+1;k<i;k++){
                        sum+=abs(a[j]-a[k]);
                    }
                    f[i]=min(f[i],f[j]+sum);
                    continue;
                }
                for(int k=j+1;k<i;k++){
                    sum+=abs(a[i]-a[k]);
                }
                tmp=sum;
                if(lev[i]>1)
                for(int k=j+1;k<i;k++){
                    sum-=abs(a[i]-a[k]);
                    sum+=abs(a[j]-a[k]);
                    tmp=min(tmp,sum);
                }
                f[i]=min(f[i],f[j]+tmp);
            }
        }
    }
    //for(int i=1;i<=n;i++)cout<<f[i]<<endl;
    cout<<n-ans<<'\n'<<f[n+1];
    cout.flush();
    //system("pause");
    return 0;
}