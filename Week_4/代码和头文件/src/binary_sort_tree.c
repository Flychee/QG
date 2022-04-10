#include "../inc/binary_sort_tree.h"
/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr BSTP)
{
    BSTP->root = (NodePtr)malloc(sizeof(Node));
    BSTP->root->value = -1;
    BSTP->root->left = NULL;
    BSTP->root->right = NULL;
    return succeed;
};

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(BinarySortTreePtr BSTP, ElemType i)
{
    if(BSTP == NULL||BSTP->root == NULL) return failed;

    NodePtr p1 = NULL;
    if(BSTP->root->value == -1)/*初始根节点赋值*/
    {
        BSTP->root->value = i;
        return succeed;
    }

    else/*存在根节点*/
    {
        p1 = BSTP->root;
        while(1)
        {
            NodePtr temp = NULL;
            if(p1 ->value == i)
            {
                printf("数据已存在\n");
                return succeed;
            }
            else if(p1->value > i)/*进入左节点*/
            {
                if(p1->left == NULL)
                {
                    temp = (NodePtr)malloc(sizeof(Node));
                    temp->left = NULL;
                    temp->right = NULL;
                    temp->value = i;
                    p1->left = temp;
                    temp = NULL;
                    return succeed;
                }
                else p1 = p1->left;
            }
            else /*进入右节点*/
            {
                if(p1->right == NULL)
                {
                    temp = (NodePtr)malloc(sizeof(Node));
                    temp->left = NULL;
                    temp->right = NULL;
                    temp->value = i;
                    p1->right = temp;
                    temp = NULL;
                    return succeed;
                }
                else p1 = p1->right;
            }
        }
    }
};

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete(BinarySortTreePtr BSTP, ElemType i)
{
    if(BSTP == NULL||BSTP->root == NULL) return failed;
    NodePtr p1 = BSTP->root;/*遍历*/
    NodePtr p2 = BSTP->root;/*指向p1父节点*/
    NodePtr temp1,temp2;/*用于双子节点删除情况*/
    while(p1 != NULL)
    {
        if(p1->value == i)/*找到数据*/
        {
            if(p1->left ==  NULL&&p1->right == NULL)/*叶子*/
            {
                if(p1 == BSTP->root)/*仅有根节点*/
                {
                    p1->value = -1;
                    return succeed;
                }
                if(i < p2->value)
                {
                    p2->left = NULL;
                    free(p1);
                    return succeed;
                }
                else if(i > p2->value)
                {
                    p2->right = NULL;
                    free(p1);
                    return succeed;
                }
            }

            else if(p1->left !=  NULL&&p1->right != NULL)/*有两个子节点*/
            {
                for(temp1 = p1->left; temp1->right!= NULL ;temp2 = temp1 , temp1 = temp1->right);
                if(temp1 == p1->left)/*左子树最大值为p1左子节点*/
                {
                    p1->value = temp1->value;
                    p1->left = temp1->left;
                    free(temp1);
                }
                else
                {
                    temp2->right = temp1->left;
                    p1->value = temp1->value;
                    free(temp1); 
                }
            }

            else/*一个子结点*/
            {
                if(p1 == BSTP->root)/*仅有根节点*/
                {
                    if(p1->left == NULL)
                    {
                        p2 = p1->right;
                        BSTP->root = p2;
                        free(p1);
                    }
                    else if(p1->right == NULL)
                    {
                        p2 = p1->left;
                        BSTP->root = p2;
                        free(p1);
                    }
                    return succeed;
                }
                if(i < p2->value)
                {
                    if(p1->left == NULL)
                    {
                        p2->left = p1->right;
                        free(p1);
                    }
                    else if(p1->right == NULL)
                    {
                        p2->right = p1->left;
                        free(p1);
                    }
                    return succeed;
                }
                else if(i > p2->value)
                {
                    if(p1->left == NULL)
                    {
                        p2->right = p1->right;
                        free(p1);
                    }
                    else if(p1->right == NULL)
                    {
                        p2->right = p1->left;
                        free(p1);
                    }
                    return succeed;
                }
            }
        }
        else if(p1->value > i)
        {
            p2 =p1;
            p1 = p1->left;
        }
        else if(p1->value < i)
        {
            p2 =p1;
            p1 = p1->right;
        }
    }
    printf("不存在该数据\n");
    return failed;
};

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(BinarySortTreePtr BSTP, ElemType i)
{
    if(BSTP == NULL || BSTP->root == NULL)
        return failed;
    NodePtr p1 = BSTP->root;
    while(p1 != NULL)
    {
        if(i < p1->value)
            p1 = p1->left;
        else if(i > p1->value)
            p1 = p1->right;
        else
            return succeed;
    }
    return failed;
};

void visit(NodePtr p1)
{
    printf("%d ",p1->value);
}

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderI(BinarySortTreePtr BSTP, void (*visit)(NodePtr p1))
{
    if(BSTP == NULL || BSTP->root == NULL)return failed;
    typedef struct level
    {
        NodePtr data;
        struct level* next;
    }level;

    level *head = NULL;
    level *temp = NULL;
    NodePtr p1 = BSTP->root;
    while(p1 != NULL||head != NULL)
    {
        if(p1 != NULL)
        {
            visit(p1);

            temp = (level*)malloc(sizeof(level));
            temp->data = p1;
            temp->next = head;
            head = temp;/*压栈*/
            temp = NULL;
            p1 = p1->left;
        }
        else
        {
            p1 = head->data;
            temp = head;
            head = head->next;
            free(temp);/*出栈*/
            p1 = p1->right;
        }
    }

};

/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderR(BinarySortTreePtr BSTP, void (*visit)(NodePtr p1))
{
    if(BSTP == NULL || BSTP->root == NULL) return failed;
    BinarySortTreePtr lBSTP,rBSTP;
    lBSTP = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
    rBSTP = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
    lBSTP->root = BSTP->root->left;
    rBSTP->root = BSTP->root->right;
    visit(BSTP->root);
	BST_preorderR(lBSTP,visit);
    BST_preorderR(rBSTP,visit);
};

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderI(BinarySortTreePtr BSTP, void (*visit)(NodePtr p1))
{
    if(BSTP == NULL || BSTP->root == NULL)return failed;
    typedef struct level
    {
        NodePtr data;
        struct level* next;
    }level;
    level *head = NULL;
    level *temp = NULL;
    NodePtr p1 = BSTP->root;
    while(p1 != NULL||head != NULL)
    {
        if(p1 != NULL)
        {
            temp = (level*)malloc(sizeof(level));
            temp->data = p1;
            temp->next = head;
            head = temp;/*压栈*/
            temp = NULL;
            p1 = p1->left;
        }
        else
        {
            p1 = head->data;
            visit(p1);

            temp = head;
            head = head->next;
            free(temp);/*出栈*/
            p1 = p1->right;
        }
    }
};

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderR(BinarySortTreePtr BSTP, void (*visit)(NodePtr p1))
{
    if(BSTP == NULL || BSTP->root == NULL) return failed;
    BinarySortTreePtr lBSTP,rBSTP;
    lBSTP = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
    rBSTP = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
    lBSTP->root = BSTP->root->left;
    rBSTP->root = BSTP->root->right;
	BST_inorderR(lBSTP,visit);
    visit(BSTP->root);
    BST_inorderR(rBSTP,visit);
};

/**
 * BST postorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderI(BinarySortTreePtr BSTP, void (*visit)(NodePtr p1))
{
    if(BSTP == NULL || BSTP->root == NULL)return failed;
    typedef struct level
    {
        NodePtr data;
        struct level* next;
    }level;
    level *head = NULL;
    level *temp = NULL;
    NodePtr p1 = BSTP->root;
    NodePtr mark = NULL;
    while(p1 != NULL||head != NULL)
    {
        if(p1 != NULL)
        {
            temp = (level*)malloc(sizeof(level));
            temp->data = p1;
            temp->next = head;
            head = temp;/*压栈*/
            temp = NULL;
            p1 = p1->left;
        }
        else
        {
            p1 = head->data;
            if(p1->right != NULL && p1->right != mark)
            {
                p1 = p1->right;
                temp = (level*)malloc(sizeof(level));
                temp->data = p1;
                temp->next = head;
                head = temp;/*压栈*/
                temp = NULL;
                p1 = p1->left;
            }
            else
            {
                temp = head;
                head = head->next;
                free(temp);/*出栈*/
                visit(p1);
                mark = p1;
                p1 = NULL;
            }
        }
    }
};

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderR(BinarySortTreePtr BSTP, void (*visit)(NodePtr p1))
{
    if(BSTP == NULL || BSTP->root == NULL) return failed;
    BinarySortTreePtr lBSTP,rBSTP;
    lBSTP = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
    rBSTP = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
    lBSTP->root = BSTP->root->left;
    rBSTP->root = BSTP->root->right;
	BST_postorderR(lBSTP,visit);
    BST_postorderR(rBSTP,visit);
    visit(BSTP->root);
};

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(BinarySortTreePtr BSTP, void (*visit)(NodePtr p1))
{
    if(BSTP == NULL || BSTP->root == NULL)return failed;
    typedef struct level
    {
        NodePtr data;
        struct level* next;
    }level;
    level *head;
    head = (level*)malloc(sizeof(level));
    head->data = BSTP->root;
    head->next = NULL;
    level *p1 = head;
    while(head != NULL)
    {
        level *p2;/*操作指针*/
        visit(head->data);
        if(head->data->left != NULL)
        {
            p2 = (level*)malloc(sizeof(level));
            p2->data = head->data->left;
            p2->next = NULL;
            p1->next = p2;
            p1 = p1->next;
            p2 = NULL;
        }
        if(head->data->right != NULL)
        {
            p2 = (level*)malloc(sizeof(level));
            p2->data = head->data->right;
            p2->next = NULL;
            p1->next = p2;
            p1 = p1->next;
            p2 = NULL;
        }
        p2 = head;
        head = head->next;
        free(p2);
    }
};

