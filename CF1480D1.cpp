#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10; 
using namespace std;
int a[N];
int num[N]={};
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
    }
    ll ans=1;
    int now=a[1];
    int flag=0;
    int val1,val2;
    int cat=0;
    for(int i=2;i<=n;i++){
        if((a[i]==now)&&(!flag)){
            if(i>4){
                if(cat&&a[i]==val1){
                    ans--;
                }
                else if((a[i-3]==now)&&(a[i-4]==now)){
                    ans--;
                }
            }
            if(cat)cat=0;
            ans++;
            flag=1;
        }
        else if(a[i]!=now){
            if(cat){
                if(a[i]!=val1&&a[i]!=val2)
                    cat=0;
            }
            if(flag){
                val2=a[i];
                val1=a[i-1];
                cat=1;
            }
            flag=0;
            ans++;
            now=a[i];
        }
    }
    cout<<ans;
    //system("pause");
    return 0;
}