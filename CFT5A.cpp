#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int cnt[220];
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
        memset(cnt,0,sizeof(cnt));
        int n;
        cin>>n;
        int tmp;
        for(int i=1;i<=n;i++){
            cin>>tmp;
            cnt[tmp]++;
        }
        int ans=0;
        int flag=0;
        for(int i=0;i<=100;i++){
            if(cnt[i]<2){
                if(flag&&cnt[i]==0){
                    ans+=i;
                    break;
                }
                else if(cnt[i]==0){
                    ans=2*i;
                    break;
                }
                else if(!flag){
                    flag=1;
                    ans+=i;
                }
            }
        }
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}