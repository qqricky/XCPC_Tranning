#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int acu[1070];
map<int,int>mp;
int h,m;
int ck(int x,int y)
{
    int a=0;
    int b=0;
    int xx=x;
    int yy=y;
    while(x){
        if(mp[x%10]==0&&(x%10)!=0)return 0;
        a=a*10+mp[x%10];
        x/=10;
    }
    while(y){
        if(mp[y%10]==0&&(y%10)!=0)return 0;
        b=b*10+mp[y%10];
        y/=10;
    }
    if(xx<10)a*=10;
    if(yy<10)b*=10;
    if(b<=h-1&&a<m)return 1;
    else return 0;
}
// string tf(int x,int len)
// {
//     string a;
//     while(x){
//         if(mp[x%10]==0&&(x%10)!=0)return 0;
//         a=a+mp[x%10];
//         x/=10;
//         len--;
//     }
//     if(len)
// }
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    mp[1]=1;
    mp[2]=5;
    mp[5]=2;
    mp[8]=8;
    mp[0]=0;
    while(t--)
    {
        cin>>h>>m;
        map<int,ll>tmp;
        int pos=0;
        for(int i=0;i<h;i++){
            for(int j=0;j<m;j++){
                if(ck(i,j)){
                    acu[++pos]=i*m+j;
                    tmp[i*m+j]=i*1000+j;
                    //cout<<i<<":"<<j<<endl;
                }
            }
        }
        sort(acu+1,acu+pos+1);
        char ch;
        int x,y;
        cin>>x>>ch>>y;
        int val=x*m+y;
        int poss=lower_bound(acu+1,acu+pos+1,val)-acu;
        // if(poss==1){
        //     if(acu[poss]-val<val){
        //          cout<<tmp[acu[pos]]/1000<<':'<<tmp[acu[pos]]%1000<<endl;
        //     }
        //     else{
        //         cout<<"00:00"<<endl;
        //     }
        // }
        if(poss>pos){
            // if(h*m-val<val-acu[pos]){
            //     cout<<"00:00"<<endl;
            // }
            // else{
            //     cout<<tmp[acu[pos]]/1000<<':'<<tmp[acu[pos]]%1000<<endl;
            // }
            cout<<"00:00"<<endl;
        }
        else{
            // if(val-acu[poss-1]<acu[poss]-val){
            //     cout<<tmp[acu[poss-1]]/1000<<':'<<tmp[acu[poss-1]]%1000<<endl;
            // }
            // else{
            //     cout<<tmp[acu[poss]]/1000<<':'<<tmp[acu[poss]]%1000<<endl;
            // }
            if(tmp[acu[poss]]/1000<10)cout<<'0'<<tmp[acu[poss]]/1000;
            else cout<<tmp[acu[poss]]/1000;
            cout<<":";
            if(tmp[acu[poss]]%1000<10)cout<<'0'<<tmp[acu[poss]]%1000<<endl;
            else cout<<tmp[acu[poss]]%1000<<endl;
        }
    }
    //system("pause");
    return 0;
}