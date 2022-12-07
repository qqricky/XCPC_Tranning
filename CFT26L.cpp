#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=3e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int cnt[4][3*N]={};
vector<int>mp[4];
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    n*=3;
    string str;
    cin>>str;
    str=' '+str+' ';
    int num=n/3;
    for(int i=1;i<=n;i++){
        mp[str[i]-'A'+1].push_back(i);
    }
    int flag=0;
    int ans1,ans2;
    for(int j=1;j<=3;j++){
        if(cnt[j][n]<num)continue;
        int cntt=0;
        int l=0,r=cnt[j][n]-num-1;
        while(r<mp[j].size()){
            int k1=j+1;
            if(k1>3)k1=1;
            int k2=k1+1;
            if(k2>3)k2=1;
            if(cnt[k1][n]<cnt[k2][n])swap(k1,k2);
            int x=cnt[k2][mp[j][l]-1]+cnt[k2][n]-cnt[k2][mp[j][r]]+mp[j][r]-mp[j][l]+1;
            int y=cnt[k2][mp[j][l-1]-1]+cnt[k2][n]-cnt[k2][mp[j][r+1]]+mp[j][r+1]-mp[j][l-1]-1;
            if(num>=x&&num<=y){
                flag=j;
                ans1=mp[j][l];
                ans2=mp[j][r];
            }
            l++,r++;
        }
    }
    cout.flush();
    system("pause");
    return 0;
}