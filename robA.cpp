#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
#define INF 0x3f3f3f3f
int a[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    a[n+1]=INF;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int st=0;
    bool is=1;
    int ed=-1;
    for(int i=1;i<=n+1;i++){
        if(a[i]>ed){
            if(ed>0){
                cout<<st<<' '<<ed<<'\n';
            }
            st=a[i]+15;
            ed=a[i]+44;
            is=1;
        }else if(a[i]>=st&&is){
            is=0;
            ed+=15;
        }
    }
    // cout.flush();
    // system("pause");
    return 0;
}