#include <stdio.h>
#include <stdlib.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode;


void merge(LNode *A,LNode *B)
{
    LNode *C=(struct LNode*)malloc(sizeof(struct LNode));
    LNode *p=A->next;
    LNode *q=B->next;
    LNode *r;
    C=A;
    C->next=NULL;
    r=C;
    while(p!=NULL&&q!=NULL)
    {
        if(p->data<=q->data)
        {
            r->next->data=p->data;
            p=p->next;
            r=r->next;
        }
        else
        {
            r->next=q;
            r->next->data=q->data;
            q=q->next;
            r=r->next;
        }
    }
    r->next=(p!=NULL?p:q);
    while(C->next!=NULL)
    {
        printf("%d ",C->next->data);
        C=C->next;
    }
}

int main()
{
    struct LNode *one;
    struct LNode *two;
    struct LNode *three;
    LNode *A=(struct LNode*)malloc(sizeof(struct LNode));
    A->next=NULL;
    one=A;
    LNode *B=(struct LNode*)malloc(sizeof(struct LNode));
    B->next=NULL;
    two=B;

    int temp;
    while(scanf("%d",&temp))
    {
        struct LNode* s=(struct LNode*)malloc(sizeof(struct LNode));
        s->data=temp;
        one->next=s;
        s->next=NULL;
        one=s;
        if(getchar()!=' ')
            break;

    }
    one=A;
    while(scanf("%d",&temp))
    {
        struct LNode* f=(struct LNode*)malloc(sizeof(struct LNode));
        f->data= temp;
        two->next=f;
        f->next=NULL;
        two=f;
        if(getchar()!=' ')
            break;

    }
    two=B;
    merge(one,two);
    system("pause");
    return 0;
}