#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;

map<string,string>f;
map<string,string>m;
map<string,int>gen;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s,s1,s2;
        char ge;
        cin>>s>>ge>>s1>>s2;
        if(s1!="-1")f[s]=s1;
        if(s2!="-1")m[s]=s2;
        if(ge=='M')gen[s]=1;
        else gen[s]=0;
    }
    cin>>n;
    for(int i=1;i<=n;i++){
        string s1,s2;
        map<string,int>tj;
        queue<string>q;
        int flag=0;
        cin>>s1>>s2;
        if(gen[s1]==gen[s2]){
            cout<<"Never Mind";
            goto paris;
        }
        q.push(s1);
        tj[s1]=1;
        while(q.size())
        {
            string tmp=q.front();
            q.pop();
            if(f[tmp]!=""){
                tj[f[tmp]]=tj[tmp]+1;
                if(tj[f[tmp]]<5)q.push(f[tmp]);
            }
            if(m[tmp]!=""){
                tj[m[tmp]]=tj[tmp]+1;
                if(tj[m[tmp]]<5)q.push(m[tmp]);
            }
        }
        q.push(s2);
        if(tj[s2]>0){
            cout<<"No";
            goto paris;
        }
        tj[s2]=1;
        while(q.size())
        {
            string tmp=q.front();
            q.pop();
            if(f[tmp]!=""){
                if(tj[f[tmp]]>0){
                    flag=1;
                    break;
                }
                tj[f[tmp]]=tj[tmp]+1;
                if(tj[f[tmp]]<5)q.push(f[tmp]);
            }
            if(m[tmp]!=""){
                if(tj[m[tmp]]>0){
                    flag=1;
                    break;
                }
                tj[m[tmp]]=tj[tmp]+1;
                if(tj[m[tmp]]<5)q.push(m[tmp]);
            }
        }
        if(flag)cout<<"No";
        else cout<<"Yes";
        paris:;
        if(i!=n)cout<<endl;
    }
    //system("pause");
    return 0;
}