#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void screen()
{
    printf("1.创建链表\n");
    printf("2.销毁链表\n");
    printf("3.前驱插入节点\n");
    printf("4.后驱插入节点\n");
    printf("5.删除结点\n");
    printf("6.遍历链表\n");
    printf("7.退出程序\n");
    printf("\n请输入1-7: \n");
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
    DuLinkedList my_list;
    DuLNode *head = NULL;
    DuLNode *now = NULL;
    DuLNode *insert = NULL;
    for(;;)
    {
        screen();
        scanf("%d",&num);
        ch = getchar();//清除缓冲区
        system("cls");
        if(num < 1 || num > 7) continue;
        else
        {
            switch(num)
            {
                case 7: exit(0);

                case 6:
                    TraverseList_DuL(my_list,visit);
                    break;
                case 5:
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
                        DeleteList_DuL(now,&my_data);
                        now = NULL;
                        my_data = OVERFLOW;
                        break;
                    }
                case 4:
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
                    insert = (DuLNode*)malloc(sizeof(DuLNode));
                    insert->next =NULL;
                    printf("请输入需插入的数据(值尽量不为-1)： ");
                    scanf("%d",&(insert->data));
                    ch = getchar();//清除缓冲区
                    InsertAfterList_DuL(now,insert);
                    break;
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
                    insert = (DuLNode*)malloc(sizeof(DuLNode));
                    insert->next =NULL;
                    printf("请输入需插入的数据(值尽量不为-1)： ");
                    scanf("%d",&(insert->data));
                    ch = getchar();//清除缓冲区
                    InsertBeforeList_DuL(now,insert);
                    break;
                case 2:
                    DestroyList_DuL(&my_list);
                    break;
                case 1:
                    InitList_DuL(&my_list);
                    break;
            }
        end();
        }
    }
}