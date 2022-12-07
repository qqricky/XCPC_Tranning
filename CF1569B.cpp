#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
char ans[55][55];
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
        string str;
        cin>>str;
        str=' '+str;
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ans[i][j]='=';
            }
        }
        for(int i=1;i<=n;i++){
            if(str[i]=='2'){
                cnt++;
            }
        }
        if(cnt<3&&cnt>0){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        if(cnt==0){
            for(int i=1;i<=n;i++)ans[i][i]='X';
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=n;j++){
                        cout<<ans[i][j];
                    }
                    cout<<'\n';
                }
            continue;
        }
        int next=n;
        while(str[next]=='1')next--;
        int tmp=next;
        for(int i=tmp-1;i>=1;i--){
            if(str[i]=='2'&&cnt){
                cnt--;
                ans[i][next]='+';
                ans[next][i]='-';
                next=i;
            }
        }
        ans[tmp][next]='+';
        ans[next][tmp]='-';
        for(int i=1;i<=n;i++)ans[i][i]='X';
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<ans[i][j];
            }
            cout<<'\n';
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}