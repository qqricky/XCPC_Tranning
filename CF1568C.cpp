#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e6+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
vector<int>mp[N];
bool self[N];
bool lf[N];
vector<int>pos;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        mp[i].push_back(0);
        for(int j=1;j<=m;j++){
            char ch;
            cin>>ch;
            if(ch=='X'){
                if(i<=n)
                mp[i].push_back(1);
            }
            else{    
                mp[i].push_back(0);
            }
        }
    }
    for(int j=1;j<=m;j++){
        bool fl=0;
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(mp[i][j]){
                if(!self[j]){
                    self[j]=1;
                    fl=1;
                    cnt=0;
                }
                else{
                    if(cnt>0&&fl){
                        lf[j]=1;
                        break;
                    }
                }
            }
            else if(fl){
                if(mp[i][j-1]==0)fl=0;
                else cnt++;
            }
        }
        if(fl&&cnt>0)lf[j]=1;
    }
    for(int j=1;j<=m;j++){
            
    }
    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
    }
    cout.flush();
    system("pause");
    return 0;
}