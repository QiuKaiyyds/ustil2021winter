#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
typedef struct BiTNode {
	ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
void CreateBiTree(BiTree* T) {
	ElemType ch;
	scanf_s("%c", &ch);
	getchar();
	if (ch == '#')
		*T = NULL;
	else {
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}
void operation2(ElemType ch, int level) {
	printf("%c�ڵ�", ch);
	printf("%d��", level);
}
void PreOrderTraverse(BiTree T, int level) {
	if (T == NULL)
		return;
	operation2(T->data, level);
	PreOrderTraverse(T->lchild, level + 1);
	PreOrderTraverse(T->rchild, level + 1);
}
void InOrderTraverse(BiTree T, int level) {
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild, level + 1);
	operation2(T->data, level);
	InOrderTraverse(T->rchild, level + 1);
}
void PostOrderTraverse(BiTree T, int level) {
	if (T == NULL)
		return;
	PostOrderTraverse(T->lchild, level + 1);
	PostOrderTraverse(T->rchild, level + 1);
	operation2(T->data, level);
}
int main() {
	int level = 1;
	int c = 0;
	BiTree T = NULL;
	printf("����ʽ����������:");
	CreateBiTree(&T);
	printf("�ݹ�ǰ��������Ϊ��\n");
	PreOrderTraverse(T, level);
	printf("\n");
	printf("�ݹ�����������Ϊ��");
	InOrderTraverse(T, level);
	printf("\n");
	printf("�ݹ����������Ϊ��");
	PostOrderTraverse(T, level);
	printf("\n");
	return 0;
}