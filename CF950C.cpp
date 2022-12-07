#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int cnt=0;
vector<int>ans[N];
queue<int>q0,q1,q2;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    string str;
    cin>>str;
    bool flag=1;
    for(int i=0;i<str.size();i++){
        if(str[i]=='1'&&(q0.size()+q2.size())==0){
            flag=0;
            break;
        }
        if(str[i]=='1'){
            if(q0.size()){
                int tmp=q0.front();
                q0.pop();
                ans[tmp].push_back(i+1);
                q1.push(tmp);
            }
            else{
                int tmp=q2.front();
                q2.pop();
                ans[tmp].push_back(i+1);
                q1.push(tmp);
            }
        }
        else{
            if(q1.size()){
                int tmp=q1.front();
                q1.pop();
                ans[tmp].push_back(i+1);
                q2.push(tmp);
            }
            else{
                q0.push(++cnt);
                ans[cnt].push_back(i+1);
            }
        }
    }
    if(!flag||q1.size()){
        cout<<-1;
    }
    else{
        cout<<cnt<<'\n';
        for(int i=1;i<=cnt;i++){
            cout<<ans[i].size()<<' ';
            for(int val:ans[i]){
                cout<<val<<' ';
            }
            cout<<'\n';
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}