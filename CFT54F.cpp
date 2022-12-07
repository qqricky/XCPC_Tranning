#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
using namespace std;
unsigned ll has[1000000+10];
unsigned long long base=1331;
unsigned ll pp[1000000+10]; 
ll gcd(ll a,ll b){
    return b ? gcd(b,a%b) : a;
}
bool fun(string str,int cha){
	unsigned ll fun1=0;
	int i;
	for(i=0;i<str.size();i++){
		fun1=fun1*base+str[i];
	}
	unsigned ll tmp;
	for(i=0;i<str.size();i++){
		if(i!=0)tmp=has[i-1+str.size()]-has[i-1]*pp[str.size()];
		else tmp=has[i-1+str.size()];
		unsigned ll funn=fun1;

		if(funn==tmp&& (i)%(gcd(cha,str.length()))==0)return true;
        if(funn==tmp&& (str.length()-i)%(gcd(cha,str.length()))==0)return true;
	}
	return false;
}
string work(string str,int l){
	string ans;
	int i;
	for(i=l-1;i>=0;i--){
		ans.push_back(str[i]);
	}
	for(i=(int)str.size()-1;i>=l;i--){
		ans.push_back(str[i]);
	}
	return ans;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int jj;
    pp[0]=1;
	for(jj=1;jj<=1e6+1;jj++)pp[jj]=pp[jj-1]*base; 
    while(t--){
    	string str1,str2;
    	cin>>str1>>str2;
    	int l,r;
    	cin>>l>>r;
        if(l>r)swap(l,r);
        int n=str1.length();
    	int cha=abs((n-r)-(r-l));
    	str1=str1+str1;
    	int i;
    	for(i=0;i<str1.size();i++){
    		if(i==0){
    			has[i]=str1[i];
			}
			else{
				has[i]=has[i-1]*base+str1[i];
			}
		}	
		if(fun(str2,cha)){
			cout<<"yes\n";
			continue;
		}
		cout<<"no\n";
	}
    cout.flush();
    // system("pause");
}
