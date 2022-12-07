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
int divide(int x)
{
    int sum=0;
    while(x){
        sum+=x%10;
        x/=10;
    }
    return sum;
}
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
        ll n,d;
        cin>>n>>d;
        int sum=divide(n);
        vector<ll>ans;
        if(sum>=d){
            d--;
            ll base=1;
            while(n){
                while(n%10&&d){
                    n--;
                    ans.push_back(base);
                    d--;
                }
                if(d==0)break;
                n/=10;
                base*=10;
            }
            ans.push_back(n*base);
        }
        else{
            ll base=1;
            while(n){
                while(n%10){
                    n--;
                    d--;
                    ans.push_back(base);
                }
                n/=10;
                base*=10;
            }
            reverse(ans.begin(),ans.end());
            int pos=ans.size()-1;
            while(ans[pos]==1){
                pos--;
            }
            while(d){
                while(ans[pos]==1){
                    pos--;
                }
                if(d>9){
                    for(int i=1;i<=10;i++){
                        ans.push_back(ans[pos]/10);
                    }
                    ans.erase(ans.begin()+pos);
                    d-=9;
                    pos=ans.size()-1;
                }
                else{
                    for(int i=1;i<=d;i++){
                        ans.push_back(ans[pos]/10);
                    }
                    ans.push_back(ans[pos]/10*(10-d));
                    ans.erase(ans.begin()+pos);
                    break;
                }
            }
        }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<' ';
        }
        //cout<<endl;
        cout<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}