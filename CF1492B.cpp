#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int p[N];
int ma[N];
int pos[N];
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
        memset(ma,0,sizeof(ma));
        pos[0]=0;
        for(int i=1;i<=n;i++){
            cin>>p[i];
            if(p[i]>ma[i-1]){
                pos[i]=i;
                ma[i]=p[i];
            }
            else{
                pos[i]=pos[i-1];
                ma[i]=ma[i-1];
            }

        }
        //for(int i=1;i<=n;i++)cout<<pos[i]<<endl;
        int poss=n;
        while(poss>0){
            for(int j=pos[poss];j<=poss;j++){
                cout<<p[j]<<' ';
            }
            poss=pos[poss]-1;
        }
        cout<<endl;
    }
    //system("pause");
    return 0;
}