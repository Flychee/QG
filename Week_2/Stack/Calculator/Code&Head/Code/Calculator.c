#include "../Head/LinkStack.h"
#include "LinkStack.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void change(char *p)/*��׺����ʽת��Ϊ��׺����ʽ*/
{
    LinkStack *s;
    s = (LinkStack*)malloc(sizeof(LinkStack));
    int *top = (int *)malloc(sizeof(int));/*ջ�����ݻ�ȡ*/
    initLStack(s);
    char q[21];
    int n = 0 ;
    for( int i = 0 ; p[i] != '\0' ; i++)
    {
        if( p[i] >= '0' && p[i] <= '9')/*���ֲ���*/
            q[n++] = p[i];
        
        else if( p[i]  == '(' )/*������*/
            pushLStack(s , (int)p[i]);
        
        else if( p[i] == '-' || p[i] == '+')/*�Ӽ���*/
        {
            if(s->top == NULL)
                pushLStack(s , (int)p[i]);
            else if(s->top->data == '(')
                pushLStack(s , (int)p[i]);
            else
            {
                while(s->top->data == '-' || s->top->data == '+'
                    ||s->top->data == '*' || s->top->data == '/')
                {
                    popLStack(s , top);
                    q[n++] = (char)(*top);
                    if(s->top ==NULL) break;
                }
                pushLStack(s , (int)p[i]);
            }
        }
        
        else if( p[i] == '*' || p[i] == '/' )/*�˳���*/
        {
            if(s->top == NULL)
                pushLStack(s , (int)p[i]);
            else if(s->top->data == '(')
                pushLStack(s , (int)p[i]);
            else
            {
                while( s->top->data == '*' || s->top->data == '/')
                {
                    popLStack(s , top);
                    q[n++] = (char)(*top);
                    if(s->top ==NULL) break;
                }
                pushLStack(s , (int)p[i]);
            }
        }

        else if( p[i] == ')' )/*������*/
        {
            while(s->top->data != (int)'(')
            {
                popLStack(s , top);
                q[n++] = (char)(*top);
            }
            popLStack(s , top);/*�������ŵ���*/
        }

        else
        {
            printf("�ַ��Ƿ���\n");
            system("pause");
            exit(1);
        }
    }
    while(s->top != NULL)/*��ջ������ȫ������*/
    {
        popLStack(s , top);
        q[n++] = (char)(*top);
    }
    q[strlen(q)] = '\0';
    destroyLStack(s);
    strcpy(p,q);
    return ;
}

int calculate(char *p)/*����*/
{
    LinkStack *s;
    s = (LinkStack*)malloc(sizeof(LinkStack));
    initLStack(s);
    int *front = (int *)malloc(sizeof(int));
    int *last = (int *)malloc(sizeof(int));
    int *sum = (int *)malloc(sizeof(int));
    for(int i = 0 ; p[i] != '\0' ; i++)
    {
        if(p[i] >='0' && p[i] <= '9')
            pushLStack(s , (int)(p[i]-'0'));
        else if( p[i] == '+')
        {
            popLStack(s , front);
            popLStack(s , last);
            pushLStack(s , (*last)+(*front));
        }
        else if(p[i] == '-' )
        {
            popLStack(s , front);
            popLStack(s , last);
            pushLStack(s , (*last)-(*front));
        }
        else if( p[i] == '*')
        {
            popLStack(s , front);
            popLStack(s , last);
            pushLStack(s , (*last)*(*front));
        }
        else if( p[i] == '/')
        {
            popLStack(s , front);
            popLStack(s , last);
            if( *front == 0)
            {
                printf("���ڳ���Ϊ0��\n");
                system("pause");
                exit(1);
            }
            else pushLStack(s , (*last)/(*front));
        }
    }
    popLStack(s , sum);
    return *sum;
}