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


Status InitList(LinkedList *L) /*��������*/
{
	int num = 0;
	printf("������ڵ���:  ");
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
		printf("�������%d���ڵ������:  ", i);
		scanf("%d",&(p->data));
		q = p;
		p = p->next;
	}
	*L = head;
	if(*L != NULL) return SUCCESS;
	else return ERROR;
};

void DestroyList(LinkedList *L)/*��������*/
{
	if(*L == NULL) return ;
	LNode *p = NULL;/*����������*/
	LNode *q = NULL;
	p = *L;
	while(p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
};

Status InsertList(LNode *p, LNode *q)/*����ڵ�*/
{
	if(p == NULL || q == NULL) return ERROR;
	q->next = p->next;
	p->next = q;
	return SUCCESS;
};

Status DeleteList(LNode *p, ElemType *e)/*ɾ���ڵ�*/
{
	if(p == NULL) return ERROR;
	LNode *temp = NULL;
	temp = p->next;
	p->next = p->next !=NULL ? p->next->next : NULL;
	*e = temp != NULL ? temp->data : OVERFLOW;
	printf("���ɾ����������Ϊ%d (��Ϊ-1���޴˽��)",*e);
	free(temp);
	return SUCCESS;
};

void TraverseList(LinkedList L, void (*visit)(ElemType e))/*��������*/
{
	LNode *p = L;
	while (p != NULL)
	{
		visit(p->data);
		p = p->next;
	}
	printf("NULL\n");/*��������������־*/
};

void visit(ElemType e)/*�������*/
{
	printf("%d -> ",e);
};

Status SearchList(LinkedList L, ElemType e)/*��ѯ�ڵ�����*/
{
	if(L == NULL) return ERROR;
	LNode *p = NULL;
	p = L;/*����������*/
	while(p != NULL)
	{
		if(p->data == e) return SUCCESS;
		else p = p->next;
	}
	return ERROR;/*�������޴�����*/
};

Status ReverseList(LinkedList *L)/*��������*/
{
	if(*L == NULL) return ERROR;
	LNode *p = NULL;
	LNode *q = NULL;
	LNode *r = NULL;
	LNode *head = NULL;
	
	head=(*L);/*���ͷ���*/
	p = (*L)->next == NULL ? NULL : (*L)->next->next;
	q = (*L) == NULL ? NULL : (*L)->next;
	r = (*L) == NULL ? NULL : (*L);/*nextָ�벻Ϊ����ֵ*/
	
	if(r == NULL || q == NULL) return SUCCESS;
	if(p == NULL)
	{
		(*L) = head = q;
		q->next = r;
		r->next = NULL;
		return SUCCESS;
	}/*���������ڵ�(������ͷ���)���������*/
	while(p!=NULL)
	{
		q->next = r;
		if(head == r) r->next = NULL;
		r = q;
		q = p;
		p = p->next;
	}
	q->next =r;/*ѭ�����������ô���佫��β����*/
	(*L) = head = q;
	return SUCCESS;
};

Status IsLoopList(LinkedList L)/*�ж�����ѭ��*/
{
	if(L == NULL) return ERROR;
	LNode *fast = NULL;
	LNode *slow = NULL;
	fast = slow = L;
	while(fast != NULL)
	{
		fast = fast->next;
		if(fast != NULL) 
			fast = fast->next;/*��ָ��������*/
		else return ERROR;/*�ж�Ϊ�ǻ�*/
		slow = slow->next;
		if(slow == fast) return SUCCESS;/*����ָ��ͬһλ���������ɻ�*/
	}
	return ERROR;/*�ж�Ϊ�ǻ�*/
};

LNode* ReverseEvenList(LinkedList *L)/*ż����ת(��ǰ�ڵ�(��ĩ�����)���һ���ڵ�λ�õ���)*/
{
	if((*L) == NULL) return *L;
	LNode *head = NULL;
	LNode *p = NULL;/*����������*/
	LNode *q = NULL;
	LNode *r = NULL;

	head=(*L);/*���ͷ���*/
	p = (*L)->next == NULL ? NULL : (*L)->next->next;
	q = (*L) == NULL ? NULL : (*L)->next;
	r = (*L) == NULL ? NULL : (*L);/*nextָ�벻Ϊ����ֵ*/

	if(q == NULL || r == NULL) return head;
	if(p == NULL)/*�����ڵ�С������*/
	{
		if(r->data %2 == 0)
		{
			head = q;
			q->next = r;
			r->next = NULL;
			return head;
		}
		else return head;
	}
	while(p != NULL)/*�ڵ����4��*/
	{
		if(r == head && r->data %2 == 0)
		{	
			r->next = p;
			q->next = r;
			head = q;
		}
		else if(q->data %2 == 0)
		{
			q->next = p == NULL ? NULL : p->next;
			p->next = q;
			r->next = p;/*��ת*/
			p = q == NULL ? NULL : q->next;/*����*/
		}

		if(r->next != p) r = q;
		q = p;
		p = p == NULL ? NULL : p->next;
	}
	return head;
};

LNode* FindMidNode(LinkedList *L)/*��ѯ�м�ڵ�*/
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