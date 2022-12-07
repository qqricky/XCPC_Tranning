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
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    bool flag=0;
    string str1,str2;
    cin>>str1>>str2;
    if(str1.length()!=str2.length()+1){
        cout<<0;
        return 0;
    }
    bool f1=1,f2=1;
    for(int i=0;i+1<str1.length();i++){
        if(str1[i]!=str1[i+1]){
            f1=0;
        }
    }
    for(int i=0;i+1<str2.length();i++){
        if(str2[i]!=str2[i+1]){
            f2=0;
        }
    }
    if(f1&&f2&&str1[0]==str2[0]){
        cout<<str1.length()<<'\n';
        for(int i=1;i<=str1.length();i++){
            cout<<i<<' ';
        }
        return 0;
    }
    vector<int>pos;
    for(int i=0,j=0;i<str1.length(),j<str2.length();i++,j++){
        if(str1[i]!=str2[j]){
            if(i!=str1.length()-1 && str1[i+1]!=str2[j]){
                cout<<0;
                return 0;
            }
            if(flag){
                cout<<0;
                return 0;
            }
            else{
                flag=1;
                for(int k=i;k>=0;k--){
                    if(str1[k]==str1[i]){
                        pos.push_back(k+1);
                    }
                    else{
                        break;
                    }
                }
                i++;
            }
        }
    }
    if(!flag){
        for(int k=str1.length()-1;k>=0;k--){
            if(str1[k]==str1[str1.length()-1]){
                pos.push_back(k+1);
            }
            else{
                break;
            }
        }
    }
    cout<<pos.size()<<'\n';
    reverse(pos.begin(),pos.end());
    for(int i:pos)cout<<i<<' ';
    cout.flush();
    //system("pause");
    return 0;
}