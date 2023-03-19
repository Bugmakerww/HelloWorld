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
		printf("��ʼ��ʧ�ܣ�\n");
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
			p->prior = NULL;//p��Ϊ�գ��Ͽ���ǰ����������
	}
}

Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q){
	if (p == NULL)
		return ERROR;
	DuLNode *b = p->prior;//p��ǰ�����
	if (b)
		b->next = q;//a��Ϊ�գ���������Ϊq
	q->next = p;
	q->prior = b;
	p->prior = q;
	return SUCCESS;
}

Status InsertAfterList_DuL(DuLNode *p, DuLNode *q){
	if (p == NULL)
		return ERROR;
	DuLNode *a = p->next;//p�ĺ������
	if (a)
		a->prior = q;//a��Ϊ�գ���ǰ�����Ϊq
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
	p->next = q->next;//pָ��q�ĺ������
	q->next->prior = p;//q�ĺ�������ǰ�����ָ��p
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
