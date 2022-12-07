#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10;
using namespace std;
int a[N];
int a1[N];
int b[N];
int b1[N];
int pos1,pos2;
int po1,po2;
int calc(int a[],int b[],int lena,int lenb)
{
    int bk[lenb+2];
    bk[lenb+1]=0;
    map<int,int>mp;
    for(int i=1;i<=lena;i++){
        mp[a[i]]=1;
    }
    for(int i=lenb;i>=1;i--){
        if(mp[b[i]])bk[i]=bk[i+1]+1;
        else bk[i]=bk[i+1];
    }
    //cout<<endl;
    int ans=bk[1];
    //for(int i=1;i<=lenb;i++)cout<<'i'<<i<<'-'<<bk[i]<<endl;
    for(int i=1;i<=lenb;i++){
        int sum=upper_bound(a+1,a+lena+1,b[i])-a-1;
        if(sum<=0){
            continue;
        }
        int p=lower_bound(b+1,b+lenb+1,b[i]-sum+1)-b;
        //cout<<i<<"sum"<<sum<<"p"<<p<<"aaa"<<bk[i+1]<<"ans"<<i-p+1+bk[i+1]<<endl;
        ans=max(ans,i-p+1+bk[i+1]);
    }
    return ans;
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
        int n,m;
        cin>>n>>m;
        pos1=pos2=0;
        int tmp;
        int res=0;
        for(int i=1;i<=n;i++){
            cin>>tmp;
            if(tmp>0){
                a[++pos1]=tmp;
            }
            else{
                a1[++pos2]=(-tmp);
            }
        }
        reverse(a1+1,a1+1+pos2);
        po1=po2=0;
        for(int i=1;i<=m;i++){
            cin>>tmp;
            if(tmp>0){
                b[++po1]=tmp;
            }
            else{
                b1[++po2]=(-tmp);
            }
        }
        reverse(b1+1,b1+1+po2);
        res+=calc(a,b,pos1,po1);
        res+=calc(a1,b1,pos2,po2);
        cout<<res<<endl;
    }
    //system("pause");
    return 0;
}