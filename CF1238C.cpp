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
int dis[N];
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
        int h,n;
        cin>>h>>n;
        int ncnt=0;
        int pre=h;
        int x;
        for(int i=1;i<=n;i++){
            cin>>x;
            dis[++ncnt]=pre-x;
            pre=x;
        }
        if(x>1)dis[++ncnt]=x-1;
        int ans=INF;
        int sum=0;
        for(int i=1;i<=ncnt;i++){
            if(i%2==0){
                if(dis[i]>2)sum++;
            }
        }
        ans=min(ans,sum);
        int sum=1;
        dis[1]--;
        for(int i=1;i<=ncnt;i++){

        }
    }
    cout.flush();
    system("pause");
    return 0;
}