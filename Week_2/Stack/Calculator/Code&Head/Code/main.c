#include <stdio.h>
#include "../Head/Calculator.h"
#include "Calculator.c"

int main()
{
    char p[21];
    int end_sum;
    printf("20个字符以内，个位整数运算\n");
    printf("请输入算式：\n");
    gets(p);
    change(p);
    end_sum = calculate(p);
    printf("结果为：%d\n",end_sum);
    system("pause");
}
