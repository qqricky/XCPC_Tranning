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