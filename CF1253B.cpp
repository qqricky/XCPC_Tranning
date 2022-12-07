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
int a[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    set<int>s;
    vector<int>ans;
    map<int,int>cnt;
    int tmp;
    bool flag=1;
    ans.push_back(0);
    for(int i=1;i<=n;i++){
        if(a[i]>0){
            if(cnt[a[i]]>=1){
                flag=0;
                break;
            }
            s.insert(a[i]);
            cnt[a[i]]=1;
        }
        else{
            a[i]=abs(a[i]);
            if(cnt[a[i]]!=1){
                flag=0;
                break;
            }
            cnt[a[i]]=2;
            s.erase(a[i]);
        }
        if(s.size()==0){
            ans.push_back(i);
            cnt.clear();
        }
    }
    if(s.size())flag=0;
    if(!flag){
        cout<<"-1";
        return 0;
    }
    cout<<ans.size()-1<<'\n';
    for(int j=1;j<ans.size();j++){
        cout<<ans[j]-ans[j-1]<<' ';
    }
    cout.flush();
    //system("pause");
    return 0;
}