#include "../Headers/sort.h"
#include <stdio.h>
#include <math.h>
void insertSort(int *a,int n)
{
    if(a == NULL)
    {
        printf("数组为空！\n");
        return ;
    }
    int temp ;/*存放数据*/
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i ; j > 0 && a[j] <= a[j-1] ; j--)/*从后向前排*/
        {
            int temp = a[j];
            a[j] = a[j-1];
            a[j-1] = temp;
        }
    }
    return ;
};

void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
    if(begin >= end)return ;
    int i = 0;
    int j = begin;
    int k = mid+1;
    while(j <= mid && k <= end)/*数组分为两段*/
    {
        if(a[j] <= a[k])
            temp[i++] = a[j++];
        else
            temp[i++] = a[k++];
    }

    while(j <= mid)/*防止遗漏*/
            temp[i++] = a[j++];

    while(k <= end)/*防止遗漏*/
        temp[i++] = a[k++];

    for(int n = 0  ; n < i ; n++)
        a[n+begin] = temp[n];
    for(int n = 0 ; n < i ; n++)/*清空*/
        temp[n] = -1;
};

void MergeSort(int *a,int begin,int end,int *temp)
{
    if(begin >= end) return ;
    int mid;
    mid = (end + begin) / 2 ;
    MergeSort(a , begin , mid , temp);
    MergeSort(a , mid+1 , end , temp);/*分治*/
    MergeArray(a , begin , mid , end , temp);
};

void QuickSort_Recursion(int *a, int begin, int end)
{
    if(begin < end)
	{
		int i =Partition(a, begin ,end);
		QuickSort_Recursion(a,begin,i-1);
		QuickSort_Recursion(a,i+1,end);/*分治*/
	}
	else
		return;
};

void QuickSort(int *a,int size);

int Partition(int *a, int begin, int end)
{
    int temp = a[begin];
	int i = begin;
	int j = end;
		
	while(i < j)
	{
		while(i < j && a[j] > temp)
			j--;
		a[i] = a[j];/*位置交换*/
		while(i < j && a[i] <= temp)
			i++;
		a[j] = a[i];/*位置交换*/
	}
	a[i] = temp;
    return i;
};

void CountSort(int *a, int size , int max)
{
    int temp[max+1];
    for(int i = 0 ; i < max+1 ; i++)/*初始化*/
        temp[i] = 0;
    for(int i = 0 ; i < size ; i++)/*收集*/
        temp[a[i]]++;
    for(int i = 1 ; i < max+1 ; i++)/*统计*/
        temp[i] += temp[i-1];
    for(int i = max ; i >= 0 ; i--)/*排序*/
    {    
        while(i != 0 && temp[i] != temp[i-1])
        {
            a[temp[i]-1] = i;
            temp[i]--;
        }
        while(i == 0 && temp[i] != 0)
        {
            a[temp[0]-1] = 0;
            temp[0]--;
        }
    }

    return ;
};

void RadixCountSort(int *a,int size)
{
    int barrel[10][size];/*10个桶存放数据*/
    int br_size[10];/*记录每桶数据个数*/
    
    for(int num = 0 ;  ; num++)/*位数*/
    {
        for(int i = 0 ; i < 10 ; i++)/*桶初始化*/
        {
            br_size[i] = 0;
            for(int n = 0 ; n < size ; n++)
                barrel[i][n] = 0;
        }

        for(int i = 0 ; i < size ; i++)/*放入桶中*/
            barrel[a[i]/(int)pow(10,num)%10] [br_size[a[i]/(int)pow(10,num)%10]++] = a[i];
        
        for(int i = 0 ; i < 10 ; i++)/*桶排序*/
            insertSort(barrel[i] , br_size[i]);

        for(int i = 0 , num = 0 ; i < 10 ; i++)/*排序后数据返回数组中*/
            for(int n = 0 ; n < br_size[i] ; n++)
                a[num++] = barrel[i][n];

        for(int i = 0 ; i < 10 ; i++)/*检查桶内是否无值*/
            for(int n = 0 ; barrel[i][n] == 0 ; n++)
                if( i == 9 && n == size-2 && barrel[9][size-1] == 0 )
                    return ;
    }
};

void ColorSort(int *a,int size)
{
    int p0 = 0;
    int p2 = size-1;
    for(int p1 = 0 ; p1 <= p2 ; p1++)
    {
        int temp;
        if(a[p1] == 0)
        {
            temp = a[p1];
            a[p1] = a[p0];
            a[p0++] = temp;
        }
        else if(a[p1] == 2)
        {
            temp = a[p1];
            a[p1--] = a[p2];
            a[p2--] = temp;
        }
    }
    return ;
};
void Find(int *a,int size)
{
    int num;
    int k;
    printf("1. 需要找较小数\n");
    printf("2. 需要找较大数\n");
    printf("请输入序号：");
    scanf("%d" , &num);
    printf("请输入k值:");
    scanf("%d" , &k);
    if( k > size )
    {
        printf("k值超界\n");
        return ;
    }
    
    switch(num)
    {
        case 1:
            QuickSort_Recursion(a , 0 , size-1);
            printf("第%d小值为 %d \n", k , a[k-1]);
            break;
        case 2:
            QuickSort_Recursion(a , 0 , size-1);
            printf("第%d大值为 %d \n", k , a[size-1-k]);
            break;
        default:
            printf("序号有误\n");
            break;
    }
};

