#include "../Head/LinkStack.h"
#include "LinkStack.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void change(char *p)/*中缀表达式转化为后缀表达式*/
{
    LinkStack *s;
    s = (LinkStack*)malloc(sizeof(LinkStack));
    int *top = (int *)malloc(sizeof(int));/*栈顶数据获取*/
    initLStack(s);
    char q[21];
    int n = 0 ;
    for( int i = 0 ; p[i] != '\0' ; i++)
    {
        if( p[i] >= '0' && p[i] <= '9')/*数字操作*/
            q[n++] = p[i];
        
        else if( p[i]  == '(' )/*左括号*/
            pushLStack(s , (int)p[i]);
        
        else if( p[i] == '-' || p[i] == '+')/*加减号*/
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
        
        else if( p[i] == '*' || p[i] == '/' )/*乘除号*/
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

        else if( p[i] == ')' )/*右括号*/
        {
            while(s->top->data != (int)'(')
            {
                popLStack(s , top);
                q[n++] = (char)(*top);
            }
            popLStack(s , top);/*将左括号弹出*/
        }

        else
        {
            printf("字符非法！\n");
            system("pause");
            exit(1);
        }
    }
    while(s->top != NULL)/*将栈顶数据全部弹出*/
    {
        popLStack(s , top);
        q[n++] = (char)(*top);
    }
    q[strlen(q)] = '\0';
    destroyLStack(s);
    strcpy(p,q);
    return ;
}

int calculate(char *p)/*计算*/
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
                printf("存在除数为0！\n");
                system("pause");
                exit(1);
            }
            else pushLStack(s , (*last)/(*front));
        }
    }
    popLStack(s , sum);
    return *sum;
}