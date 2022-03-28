#include "../head/LinkStack.h"
#include "LinkStack.c"
#include <stdio.h>
#include <stdlib.h>

void window()
{
    printf("1.��ʼ��ջ\n");
    printf("2.�ж�ջ�Ƿ�Ϊ��\n");
    printf("3.�õ�ջ��Ԫ��\n");
    printf("4.���ջ\n");
    printf("5.����ջ\n");
    printf("6.���ջ����\n");
    printf("7.��ջ\n");
    printf("8.��ջ\n");
    printf("9.�˳�����\n\n");
    printf("��������ţ�");
}
int main()
{
    LinkStack *s;
    s = (LinkStack*)malloc(sizeof(LinkStack));
    int judge;/*�ж���*/
    int *temp = (int*)malloc(sizeof(int));/*��ȡ��*/
    while(1)
    {
        int num = -1;
        window();
        scanf("%d" , &num);
        if(num < 1 || num > 9) continue;
        switch(num)
        {
            case 1:
                system("cls");
                judge = initLStack(s);
                if(judge == 1) printf("��ʼ��ջ�ɹ���\n");
                system("pause");
                break;
            
            case 2:
                system("cls");
                judge = isEmptyLStack(s);
                if(judge == 1) printf("ջΪ��\n");
                else printf("ջ��Ϊ�գ�\n");
                system("pause");
                break;
            
            case 3:
                system("cls");
                judge = getTopLStack(s , temp);
                if(judge == 1) printf("ջ��Ԫ��Ϊ%d\n",*temp);
                else printf("��ջ��Ԫ�أ�\n");
                system("pause");
                break;
            case 4:
                system("cls");
                judge = clearLStack(s);
                if(judge == 1) printf("ջ�ѱ����\n");
                else printf("������ջ��\n");
                system("pause");
                break;
            
            case 5:
                system("cls");
                judge = destroyLStack(s);
                if(judge == 1) printf("ջ�ѱ�����\n");
                else printf("������ջ��\n");
                system("pause");
                break;
            
            case 6:
                system("cls");
                judge = LStackLength(s , temp);
                if(judge == 1) printf("ջ������ȷ��Ϊ%d\n",*temp);
                else printf("ջ���ȴ������޸�Ϊ%d��\n",*temp);
                system("pause");
                break;

            case 7:
                system("cls");
                printf("���������ݣ�");
                scanf("%d",temp);
                judge = pushLStack(s , *temp);
                if(judge == 1) printf("��ջ�ɹ�\n");
                else printf("������ջ��\n");
                system("pause");
                break;
            case 8:
                system("cls");
                judge = popLStack(s , temp);
                if(judge == 1) printf("��ջ�ɹ�������Ϊ%d\n",*temp);
                else printf("������ջ��\n");
                system("pause");
                break;
            case 9:
                exit(0);
        }
        system("cls");
    }
}