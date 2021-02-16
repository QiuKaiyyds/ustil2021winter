#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
//创建链表
struct Node* creatlist() {
	struct Node* headNode = (struct Node *)malloc(sizeof(struct Node));
	headNode->next = NULL;
	return headNode;
}
//创建节点
struct Node* createNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
};
//插入
void insert(struct Node* headNode,int data) {
	struct Node* newNode = createNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}
void delete(struct Node* headNode) {
	struct Node* NextNode = headNode->next;
	headNode->next = NextNode->next;
	free(NextNode);
}
struct Node* searchResult(struct Node* headNode, int data)
{
	struct Node* pMove = headNode->next;
	while (pMove != NULL && pMove->data != data)
	{
		pMove = pMove->next;
	}
	return pMove;
}

//打印
void printList(struct Node* headNode) {
	struct Node* pMove = headNode->next;
	while (pMove) {
		printf("%d\t",pMove->data);
		pMove = pMove->next;
	}
	puts("");
}

struct stack {
	int stackSize;
	struct Node* stackTop;	//栈顶指针
};

struct stack* creatStack() {
	struct stack* mystack = (struct stack*)malloc(sizeof(struct stack));
	mystack->stackSize = 0;
	mystack->stackTop = creatlist();
	return mystack;
}

void push(struct stack* mystack, int data) {
	insert(mystack->stackTop, data);
	mystack->stackSize++;
}
void updata(struct stack* mystack, int data) {
	mystack->stackSize--;
	insert(mystack->stackTop, data);
}
int Top(struct stack* mystack) {
	if (mystack->stackSize == 0)
		return -1;
	else
		return mystack->stackTop->next->data;
}
//出栈
void pop(struct stack* mystack) {
	if (mystack->stackSize == 0)
		printf("栈为空，无法出栈");
	else {
		delete(mystack->stackTop);
		mystack->stackSize--;
	}
}
//展示
void Display(struct stack* Stack) {
	printf("栈中元素:");
	while (!empty(Stack)) {
		printf("%d\t", Top(Stack));
		pop(Stack);
	}
	printf("\n");
}
int empty(struct stack* mystack) {
	if (mystack->stackSize == 0)
		return 1;
	else
		return 0;
}
void main() {
	struct stack* mystack = creatStack();
	//增
	push(mystack, 1);
	push(mystack, 2);
	push(mystack, 3);
	while (!empty(mystack)) {
		printf("%d\t", Top(mystack));
		pop(mystack);
	}
	printf("\n");
	//查栈顶
	printf("栈顶为:%d\n", Top(mystack));

	//改
	updata(mystack, 10);

	//删
	pop(mystack);
	//while (!empty(mystack)) {
	//	printf("%d\t", Top(mystack));
	//	pop(mystack);
	//}
	printf("\n");
	system("pause");
}
