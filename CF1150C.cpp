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
    int n;
    cin>>n;
    char ch;
    int cnt0=0,cnt1=0;
    for(int i=1;i<=n;i++){
        cin>>ch;
        if(ch=='1')cnt1++;
        else cnt0++;
    }
    if(cnt1&&cnt0){
        cout<<"2 1 ";
        for(int i=1;i<cnt0;i++)cout<<"2 ";
        for(int i=1;i<cnt1;i++)cout<<"1 ";
        cout<<"\n";
    }
    else{
        for(int i=1;i<=cnt0;i++)cout<<"2 ";
        for(int i=1;i<=cnt1;i++)cout<<"1 ";
        cout<<"\n";
    }
    cout.flush();
    //system("pause");
    return 0;
}