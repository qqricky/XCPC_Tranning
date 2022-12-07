#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10; 
using namespace std;
int  mt[101]={};
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
        int n,k;
        cin>>n>>k;
        int maxx=0,pos;
        int sum=0;
        int tot=0;
        for(int i=1;i<=n;i++){
            cin>>mt[i];
            tot+=mt[i];
        }
        for(int i=n;i>=1;i--){
            maxx=max(maxx,mt[i]);
            sum+=maxx;
        }
        if(k>sum-tot){
            cout<<-1<<endl;
            continue;
        }
        int poss;
        for(int i=1;i<=k;i++){
            int j=1;
            while(mt[j]>=mt[j+1])j++;
            mt[j]++;
            if(i==k)poss=j;
        }
        cout<<poss<<endl;
    }
    //system("pause");
    return 0;
}