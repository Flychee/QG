#include "../head/LQueue.h"
#include "LQueue.c"
#include <stdio.h>
#include <stdlib.h>

void window()
{
    printf("1.��ʼ������\n");
    printf("2.���ٶ���\n");
    printf("3.�������Ƿ�Ϊ��\n");
    printf("4.�鿴��ͷԪ��\n");
    printf("5.ȷ�����г���\n");
    printf("6.��Ӳ���\n");
    printf("7.���Ӳ���\n");
    printf("8.��������\n");
    printf("9.��ն���\n");
    printf("10.�˳�����\n\n");
    printf("��������ţ�");
}
int main()
{
    LQueue *q;
    q = (LQueue*)malloc(sizeof(LQueue));
    int judge;/*�ж���*/
    
    while(1)
    {
        void *temp = malloc(21);/*��Ӳ�����*/
        int num = -1;
        window();
        scanf("%d" , &num);
        if(num < 1 || num > 10) continue;
        switch(num)
        {
            case 1:
                system("cls");
                InitLQueue(q);
                printf("��ʼ���ɹ�\n");
                system("pause");
                break;
            
            case 2:
                system("cls");
                DestoryLQueue(q);
                printf("���ٳɹ�\n");
                system("pause");
                break;
            
            case 3:
                system("cls");
                judge = IsEmptyLQueue(q);
                if(judge == 0) printf("����Ϊ��\n");
                else printf("���в�Ϊ��\n");
                system("pause");
                break;
            
            case 4:
                system("cls");
                GetHeadLQueue(q , temp);
                system("pause");
                break;
            
            case 5:
                system("cls");
                judge = LengthLQueue(q);
                if(judge = 0) printf("δ��ȷ�����г���\n");
                else printf("���г���Ϊ %d\n" , q->length);
                system("pause");
                break;
            
            case 6:
                system("cls");
                printf("�������������ͣ�1.int 2.float 3.char 4.string\n");
                scanf("%d",&num);
                getchar();
                if(num<1||num>4)
                {
                    printf("���벻���������˳�\n");
                    break;
                }

                datatype[q->length] = num;/*ȷ����������*/
                switch(num)/*�����������*/
                {
                    case 1:
                        printf("�������������ݣ�");
                        scanf("%d", (int*)temp);
                        getchar();
                        EnLQueue(q, temp);
                        break;
                    case 2:
                        printf("�����븡�������ݣ�");
                        scanf("%f", (float*)temp);
                        getchar();
                        EnLQueue(q, temp);
                        break;
                    case 3:
                        printf("�������ַ���");
                        scanf("%c", (char*)temp);
                        getchar();
                        EnLQueue(q, temp);
                        break;
                    case 4:
                        printf("�������ַ���(20���ַ�����)��");
                        gets(temp);
                        EnLQueue(q, temp);
                        break;
                }
                printf("��ӳɹ���\n");
                system("pause");
                break;

            case 7:
                system("cls");
                judge = DeLQueue(q);
                if(judge = 0)printf("����ʧ��\n");
                else printf("���ӳɹ�\n");
                system("pause");
                break;
            case 8:
                system("cls");
                TraverseLQueue(q , LPrint);
                system("pause");
                break;
            case 9:
                system("cls");
                ClearLQueue(q);
                printf("��ճɹ���\n");
                system("pause");
                break;
            case 10:
                exit(0);
        }
        system("cls");
    }
}