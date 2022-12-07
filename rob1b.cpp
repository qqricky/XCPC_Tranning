#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10;
int t[N];
int last[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>t[i];
        last[i]=-INF;
    }
    while(m--){
        bool flag=1;
        int x,k;
        cin>>x>>k;
        for(int i=1;i<=k;i++){
            int y;
            cin>>y;
            if(t[y]!=-1){
                if(x-last[y]<t[y]){
                    cout<<"Don't take ";
                    cout<<y<<" at "<<x<<"!\n";
                }else{
                    last[y]=x;
                }
            }
        }
    }
    cout.flush();
    return 0;
}