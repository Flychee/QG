#include "../head/LinkStack.h" 
#include <stdio.h>
//Á´Õ»

//³õÊ¼»¯Õ»
Status initLStack(LinkStack *s)
{
    s->top = NULL;
    s->count = 0;
    return SUCCESS;
}

//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
Status isEmptyLStack(LinkStack *s)
{
	if(s->count == 0) return SUCCESS;
    else return ERROR;
}

//µÃµ½Õ»¶¥ÔªËØ
Status getTopLStack(LinkStack *s,ElemType *e)
{
	if(s->top == NULL) return ERROR;
    *e = s->top->data;
    return SUCCESS;
}

//Çå¿ÕÕ»
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

//Ïú»ÙÕ»
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

//¼ì²âÕ»³¤¶È
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

//ÈëÕ»
Status pushLStack(LinkStack *s,ElemType data)
{
    StackNode *temp = (StackNode*)malloc(sizeof(StackNode));
    temp->data = data;
    temp ->next = s->top;
    s->top = temp;
    s->count++;
    return SUCCESS;
}

//³öÕ»
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
