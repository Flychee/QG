#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "../Headers/sort.h"
#include "sort.c"

void window()
{
    printf("***************");
    printf("仅展示部分数据");
    printf("***************\n");
    printf("1.随机数生成\n");
    printf("2.归并排序\n");
    printf("3.插入排序\n");
    printf("4.快速排序\n");
    printf("5.计数排序\n");
    printf("6.基数计数排序\n");
    printf("7.颜色排序\n");
    printf("8.自拟\n");
    printf("9.退出程序\n");
}

int main()
{
    int sr = 0 ;
    int *a , *b;/*数组*/
    FILE *file;/*文件指针*/
    clock_t start,stop;
    double time1;
    while(1)
    {
        system("cls");
        window();
        int num;
        int max;
        int k10 = 10000 , k50 = 50000 , k200 = 200000 , h1 = 100;
        a = (int*)malloc(200000*sizeof(int));
        b = (int*)malloc(200000*sizeof(int));
        for(int i = 0 ; i < 200000 ; i++)
            a[i] = -1;
        file = fopen("dt.dat","rb+");
        fread( a , sizeof(int) , 200000 , file);
        fclose(file);
        printf("请输入序号\n");
        scanf("%d" , &num);
        system("cls");
        switch(num)
        {
            case 1:
                printf("1. 10k个数据\n");
                printf("2. 50k个数据\n");
                printf("3. 200k个数据\n");
                printf("4. 100个数据*100k次运行\n");
                printf("5. 颜色排序专用(50k个数据)\n");
                printf("请输入序号:");
                scanf("%d" , &num);
                if(num == 1)
                {
                    srand(sr++);/*重置种子*/
                    for(int i = 0 ; i < k10 ; i++)
                        a[i] = rand();
                    file = fopen("dt.dat","wb+");
                    fwrite(a , sizeof(int) , k10 , file);
                    fclose(file);
                }
                else if(num == 2)
                {
                    srand(sr++);/*重置种子*/
                    for(int i = 0 ; i < k50 ; i++)
                        a[i] = rand();
                    file = fopen("dt.dat","wb+");
                    fwrite(a , sizeof(int) , k50 , file);
                    fclose(file);
                }
                else if(num == 3)
                {
                    srand(sr++);/*重置种子*/
                    for(int i = 0 ; i < k200 ; i++)
                        a[i] = rand();
                    file = fopen("dt.dat","wb+");
                    fwrite(a , sizeof(int) , k200 , file);
                    fclose(file);
                }
                else if(num == 4)
                {
                    srand(sr++);/*重置种子*/
                    for(int i = 0 ; i < h1 ; i++)
                        a[i] = rand();
                    file = fopen("dt.dat","wb+");
                    fwrite(a , sizeof(int) , h1 , file);
                    fclose(file);
                }
                else if(num == 5)
                {
                    srand(sr++);/*重置种子*/
                    for(int i = 0 ; i < k50 ; i++)
                        a[i] = rand()%3;
                    file = fopen("dt.dat","wb+");
                    fwrite(a , sizeof(int) , k50 , file);
                    fclose(file);
                }
                else printf("无效序号\n");
                break;
            
            case 2:
                file = fopen("dt.dat","rb+");
                fread( a , sizeof(int) , 200000 , file);
                fclose(file);
                for(num = 0 ; a[num] != -1 && num < k200 ; num++);
                if(num == h1)
                {
                    start = clock();
                    for(int i = 0 ; i < h1*1000 ; i++)
                    {
                        MergeSort( a , 0 , h1-1 ,b );
                    }
                    stop = clock();
                    for(int i = 0 ; i < 50 ; i++)
                        printf("%d ", a[i]);
                    printf("\n运行时间为：%f ms" ,time1 = (double)(stop - start));
                }
                else if(num == k10)
                {
                    start = clock();
                    MergeSort( a , 0 , k10-1 ,b );
                    stop = clock();
                    for(int i = 0 ; i < 50 ; i++)
                        printf("%d ", a[i]);
                    printf("运行时间为：%f ms" ,time1 = (double)(stop - start));
                }
                else if(num == k50)
                {
                    start = clock();
                    MergeSort( a , 0 , k50-1 ,b );
                    stop = clock();
                    for(int i = 0 ; i < 50 ; i++)
                        printf("%d ", a[i]);
                    printf("运行时间为：%f ms" ,time1 = (double)(stop - start));
                }
                else if(num == k200)
                {
                    start = clock();
                    MergeSort( a , 0 , k200-1 ,b );
                    stop = clock();
                    for(int i = 0 ; i < 50 ; i++)
                        printf("%d ", a[i]);
                    printf("运行时间为：%f ms" ,time1 = (double)(stop - start));
                }
                break;
            case 3:
                file = fopen("dt.dat","rb+");
                fread( a , sizeof(int) , 200000 , file);
                fclose(file);
                for(num = 0 ; a[num] != -1 && num < k200 ; num++);
                if(num == h1)
                {
                    start = clock();
                    for(int i = 0 ; i < h1*1000 ; i++)
                    {
                        insertSort(a , h1);
                    }
                    stop = clock();
                    for(int i = 0 ; i < 50 ; i++)
                        printf("%d ", a[i]);
                    printf("运行时间为：%f ms" ,time1 = (double)(stop - start));
                }
                if(num == k10)
                {
                    start = clock();
                    insertSort(a , k10);
                    stop = clock();
                    for(int i = 0 ; i < 50 ; i++)
                        printf("%d ", a[i]);
                    printf("运行时间为：%f ms" ,time1 = (double)(stop - start));
                }
                if(num == k50)
                {
                    start = clock();
                    insertSort(a , k50);
                    stop = clock();
                    for(int i = 0 ; i < 50 ; i++)
                        printf("%d ", a[i]);
                    printf("运行时间为：%f ms" ,time1 = (double)(stop - start));
                }
                if(num == k200)
                {
                    start = clock();
                    insertSort(a , k200);
                    stop = clock();
                    for(int i = 0 ; i < 50 ; i++)
                        printf("%d ", a[i]);
                    printf("运行时间为：%f ms" ,time1 = (double)(stop - start));
                }
                break;
            case 4:
                file = fopen("dt.dat","rb+");
                fread( a , sizeof(int) , 200000 , file);
                fclose(file);
                for(num = 0 ; a[num] != -1 && num < k200 ; num++);
                if(num == h1)
                {
                    start = clock();
                    for(int i = 0 ; i < h1*1000 ; i++)
                    {
                        QuickSort_Recursion( a , 0 , h1-1 );
                    }
                    stop = clock();
                    for(int i = 0 ; i < 50 ; i++)
                        printf("%d ", a[i]);
                    printf("运行时间为：%f ms" ,time1 = (double)(stop - start));
                }
                if(num == k10)
                {
                    start = clock();
                    QuickSort_Recursion( a , 0 , k10-1 );
                    stop = clock();
                    for(int i = 0 ; i < 50 ; i++)
                        printf("%d ", a[i]);
                    printf("运行时间为：%f ms" ,time1 = (double)(stop - start));
                }
                if(num == k50)
                {
                    start = clock();
                    QuickSort_Recursion( a , 0 , k50-1 );
                    stop = clock();
                    for(int i = 0 ; i < 50 ; i++)
                        printf("%d ", a[i]);
                    printf("运行时间为：%f ms" ,time1 = (double)(stop - start));
                }
                if(num == k200)
                {
                    start = clock();
                    QuickSort_Recursion( a , 0 , k200-1 );
                    stop = clock();
                    for(int i = 0 ; i < 50 ; i++)
                        printf("%d ", a[i]);
                    printf("运行时间为：%f ms" ,time1 = (double)(stop - start));
                }
                break;
            case 5:
                file = fopen("dt.dat","rb+");
                fread( a , sizeof(int) , 200000 , file);
                fclose(file);
                for(num = 0 ; a[num] != -1 && num < k200 ; num++);
                
                max = a[0];
                for(int i = 0; i < num ; i++)/*求最大值*/
                    if(a[i] >= max)
                        max = a[i];
                
                if(num == h1)
                {
                    start = clock();
                    for(int i = 0 ; i < h1*1000 ; i++)
                    {
                        CountSort(a, h1 , max);
                    }
                    stop = clock();
                    for(int i = 0 ; i < 50 ; i++)
                        printf("%d ", a[i]);
                    printf("运行时间为：%f ms" ,time1 = (double)(stop - start));
                }

                else if(num == k10)
                {
                    start = clock();
                    CountSort(a, k10 , max);
                    stop = clock();
                    for(int i = 0 ; i < 50 ; i++)
                        printf("%d ", a[i]);
                    printf("运行时间为：%f ms" ,time1 = (double)(stop - start));
                }

                else if(num == k50)
                {
                    start = clock();
                    CountSort(a, k50 , max);
                    stop = clock();
                    for(int i = 0 ; i < 50 ; i++)
                        printf("%d ", a[i]);
                    printf("运行时间为：%f ms" ,time1 = (double)(stop - start));
                }

                else if(num == k200)
                {
                    start = clock();
                    CountSort(a, k200 , max);
                    stop = clock();
                    for(int i = 0 ; i < 50 ; i++)
                        printf("%d ", a[i]);
                    printf("运行时间为：%f ms" ,time1 = ((double)stop - start));
                }
                break;
            case 6:
                file = fopen("dt.dat","rb+");
                fread( a , sizeof(int) , 200000 && num < k200 , file);
                fclose(file);
                for(num = 0 ; a[num] != -1 ; num++);
                if(num == h1)
                {
                    start = clock();
                    for(int i = 0 ; i < h1*1000 ; i++)
                    {
                        RadixCountSort(a , num);
                    }
                    stop = clock();
                    for(int i = 0 ; i < 50 ; i++)
                        printf("%d ", a[i]);
                    printf("运行时间为：%f ms" ,time1 = (double)(stop - start));
                }
                if(num == k10)
                {
                    start = clock();
                    RadixCountSort(a , num);
                    stop = clock();
                    for(int i = 0 ; i < 50 ; i++)
                        printf("%d ", a[i]);
                    printf("运行时间为：%f ms" ,time1 = (double)(stop - start));
                }
                if(num == k50)
                {
                    start = clock();
                    RadixCountSort(a , num);
                    stop = clock();
                    for(int i = 0 ; i < 50 ; i++)
                        printf("%d ", a[i]);
                    printf("运行时间为：%f ms" ,time1 = (double)(stop - start));
                }
                if(num == k200)
                {
                    start = clock();
                    RadixCountSort(a , num);
                    stop = clock();
                    for(int i = 0 ; i < 50 ; i++)
                        printf("%d ", a[i]);
                    printf("运行时间为：%f ms" ,time1 = (double)(stop - start));
                }
                break;
            case 7:
                file = fopen("dt.dat","rb+");
                fread( a , sizeof(int) , 200000 && num < k200 , file);
                fclose(file);
                for(num = 0 ; a[num] != -1 ; num++);
                if(num == h1)
                {
                    start = clock();
                    for(int i = 0 ; i < h1*1000 ; i++)
                    {
                        ColorSort( a, num );
                    }
                    stop = clock();
                    for(int i = 0 ; i < 50 ; i++)
                        printf("%d ", a[i]);
                    printf("运行时间为：%f ms" ,time1 = (double)(stop - start));
                }
                if(num == k10)
                {
                    start = clock();
                    ColorSort( a, num );
                    stop = clock();
                    for(int i = 0 ; i < 50 ; i++)
                        printf("%d ", a[i]);
                    printf("运行时间为：%f ms" ,time1 = (double)(stop - start));
                }
                if(num == k50)
                {
                    start = clock();
                    ColorSort( a, num );
                    stop = clock();
                    for(int i = 0 ; i < 50 ; i++)
                        printf("%d ", a[i]);
                    printf("运行时间为：%f ms" ,time1 = (double)(stop - start));
                }
                if(num == k200)
                {
                    start = clock();
                    ColorSort( a, num );
                    stop = clock();
                    for(int i = 0 ; i < 50 ; i++)
                        printf("%d ", a[i]);
                    printf("运行时间为：%f ms" ,time1 = (double)(stop - start));
                }
                break;
            case 8:
                file = fopen("dt.dat","rb+");
                fread( a , sizeof(int) , 200000 && num < k200 , file);
                fclose(file);
                for(num = 0 ; a[num] != -1 ; num++);
                Find(a , num);
                break;
            case 9: 
                exit(0);
            default:
                break;
        }
        free(a);
        free(b);
        system("pause");
    }
}