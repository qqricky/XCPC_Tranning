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
    int n,m,k;
    cin>>n>>m>>k;
    if(m<n-1){
        cout<<-1;
        return 0;
    }
    // if((n&1) && m> 2*(n/2+1)*(n/2+1)){
    //     cout<<-1;
    //     return 0;
    // }
    if(m>1+(n-1)*(n-2)/2){
        cout<<-1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(i==k)continue;
        m--;
        cout<<i<<' '<<k<<'\n';
    }
    int sp=1;
    if(sp==k)sp++;
    if(m==0)goto ed;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(i==sp||j==sp)continue;
            if(i==k||j==k)continue;
            cout<<i<<' '<<j<<'\n';
            m--;
            if(m==0)goto ed;
        }
    }
    // else{
    //     vector<int>v;
    //     int pos=1;
    //     for(int i=1;i<=n/2;i++){
    //         if(pos==k){
    //             pos++;
    //         }
    //         v.push_back(pos);
    //         pos++;
    //     }
    //     cout<<v.size()<<endl;
    //     for(int i=0;i<v.size();i++){
    //         for(int j=i+1;j<v.size();j++){
    //             cout<<v[i]<<' '<<v[j]<<'\n';
    //             m--;
    //             if(m==0)goto ed;
    //         }
    //     }
    //     v.clear();
    //     for(int i=1;i<=n/2;i++){
    //         if(pos==k){
    //             pos++;
    //         }
    //         v.push_back(pos);
    //         pos++;
    //     }
    //     for(int i=0;i<v.size();i++){
    //         for(int j=i+1;j<v.size();j++){
    //             cout<<v[i]<<' '<<v[j]<<'\n';
    //             m--;
    //             if(m==0)goto ed;
    //         }
    //     }
    // }
    ed:;
    cout.flush();
    //system("pause");
    return 0;
}