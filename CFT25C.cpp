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
int getC(int &pos){
    int s=1;
    if(str[pos]=='-'){
        s=-1;
        pos++;
    }
    else if(str[pos]=='+'){
        s=1;
        pos++;
    }
    int c=0;
    while(pos<str.length()&&str[pos]!='x'){
        c=c*10+str[pos]-'0';
        pos++;
    }
    if(c==0){
        c=1;
    }
    return c*s;
}
int getmi(int &pos){
    if(str[pos]=='x')pos++;
    int c=0;
    while(pos<str.length()&&str[pos]>='0'&&str[pos]<='9'){
        c=(c*10)+str[pos]-'0';
        pos++;
    }
    if(c==0)return 1;
    return c;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>str;
    int pos=0;
    bool fst=1;
    if(str=="x"){
        cout<<1;
        return 0;
    }
    else if(str=="-x"){
        cout<<-1;
        return 0;
    }
    while(pos<str.length()){
        int c=getC(pos);
        if(pos>=str.length()){
            if(fst)cout<<0;
            break;
        }
        int mi=getmi(pos);
        //cout<<c<<' '<<mi<<endl;
        c*=mi;
        mi--;
        if(fst){
            fst=0;
            if(c>0){
                if(c>1)cout<<c;
            }
            else{
                cout<<'-';
                if(abs(c)>1)cout<<abs(c);
            }
        }
        else{
            if(c<0)cout<<'-';
            else cout<<'+';
            if(abs(c)>1)cout<<abs(c);
        }
        if(mi>0){
            cout<<'x';
        }
        else if(mi==0){
            if(abs(c)==1){
                cout<<abs(c);
            }
            break;
        }
        if(mi>1){
            cout<<mi;
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}