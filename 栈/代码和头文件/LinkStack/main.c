#define _CRT_SECURE_NO_WARNINGS 1
#include "LinkStack.h"

int main(){
	LinkStack *s;
	s = (LinkStack*)malloc(sizeof(StackNode));
	ElemType *e = (ElemType*)malloc(sizeof(ElemType));
	int *length = (int *)malloc(sizeof(int));
	ElemType data = 0;
	menu();
	while (1){
		printf("�����������");
		int k = getchar();
		getchar();
		switch (k){
		case '1':
			initLStack(s);
			break;
		case '2':
			isEmptyLStack(s);
			break;
		case '3':
			getTopLStack(s, e);
			break;
		case '4':
			clearLStack(s);
			break;
		case '5':
			destroyLStack(s);
			break;
		case '6':
			LStackLength(s, length);
			break;
		case '7':
			printf("��������ջԪ�أ�");
			scanf("%d", &data);
			getchar();
			pushLStack(s, data);
			break;
		case '8':
			popLStack(s, e);
			break;
		default:
			printf("û�и�ѡ�������ѡ��\n");
			break;
		}

	}
}