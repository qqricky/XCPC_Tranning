#include <iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<stack>
using namespace std;
struct Node
{
	bool isnum;
	int val;//-1 if it's a variable
	char c;
	Node *lchild,*rchild;
};
stack<Node*>Stack;
Node *exp1;//表达式1
void converse(Node *t,char s)
{
	if(s<'0'||s>'9')
	{
		t->isnum=0;
		t->val=-1;
		t->c=s;
	}
	else
	{
		t->isnum=1;
		t->c='#';
		t->val=s-'0';
	}
}
//将表达式1与表达式二合并，并将合并后的树根设置为表达式1的根指针。
void CompoundExpr(Node (*&tree1),Node (*&tree2),char s){
	Node * newroot;
	newroot=new Node;
	newroot->lchild=tree1;
	newroot->rchild=tree2;
	newroot->isnum=0;
	newroot->val=-1;
	newroot->c=s;
	tree1=newroot;
}
//比较运算符优先级
bool Cmp(char c1,char c2)
{
	if((c1=='^'||c1=='*'||c1=='-'||c1=='+'||c1=='/')&&(c2=='^'||c2=='*'||c2=='-'||c2=='+'||c2=='/'))
	{
		if(c1=='^')
		{
			if(c2!='^') return 1;
			else return 0;
		}
		else if(c1=='*'||c1=='/')
		{
			if(c2=='^'||c2=='*'||c2=='/') return 0;
			else return 1;
		}
		else return 0;
	}
	else return 0;
}
//读入表达式
void ReadExpr(Node (*&tree),string &str,int len)
{
	Node *p,*q;
	tree=new Node;
	tree->lchild=NULL;
	tree->rchild=NULL;
	if(len==1)
		converse(tree,str[0]);
	else 
	{
		converse(tree,str[0]);
		q=tree;
		Stack.push(tree);
        Stack.push(tree);
		for(int i=1;i<len&&!Stack.empty();i++)
		{
			p=new Node;
			converse(p,str[i]);
			p->lchild=NULL;
			p->rchild=NULL;
			if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='^') 
			{
				if(!q->lchild)	
				{
					q->lchild=p;
					Stack.push(p);
					q=p;
				}
				else	
				{
                    //cout<<q->c<<"->rc "<<p->c<<endl;
					q->rchild=p;
					Stack.push(p);
					q=p;
				}
			}
			else
			{
				if(!q->lchild)	
				{
					q->lchild=p;
                    //cout<<q->c<<"->lc "<<p->c<<endl;
                    if(!Stack.empty()){
					    q=Stack.top();
                        Stack.pop();
                    }
				}
				else	
				{
					q->rchild=p;
                    //cout<<q->c<<" ->rc "<<p->c<<endl;
                    if(!Stack.empty()){
					    q=Stack.top();
                        Stack.pop();
                    }
				}
			}
		}
	}
}	
 
void WriteExpr(Node *Tree)
{
	if(Tree!=NULL)
	{
        //if(Tree->c=='\0')cout<<"wtf"<<endl;
        // cout<<(Tree->c)<<"\\\\\\\\"<<(Tree->val)<<endl;
        // cout<<Tree->lchild<<endl;
		if(Tree->lchild&&!Tree->lchild->isnum)
		{
			if(Cmp(Tree->c,Tree->lchild->c)) 
			{
				cout<<"(";
				WriteExpr(Tree->lchild);
				cout<<")";
			}
			else
				WriteExpr(Tree->lchild);			
		}
		else
			WriteExpr(Tree->lchild);				
			
		if(Tree->isnum)
		{
			cout<<Tree->val;
		}
		else
			cout<<Tree->c;
			
		if(Tree->rchild&&!Tree->rchild->isnum)
		{
			if(Cmp(Tree->c,Tree->rchild->c))
			{
				cout<<"(";
				WriteExpr(Tree->rchild);
				cout<<")";
			
			}
			else 
				WriteExpr(Tree->rchild);
		}
		else 
			WriteExpr(Tree->rchild);
	}
}
//为变量赋值
void Assign(Node *Tree,char V,int c,int *flag)
{
	if(Tree)
	{
		if(Tree->isnum==false&&Tree->c==V)
		{
			Tree->isnum=true;
			Tree->val=c;
			*flag=1;
		}
		Assign(Tree->lchild,V,c,flag);
		Assign(Tree->rchild,V,c,flag);
	}
}
//检查表达式是否有确定的值
int Check(Node *Tree)
{
	if(Tree&&Tree->isnum==0)
	{		
		if(Tree->c!='*'&&Tree->c!='^'&&Tree->c!='-'&&Tree->c!='+'&&Tree->c!='/')return 0;
		if(Check(Tree->lchild)&&Check(Tree->rchild)){
			return 1;
		}
        else{
            return 0;
        }
	}
    return 1;
}
//快速幂
int pow_q(int x,int y){
    int ans=1;
    while(y){
        if(y&1)ans*=x;
        y>>=1;
        x*=x;
    }
    return ans;
}
//计算值
int Calc(int n1,char opr,int n2)
{
	int res;
	switch(opr)
	{
		case '+':
			res=n1+n2;
			return res;
			break;
		case '-':
			res=n1-n2;
			return res;
			break;
		case '*': 
			res=n1*n2;
			return res;
			break;
		case '/':
			res=n1/n2;
			return res;
			break;
		case '^':
			res=pow_q(n1,n2);
			return res;
			break;
		default:break;
	}
}
//计算整个表达式的值
int Value(Node *Tree)
{
	if(Tree)
	{
		if(!Tree->lchild&&!Tree->rchild&&Tree->isnum) return (Tree->val);
		return Calc(Value(Tree->lchild),Tree->c,Value(Tree->rchild));
	}
}
int main()
{
    //解决windows终端中文乱码问题
    #if defined(_WIN16) || defined(_WIN32) || defined(_WIN64)
        // change code page，use utf-8
        system("chcp 65001");
    #endif
	string str;//存前缀表达式
	int n;
	while(1)
	{
		cout<<"请输入前缀表达式"<<endl;
		cin>>str;
		n=str.length();
		ReadExpr(exp1,str,n);
        //cout<<exp1->c<<endl;
        cout<<"它的中缀表达式是"<<endl;
        WriteExpr(exp1);
        cout<<endl;
        int s=0,Assign_flag=0,t=Check(exp1);
        while(!t)
        {
			int c;char V;
			cout<<"表达式中存在变量未赋值！"<<endl;
			cout<<"请输入要赋值的值：";	
			cin>>V;
			cout<<endl;
			cout<<"请输入要将赋值为：";	
			cin>>c;
			cout<<endl;
			Assign(exp1,V,c,&Assign_flag);
			if(Assign_flag)	
			{
				cout<<"赋值成功!"<<endl;
			}
			else
			{
				cout<<"表达式里没有"<<V<<",请重新输入!"<<endl;
			}
            t=Check(exp1);
        }
        cout<<"整个表达式赋值成功!"<<endl;
        cout<<"表达式为:";
        WriteExpr(exp1);
        cout<<endl;
        int res=Value(exp1);
        cout<<"算数表达式的值为: ";
        WriteExpr(exp1);
        cout<<"="<<res<<endl;
	}
}