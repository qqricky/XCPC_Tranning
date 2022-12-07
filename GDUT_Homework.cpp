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
vector<int>f;
vector<int>sz;
vector<int>val;
vector<int>ma;
//初始化
void init(int n){
    f.clear();sz.clear(),val.clear(),ma.clear();
    sz.assign(n+1,1);
    f.push_back(0),val.push_back(0),ma.push_back(0);
    cout<<"请依次输入每个节点的值的大小"<<endl;
    for(int i=1;i<=n;i++){
        f.push_back(i);
        int x;
        cin>>x;
        val.push_back(x);
        ma.push_back(x);
    }
}
//路径压缩
int getfa(int x){
    return x==f[x] ? x : f[x]=getfa(f[x]);
}
//按秩合并同时处理附加信息
void merge(int x,int y){
    int xx=getfa(x),yy=getfa(y);
    if(xx==yy)return;
    if(xx<yy){
        f[xx]=yy;
        ma[yy]=max(ma[yy],ma[xx]);
        sz[yy]+=sz[xx];
    }
    else{
        f[yy]=xx;
        ma[xx]=max(ma[xx],ma[yy]);
        sz[xx]+=sz[yy];
    }
}
//询问两点是否在同一个集合当中
int ask(int x,int y){
    return(getfa(x)==getfa(y));
}
//询问某点所在集合所有元素值的最大值
int askMax(int x){
    return ma[getfa(x)];
}
int askSize(int x){
    return sz[getfa(x)];
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    #if defined(_WIN16) || defined(_WIN32) || defined(_WIN64)
        // change code page，use utf-8
        system("chcp 65001");
    #endif
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int inf;
    bool flag=1;
    while(inf=1){
        if(flag){
            flag=0;
            cout<<"请输入元素个数"<<endl;
            int n;
            cin>>n;
            init(n);
        }
        cout<<"请输入操作\n1,合并两集合\n2,询问两节点是否在同一集合\n3,"
        <<"询问某节点所在集合最大值\n4,查询集合大小\n5,退出"<<endl;
        int var;
        cin>>var;
        if(var==1){
            cout<<"请输入要合并的两个节点编号"<<endl;
            int x,y;
            cin>>x>>y;
            merge(x,y);
        }
        else if(var==2){
            cout<<"请输入两个要询问的节点"<<endl;
            int x,y;
            cin>>x>>y;
            cout<<(ask(x,y) ? "他们在同一个集合当中" : "他们不在同一个集合当中" )<<endl;
        }
        else if(var==3){
            cout<<"请输入要查询的节点编号"<<endl;
            int x;
            cin>>x;
            cout<<"该节点所在的集合内所有元素最大值为"<<askMax(x)<<endl;
        }
        else if(var==4){
             cout<<"请输入要查询的节点编号"<<endl;
            int x;
            cin>>x;
            cout<<"该节点所在的集合的大小为"<<askSize(x)<<endl;
        }
        else if(var==5){
            cout<<"goodbye"<<endl;
            break;
        }
        else{
            cout<<"输入无效，请重新输入"<<endl;
        }
    }
    cout.flush();
    system("pause");
    return 0;
}