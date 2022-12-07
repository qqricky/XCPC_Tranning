#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
int fb[12];
struct node
{
    int c;
    int t;
    int val;
    vector<int>lst;
    bool operator<(const node &y)const{
        if(c==y.c){
            if(t==y.c){
                if(lst==y.lst){
                    return val>y.val;
                }
                return lst<y.lst;
            }
            return t<y.t;
        }
        return c>y.c;
    }
}nd[1070];
int p[11];
int fashi[11]={};
int times[11]={};
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    cin.get();
    memset(fb,0x3f,sizeof(fb));
    for(int i=1;i<=10;i++){
        p[i]=i;
    }
    int mit=INF,mxt=0;
    n--;
    for(int i=1;i<=n;i++){
        string str;
        getline(cin,str);
        int cnt=1;
        int cntt=0;
        int pos=0;
        int tim=0;
        int tmp=INF;
        int tmpp=0;
        while(pos<str.size()){
        	if(str[pos]=='-'){
        		pos+=2;
        		continue;
			}
			nd[i].c++;
			cntt=0;
            tim=0;
			int j;
			for(j=pos;j<str.size();j++){
				if(str[j]==' ')break;
				tim=tim*10+str[j]-'0';
			}
			j++;
			for(;j<str.size();j++){
				if(str[j]==',')break;
				cntt=cntt*10+str[j]-'0';
			}
			pos=j+1;
            fb[cnt]=min(fb[cnt],tim);
            tmp=min(tim,tmp);
            tmpp=max(tmpp,tim);
            cnt++;
            nd[i].t+=tim+cntt*20;
            nd[i].lst.push_back(tim);
		}
        if(nd[i].c>0){
            mit=min(mit,tmp);
            mxt=max(mxt,tmpp);
        }
        sort(nd[i].lst.begin(),nd[i].lst.end());
        // cout<<"############";
        // cout<<str<<'\n';
        // cout<<i<<' '<<nd[i].c<<' '<<nd[i].t<<'\n';
    }
    string str;
    getline(cin,str);
    int cnt=1;
    int cntt=0;
    int pos=0;
    int tim=0;
    while(pos<str.size()){
        if(str[pos]=='-'){
            pos+=2;
            continue;
        }
        cntt=0;
        tim=0;
        int j;
        for(j=pos;j<str.size();j++){
            if(str[j]==' ')break;
            tim=tim*10+str[j]-'0';
        }
        j++;
        for(;j<str.size();j++){
            if(str[j]==',')break;
            cntt=cntt*10+str[j]-'0';
        }
        pos=j+1;
        times[cnt]=tim;
        fashi[cnt]=cntt;
        cnt++;
    }
    int ans=0;
    bool first=1;
    while(first || next_permutation(p+1,p+1+10)){
        first=0;
        int res=0;
        int tot=0;
        int sum=0;
        node me;
        int num=0;
        // cout<<"####\n";
        for(int j=1;j<=10;j++){
            int now=p[j];
            if(times[now]==0)continue;
            tot+=times[now];
            // cout<<now<<' '<<times[now]<<endl;
            if(tot>300){
                break;
            }
            num++;
            sum+=fashi[now]*20+tot;
            if(tot<=fb[now]){
                res+=800;
            }
            me.lst.push_back(now);
        }
        me.val=1;
        me.c=num;
        me.t=sum;
        if(num>0&&me.t<=mit){
            res+=700;
        }
        if(num>0&&me.t>=mxt){
            res+=500;
        }
        int rk=lower_bound(nd+1,nd+n+1,me)-nd-1;
        rk++;
        res+=5000/rk;
        int tmp=n/10;
        if(rk<=tmp){
            res+=1200;
        }else if(rk<=tmp*3){
            res+=800;
        }else if(rk<=tmp*6){
            res+=400;
        }
        ans=max(ans,res);
    }
    cout<<ans;
    // cout.flush();
    // system("pause");
    return 0;
}