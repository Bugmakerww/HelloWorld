#define _CRT_SECURE_NO_WARNINGS 1
#include "LinkStack.h"

void menu(){
	printf("1. 初始化\n");
	printf("2. 判断栈是否为空\n");
	printf("3. 取栈顶元素\n");
	printf("4. 清空栈\n");
	printf("5. 销毁栈\n");
	printf("6. 栈长度\n");
	printf("7. 入栈\n");
	printf("8. 出栈\n");
}

Status initLStack(LinkStack *s){
	s->top = NULL;
	s->count = 0;
	printf("初始化成功！\n");
	return SUCCESS;
}

Status isEmptyLStack(LinkStack *s){
	if (s->top == NULL)
	{
		printf("栈为空\n");
		return SUCCESS;
	}
	else
	{
		printf("栈不为空\n");
		return SUCCESS;
	}
}

Status getTopLStack(LinkStack *s, ElemType *e){
	if (s->top == NULL){
		printf("栈顶为空！\n");
		return ERROR;
	}
	else{
		*e = s->top->data;
		printf("栈顶元素数据为：%d\n", *e);
		return SUCCESS;
	}
}

Status clearLStack(LinkStack *s){
	StackNode *n = NULL;
	if (s->top == NULL){
		printf("空栈，无需清除\n");
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
		printf("清空成功！\n");
		return SUCCESS;
	}
}

Status destroyLStack(LinkStack *s){
	StackNode *n = NULL;
	if (s->top == NULL){
		printf("空栈，无需销毁\n");
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
		printf("销毁成功！\n");
		return SUCCESS;
	}
}

Status LStackLength(LinkStack *s, int *length){
	printf("栈长为%d\n", s->count);
	return SUCCESS;
}

Status pushLStack(LinkStack *s, ElemType data){
	StackNode *n = NULL;
	n = (StackNode*)malloc(sizeof(StackNode));
	n->data = data;
	n->next = s->top;
	s->top = n;
	s->count++;
	printf("入栈成功！\n");
	return SUCCESS;
}

Status popLStack(LinkStack *s, ElemType *data){
	StackNode *n = NULL;
	if (s->top == NULL){
		printf("空栈，无法出栈！\n");
		return ERROR;
	}
	else{
		*data = s->top->data;
		n = s->top;
		s->top = n->next;
		free(n);
		printf("出栈成功！\n出栈元素为：%d\n", *data);
		s->count--;
		return SUCCESS;
	}
}