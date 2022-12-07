#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
ll a[N];
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
        set<ll>s;
        ll ma=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            ma=max(ma,a[i]);
        }
        if(n<=2){
            cout<<0<<endl;
            continue;
        }
        for(int i=2;i<=n;i++)s.insert(a[i]-a[i-1]);
        int flag=1;
        if(s.size()>2)flag=0;
        else if(s.size()==1)flag=2;

        if(flag==2){
            cout<<0<<endl;
        }
        else if(flag){
            auto it=s.begin();
            int x=*it;
            int y=*(++it);
            if(x>y){
                swap(x,y);
            }
            int m=abs(x)+y;
            int c=y;
            int val=a[1];
            int f1=1;
            if(m==0||m<=ma)f1=0;
            if(f1){
                for(int i=2;i<=n;i++){
                    val=(val+c)%m;
                    if(val!=a[i]){
                        f1=0;
                        break;
                    }
                }
            }
            if(f1)cout<<m<<' '<<c<<endl;
            else cout<<-1<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    //system("pause");
    return 0;
}