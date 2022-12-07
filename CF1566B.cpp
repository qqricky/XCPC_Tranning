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
    while(t--)
    {
        string str;
        cin>>str;
        int sum=0;
        for(int i=0;i<str.size();i++){
            sum+=str[i]-'0';
        }
        if(sum==0){
            cout<<1<<'\n';
        }
        else if(sum==str.size()){
            cout<<0<<'\n';
        }
        else{
            int fl=0;
            str=' '+str;
            for(int i=1;i<str.size();i++){
                if(str[i]=='0'){
                    if(!fl){
                        fl=1;
                    }
                    else if(str[i]!=str[i-1]){
                        fl=2;
                    }
                }
            }
            if(fl<2){
                cout<<1<<'\n';
            }
            else{
                cout<<2<<'\n';
            }
        }
    }
    //cout.flush();
    //system("pause");
    return 0;
}