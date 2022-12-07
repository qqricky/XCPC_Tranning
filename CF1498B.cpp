#include <bits/stdc++.h>
#include <cmath>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int num[1070]={};
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
        int n,w;
        cin>>n>>w;
        int tmp;
        int m=0;
        for(int i=1;i<=n;i++){
            cin>>tmp;
            tmp=log2(tmp);
            m=max(m,tmp);
            num[tmp]++;
        }
        int cnt=0;
        int re=n;
        while(re)
        {
            ll rm=w;
            int pos=m;
            while(pos>=0){
                while((1<<pos)<=rm&&num[pos]){
                    rm-=(1<<pos);
                    num[pos]--;
                    re--;
                }
                pos--;
            }
            cnt++;
        }
        cout<<cnt<<"\n";
    }
    //system("pause");
    return 0;
}