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
    int t;
    cin>>t;
    while(t--){
        int x,y,k;
        cin>>x>>y>>k;
        //saple
        if(x+y==3){
            cout<<"umaii!!!\n";
            continue;
        }
        if(x>y)swap(x,y);
        if((y-x-1)%(k+1)==0){
            cout<<"nano no baka!!!\n";
        }
        else{
            cout<<"umaii!!!\n";
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}