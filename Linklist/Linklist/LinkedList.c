#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include "linkedList.h"
int main(){
	LinkedList *L=malloc(sizeof(LinkedList));//ָ��ṹ��ָ���ָ��
	InitList(L);
	printf("%d\n", (*L)->data);
}

Status InitList(LinkedList *L){
	*L = (LinkedList)malloc(sizeof(LNode));
	if (*L == NULL){
		printf("����ʧ�ܣ�\n");
		return ERROR;
	}
	(*L)->next = NULL;
	(*L)->data = 0;
	printf("�����ɹ�\n");
	return SUCCESS;
}

void DestroyList(LinkedList L){
	LNode *p;//�ӵ�ǰ��Ҫɾ���Ľ����ָ�����һ���
	while (L){//L��ΪNULL��һֱ�ͷŽ��
		p = L->next;
		free(L);
		L = p;
	}
}

Status InsertList(LNode *p, LNode *q){
	if (p == NULL)
		return ERROR;
	q->next = p->next;
	p->next = q;
	return SUCCESS;
}


//Status DeleteList(LNode *p, ElemType *e){
//	if (p == NULL)
//		return ERROR;
//	if (p->next == NULL)
//		return ERROR;
//	LNode *q;
//	q = p->next;
//	*e = q->data;
//	p->next = q->next;
//	free(q);
//	return SUCCESS;
//}

//Status DeleteList(LNode *p, ElemType *e){
//	if (p == NULL)
//		return ERROR;
//	if (p->next == NULL)
//		return ERROR;
//	LNode *q;
//	q = p->next;
//	*e = q->data;
//	p->next = q->next;
//	free(q);
//	return SUCCESS;
//}

//void TraverseList(LinkedList L, void(*visit)(ElemType e)){
//	LNode *p;
//	p = L->next;
//	while (p){
//		visit(p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//
//void printf(ElemType e){
//	printf("%d ", e);
//}
//
//Status SearchList(LinkedList L, ElemType e){
//	if (L == NULL)
//		return ERROR;
//	if (L->next == NULL)
//		return ERROR;
//	LNode *p;
//	p= L->next;
//	while (p){
//		if (p->data == e)
//			return SUCCESS;
//		p = p->next;
//	}
//	return ERROR;
//}
//
//int ListLength(LinkedList L){
//	int length = 0;//Ĭ�ϳ���Ϊ0,ͷָ�벻�Ƴ���
//	LNode *p = L;//�����ƶ�ָ���ʼ��ָ��ͷ���
//	while (p->next != NULL){
//		p = p->next;
//		length++;//���ȼ�1
//	}
//	return length;
//}