#include "../head/LQueue.h" 
#include <stdio.h>

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
    Q->front = NULL;
    Q->rear = NULL;/*��ͷ��βָ���ָ��*/
    Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
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
    free(Q->front);/*��ͷ��β�غ�*/
    free(Q);
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
	if(Q->length == 0) return FALSE;
    else return TRUE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e)
{
	if(Q->length == 0) 
    {
        printf("������ͷԪ��\n");
        getchar();/*��ȡ�������Ļس���*/
        return FALSE;
    }
    else
    {
        e = Q->front->data;
        if(datatype[0] == 1)
            printf("��ͷԪ��Ϊ%d\n", *((int*)e));
        else if(datatype[0] == 2)
            printf("��ͷԪ��Ϊ%f\n", *((float*)e));
        else if(datatype[0] == 3)
            printf("��ͷԪ��Ϊ%c\n", *((char*)e));
        else if(datatype[0] = 4)
        {
            printf("��ͷԪ��Ϊ");
            puts((char*)e);
            printf("\n");
        }
        getchar();/*��ȡ�������Ļس���*/
    }
    return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
	if(Q->front == NULL) return;
    Node *temp = Q->front;
    int num = 0;
    while(Q->front != Q->rear)
        DeLQueue(Q);
    free(Q->front);/*ͷβ�غ�*/
    Q->front = Q->rear = NULL;
    Q->length = 0;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
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
 *    @description : ��������
 *    @param         q ָ��q

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

