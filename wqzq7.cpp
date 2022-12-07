#include <bits/stdc++.h>
#define ll long long
const int N=1e5+10; 
using namespace std;
int f[N],a[N];//a存题目输入的数组，
//f[i]表示从1点跳到i点所需要的最少步数
int main()
{
    memset(f,0x3f,sizeof(f));//f数组初始化为无穷大（一个很大的数）
    int n;//位置的个数
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    f[1]=0;//开始位于位置1所需代价为0
    for(int i=1;i<=n-1;i++){//枚举每一个位置
        for(int j=1;j<=a[i]&&i+j<=n;j++){
            f[i+j]=min(f[i+j],f[i]+1);//如果从当前位置跳到位置i+j比其他到i+j
            //的方案更优，就用此方案+1更新i+j的方案
        }
    }
    cout<<f[n]<<endl;//输出答案
    system("pause");
    return 0;
}