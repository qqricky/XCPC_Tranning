#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int MAXN=1e5+10; 
using namespace std;
char s[MAXN];

struct Node{
    int sum, len;//统计每个回文串的出现次数, len表示当前节点回文串的长度
    Node *fail, *ch[26];//每个节点的儿子, fail如上所述

    Node() {}
}tr[MAXN];

Node *last;
int ncnt;//ncnt表示节点数，last表示当前节点

Node *New(int len) {//新建一个节点
    tr[ncnt].len = len;
    tr[ncnt].fail = &tr[0];
    for (int i = 0; i < 26; i++) tr[ncnt].ch[i] = &tr[0];
    return &tr[ncnt++];
}

Node *GetFail(Node *pre, int now) {//跳fail指针
    while (s[now - pre->len - 1] != s[now]) pre = pre->fail;
    return pre;
}

void Build() {
    ncnt = 2;//tr[0] tr[1]为奇数根和偶数根 ,其他节点从2开始
    tr[0].len = 0; tr[1].len = -1;//初始化，如上所述
    tr[0].fail = &tr[1]; tr[1].fail = &tr[0];//初始化，如上所述
    for (int i = 0; i < 26; i++) tr[0].ch[i] = tr[1].ch[i] = &tr[0];
    last = &tr[0];
    for (int i = 1; s[i]; i++) {
        if(i>1){
            int num=0;
            Node *tmp=last;
            while(tmp->fail!=&tr[1]){
                num++;
                tmp=tmp->fail;
            }
            cout<<num<<' ';
            s[i]=(s[i]-97+num)%26+97;
        }
        Node *cur = GetFail(last, i);//从当前节点开始，找到可扩展的节点
        if (cur->ch[s[i] - 'a'] == &tr[0]) {//没有这个儿子
            Node *now = New(cur->len + 2);//新建节点
            now->fail = GetFail(cur->fail, i)->ch[s[i] - 'a'];//找到最长回文后缀
            cur->ch[s[i] - 'a'] = now;//父子相认
        }
        last = cur->ch[s[i] - 'a'];//更新last
        last->sum++;//顺带求出每个回文串的出现次数
    }
}

int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    int n;
    n=strlen(s);
    cout<<n<<endl;
    Build();
    cout.flush();
    system("pause");
    return 0;
}