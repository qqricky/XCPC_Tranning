#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
vector<int>num[30];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str1,str2;
    while(cin>>str1>>str2)
    {
        for(int i=str2.length()-1;i>=0;i--){
            num[str2[i]-'a'].push_back(i);
        }
        vector<int>s1;
        for(int i=0;i<str1.length();i++){
            for(int j=0;j<num[str1[i]-'a'].size();j++){
                s1.push_back(num[str1[i]-'a'][j]);
            }
        }
        if(s1.empty()){
            cout<<0<<endl;
            continue;
        }
        vector<int>tmp;
        tmp.push_back(s1[0]);
        for(int i=1;i<s1.size();i++){
            if(s1[i]>tmp[tmp.size()-1])tmp.push_back(s1[i]);
            else{
                int k=lower_bound(tmp.begin(),tmp.end(),s1[i])-tmp.begin();
                tmp[k]=s1[i];
            }
        }
        cout<<tmp.size()<<endl;
        for(int j=0;j<=26;j++)num[j].clear();
    }
    //system("pause");
    return 0;
}