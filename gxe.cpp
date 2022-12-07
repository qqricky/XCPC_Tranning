#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string a[N];
struct node
{
    int id;
    string pf,sf;
}nd[N];
int ans[N];
bool cmp1( string &s1, string &s2){
    if(s1.size()==0||s2.size()==0)return 1;
    for(int j=0;j<min(s1.size(),s2.size());j++){
        if(s1[j]!=s2[j]){
            return s1[j]<s2[j];
        }
    }
    if(s1.size()<=s2.size())return 1;
    else return 0;
}
bool cmp(node a,node b){
    return cmp1(a.pf,b.pf);
}
bool can(string &s1,string &s2){
    if(s2.size()>s1.size())return 0;
    for(int j=0;j<s2.size();j++){
        if(s1[j]!=s2[j])return 0;
    }
    return 1;
}
map<string,int>num;
void add(int pos){
    for(int i=0;i<a[pos].size();i++){
        num[a[pos].substr(i,a[pos].size()-i)]++;
        // cout<<"   :--->"<<a[pos].substr(i,a[pos].size()-i)<<endl;
    }
}
void sub(int pos){
    for(int i=0;i<a[pos].size();i++){
        num[a[pos].substr(i,a[pos].size()-i)]--;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    a[0]="adjskfjklasdjkf";
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=q;i++){
        cin>>nd[i].pf>>nd[i].sf;
        nd[i].id=i;
    }
    sort(a+1,a+n+1,cmp1);
    sort(nd+1,nd+q+1,cmp);
    int l=1,r=1;
    while(r<=n&&!can(a[r],nd[1].pf))r++;
    l=r;
    for(int i=1;i<=q;i++){
        if(!can(a[r-1],nd[i].pf)){
            while(r<=n&&!can(a[r],nd[i].pf)){
                add(r);
                r++;
            }
        }        
        while(r<=n&&can(a[r],nd[i].pf)){
            add(r);
            r++;
        }
        while(l<r&&!can(a[l],nd[i].pf)){
            sub(l);
            l++;
        }
        // cout<<i<<' '<<nd[i].id<<' '<<l<<' '<<r<<endl;
        ans[nd[i].id]=num[nd[i].sf];
    }
    for(int i=1;i<=q;i++){
        cout<<ans[i];
        if(i!=q)cout<<'\n';
    }
    cout.flush();
    // system("pause");
    return 0;
}