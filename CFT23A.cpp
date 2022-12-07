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
vector<int>cnt(30);
vector<int>s(30);
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str,ss;
    cin>>str>>ss;
    if(ss.size()>str.size()){
        cout<<0;
        return 0;
    }
    for(char c : ss){
        s[c-'a']++;
    }
    int lenn=str.length();
    int len=ss.length();
    str=' '+str+'z';
    ss=' '+ss+'z';
    int num=0;
    for(int i=1;i<=len;i++){
        if(str[i]=='?')num++;
        else cnt[str[i]-'a']++;
    }
    int ans=0;
    for(int l=1;l+len-1<=lenn;l++){
        bool flag=1;
        for(int i=0;i<='z'-'a';i++){
            if(cnt[i]>s[i]){
                flag=0;
                break;
            }
        }
        ans+=flag;
        if(str[l]=='?')num--;
        else cnt[str[l]-'a']--;
        if(str[l+len]=='?')num++;
        else cnt[str[l+len]-'a']++;
    }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}