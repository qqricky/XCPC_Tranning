/*
【算法介绍】
Splay叫做伸展树，是一种二叉搜索树，也可以说是一种平衡树结构。
其可以维护节点的左右次序值，也就是说，我们在Splay上做中序遍历的次序输出节点，得到的便是所有节点的左右次序。
【数据结构】
int ch[N][2], fa[N];	//节点的链接关系
int num[N], sz[N];		//节点个数与子树大小
1，anc定义为该平衡树实际上的根，然而其中并不存放任何信息，初始有const anc = 0
2，#define rt ch[anc][0] 为该平衡树逻辑上的根
3，#define keynode ch[ch[rt][1]][0] 为逻辑根的右儿子的左儿子，可以方便我们做一系列操作
【基本操作】
1，int newnode(int val) 新建节点，给节点赋予初值val
2，int D(int x) 返回x是其父节点的哪个儿子
3，void setc(int x, int y, int d) 设置x的d号儿子为y
4，void rotate(int x) 旋转使得x与其父节点交换位置，然而其左右关系保持不变
5，void splay(int x) 把节点x旋转到anc的左儿子位置，即rt位置。该操作的旋转特性使得总复杂度维持在log级别
有了这5个操作，我们可以在不改变中序遍历的条件下改变子孙关系了。
【查找插入操作】
然而，splay的节点除了父子关系外，还具有权值v[]。
如果，v[]只是其先后次序的离散化映射，那么，我们便可以在这个二叉搜索树上查询某个值val在树的哪个节点上。
splay是一棵可以快速动态维护的二叉搜索树.
所以我们还可以在树上查找权值所对应的节点：find(val)；可以在树上ins(val)
平衡树上的查找操作，除了find()
还有查找最左元素void first()，查找最右元素void last()，以及查找第k小操作void kth()
【高级区间操作】
在这些基础操作之上，我们可以实现一些高级的Splay的区间操作
1，void del(x) 把x节点删除
实现方法：先把x转到rt，再把左子树放到rt，再把右子树放到左子树的右子树位置
2，void segment(l, r) 把[l,r]区间都转到keynode的位置
{ splay(kth(l - 1), anc); splay(kth(r + 1), rt); return keynode; }
实现方法：先把第l-1个节点转到anc的儿子（左儿子）位置，即rt位置。这时[l,n]的所有节点都在rt的右子树上。
然后	再把第r+1个节点转到rt的儿子（右儿子）位置，这时[l,r]的所有节点都在第r+1号节点的左儿子处，即keynode位置。
3，void split(l, r) 把区间[l,r]删除
实现方法：先调用seg4，void inspos(int x, int pos) 把子树x插入到pos位置的右侧
实现方法：先调用segment(pos+1,pos)使得位于rt,pos+1位于rt的右儿子位置(ch[rt][1]位置)
这时ch[rt][1]的左儿子为空，直接把x插入到该位置即可
【修改相关操作】
除了我们需要实现位置的变更以外，有时还需要用splay做区间修改操作。
区间修改操作为了保证复杂度的要求，一定会需要用到延迟标记。
然而，这里的延迟标记与线段树的不同
线段树的延迟标记是位于实际并不存在的虚拟段节点上
而Splay的延迟标记则是切切实实放在某个具体节点上的。
如果一个节点具有延迟性的标记，那么意味着，在其整棵子树上，都应该生效其影响。
于是，我们需要有pushdown()和pushup()的函数
什么时候需要pushdown()?
在我们改变父子关系（即splay操作）的时候，需要对父与子都各自做一次pushdown()
在我们改变做子树遍历查找的时候，因为这里涉及到reverse操作，所以也需要pushdown()
什么时候需要pushup()?
setc()的时候需要做pushup()，而且这个pushup()需要一直延续到根（即rt位置）
【Debug相关操作】
我们还可以通过一定函数实现方便的Debug
有两个问题——
1，左右顺序是我们定的，与val无关
2，左右顺序是由val决定的
*/
#include <bits/stdc++.h>
using namespace std;
#define MP(x,y) make_pair(x,y)
#define ll long long
template <class T1, class T2>inline void gmax(T1 &a, T2 b) { if (b>a)a = b; }
template <class T1, class T2>inline void gmin(T1 &a, T2 b) { if (b<a)a = b; }
const int N = 1e5 + 10, M = 0, mod = 1e9 + 7, INF = 0x3f3f3f3f;
int casenum, casei;
int n, m;
 
//Splay模板
struct SPT
{
	int ch[N][2], fa[N];	//节点的结构状况
	int num[N], sz[N];		//节点个数与子树大小
	int v[N];				//节点权值
	int rev[N], ad[N];		//节点标记信息
	int ID;
	const int anc = 0;
#define rt ch[anc][0]
#define keynode ch[ch[rt][1]][0]
	//基本点操作：单点初始化
	void clear(int x)
	{
		ch[x][0] = ch[x][1] = fa[x] = 0;
		sz[x] = rev[x] = ad[x] = 0;
	}
 
	//基本点操作，从内存池中创建新节点
	int newnode(int val)
	{
		int x = ++ID; clear(x);
		v[x] = val;
		num[x] = sz[x] = 1;
		return x;
	}
 
	//基本点操作：返回当前节点是父节点的第几个儿子
	int D(int x)
	{
		return ch[fa[x]][1] == x;
	}
 
	//基本点操作：设置x的d号儿子为y
	void setc(int x, int y, int d)
	{
		ch[x][d] = y;
		if (y)fa[y] = x;
		if (x)pushup(x);
	}
 
	//区间操作转为点操作：对x的左右子树做反转
	void reverse(int x)
	{
		if (x == 0)return;//Necessary
		swap(ch[x][0], ch[x][1]);
		rev[x] ^= 1;
	}
 
	//区间操作转为点操作：对x的子树做加权
	void add(int x, int val)
	{
		if (x == 0)return;
		v[x] += val;
		ad[x] += val;
	}
 
	//基本点操作：把x的信息从子节点处更新
	void pushup(int x)
	{
		sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + num[x];
	}
 
	//基本点操作：把x的延迟标记向下打
	void pushdown(int x)
	{
		if (x == 0)return;
		if (rev[x])
		{
			reverse(ch[x][0]);
			reverse(ch[x][1]);
			rev[x] = 0;
		}
		if (ad[x])
		{
			add(ch[x][0], ad[x]);
			add(ch[x][1], ad[x]);
			ad[x] = 0;
		}
	}
 
	//内存池初始化
	void init()
	{
		ID = 0; clear(0);
	}
 
	//旋转操作：旋转使得节点x与其父节点交换位置
	void rotate(int x)
	{
		int f = fa[x];
		int ff = fa[f];
		bool d = D(x);
		bool dd = D(f);
		setc(f, ch[x][!d], d);	//第一步：把与x原父节点同方向的子树取作原父节点f的子树
		setc(x, f, !d);			//第二步：使与x原父节点同方向的子树连接原父节点f
		setc(ff, x, dd);		//第三步：使得x替代原父节点f，变为新父节点点ff的子树
	}
 
	//旋转操作：把节点x旋转到anc的左儿子位置，即rt位置。
	void splay(int x, int anc = 0)
	{
		if (x == 0)return;
		while (fa[x] != anc)
		{
			//pushdown(fa[fa[x]]);
			pushdown(fa[x]);
			pushdown(x);
			if (fa[fa[x]] != anc)rotate(D(x) == D(fa[x]) ? fa[x] : x);
			rotate(x);
		}
	}
 
	//查找操作：查找权值为val的节点。查找不到返回0；查找到返回相应节点编号，并把该节点旋转为根节点
	int find(int val)
	{
		int x = rt;
		while (1)
		{
			if (x == 0)return 0;
			if (val == v[x]) { splay(x); return x; }
			bool d = val > v[x];
			x = ch[x][d];
		}
		splay(x);
	}
	//插入操作：插入权值为val的节点。并把节点旋转为根节点
	void ins(int val)
	{
		int x = find(val);
		if (x)
		{
			num[x] += 1;
			sz[x] += 1;
			return;
		}
		int fa = anc;
		x = rt;
		bool d = 0;
		while (x)
		{
			fa = x;
			d = val > v[x];
			x = ch[x][d];
		}
		x = newnode(val);
		setc(fa, x, d);
		splay(x);
	}
 
	//查找操作：返回子树x下最小节点（rev延迟标记与此同时生效）
	int first(int x)
	{
		pushdown(x);
		while (ch[x][0])x = ch[x][0], pushdown(x);
		return x;
	}
 
	//查找操作：返回子树x下最大节点（rev延迟标记与此同时生效）
	int last(int x)
	{
		pushdown(x);
		while (ch[x][1])x = ch[x][1], pushdown(x);
		return x;
	}
 
	//查找操作：返回树中第k小的节点（延迟标记与此同时生效）
	int kth(int k)
	{
		//++k;	//这里涉及到区间操作，我们在左右界各添加新节点，因此进入时要++k
		int x = rt;
		//assert(sz[x] >= k);
		while (1)
		{
			pushdown(x);
			if (sz[ch[x][0]] >= k)x = ch[x][0];
			else if (sz[ch[x][0]] + num[x] >= k)return x;
			else
			{
				k -= sz[ch[x][0]] + num[x];
				x = ch[x][1];
			}
		}
	}
    //查找操作 ：返回x的排名
    inline int find_rank(int x){
        int now=rt,ans=0;  
        while(1){  
            if (x<v[now])  
            now=ch[now][0];
            else{  
                ans+=(ch[now][0]?sz[ch[now][0]]:0);
                if (x==v[now]){  
                    splay(now); return ans+1;  
                }  
                ans+=num[now];
                now=ch[now][1];  
            }  
        }  
    }

	//查找操作：返回树中[l,r]区间段的根节点
	int segment(int l, int r)
	{
		splay(kth(l - 1), anc);
		splay(kth(r + 1), rt);
		return keynode;
	}
 
	//删除操作：删除节点x。先把其旋转为根，然后合并左右子树
	void del(int x)
	{
		splay(x);//转到根后便不再需要pushdown()
		if (ch[x][0] == 0)setc(anc, ch[x][1], 0);	//如果没有左子树，则直接把右子树放到树根
		else
		{
			setc(anc, ch[x][0], 0);					//第一步：把左子树放到树根
			splay(last(ch[x][0]), anc);				//第二步：把左子树最大节点转到树根
			setc(rt, ch[x][1], 1);					//第三步：把右子树接到树根上
		}
	}
 
	//分离操作：把[l,r]区间段从树中分离
	int split(int l, int r)
	{
		int x = segment(l, r); fa[x] = 0;
		setc(ch[rt][1], 0, 0);
		pushup(rt);
		return x;
	}

	//合并操作，把子树x插入到pos位置的右侧
	void inspos(int x, int pos)
	{
		segment(pos + 1, pos);	//使得pos位于根，pos+1位于根的右子树
		setc(ch[rt][1], x, 0);
		pushup(rt);
	}
 
	//遍历操作：中序遍历以x为根的子树
	void print(int x)
	{
		if (ch[x][0])print(ch[x][0]);
        cout<<"node:"<<v[x]<<' '<<"leftson:"<<v[ch[x][0]]<<" rightson:"<<v[ch[x][1]]<<endl;
		//printf("(节点%d)(左儿子%d)(右儿子%d)(子树大小%d)\n", x, ch[x][0], ch[x][1], sz[x]);
		if (ch[x][1])print(ch[x][1]);
	}
 
	//画树程序
	const int diF[20] = { 0,10,9,8,7,6,5,4,3,2,1 };
	char mp[20][200];
	int ln[20];
	int maxdep;
	void draw(int x, int dep, int pos, int anc = 0)
	{
		//pushdown(x);
		gmax(maxdep, dep);
		int d = diF[dep]; if (ch[x][0] == 0 || ch[x][1] == 0)d = 3;
		if (ch[x][0])draw(ch[x][0], dep + 1, pos - d, anc);
		//print information
		while (ln[dep] < pos - 1)mp[dep][ln[dep]++] = ' ';
		int tmp = v[x];
		if (tmp < 0)mp[dep][ln[dep]++] = '-', tmp = -tmp;
		if (tmp >= 10)mp[dep][ln[dep]++] = tmp / 10 + 48; mp[dep][ln[dep]++] = tmp % 10 + 48;
		//print information
		if (ch[x][1])draw(ch[x][1], dep + 1, pos + d, anc);
	}
	void DRAW()
	{
		memset(ln,0,sizeof(ln));
		memset(mp,0,sizeof(mp));
		maxdep = 1;
		draw(rt, 1, 40);
		for (int i = 1; i <= maxdep; ++i)puts(mp[i]);
		puts("");
	}
 
	//具体程序的函数实现——
	void add(int l, int r, int val)
	{
		int x = segment(l, r);
		add(x, val);
		splay(x);
	}
 
	void reverse(int l, int r)
	{
		int x = segment(l, r);
		reverse(x);
		splay(x);
	}

    void solve()
    {
        init();

    }
	/*合并两棵平衡树
	void merge(int anc1, int anc2)
	{
	int rt1 = ch[anc1][0];
	int rt2 = ch[anc2][0];
	if (sz[rt1] > sz[rt2]) swap(rt1, rt2), swap(anc1, anc2);
	f[anc1] = anc2;	//不要忘了集合合并
	int tim = sz[rt1];
	while (tim--)
	{
	int x = ch[anc1][0];
	del(x, anc1);
	setc(x, 0, 0);
	setc(x, 0, 1);
	ins(v[x], num[x], anc2);
	}
	}*/
}spt;

 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
	
    //system("pause");
	return 0;
}
/*
【题目总结】
HDU4453
[题意]
有一个圆环，圆环上有一个指针，指针位置设置为1号位置，其余位置按照顺时针方向标记为2~x号位置
圆环上每个点有一个权值，指针位置可能发生顺时针逆时针变化，节点状态也有所修改。让你动态维护这个过程。
[分析]
如果没有插入删除操作，我们可以用线段树实现。
然而，在存在插入删除的条件下，加上有指针的位移操作，我们用Splay解决问题
需要实现Splay的——
1，区间加（add(1, k2, val)）
2，区间翻转（reverse(1, k1)）
3，单点插入（inspos(newnode(val), 1)）
4，单点删除（del(kth(1))）
5，单点移动（split(p,p)，inspos()）
6，单点询问（v[kth(1)]）
*/
 