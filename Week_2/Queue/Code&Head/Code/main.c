#include "../head/LQueue.h"
#include "LQueue.c"
#include <stdio.h>
#include <stdlib.h>

void window()
{
    printf("1.初始化队列\n");
    printf("2.销毁队列\n");
    printf("3.检查队列是否为空\n");
    printf("4.查看队头元素\n");
    printf("5.确定队列长度\n");
    printf("6.入队操作\n");
    printf("7.出队操作\n");
    printf("8.遍历队列\n");
    printf("9.清空队列\n");
    printf("10.退出程序\n\n");
    printf("请输入序号：");
}
int main()
{
    LQueue *q;
    q = (LQueue*)malloc(sizeof(LQueue));
    int judge;/*判断用*/
    
    while(1)
    {
        void *temp = malloc(21);/*入队操作用*/
        int num = -1;
        window();
        scanf("%d" , &num);
        if(num < 1 || num > 10) continue;
        switch(num)
        {
            case 1:
                system("cls");
                InitLQueue(q);
                printf("初始化成功\n");
                system("pause");
                break;
            
            case 2:
                system("cls");
                DestoryLQueue(q);
                printf("销毁成功\n");
                system("pause");
                break;
            
            case 3:
                system("cls");
                judge = IsEmptyLQueue(q);
                if(judge == 0) printf("队列为空\n");
                else printf("队列不为空\n");
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
                if(judge = 0) printf("未能确定队列长度\n");
                else printf("队列长度为 %d\n" , q->length);
                system("pause");
                break;
            
            case 6:
                system("cls");
                printf("请输入数据类型：1.int 2.float 3.char 4.string\n");
                scanf("%d",&num);
                getchar();
                if(num<1||num>4)
                {
                    printf("输入不符，函数退出\n");
                    break;
                }

                datatype[q->length] = num;/*确定数据类型*/
                switch(num)/*输入入队数据*/
                {
                    case 1:
                        printf("请输入整型数据：");
                        scanf("%d", (int*)temp);
                        getchar();
                        EnLQueue(q, temp);
                        break;
                    case 2:
                        printf("请输入浮点型数据：");
                        scanf("%f", (float*)temp);
                        getchar();
                        EnLQueue(q, temp);
                        break;
                    case 3:
                        printf("请输入字符：");
                        scanf("%c", (char*)temp);
                        getchar();
                        EnLQueue(q, temp);
                        break;
                    case 4:
                        printf("请输入字符串(20个字符以下)：");
                        gets(temp);
                        EnLQueue(q, temp);
                        break;
                }
                printf("入队成功！\n");
                system("pause");
                break;

            case 7:
                system("cls");
                judge = DeLQueue(q);
                if(judge = 0)printf("出队失败\n");
                else printf("出队成功\n");
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
                printf("清空成功！\n");
                system("pause");
                break;
            case 10:
                exit(0);
        }
        system("cls");
    }
}