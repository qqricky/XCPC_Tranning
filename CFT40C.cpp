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
int x[N],c[N];
vector<int>tp;
vector<pair<char,int> >v;
vector<pair<char,int>>k;
vector<pair<char,int>>s;
unordered_map<int,char>to;
string solve(int num){
    if(num==1)return "0";
    string res;
    int val;
    while(num){
        val=num%16;
        num/=16;
        res=res+to[val];
    }
    reverse(res.begin(),res.end());
    return res;
}
bool ck(int val){
    while(val>1){
        if(val%16>0)return 0;
        val/=16;
    }
    return 1;
}
bool vis=0;
int poss;
void print(){
    string ans;
    for(auto pr:v){
        string tmp=solve(pr.second);
        cout<<pr.first;
        if(tmp!="0")cout<<tmp;
    }
    cout<<'\n';
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;
    to[0]='0';
    for(char ch='1',i=1;ch<='9';i++,ch++){
        to[i]=ch;
    }
    for(char ch='A',i=10;ch<='F';i++,ch++){
        to[i]=ch;
    }
    while(cin>>str){
        v.clear(),k.clear(),s.clear();
        tp.clear();
        char ch=str[0];
        int cnt=1;
        str=str+'G';
        for(int i=1;i<str.length();i++){
            if(str[i]!=str[i-1]){
                if(cnt==1){
                    int pos=v.size();
                    k.push_back(make_pair(str[i-1],pos));
                    tp.push_back(1);
                }
                else{
                    if(ck(cnt)){
                        int pos=v.size();
                        k.push_back(make_pair(str[i-1],pos));
                        tp.push_back(0);
                    }
                }
                v.push_back(make_pair(str[i-1],cnt));
                cnt=1;
                ch=str[i];
            }
            else{
                cnt++;
            }
        }
        if(k.size()){
            for(int j=0;j<k.size();j++){
                if(j==k.size()-1){
                    if(tp[j]==1){
                        v.erase(v.begin()+k[j].second);
                    }
                    else{
                        v[k[j].second].second--;
                    }
                    break;
                }
                if(k[j].first>v[k[j].second+1].first){
                    if(tp[j]==1){
                        v.erase(v.begin()+k[j].second);
                    }
                    else{
                        continue;
                        v[k[j].second].second--;
                        break;
                    }
                    break;
                }
            }
        }
        else{
            // if(s.size()){
            //     for(int j=0;j<s.size();j++){
            //         if(j==s.size()-1){
            //             v[s[j].second].second--;
            //             break;
            //         }
            //         if(s[j].first>v[s[j].second+1].first){
            //             v[s[j].second].second--;
            //             break;
            //         }
            //     }
            // }
            v[0].second--;
        }
        print();
        //cout<<endl;
    }
    cout.flush();
    //system("pause");
    return 0;
}