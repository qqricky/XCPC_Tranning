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
char ne[N];
char st[N];
char ed[N];
void init(){
    for(int i=32;i<=126;i++){
        st[i]=ed[i]=i;
        ne[i]=i+1;
    }
    ne[' ']='0';
    ne['9']='A';
    ne['Z']='a';
    st['0']='!';
    st['A']=':';
    st['a']='[';
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    string str;
    getline(cin,str);
    set<char>s;
    for(char ch : str){
        s.insert(ch);
    }
    string rev;
    if(s.count(' ')==0){
        rev+=' ';
    }
    for(char ch='0';ch<='9';ch++){
        if(s.count(ch)==0){
            rev+=ch;
        }
    }
    for(char ch='A';ch<='Z';ch++){
        if(s.count(ch)==0){
            rev+=ch;
        }
    }
    for(char ch='a';ch<='z';ch++){
        if(s.count(ch)==0){
            rev+=ch;
        }
    }
    string ans1,ans2;
    sort(str.begin(),str.end());
    sort(rev.begin(),rev.end());
    int pos1=unique(str.begin(),str.end())-str.begin();
    int pos2=unique(rev.begin(),rev.end())-rev.begin();
    str=str.substr(0,pos1);
    rev=rev.substr(0,pos2);
    // for(char ch:rev){
    //     cout<<ch;
    // }
    // cout<<endl;
    int l=0;
    for(int i=0;i<(int)str.length()-1;i++){
        if(ne[str[i]]!=str[i+1]){
            int r=i;
            //cout<<l<<' '<<r<<endl;
            if(r-l+1==2){
                ans1+=str[l];
                ans1+=str[r];
            }
            else if(r-l+1==1){
                ans1+=str[l];
            }
            else{
                ans1+=st[str[l]];
                ans1+='-';
                ans1+=str[r];
            }
            l=i+1;
        }
    }
    int r=str.length()-1;
    if(r-l+1==2){
        ans1+=str[l];
        ans1+=str[r];
    }
    else if(r-l+1==1){
        ans1+=str[l];
    }
    else{
        ans1+=st[str[l]];
        ans1+='-';
        ans1+=str[r];
    }
    //-----------------------------------------------
    l=0;
    for(int i=0;i<(int)rev.length()-1;i++){
        if(ne[rev[i]]!=rev[i+1]){
            int r=i;
            if(r-l+1==2){
                ans2+=rev[l];
                ans2+=rev[r];
            }
            else if(r-l+1==1){
                ans2+=rev[l];
            }
            else{
                ans2+=st[rev[l]];
                ans2+='-';
                ans2+=rev[r];
            }
            l=i+1;
        }
    }
    if(!rev.empty()){
        r=rev.length()-1;
        if(r-l+1==2){
            ans2+=rev[l];
            ans2+=rev[r];
        }
        else if(r-l+1==1){
            ans2+=rev[l];
        }
        else{
            ans2+=st[rev[l]];
            ans2+='-';
            ans2+=rev[r];
        }
    }
    ans2='^'+ans2;
    if(ans2=="^"){
        ans2+='!';
    }
    // cout<<"\n";
    // cout<<ans1<<endl;
    // cout<<ans2<<endl;
    // cout<<endl;
    cout<<"%[";
    if(ans1.size()<ans2.size()){
        cout<<ans1;
    }
    else if(ans1.size()>ans2.size()){
        cout<<ans2;
    }
    else{
        if(ans1<=ans2){
            cout<<ans1;
        }
        else{
            cout<<ans2;
        }
    }
    cout<<"]";
    cout.flush();
    //system("pause");
    return 0;
}