#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void screen()
{
    printf("1.��������\n");
    printf("2.��������\n");
    printf("3.ǰ������ڵ�\n");
    printf("4.��������ڵ�\n");
    printf("5.ɾ�����\n");
    printf("6.��������\n");
    printf("7.�˳�����\n");
    printf("\n������1-7: \n");
}

void end()
{
    printf("ѡ����ִ��\n");
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
        ch = getchar();//���������
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
                    printf("������ɾ��������(��СΪ2)�� ");
                    scanf("%d",&scf);
                    ch = getchar();//���������
                    if(scf<2) printf("�������");
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
                    printf("�����������Ľ�����(��СΪ1)�� ");
                    scanf("%d",&scf);
                    ch = getchar();//���������
                    now = my_list;
                    for(int i=1;i<scf;i++)
                    {
                        if(now == NULL)
                        break;
                        else now = now->next;
                        
                    }
                    insert = (DuLNode*)malloc(sizeof(DuLNode));
                    insert->next =NULL;
                    printf("����������������(ֵ������Ϊ-1)�� ");
                    scanf("%d",&(insert->data));
                    ch = getchar();//���������
                    InsertAfterList_DuL(now,insert);
                    break;
                case 3:
                    printf("�����������Ľ�����(��СΪ1)�� ");
                    scanf("%d",&scf);
                    ch = getchar();//���������
                    now = my_list;
                    for(int i=1;i<scf;i++)
                    {
                        if(now == NULL)
                        break;
                        else now = now->next;
                        
                    }
                    insert = (DuLNode*)malloc(sizeof(DuLNode));
                    insert->prior = NULL;
                    insert->next = NULL;
                    printf("����������������(ֵ������Ϊ-1)�� ");
                    scanf("%d",&(insert->data));
                    ch = getchar();//���������
                    InsertBeforeList_DuL(now,insert);
                    if(now == my_list) my_list = my_list->prior;/*��ͷ���ǰ�������ʹͷ���ǰ��*/
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