#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int a[N];
int b[N];
unordered_map<int,int>num;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        num.clear();
        for(int i=1;i<=n;i++){
            cin>>a[i];
            num[a[i]]++;
        }
        for(int i=1;i<=n;i++){
            cin>>b[i];
        }
        bool flag=1;
        multiset<int>s;
        int j=n;
        a[n+1]=INF;
        b[0]=INF;
        for(int i=n;i>=1;){
            if(a[i]!=b[j]){
                if(a[i+1]==b[j]&&num[b[j]]>0){
                    s.insert(b[j]);
                    num[b[j]]--;
                    j--;
                }
                else if(s.count(a[i])){
                    auto it=s.find(a[i]);
                    s.erase(it);
                    i--;
                }
                else{
                    // cout<<num[b[j]]<<'\n';
                    // cout<<i<<' '<<j<<"ahwklejla\n";
                    flag=0;
                    break;
                }
            }
            else{
                num[a[i]]--;
                i--,j--;
            }
        }
        if(s.size())flag=0;
        if(flag)cout<<"YES\n";
        else cout<<"NO\n";
    }
    cout.flush();
    //system("pause");
    return 0;
}