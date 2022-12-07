#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int a[620];
int p[820];
int d[620];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        memset(p,0,sizeof(p));
        memset(a,0,sizeof(a));
        cin>>n;
        int tmp;
        for(int i=1;i<=n;i++){
            cin>>tmp;
            a[tmp]++;
        }
        int pos=0;
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]){
                if(a[i]&1){
                    if((i-a[i]/2)>pos){
                        for(int j=i-a[i]/2;j<=i+a[i]/2;j++){
                            p[j]=i;
                        }
                        pos=i+a[i]/2;
                    }
                    else{
                        for(int j=pos+1;j<=pos+a[i];j++){
                            p[j]=i;
                        }
                        pos+=a[i];
                    }
                }
                else{
                    if(i-a[i]/2>pos){
                        for(int j=i-a[i]/2;j<=i+a[i]/2-1;j++){
                            p[j]=i;
                        }
                        pos=i+a[i]/2-1;
                    }
                    else if(i-a[i]/2+1>pos){
                        for(int j=i-a[i]/2+1;j<=i+a[i]/2;j++){
                            p[j]=i;
                        }
                        pos=i+a[i]/2;
                    }
                    else{
                        for(int j=pos+1;j<=pos+a[i];j++){
                            p[j]=i;
                        }
                        pos+=a[i];
                    }
                }
            }
        }
        // for(int i=1;i<=n;i++){
        //     if(a[i]==0)continue;
        //     if(pos<i-a[i]+1){
        //         for(int j=i;j>=i-a[i]+1;j--){
        //             p[j]=i;
        //         }
        //         pos=i;
        //     }
        //     else{
        //         for(int j=pos+1;j<=pos+a[i];j++){
        //             p[j]=i;
        //         }
        //         pos+=a[i];
        //     }
        // }
        for(int j=1;j<=2*n;j++){
                if(p[j]==0)continue;
                if(p[j]!=p[j+1]){
                    int x=p[j];
                    int kk=j;
                    int k=j-a[x];
                    while(k>0&&abs(x-k)<abs(x-kk)){
                        if(p[k]==0){
                            p[k]=x;
                            p[kk]=0;
                            k--;
                            kk--;
                        }
                        else if()
                        else{
                            k--;
                        }
                    }
                }
            }
        for(int i=1;i<=2*n;i++){
            //cout<<p[i]<<' ';
            if(p[i])cnt+=abs(i-p[i]);
        }
        cout<<cnt<<"\n";
    }
    //cout.flush();
    //system("pause");
    return 0;
}