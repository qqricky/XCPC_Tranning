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
map<int,int>mp1;
map<int,int>mp2;
set<int>s;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        s.insert(x),s.insert(y);
        if(mp1[x]){
            mp2[x]=y;
        }
        else{
            mp1[x]=y;
        }
        if(mp1[y]){
            mp2[y]=x;
        }
        else{
            mp1[y]=x;
        }
    }
    int st;
    for(int p : s){
        if(mp2[p]==0){
            st=p;
            break;
        }
    }
    cout<<st<<' ';
    int pos=mp1[st];
    int pre=st;
    while(mp2[pos]){
        cout<<pos<<' ';
        if(mp1[pos]==pre){
            pre=pos;
            pos=mp2[pos];
        }
        else{
            pre=pos;
            pos=mp1[pos];
        }
    }
    cout<<pos;
    cout.flush();
    //system("pause");
    return 0;
}