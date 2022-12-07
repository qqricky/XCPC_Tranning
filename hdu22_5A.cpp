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
int num1[7],num2[7];
int num[7];
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        set<int>s1,s2,s;
        memset(num1,0,sizeof(num1));
        memset(num2,0,sizeof(num2));
        memset(num,0,sizeof(num));
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            num1[x]++;
            num[x]++;
            s.insert(x);
            s1.insert(x);
        }
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            num2[x]++;
            num[x]++;
            s2.insert(x);
            s.insert(x);
        }
        if(s1.size()==n){
            for(auto x:s1){
                num1[x]--;
                num[x]--;
            }
        }
        if(s1.size()==1){
            for(int x:s1){
                num1[x]++;
                num[x]++;
            }
        }
        if(s2.size()==n){
            for(int x:s2){
                num2[x]--;
                num[x]--;
            }
        }
        if(s2.size()==1){
            for(int x:s2){
                num2[x]++;
                num[x]++;
            }
        }
        if(s1.size()==n&&s2.size()==n){
            cout<<"Just a game of chance.\n";
        }else{
            cout<<"Win!\n";        
            // for(int i=1;i<=6;i++){
            //     int x=num[i];
            //     if(i!=1)x+=num1[1];
            //     bool can=1;
            //     for(int j=1;j<=6;j++){
            //         int y=num[j];
            //         if(j!=1)y+=num[1];
            //     }
            // }
        }
        /*
        if(s1.size()==1){
            if(s2.size()==1&&(*s2.begin()>*s1.begin())){
                cout<<"Just a game of chance.\n";
            }else{
                cout<<"Win!\n";
            }
        }else if(s1.size()==n){
            cout<<"Just a game of chance.\n";
        }else if(s2.size()==n){
            cout<<"Win!\n";
        }else{
            bool flag=0;
            for(int i=1;i<=6;i++){
                int x=num1[i];
                if(i!=1)x+=num1[1];
                bool is=0;
                for(int j=i+1;j<=6;j++){
                    int y=num2[j]+num2[1];
                    if(i==1)y-=num2[1];
                    if(num2[j]==n){
                        y=num2[j]+1;
                    }
                    if(y>=x){
                        is=1;
                    }
                }
                if(!is){
                    flag=1;
                }
            }
            if(flag){
                cout<<"Win!\n";
            }else{
                cout<<"Just a game of chance.\n";
            }
        }
        */
    }
    // cout.flush();
    // system("pause");
    return 0;
}