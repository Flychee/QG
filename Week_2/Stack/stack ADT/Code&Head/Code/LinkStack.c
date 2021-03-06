#include "../head/LinkStack.h" 
#include <stdio.h>
//??ջ

//??ʼ??ջ
Status initLStack(LinkStack *s)
{
    s->top = NULL;
    s->count = 0;
    return SUCCESS;
}

//?ж?ջ?Ƿ?Ϊ??
Status isEmptyLStack(LinkStack *s)
{
	if(s->count == 0) return SUCCESS;
    else return ERROR;
}

//?õ?ջ??Ԫ??
Status getTopLStack(LinkStack *s,ElemType *e)
{
	if(s->top == NULL) return ERROR;
    *e = s->top->data;
    return SUCCESS;
}

//????ջ
Status clearLStack(LinkStack *s)
{
	if(s == NULL)return ERROR;
    StackNode *temp = s->top;
    while(s->top != NULL)
    {
        s->top = s->top->next;
        free(temp);
        temp = s->top;
    }
    s->count = 0;
    return SUCCESS;
}

//????ջ
Status destroyLStack(LinkStack *s)
{
	if(s == NULL)return ERROR;
    StackNode *temp = s->top;
    while(s->top != NULL)
    {
        s->top = s->top->next;
        free(temp);
        temp = s->top;
    }
    s->count = 0;
    free(s);
    return SUCCESS;
}

//????ջ????
Status LStackLength(LinkStack *s,int *length)
{
	StackNode *temp = s->top;
    *length = 0;
    while(temp != NULL)
    {
        (*length)++;
        temp = temp->next;
    }
    if(*length != s->count)
    {
        s->count = (*length);
        return ERROR;
    }
    else return SUCCESS;
}

//??ջ
Status pushLStack(LinkStack *s,ElemType data)
{
    StackNode *temp = (StackNode*)malloc(sizeof(StackNode));
    temp->data = data;
    temp ->next = s->top;
    s->top = temp;
    s->count++;
    return SUCCESS;
}

//??ջ
Status popLStack(LinkStack *s,ElemType *data)
{
	if(s->top == NULL) return ERROR;
    StackNode *temp = s->top;
    *data = temp->data;
    s->top = s->top->next;
    free(temp);
    s->count--;
    return SUCCESS;
}
