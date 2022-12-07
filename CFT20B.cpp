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
struct node
{
    int h;
    string m;
    bool isAm;
    int cnt;
    void add(int hh){
        h+=hh;
        while(h>=12){
            if(!isAm){
                cnt++;
            }
            h-=12;
            isAm^=1;
        }
        while(h<0){
            if(isAm){
                cnt--;
            }
            h+=12;
            isAm^=1;
        }
    }
};

map<string,int>tmm;
void init(){
    tmm["Washington"]=-5;
    tmm["London"]=0;
    tmm["Moscow"]=3;
    tmm["Beijing"]=8;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    node nd;
    char _;
    string str;
    init();
    for(int t=1;t<=T;t++){
        string str1,str2;
        cin>>nd.h>>_>>nd.m>>str;
        nd.cnt=0;
        if(str=="AM")nd.isAm=1;
        else nd.isAm=0;
        if(nd.h==12)nd.h=0;
        //cout<<nd.isAm<<endl;
        cin>>str1>>str2;
        nd.add(tmm[str2]-tmm[str1]);
        cout<<"Case "<<t<<": ";
        if(nd.cnt==0)cout<<"Today ";
        else if(nd.cnt==1)cout<<"Tomorrow ";
        else cout<<"Yesterday ";
        if(nd.h==0)nd.h=12;
        cout<<nd.h<<':'<<nd.m<<' ';
        if(nd.isAm)cout<<"AM";
        else cout<<"PM";
        cout<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}