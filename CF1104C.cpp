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
    string str;
    cin>>str;
    bool f1=0,f0=0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='0'){
            if(f0){
                cout<<"1 4\n";
            }
            else{
                cout<<"3 4\n";
            }
            f0^=1;
        }
        else{
            if(f1){
                cout<<"1 3\n";
            }
            else{
                cout<<"1 1\n";
            }
            f1^=1;
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}