#include <stdio.h>
#include "../Head/Calculator.h"
#include "Calculator.c"

int main()
{
    char p[21];
    int end_sum;
    printf("20���ַ����ڣ���λ��������\n");
    printf("��������ʽ��\n");
    gets(p);
    change(p);
    end_sum = calculate(p);
    printf("���Ϊ��%d\n",end_sum);
    system("pause");
}