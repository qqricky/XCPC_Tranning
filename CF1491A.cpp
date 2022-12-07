#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int a[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    int tmp,x;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt+=a[i];
    }
    for(int i=1;i<=q;i++){
        cin>>tmp>>x;
        if(tmp==1){
            if(a[x]){
                cnt--;
                a[x]=0;
            }
            else{
                cnt++;
                a[x]=1;
            }
        }
        else{
            if(x>cnt)cout<<0<<"\n";
            else cout<<1<<"\n";
        }
    }
    //system("pause");
    return 0;
}