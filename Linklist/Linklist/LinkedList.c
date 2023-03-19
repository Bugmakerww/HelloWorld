#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include "linkedList.h"
int main(){
	LinkedList *L=malloc(sizeof(LinkedList));//指向结构体指针的指针
	InitList(L);
	printf("%d\n", (*L)->data);
}

Status InitList(LinkedList *L){
	*L = (LinkedList)malloc(sizeof(LNode));
	if (*L == NULL){
		printf("创建失败！\n");
		return ERROR;
	}
	(*L)->next = NULL;
	(*L)->data = 0;
	printf("创建成功\n");
	return SUCCESS;
}

void DestroyList(LinkedList L){
	LNode *p;//接当前需要删除的结点所指向的下一结点
	while (L){//L不为NULL，一直释放结点
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
//	int length = 0;//默认长度为0,头指针不计长度
//	LNode *p = L;//定义移动指针初始化指向头结点
//	while (p->next != NULL){
//		p = p->next;
//		length++;//长度加1
//	}
//	return length;
//}