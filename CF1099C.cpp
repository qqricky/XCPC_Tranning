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
    int k;
    cin>>k;
    bool flag=0;
    int num=0;
    for(char c : str){
        if(c=='*')flag=1;
        if(c!='*'&&c!='?')num++;
    }
    if(flag){
        if(str.length()-num>k){
            cout<<"Impossible";
            return 0;
        }
        for(int i=0;i<str.length();i++){
            int pos=-1;
            if(str[i]=='?'){
                str.erase(i-1,2);
            }
            else if(str[i]=='*'){
                if(pos!=-1){
                    pos=i;
                }
            }
        }
    }

    cout.flush();
    system("pause");
    return 0;
}