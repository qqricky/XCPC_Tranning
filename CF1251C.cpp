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
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        queue<int>q1,q2;
        string str;
        cin>>str;
        for(char x:str){
            int num=x-'0';
            if(num&1)q1.push(num);
            else q2.push(num);
        }
        while((!q1.empty()) || (!q2.empty())){
            if(q1.empty()){
                cout<<q2.front();
                q2.pop();
            }
            else if(q2.empty()||q1.front()<q2.front()){
                cout<<q1.front();
                q1.pop();
            }
            else{
                cout<<q2.front();
                q2.pop();
            }
        }
        cout<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}