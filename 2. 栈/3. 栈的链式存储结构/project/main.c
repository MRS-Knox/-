#include <stdio.h>
#include <stdlib.h>

//单链表有头结点进行记录地址，而栈没有，所以使用函数封装需要使用二级指针来返回第一个结点的值和地址！！！！！！！

typedef int ElemType;

typedef struct{
    ElemType data;
    struct ListStack *next;
}ListStack;
typedef ListStack* LinkStack;

//初始化栈
void ListStack_Init(LinkStack *pstack){
    *pstack = NULL;
}

//压栈
void ListStack_Push(LinkStack *headnode,ElemType dat){
    LinkStack newnode = (LinkStack)malloc(sizeof(ListStack));
    if(newnode == NULL){
        printf("申请内存失败\r\n");
        return;
    }
    //实质为链表头结点插入法，只不过此时无头结点
    newnode->data = dat;
    newnode->next = *headnode;   //指向第一个结点
    *headnode = newnode;         //栈的第一个结点改变
}

//弹栈
ElemType ListStack_Pop(LinkStack *pstack){
    ElemType pop_data = 0;
    LinkStack headnode = *pstack;
    if(*pstack == NULL){   //空栈
        printf("空栈\r\n");
        return;
    }
    pop_data = (*pstack)->data;
    *pstack  = (*pstack)->next;
    free(headnode);
    return pop_data;
}

LinkStack stack;
int main(){
    ElemType data;
    ListStack_Init(&stack);
    for(int i = 6000;i > 0;i--){
        ListStack_Push(&stack,i);
    }
    for(int i = 0;i < 6000;i++){
        data = ListStack_Pop(&stack);
        printf("%d\r\n",data);
    }
    return 0;
}
