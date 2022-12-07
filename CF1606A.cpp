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
char s[5][102];
void init(){
    for(int i=0;i<=100;i++){
        if(i&1){
            s[2][i]='a';
            s[3][i]='b';
        }
        else{
            s[2][i]='b';
            s[3][i]='a';
        }
        s[0][i]='a';
        s[1][i]='b';
    }
}
struct node
{
    int cnt,p;
}nd[5];
bool cmp(node x,node y){
    return x.cnt<y.cnt;
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
    init();
    while(t--){
        string str;
        cin>>str;
        for(int j=0;j<=3;j++){
            nd[j].p=j;
            nd[j].cnt=0;
        }
        for(int i=0;i<str.size();i++){
            for(int j=0;j<=3;j++){
                nd[j].cnt+=(str[i]!=s[j][i]);
            }
        }
        if(str.length()&1){
            sort(nd,nd+4,cmp);
        }
        else{
            sort(nd,nd+2,cmp);
        }
        for(int i=0;i<str.length();i++){
            cout<<s[nd[0].p][i];
        }
        cout<<'\n';
    }    
    cout.flush();
    system("pause");
    return 0;
}