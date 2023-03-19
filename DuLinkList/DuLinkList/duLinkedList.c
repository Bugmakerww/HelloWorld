#define _CRT_SECURE_NO_WARNINGS 1
#include "duLinkedList.h"
#include<stdio.h>
void print(ElemType e);
int main(){
	DuLinkedList *L = malloc(sizeof(DuLinkedList));


}

Status InitList_DuL(DuLinkedList *L){
	*L = (DuLinkedList)malloc(sizeof(DuLNode));
	if (*L == NULL){
		printf("初始化失败！\n");
		return ERROR;
	}
	(*L)->prior = NULL;
	(*L)->next = NULL;
	return SUCCESS;
}

void DestroyList_DuL(DuLinkedList *L){
	DuLNode *p;
	while (p){
		p = (*L)->next;
		free(*L);
		*L = p;
		if (p)
			p->prior = NULL;//p不为空，断开与前驱结点的连接
	}
}

Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q){
	if (p == NULL)
		return ERROR;
	DuLNode *b = p->prior;//p的前驱结点
	if (b)
		b->next = q;//a不为空，其后驱结点为q
	q->next = p;
	q->prior = b;
	p->prior = q;
	return SUCCESS;
}

Status InsertAfterList_DuL(DuLNode *p, DuLNode *q){
	if (p == NULL)
		return ERROR;
	DuLNode *a = p->next;//p的后驱结点
	if (a)
		a->prior = q;//a不为空，其前驱结点为q
	q->prior = p;
	q->next = a;
	p->next = q;
	return SUCCESS;
}

Status DeleteList_DuL(DuLNode *p, ElemType *e){
	if (p == NULL||p->next==NULL)
		return ERROR;
	DuLNode *q = p->next;
	*e = q->data;
	p->next = q->next;//p指向q的后驱结点
	q->next->prior = p;//q的后驱结点的前驱结点指向p
	free(q);
	return SUCCESS;
}

void TraverseList_DuL(DuLinkedList L, void(*visit)(ElemType e)){
	DuLNode *p = L->next;
	while (p){
		visit(p->data);
		p = p->next;
	}
	printf("\n");
}

void print(ElemType e){
	printf("%d ", e);
}
