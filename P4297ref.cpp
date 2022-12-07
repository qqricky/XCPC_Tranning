#include<cstdio>
#include<algorithm>

const int maxn=555555;

char s[maxn];
int cnt,last;
int trans[maxn];
int son[maxn][26];
int len[maxn],fail[maxn];

int new_node(int length)
{
    len[++cnt]=length;
    return cnt;
}

int get_fail(int pre,int now)
{
    while(s[now-len[pre]-1]!=s[now])
        pre=fail[pre];
    return pre;
}

void build_PAM()
{
    cnt=1,last=0;
    len[0]=0,len[1]=-1;
    fail[0]=1,fail[1]=1;
    for(int i=1;s[i];i++)
    {
        int cur=get_fail(last,i);
        if(!son[cur][s[i]-'a'])
        {
            int now=new_node(len[cur]+2);
            fail[now]=son[get_fail(fail[cur],i)][s[i]-'a'];
            son[cur][s[i]-'a']=now;
            //顺带求出trans指针 
            if(len[now]<=2) trans[now]=fail[now];
            else
            {
                int tmp=trans[cur];
                while(s[i-len[tmp]-1]!=s[i]||((len[tmp]+2)<<1)>len[now]) tmp=fail[tmp];
                //注意拓展后的长度为len[tmp]+2
                trans[now]=son[tmp][s[i]-'a'];
            }
        }
        last=son[cur][s[i]-'a'];
    }
}

int n,ans;

int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    build_PAM();
    for(int i=2;i<=cnt;i++)//枚举所有节点
        if(((len[trans[i]]<<1)==len[i]&&len[trans[i]]%2==0))
            ans=std::max(ans,len[i]);//更新答案
    printf("%d\n",ans);
    system("pause");
    return 0;
}