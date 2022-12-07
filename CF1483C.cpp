#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
int v[N];
int cnt[N];
vector<int>day[N];
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
        int n,m;
        int num;
        int tmp;
        cin>>n>>m;
        for(int i=1;i<=max(n,m);i++){
            v[i]=0;
            cnt[i]=0;
            day[i].clear();
        }
        int mm=ceil((double)m/2.0);
        int flag=1;
        for(int i=1;i<=m;i++){
            cin>>num;
            if(num==1){
                cin>>tmp;
                v[i]=tmp;
                cnt[tmp]++;
                if(cnt[tmp]>mm)flag=0;
            }
            else{
                for(int j=1;j<=num;j++){
                    cin>>tmp;
                    day[i].push_back(tmp);
                }
            }
        }
        if(flag)
        for(int i=1;i<=m;i++){
            if(!v[i]){
                int mi=INF;
                int ver;
                for(int k=0;k<day[i].size();k++){
                    if(cnt[day[i][k]]<mi){
                        mi=cnt[day[i][k]];
                        ver=day[i][k];
                    }
                }
                v[i]=ver;
                cnt[ver]++;
                if(cnt[ver]>mm){
                    flag=0;
                    break;
                }
            }
        }
        if(flag){
            cout<<"YES\n";
            for(int i=1;i<=m;i++)cout<<v[i]<<' ';
            cout<<"\n";
        }
        else{
            //for(int i=1;i<=m;i++)cout<<v[i]<<' ';
            cout<<"NO\n";
        }
        cout.flush();
    }
    //system("pause");
    return 0;
}