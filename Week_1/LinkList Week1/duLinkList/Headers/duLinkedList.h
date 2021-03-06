/***************************************************************************************
 *	File Name				:	duLinkedList.h
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

#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED

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
typedef struct DuLNode {
	ElemType data;
  	struct DuLNode *prior,  *next;
} DuLNode, *DuLinkedList;

// define status
typedef enum Status {
	ERROR,
	SUCCESS,
} Status;

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L)
{
	int num = 0;
	DuLNode *head = NULL;
	DuLNode *q = NULL;
	DuLNode *p = NULL;
	printf("???????ڵ???:  ");
	scanf("%d", &num);
	for(int i = 1; i <=num ; i++)
	{
		p=(DuLNode*)malloc(sizeof(DuLNode));
		if(i != 1)
		{
			q->next = p;
			p->prior = q;
		}
		else
		{
			head = q = p;
			p->prior = NULL;
		}
		p->next = NULL;
		printf("????????%d???ڵ???????:  ", i);
		scanf("%d",&(p->data));
		q = p;
		p = p->next;
	}
	*L = head;
	if(L != NULL) return SUCCESS;
	else return ERROR;
};

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L)
{
	if(*L == NULL) return ;
	DuLNode *p = NULL;/*??????????*/
	DuLNode *q = NULL;
	p = *L;
	while(p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
};

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q)
{
	if(p == NULL || q == NULL) return ERROR;
	q->prior = p->prior;
	q->next = p;
	if(p->prior != NULL)
	p->prior->next = q;
	p->prior = q;
	return SUCCESS;
};

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
{
	if(p == NULL || q == NULL) return ERROR;
	q->prior = p;
	q->next = p->next;
	if(p->next != NULL)
	p->next->prior = q;
	p->next = q;
	return SUCCESS;
};
/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e)
{
	if(p == NULL) return ERROR;
	DuLNode *temp = NULL;
	temp = p->next;
	p->next = p->next->next;
	*e = temp->data;
	free(temp);
	return SUCCESS;
};

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
	DuLNode *p = L;
	while (p != NULL)
	{
		visit(p->data);
		p = p->next;
	}
	printf("NULL\n");/*??????????????־*/
};

void visit(ElemType e)/*????????*/
{
	printf("%d -> ",e);
};


/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
