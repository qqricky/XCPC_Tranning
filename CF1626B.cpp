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
string str;
void cut(int pos){

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
        cin>>str;
        for(int i=str.size()-1;i>0;i--){
            if(str[i]+str[i-1]-'0'-'0'>=10){
                cut(i-1);
                cout<<str<<'\n';
                continue;
            }
        }
        for(int i=0;i<str.size()-1;i++){
            
        }
    }
    cout.flush();
    system("pause");
    return 0;
}