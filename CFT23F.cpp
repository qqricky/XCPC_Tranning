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
int a,b,c,d;
void solve(string &str){
    for(char c: str){
        if(c=='4')a--;
        else if(c=='7')b--;
    }
    string a1,a2;
    for(int i=1;i<=a;i++){
        a1+='4';
    }
    for(int i=1;i<=b;i++){
        a2+='7';
    }
    for(int i=0;i<str.length();i++){
        if(str[i]=='4'){
            str.insert(i,a1);
            break;
        }
    }
    for(int i=str.length()-1;i>=0;i--){
        if(str[i]=='7'){
            str.insert(i,a2);
            break;
        }
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b>>c>>d;
    string ans;
    if(abs(c-d)>1){
        cout<<-1;
        return 0;
    }
    if(c>d){
        if(a<c||b<c){
            cout<<-1;
            return 0;
        }
        else{
            for(int i=1;i<=c;i++)ans+="47";
        }
    }
    else if(c<d){
        if(a<d||b<d){
            cout<<-1;
            return 0;
        }
        else{
            for(int i=1;i<=d;i++)ans+="74";
        }
    }
    else{
        if(a<=c&&b<=c||a<c||b<c){
            cout<<-1;
            return 0;
        }
        if(a==c){
            for(int i=1;i<=c;i++){
                ans+="74";
            }
            ans+="7";
        }
        else{
            for(int i=1;i<=c;i++){
                ans+="47";
            }
            ans+="4";
        }
    }
    solve(ans);
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}