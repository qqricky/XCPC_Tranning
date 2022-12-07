#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
unordered_map<string,int>du;
map<string,vector<string> >mp;
unordered_map<string,int>lev;
set<string>s;
vector<string>ans[100000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<string>last;
    vector<string>now;
    for(int i=1;i<=n;i++){
        string str;
        cin>>str;
        str+='.';
        int pre=0;
        for(int i=0;i<str.length();i++){
            if(str[i]=='.'){
                now.push_back(str.substr(pre,i-pre));
                pre=i+1;
            }
        }
        for(auto ss:now){
            s.insert(ss);
            // cout<<ss<<' ';
        }
        // cout<<'\n';
        if(now.size()!=last.size()){
            last=now;
            now.clear();
            continue;
        }
        int pos=0;
        while(now[pos]==last[pos])pos++;
        //cout<<"!   "<<i<<' '<<pos<<'\n';
        //cout<<last[pos]<<"<"<<now[pos]<<'\n';
        mp[last[pos]].push_back(now[pos]);
        du[now[pos]]++;
        last=now;
        now.clear();
    }
    queue<string>q;
    for(auto ss:s){
        if(du[ss]==0){
            lev[ss]=0;
            q.push(ss);
            ans[0].push_back(ss);
        }
    }
    while(q.size()){
        auto ss=q.front();
        q.pop();
        for(auto to:mp[ss]){
            du[to]--;
            if(du[to]==0){
                lev[to]=lev[ss]+1;
                q.push(to);
                ans[lev[to]].push_back(to);
            }
        }
    }
    // cout<<ans[1].size()<<'\n';
    // for(auto what:ans[1]){
    //     cout<<what<<'\n';
    // }
    for(int i=0;i<100000;i++){
        if(ans[i].size()==0)break;
        sort(ans[i].begin(),ans[i].end());
        for(int j=0;j<ans[i].size()-1;j++){
            cout<<ans[i][j]<<'.';
            s.erase(ans[i][j]);
        }
        s.erase(ans[i][ans[i].size()-1]);
        cout<<ans[i][ans[i].size()-1];
        if(ans[i+1].size()!=0){
            cout<<'.';
        }
    }
    for(auto i:s){
        cout<<"."<<i;
    }
    cout<<'\n';
    cout.flush();
    //system("pause");
    return 0;
}