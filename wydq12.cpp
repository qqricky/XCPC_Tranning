#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
typedef struct LNode{
	int data;
	struct LNode* next;
}LNode,*LinkList;

void CreateList(LinkList &L,int length);
void PrintList(LinkList &L);
void MoveToFront(LinkList &L);
/*void CreateList(LinkList &L,int length){
	//新建表头 
	L=(LinkList)malloc(sizeof(struct LNode));
	L->next=NULL;
	//使用尾插法创建链表,tail为链表尾 
	LinkList tail=L;
	int val;
	for(int i=0;i<length;i++){
		scanf("%d",&val);

		LinkList add=(LinkList)malloc(sizeof(struct LNode));
		add->data=val;
		
		add->next=tail->next;
		tail->next=add;
		tail=add;
	}
}*/
void Init_LinkList(LinkList& L) {
	L = (LinkList)malloc(sizeof(LNode));
    assert(L!=NULL);
	(L)->next = NULL;
}
void CreateList(LinkList &L){
    //创建一个指向Lnode的指针数组p并分配内存,长度为length+2,start from 1
    //p[length+1]指向NULL
    cout<<"请输入所需链表长度"<<endl;
    int length;
    cin>>length;
    cout<<endl<<"请输入每个元素的值，以空格隔开，无行末空格"<<endl;
    LNode *p=(LNode *)malloc((length+2)*sizeof(LNode));
    for(int i=1;i<=length;++i){
        (p+i)->next=(p+i+1);
        scanf("%d",&((p+i)->data));
    }
    (p+length)->next=NULL;
    L->next=p+1;
}
    /*
        原来每个节点需要三次指针修改操作，现只需要一次
    */
    
void PrintList(LinkList &L){
	LinkList now=L->next;
	while(now!=NULL){
		printf("%d ",now->data);
		now=now->next;
	}
}
/*void MoveToFront(LinkList &L){
	LinkList now=L;
	LinkList MinElement=L;
	while(now->next != NULL){
		if(now->next->data < MinElement->next->data){
			MinElement=now;
		}
		now=now->next;
	}
	/*
	int temp=L->next->data;
	L->next->data=MinElement->next->data;
	MinElement->next->data=temp;
	
	if(MinElement==L)
		return;
	else if(MinElement==L->next){
		LinkList old=MinElement->next->next;
		
		L->next=MinElement->next;
		L->next->next=MinElement;
		MinElement->next=old;
		
	}
	else{
		LinkList old=L->next->next;
		
		L->next->next=MinElement->next->next;
		MinElement->next->next=old;
		old=MinElement->next;
		MinElement->next=L->next;
		L->next=old;
	}
	
}*/

void MoveToFront(LinkList &L){
	LinkList now=L;
	LinkList MinElementPre=L;
    if(L->next==NULL)return;
    int minn=0x3f3f3f3f;//1e9
	while(now->next != NULL){
		if(minn > now->next->data){
            minn=now->next->data;
			MinElementPre=now;
		}
		now=now->next;
	}
    LinkList MinNode=MinElementPre->next;
    MinElementPre->next=MinNode->next;
    MinNode->next=L->next;
    L->next=MinNode;
}

void update(LinkList &L){
	int pos,val;
	cout<<"请输入要修改的元素下表，（表头下标为0且不存值"<<endl;
	cin>>pos>>val;
	cout<<endl;
	LinkList now=L;
	for(int i=1;i<=pos;i++){
		now=now->next;
	}
	now->data=val;
}
void addNode(LinkList &L){
	int num;
	LinkList ed=L->next;
	while(ed->next!=NULL){
		ed=ed->next;
	}
	cout<<"请输入要增加的长度"<<endl;
	cin>>num;
	cout<<endl<<"请输入每个元素的值，以空格隔开，无行末空格"<<endl;
	LNode *p=(LNode *)malloc((num+2)*sizeof(LNode));
    for(int i=1;i<=num;++i){
        (p+i)->next=(p+i+1);
        scanf("%d",&((p+i)->data));
    }
    (p+num)->next=NULL;
    ed->next=p+1;
}
int main(){
	LinkList a=NULL;
    Init_LinkList(a);
	CreateList(a);
	addNode(a);
	update(a);
	MoveToFront(a);
	PrintList(a);
    //system("pause");
	return 0;
}