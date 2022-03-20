/***************************************************************************************
 *	File Name				:	linkedList.h
 *	CopyRight				:	2020 QG Studio
 *	SYSTEM					:   win10
 *	Create Data				:	2020.3.28
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

/**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

/**************************************************************
*	Macro Define Section
**************************************************************/

#define OVERFLOW -1

/**************************************************************
*	Struct Define Section
**************************************************************/

// define element type
typedef int ElemType;

// define struct of linked list
typedef struct LNode {
	ElemType data;
  	struct LNode *next;
} LNode, *LinkedList;

// define Status
typedef enum Status {
	ERROR,
	SUCCESS
} Status;

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**************************************************************
*	Prototype Declare Section
**************************************************************/


Status InitList(LinkedList *L) /*创建链表*/
{
	int num = 0;
	printf("请输入节点数:  ");
	scanf("%d",&num);
	LNode *head = NULL;
	LNode *p = NULL;
	LNode *q = NULL;
	for(int i = 1; i <= num ; i++)
	{
		p=(LNode*)malloc(sizeof(LNode));
		if(i != 1) q->next = p;
		else head = q = p;
		p->next = NULL;
		printf("请输入第%d个节点的数据:  ", i);
		scanf("%d",&(p->data));
		q = p;
		p = p->next;
	}
	*L = head;
	if(*L != NULL) return SUCCESS;
	else return ERROR;
};

void DestroyList(LinkedList *L)/*销毁链表*/
{
	if(*L == NULL) return ;
	LNode *p = NULL;/*遍历链表用*/
	LNode *q = NULL;
	p = *L;
	while(p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
};

Status InsertList(LNode *p, LNode *q)/*插入节点*/
{
	if(p == NULL || q == NULL) return ERROR;
	q->next = p->next;
	p->next = q;
	return SUCCESS;
};

Status DeleteList(LNode *p, ElemType *e)/*删除节点*/
{
	if(p == NULL) return ERROR;
	LNode *temp = NULL;
	temp = p->next;
	p->next = p->next !=NULL ? p->next->next : NULL;
	*e = temp != NULL ? temp->data : OVERFLOW;
	printf("结点删除，该数据为%d (若为-1则无此结点)",*e);
	free(temp);
	return SUCCESS;
};

void TraverseList(LinkedList L, void (*visit)(ElemType e))/*遍历链表*/
{
	LNode *p = L;
	while (p != NULL)
	{
		visit(p->data);
		p = p->next;
	}
	printf("NULL\n");/*链表遍历结束标志*/
};

void visit(ElemType e)/*数据输出*/
{
	printf("%d -> ",e);
};

Status SearchList(LinkedList L, ElemType e)/*查询节点数据*/
{
	if(L == NULL) return ERROR;
	LNode *p = NULL;
	p = L;/*遍历链表用*/
	while(p != NULL)
	{
		if(p->data == e) return SUCCESS;
		else p = p->next;
	}
	return ERROR;/*链表中无此数据*/
};

Status ReverseList(LinkedList *L)/*链表逆置*/
{
	if(*L == NULL) return ERROR;
	LNode *p = NULL;
	LNode *q = NULL;
	LNode *r = NULL;
	LNode *head = NULL;
	
	head=(*L);/*标记头结点*/
	p = (*L)->next->next == NULL ? NULL : (*L)->next->next;
	q = (*L)->next == NULL ? NULL : (*L)->next;
	r = (*L) == NULL ? NULL : (*L);/*用三目运算符赋值*/
	
	if(r == NULL || q == NULL) return SUCCESS;
	if(p == NULL)
	{
		(*L) = head = q;
		q->next = r;
		r->next = NULL;
		return SUCCESS;
	}/*少于三个节点(不包括头结点)的特殊情况*/
	while(p!=NULL)
	{
		q->next = r;
		if(head == r) r->next = NULL;
		r = q;
		q = p;
		p = p->next;
	}
	(*L) = head = q;
	return SUCCESS;
};

Status IsLoopList(LinkedList L)/*判断链表循环*/
{
	if(L == NULL) return ERROR;
	LNode *fast = NULL;
	LNode *slow = NULL;
	fast = slow = L;
	while(fast != NULL)
	{
		fast = fast->next;
		if(fast != NULL) 
			fast = fast->next;/*快指针走两步*/
		else return ERROR;/*判定为非环*/
		slow = slow->next;
		if(slow == fast) return SUCCESS;/*快慢指针同一位置则链表成环*/
	}
	return ERROR;/*判定为非环*/
};

LNode* ReverseEvenList(LinkedList *L)/*偶数反转(当前节点(除末结点外)与后一个节点位置调换)*/
{
	if((*L) == NULL) return *L;
	LNode *head = NULL;
	LNode *p = NULL;/*遍历链表用*/
	LNode *q = NULL;
	LNode *r = NULL;
	head = p =  r = q = *L;
	while(p->next != NULL)
	{
		if(q->data %2 == 0)
		{
			if(head != q)r->next = p;
			if(head == q) head = p;
			q->next = p->next;
			p->next = q;
			p = q->next;//继续遍历
			continue;
		}
		r=q;
		q = p;
		if(p == NULL)break;
		p = p->next;
	}
	return head;
};

LNode* FindMidNode(LinkedList *L)/*查询中间节点*/
{
	if((*L) == NULL) return NULL;
	LNode *fast = NULL;
	LNode *slow = NULL;
	fast = slow = *L;
	while(1)
	{
		fast = fast->next;
		if(fast == NULL)
			return slow;
		else
			fast = fast->next;
		
		if(fast == NULL)
			return slow;
		slow = slow->next;
	}

};

/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
