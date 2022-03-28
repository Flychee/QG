#include "../head/LQueue.h" 
#include <stdio.h>

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
    Q->front = NULL;
    Q->rear = NULL;/*队头队尾指向空指针*/
    Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
	Node *temp = NULL;
    while(Q->front != Q->rear)
    {
        temp = Q->front;
        Q->front = Q->front->next;
        free(temp);
        Q->length--;
    }
    free(Q->front);/*队头队尾重合*/
    free(Q);
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
	if(Q->length == 0) return FALSE;
    else return TRUE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e)
{
	if(Q->length == 0) 
    {
        printf("队列无头元素\n");
        getchar();/*读取缓冲区的回车键*/
        return FALSE;
    }
    else
    {
        e = Q->front->data;
        if(datatype[0] == 1)
            printf("队头元素为%d\n", *((int*)e));
        else if(datatype[0] == 2)
            printf("队头元素为%f\n", *((float*)e));
        else if(datatype[0] == 3)
            printf("队头元素为%c\n", *((char*)e));
        else if(datatype[0] = 4)
        {
            printf("队头元素为");
            puts((char*)e);
            printf("\n");
        }
        getchar();/*读取缓冲区的回车键*/
    }
    return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
	if(Q->front == NULL) return 0;
    int temp_len;
    Node *temp = Q->front;
    while(temp != Q->rear->next)
    {
        temp_len++;
        temp = temp->next;
    }
    if(temp == Q->length) return TRUE;
    else return FALSE;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data)
{
    Node *LQ;
    LQ = (Node*)malloc(sizeof(Node));
    LQ->data = data;
    LQ->next = NULL;
    if(Q->rear != NULL)
    {
        Q->rear->next = LQ;
        Q->rear = LQ;
    }
    else Q->front = Q->rear = LQ;
    Q->length++;
    return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
	if(Q->front == NULL) return FALSE;
    Node *temp = Q->front->next;
    free(Q->front);
    Q->front = temp;
    Q->length--;
    return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
	if(Q->front == NULL) return;
    Node *temp = Q->front;
    int num = 0;
    while(Q->front != Q->rear)
        DeLQueue(Q);
    free(Q->front);/*头尾重合*/
    Q->front = Q->rear = NULL;
    Q->length = 0;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
	if(Q->front == NULL)return FALSE;
    int temp_num = 0;
    Node *temp = Q->front;
    for(;temp_num < Q->length;temp_num++)
    {
        type = datatype[temp_num];
        foo(temp->data);
        temp = temp->next;
    }
    return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q

 *  @notice      : None
 */
void LPrint(void *q)
{
	if(type == 1)printf("%d  ",*((int*)q));
    else if(type == 2)printf("%f  ",*((float*)q));
    else if(type == 3)printf("%c  ",*((char*)q));
    else if(type == 4)puts((char*)q);
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/ 
// LQUEUE_H_INCLUDED


