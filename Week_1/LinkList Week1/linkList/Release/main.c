#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

void screen()
{
    printf("1.创建链表\n");
    printf("2.销毁链表\n");
    printf("3.插入节点\n");
    printf("4.删除节点\n");
    printf("5.遍历链表\n");
    printf("6.查询链表\n");
    printf("7.逆置链表\n");
    printf("8.判断链表循环\n");
    printf("9.偶数反转(与后一个结点反转)\n");
    printf("10.查询中间节点\n");
    printf("11.退出程序\n");
    printf("\n请输入1-11: \n");
}

void end()
{
    printf("选项已执行\n");
    system("pause");
    system("cls");
}

int main()
{
    int num = 0;
    int scf;
    int result;
    char ch;
    ElemType my_data = OVERFLOW;
    LinkedList my_list;
    LNode *head = NULL;
    LNode *now = NULL;
    LNode *insert = NULL;
    for(;;)
    {
        screen();
        scanf("%d",&num);
        ch = getchar();//清除缓冲区
        system("cls");
        if(num < 1 || num > 11) continue;
        else
        {
            switch(num)
            {
                case 11: exit(0);
                case 10:
                    now = FindMidNode(&my_list);
                    if(now != NULL)
                    printf("中间节点数据为%d\n",now->data);
                    break; 
                case 9:
                    ReverseEvenList(&my_list);
                    break;
                case 8:
                    result = IsLoopList(my_list);
                    if(result) printf("链表成环\n");
                    else printf("链表未成环\n");
                    break;
                case 7:
                    ReverseList(&my_list);
                    break;
                case 6:
                    printf("请输入想要查询的数据：  ");
                    scanf("%d",&my_data);
                    ch = getchar();//清除缓冲区
                    result = SearchList(my_list,my_data);
                    if(result) printf("数据存在\n");
                    else printf("数据不存在\n");
                    my_data = OVERFLOW;
                    break;
                case 5:
                    TraverseList(my_list,visit);
                    break;
                case 4:
                    printf("请输入删除结点序号(最小为2)： ");
                    scanf("%d",&scf);
                    ch = getchar();//清除缓冲区
                    if(scf<2) printf("输入错误");
                    else
                    {
                        now = my_list;
                        for(int i=1;i<scf;i++)
                        {
                            if(now == NULL)
                            break;
                            else now = now->next;
                        }
                        DeleteList(now,&my_data);
                        now = NULL;
                        my_data = OVERFLOW;
                        break;
                    }
                case 3:
                    printf("请输入需插入的结点序号(最小为1)： ");
                    scanf("%d",&scf);
                    ch = getchar();//清除缓冲区
                    now = my_list;
                    for(int i=1;i<scf;i++)
                    {
                        if(now == NULL)
                        break;
                        else now = now->next;
                        
                    }
                    insert = (LNode*)malloc(sizeof(LNode));
                    insert->next =NULL;
                    printf("请输入需插入的数据(值尽量不为-1)： ");
                    scanf("%d",&(insert->data));
                    ch = getchar();//清除缓冲区
                    InsertList(now,insert);
                    break;
                case 2:
                    DestroyList(&my_list);
                    break;
                case 1:
                    InitList(&my_list);
                    break;
            }
        end();
        }
    }
}
