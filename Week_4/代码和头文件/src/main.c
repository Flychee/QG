#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "binary_sort_tree.c"
void window()
{
    printf("1.树的初始化\n");
    printf("2.增加节点\n");
    printf("3.删除节点\n");
    printf("4.查询节点\n");
    printf("5.前序遍历非递归版\n");
    printf("6.前序遍历递归版\n");
    printf("7.中序遍历非递归版\n");
    printf("8.中序遍历递归版\n");
    printf("9.后序遍历非递归版\n");
    printf("10.后序遍历递归版\n");
    printf("11.层序遍历\n");
    printf("12.退出程序\n");
}

int putdata()/*数据输入*/
{
    int num;
    printf("请输入序号/数值:");
    scanf("%d",&num);
    return num;
}

void judge(int num)
{
    if(num == succeed)
        printf("执行成功\n");
    else if(num == failed)
        printf("执行失败\n");
}

int main()
{
    int num;
    BinarySortTreePtr BSTP;
    BSTP = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
    while(1)
    {
        system("cls");
        window();
        num = putdata();
        switch(num)
        {
            case 1:
                system("cls");
                num = BST_init(BSTP);
                judge(num);
                system("pause");
                break;
            case 2:
                system("cls");
                num = putdata();
                num = BST_insert(BSTP , num);
                judge(num);
                system("pause");
                break;
            case 3:
                system("cls");
                num = putdata();
                num = BST_delete(BSTP , num);
                judge(num);
                system("pause");
                break;
            case 4:
                system("cls");
                num = putdata();
                num = BST_search(BSTP , num);
                if(num == succeed)
                    printf("存在此数据\n");
                else if(num == failed)
                    printf("不存在此数据\n");
                system("pause");
                break;
            case 5:
                system("cls");
                num = BST_preorderI(BSTP , visit);
                system("pause");
                break;
            case 6:
                system("cls");
                num = BST_preorderR(BSTP , visit);
                system("pause");
                break;
            case 7:
                system("cls");
                num = BST_inorderI(BSTP , visit);
                system("pause");
                break;
            case 8:
                system("cls");
                num = BST_inorderR(BSTP , visit);
                system("pause");
                break;
            case 9:
                system("cls");
                num = BST_postorderI(BSTP , visit);
                system("pause");
                break;
            case 10:
                system("cls");
                num = BST_postorderR(BSTP , visit);
                system("pause");
                break;
            case 11:
                system("cls");
                num = BST_levelOrder(BSTP , visit);
                system("pause");
                break;
            case 12:
                exit(0);
            default:
                system("cls");
                printf("序号错误\n");
                system("pause");
        }
    }
}

