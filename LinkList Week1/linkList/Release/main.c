#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

void screen()
{
    printf("1.��������\n");
    printf("2.��������\n");
    printf("3.����ڵ�\n");
    printf("4.ɾ���ڵ�\n");
    printf("5.��������\n");
    printf("6.��ѯ����\n");
    printf("7.��������\n");
    printf("8.�ж�����ѭ��\n");
    printf("9.ż����ת(���һ����㷴ת)\n");
    printf("10.��ѯ�м�ڵ�\n");
    printf("11.�˳�����\n");
    printf("\n������1-11: \n");
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
    LinkedList my_list;
    LNode *head = NULL;
    LNode *now = NULL;
    LNode *insert = NULL;
    for(;;)
    {
        screen();
        scanf("%d",&num);
        ch = getchar();//���������
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
                    printf("�м�ڵ�����Ϊ%d\n",now->data);
                    break; 
                case 9:
                    ReverseEvenList(&my_list);
                    break;
                case 8:
                    result = IsLoopList(my_list);
                    if(result) printf("�����ɻ�\n");
                    else printf("����δ�ɻ�\n");
                    break;
                case 7:
                    ReverseList(&my_list);
                    break;
                case 6:
                    printf("��������Ҫ��ѯ�����ݣ�  ");
                    scanf("%d",&my_data);
                    ch = getchar();//���������
                    result = SearchList(my_list,my_data);
                    if(result) printf("���ݴ���\n");
                    else printf("���ݲ�����\n");
                    my_data = OVERFLOW;
                    break;
                case 5:
                    TraverseList(my_list,visit);
                    break;
                case 4:
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
                        DeleteList(now,&my_data);
                        now = NULL;
                        my_data = OVERFLOW;
                        break;
                    }
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
                    insert = (LNode*)malloc(sizeof(LNode));
                    insert->next =NULL;
                    printf("����������������(ֵ������Ϊ-1)�� ");
                    scanf("%d",&(insert->data));
                    ch = getchar();//���������
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