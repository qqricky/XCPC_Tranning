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
    /*
    Typically Otaku
Eye-opener
Young Traveller
Excellent Traveller
Contemporary Xu Xiake

    */
    while(t--){
        int x;
        int cnt=0;
        for(int i=1;i<=4;i++){
            cin>>x;
            if(x)cnt++;
        }
        if(cnt==0){
            cout<<"Typically Otaku\n";
        }
        else if(cnt==1){
            cout<<"Eye-opener\n";
        }
        else if(cnt==2){
            cout<<"Young Traveller\n";
        }
        else if(cnt==3){
            cout<<"Excellent Traveller\n";
        }
        else if(cnt==4){
            cout<<"Contemporary Xu Xiake\n";
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}