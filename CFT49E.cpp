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
struct node
{
    int id;
    int win,winp,dif,goal;
    int val;
}nd[1070];
int cmp(node x,node y){
    if(x.val==y.val){
        if(x.win==y.win){
            if(x.winp==y.winp){
                if(x.dif==y.dif){
                    if(x.goal==y.goal){
                        return 2;
                    }
                    return x.goal<y.goal;
                }
                return x.dif<y.dif;
            }
            return x.winp<y.winp;
        }
        return x.win<y.win;
    }
    return x.val>y.val;
}
unordered_map<string,int>mp;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.flush();
    mp["Russia"]=1;
    mp["Finland"]=2;
    mp["Sweden"]=3;
    mp["NA"]=4;
    for(int i=1;i<=4;i++){
        nd[i].id=i;
    }
    string str1,str2;
    bool is=0;
    for(int i=1;i<=5;i++){
        if(!is)cin>>str1;
        else is=0;
        cin>>str2;
        int x,y;
        cin>>x>>y;
        string tmp1=str1;
        string tmp2=str2;
        if(x<y)swap(tmp1,tmp2);
        cin>>str1;
        if(str1!="OT"){
            is=1;
            nd[mp[tmp1]].val+=2;
            nd[mp[tmp1]].win++;
            nd[mp[tmp1]].winp++;
            nd[mp[tmp1]].dif+=x-y;
            nd[mp[tmp1]].goal+=x;

            nd[mp[tmp2]].dif+=y-x;
            nd[mp[tmp2]].goal+=y;
            nd[mp[tmp2]].val++;
        }
        else{
            nd[mp[tmp1]].val+=2;
            nd[mp[tmp1]].win++;
            nd[mp[tmp1]].dif+=x-y;
            nd[mp[tmp1]].goal+=x;

            nd[mp[tmp2]].dif+=y-x;
            nd[mp[tmp2]].goal+=y;
        }
    }
    if(!is)cin>>str1;
    cin>>str2;
    sort(nd+1,nd+4+1,cmp);
    int pos=1;
    while(nd[pos].id!=1)pos++;
    
    system("pause");
    return 0;
}