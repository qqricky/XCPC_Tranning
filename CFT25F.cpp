#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#pragma GCC optimise(2)
const int N=5e6+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int a[N];
int ori[1070];
int num[3070]={};
int mp[3070]={};
set<int>s;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int n;
    read(n);
    int m=(1<<n);
    for(int i=1;i<=m;i++){
        read(a[i]);
    }
    s.insert(0);
    mp[0]=1;
    int pos=0;
    for(int i=2;i<=m&&pos<n;i++){
        if(mp[a[i]]<=num[a[i]]){
            ori[++pos]=a[i];
            vector<int>tmp;
            for(auto it=s.rbegin();it!=s.rend();it++){
                int x=*it;
                mp[x+a[i]]+=mp[x];
                if(x==0){
                    num[a[i]]+=mp[0];
                }
                tmp.push_back(x+a[i]);
            }
            for(int x:tmp){
                s.insert(x);
            }
            // for(int j=1;j<(1<<(pos-1));j++){
            //     int sum=a[i];
            //     for(int k=0;k<=pos-2;k++){
            //         if((j>>k)&1){
            //             sum+=ori[k+1];
            //         }
            //     }
            //     mp[sum]++;
            // }
        }
        else{
            mp[a[i]]--;
            if(mp[a[i]]==0)s.erase(a[i]);
        }
    }
    for(int i=1;i<=n;i++)printf("%c",ori[i]);
    cout.flush();
    //system("pause");
    return 0;
}