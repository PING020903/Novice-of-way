//简单的链表
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct film//节点结构
{
	int flag;
	struct film* next;
};

struct film* Head()//头节点
{
	struct film* head = malloc(sizeof(struct film));
	head->flag = 0;
	//if (head->next == NULL)
	head->next = NULL;

	return head;
}

void* NEXT(struct film* prev, int num)//新节点
{
	struct film* Next = malloc(sizeof(struct film));
	Next->flag = num;
	Next->next = NULL;

	struct film* Poi = prev;
	while (Poi->next != NULL)//指针数毛
	{
		Poi = Poi->next;//将指针指向下一节点
	}
	Poi->next = Next;//此时指针已是下一节点不为空的"下一节点"
	return Poi->next;
}

int* show_struct(struct film* prew)
{
	struct film* current = prew;
	while (current != NULL)
	{
		printf("struct.flag=	%d , .next=	%p\n", current->flag, current->next);
		current = current->next;
	}
	return 0;
}

int main(void)
{
	struct film* now = Head();
	for (int i = 0; i < 20; i++)
	{
		NEXT(now, i);
	}
	show_struct(now);

	return 0;
}