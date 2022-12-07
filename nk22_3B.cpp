#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e6+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
string str[N];
vector<string>tmp[7];
void st(int l,int r,int len){
    if(l>=r)return;
    for(int i=0;i<=5;i++)tmp[i].clear();
    for(int i=l;i<=r;i++){
        int x=len;
        if(str[i].size()<=len){
            x=len%str[i].size();
            // tmp[0].push_back(str[i]);
        }
        if(str[i][x]=='0'){
            tmp[0].push_back(str[i]);
        }else if(str[i][x]=='1'){
            tmp[1].push_back(str[i]);
        }else if(str[i][x]=='2'){
            tmp[2].push_back(str[i]);
        }else if(str[i][x]=='3'){
            tmp[3].push_back(str[i]);
        }else{
            tmp[4].push_back(str[i]);
        }
        
    }
    int now=0;
    int pos=0;
    int lft=l;
    int rt=l-1;
    for(int i=l;i<=r;i++){
        // if(tmp[now].empty()||pos>=tmp[now].size()){
        //     rt=i-1;
        //     st(lft,rt,len+1);
        //     cout<<lft<<' '<<rt<<' '<<len+1<<'\n';
        //     lft=i;
        // }
        while(tmp[now].empty()||pos>=tmp[now].size()){
            now++;
            pos=0;
        }
        str[i]=tmp[now][pos];
        pos++;
    }
    for(int i=0;i<5;i++){
        lft=rt+1;
        rt+=tmp[i].size();
        st(lft,rt,len+1);
    }
}
int gcd(int x,int y){
    return y ? gcd(y,x%y) : x;
}
int lcm(int x,int y){
    return x*y/gcd(x,y);
}
bool cmp(string &s1,string &s2){
    int len1=min(s1.length(),s2.length());
    int len2=max(s1.length(),s2.length());
    if(len1==0)return s1.length()<s2.length();
    int x=s1.length(),xx=s2.length();
    for(int i=0;i<=len2;i++){
        int x1=i;
        int x2=i;
        if(x1>=x)x1%=x;
        if(x2>=xx)x2%=xx;
        if(s1[x1]==s2[x2])continue;
        return s1[x1]<s2[x2];
    }
    return len1<len2;
}

int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.in","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    // string t1="1";
    // string t2="101";
//     cout<<cmp(t1,t2)<<endl;
    for(int i=1;i<=n;i++){
        cin>>str[i];
        for(int j=0;j<str[i].size();j++){
            cnt[i][str[i][j]-'0']++;
        }
        ed[str[i].length()-1][str[i][str[i].length()-1]-'0']++;
    }
    for(int j=1;j<=n;j++){
        int now=0;
        while(1){
            for(int i=0;i<=4;i++){
                if(cnt[now][i]){

                }
            }
        }
    }
    // st(1,n,0);
    // sort(str+1,str+n+1,cmp);
    // for(int i=1;i<=n;i++){
    //     cout<<str[i];
    // }
    // cout.flush();
    // system("pause");
    return 0;
}