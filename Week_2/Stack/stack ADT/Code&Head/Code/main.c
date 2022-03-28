#include "../head/LinkStack.h"
#include "LinkStack.c"
#include <stdio.h>
#include <stdlib.h>

void window()
{
    printf("1.初始化栈\n");
    printf("2.判断栈是否为空\n");
    printf("3.得到栈顶元素\n");
    printf("4.清空栈\n");
    printf("5.销毁栈\n");
    printf("6.检测栈长度\n");
    printf("7.入栈\n");
    printf("8.出栈\n");
    printf("9.退出程序\n\n");
    printf("请输入序号：");
}
int main()
{
    LinkStack *s;
    s = (LinkStack*)malloc(sizeof(LinkStack));
    int judge;/*判断用*/
    int *temp = (int*)malloc(sizeof(int));/*读取用*/
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
                if(judge == 1) printf("初始化栈成功！\n");
                system("pause");
                break;
            
            case 2:
                system("cls");
                judge = isEmptyLStack(s);
                if(judge == 1) printf("栈为空\n");
                else printf("栈不为空！\n");
                system("pause");
                break;
            
            case 3:
                system("cls");
                judge = getTopLStack(s , temp);
                if(judge == 1) printf("栈顶元素为%d\n",*temp);
                else printf("无栈顶元素！\n");
                system("pause");
                break;
            case 4:
                system("cls");
                judge = clearLStack(s);
                if(judge == 1) printf("栈已被清空\n");
                else printf("不存在栈！\n");
                system("pause");
                break;
            
            case 5:
                system("cls");
                judge = destroyLStack(s);
                if(judge == 1) printf("栈已被销毁\n");
                else printf("不存在栈！\n");
                system("pause");
                break;
            
            case 6:
                system("cls");
                judge = LStackLength(s , temp);
                if(judge == 1) printf("栈长度正确，为%d\n",*temp);
                else printf("栈长度错误，已修改为%d！\n",*temp);
                system("pause");
                break;

            case 7:
                system("cls");
                printf("请输入数据：");
                scanf("%d",temp);
                judge = pushLStack(s , *temp);
                if(judge == 1) printf("入栈成功\n");
                else printf("不存在栈！\n");
                system("pause");
                break;
            case 8:
                system("cls");
                judge = popLStack(s , temp);
                if(judge == 1) printf("出栈成功，数据为%d\n",*temp);
                else printf("不存在栈！\n");
                system("pause");
                break;
            case 9:
                exit(0);
        }
        system("cls");
    }
}
