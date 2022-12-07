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

int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int x;
    cin>>x;
    int ans=1;
    int val=1;
    vector<int>v;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            ans*=i;
            int tmp=0;
            while(x%i==0){
                x/=i;
                tmp++;
            }
            v.push_back(tmp);
            val=max(val,tmp);
        }
    }
    if(x>1){
        v.push_back(1);
        ans*=x;
    }
    int base=1;
    int cnt=0;
    while(base<val){
        base<<=1;
        cnt++;
    }
    int anss=cnt;
    for(int i:v){
        if(i<(1<<cnt)){
            anss++;
            break;
        }
    }
    cout<<ans<<' '<<anss;
    cout.flush();
    //system("pause");
    return 0;
}