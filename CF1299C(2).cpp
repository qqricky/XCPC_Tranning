#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e6+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
double a[N];
struct node
{
    int num;
    double val;
};
deque<node>s;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf",&a[i]);
    }
    s.push_back(node{1,a[1]});
    for(int i=2;i<=n;i++){
        node x={1,a[i]};
        //cout<<x.val<<' '<<s.back().val<<endl;
        while(!s.empty()&&x.val<=s.back().val){
            x.val=(s.back().val*s.back().num+x.val*x.num)/(s.back().num+x.num);
            x.num=s.back().num+x.num;
            s.pop_back();
        }
        s.push_back(x);
    }
    for(auto it=s.begin();it!=s.end();it++){
        int nn=it->num;
        double vall=it->val;
        for(int j=1;j<=nn;j++){
            printf("%.9f\n",vall);
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}