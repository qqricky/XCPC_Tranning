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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int mi=0x3f3f3f3f;
        for(int i=1;i<=n;i++){cin>>a[i];mi=min(mi,a[i]);}
        int num[110];
        int ans=0;
        for(int k=mi+1;k<=100;k++){
            memset(num,0,sizeof(num));
            int cnt=0;
            for(int j=1;j<=n;j++){
                if(a[j]>=k)continue;
                if(num[k-a[j]]){
                    num[k-a[j]]--;
                    cnt++;
                }
                else{
                    num[a[j]]++;
                }
            }
            ans=max(ans,cnt);
            //cout<<ans<<endl;
            //cout<<k<<endl;
        }
        cout<<ans<<"\n";
    }
    //system("pause");
    return 0;
}