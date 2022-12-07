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
bool cmp(string s1,string s2){
    if(s1==s2)return 0;
    if(s1.size()==s2.size()){
        for(int j=0;j<s1.size();j++){
            if(s1[j]!=s2[j]){
                if(s1[j]=='0')return 1;
                else return 0;
            }
        }
    }
    return s1.size()<s2.size();
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll k;
    cin>>k;
    string str;
    cin>>str;
    int n=str.length();
    string ss;
    while(k){
        if(k&1){
            ss='1'+ss;
        }
        else{
            ss='0'+ss;
        }
        k>>=1;
    }
    int pos=0;
    while(ss[pos]=='0'){
        pos++;
    }
    pos++;
    string tmp=ss;
    ss=str;
    str=tmp;
    int ans=0;
    //cout<<ss<<' '<<str<<endl;
    while(cmp(str,ss)){
        while(ss[pos]=='0'&&pos<ss.length())pos++;
        if(pos==ss.length()){
            ans+=ss.length()-str.length();
            break;
        }
        ans++;
        ss.erase(ss.begin()+pos);
    }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}