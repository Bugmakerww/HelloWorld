#define _CRT_SECURE_NO_WARNINGS 1
#include "LinkStack.h"

void menu(){
	printf("1. ��ʼ��\n");
	printf("2. �ж�ջ�Ƿ�Ϊ��\n");
	printf("3. ȡջ��Ԫ��\n");
	printf("4. ���ջ\n");
	printf("5. ����ջ\n");
	printf("6. ջ����\n");
	printf("7. ��ջ\n");
	printf("8. ��ջ\n");
}

Status initLStack(LinkStack *s){
	s->top = NULL;
	s->count = 0;
	printf("��ʼ���ɹ���\n");
	return SUCCESS;
}

Status isEmptyLStack(LinkStack *s){
	if (s->top == NULL)
	{
		printf("ջΪ��\n");
		return SUCCESS;
	}
	else
	{
		printf("ջ��Ϊ��\n");
		return SUCCESS;
	}
}

Status getTopLStack(LinkStack *s, ElemType *e){
	if (s->top == NULL){
		printf("ջ��Ϊ�գ�\n");
		return ERROR;
	}
	else{
		*e = s->top->data;
		printf("ջ��Ԫ������Ϊ��%d\n", *e);
		return SUCCESS;
	}
}

Status clearLStack(LinkStack *s){
	StackNode *n = NULL;
	if (s->top == NULL){
		printf("��ջ���������\n");
		return ERROR;
	}
	else
	{
		while (s->top->next){
			n = s->top->next;
			free(s->top);
			s->top = n;
			s->count--;
		}
		printf("��ճɹ���\n");
		return SUCCESS;
	}
}

Status destroyLStack(LinkStack *s){
	StackNode *n = NULL;
	if (s->top == NULL){
		printf("��ջ����������\n");
		return ERROR;
	}
	else
	{
		while (s->top){
			n = s->top->next;
			free(s->top);
			s->top = n;
			s->count--;
		}
		printf("���ٳɹ���\n");
		return SUCCESS;
	}
}

Status LStackLength(LinkStack *s, int *length){
	printf("ջ��Ϊ%d\n", s->count);
	return SUCCESS;
}

Status pushLStack(LinkStack *s, ElemType data){
	StackNode *n = NULL;
	n = (StackNode*)malloc(sizeof(StackNode));
	n->data = data;
	n->next = s->top;
	s->top = n;
	s->count++;
	printf("��ջ�ɹ���\n");
	return SUCCESS;
}

Status popLStack(LinkStack *s, ElemType *data){
	StackNode *n = NULL;
	if (s->top == NULL){
		printf("��ջ���޷���ջ��\n");
		return ERROR;
	}
	else{
		*data = s->top->data;
		n = s->top;
		s->top = n->next;
		free(n);
		printf("��ջ�ɹ���\n��ջԪ��Ϊ��%d\n", *data);
		s->count--;
		return SUCCESS;
	}
}