#include<stdio.h>
#include<stdlib.h>
#define N 20
typedef struct tree {
	char ch;
	struct tree* lchild;
	struct tree* rchild;
}Bitree;
Bitree* CreateTree() {
	Bitree* bt;
	char str;
	scanf_s("%c", &str);
	if (str == '#')
		return 0;
	else {
		bt = (Bitree*)malloc(sizeof(Bitree));
		bt->ch = str;
		bt->lchild = CreateTree();
		bt->rchild = CreateTree();
		return bt;
	}
}
void PreOrder(Bitree* bt) {
	Bitree** s;
	Bitree* p;
	int top = -1;
	s = (Bitree**)malloc((N + 1) * sizeof(Bitree*));
	s[++top] = bt;
	while (top != -1) {
		p = s[top--];
		printf("%c", p->ch);
		if (p->rchild)
			s[++top] = p->rchild;
		if (p->lchild)
			s[++top] = p->lchild;
	}free(s);
}
void InOrder(Bitree* bt) {
	Bitree** s;
	Bitree* p, * q;
	int top = -1;
	s = (Bitree**)malloc((N + 1) * sizeof(Bitree*));
	if (bt) {
		while (bt) {
			s[++top] = bt;
			bt = bt->lchild;
		}
		while (top != -1) {
			p = s[top--];
			printf("%c", p->ch);
			while (p->rchild) {
				s[++top] = p->rchild;
				q = p->rchild;
				while (q->lchild) {
					s[++top] = q->lchild;
					q = q->lchild;
				}break;
			}
		}
	}
}
void PostOrder(Bitree* bt) {
	Bitree** s;
	Bitree* p;
	int top = -1;
	s = (Bitree**)malloc((N + 1) * sizeof(Bitree*));
	do {
		while (bt) {
			s[++top] = bt;
			bt = bt->lchild;
		}
		p = 0;
		while (top != -1) {
			bt = s[top];
			if (bt->rchild == p) {
				printf("%c", bt->ch);
				top--;
				p = bt;
			}
			else {
				bt = bt->rchild;
				break;
			}
		}
	} while (top != -1);
}
int main() {
	printf("����˳�����������:\n");
	Bitree* btr = CreateTree();
	printf("ǰ������ǵݹ�ʵ�֣�\n");
	PreOrder(btr);
	printf("\n");
	printf("��������ǵݹ�ʵ�֣�\n");
	InOrder(btr);
	printf("\n");
	printf("��������ǵݹ�ʵ�֣�\n");
	PostOrder(btr);
	printf("\n");
	return 0;
}