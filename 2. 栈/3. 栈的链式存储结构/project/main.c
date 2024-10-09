#include <stdio.h>
#include <stdlib.h>

//��������ͷ�����м�¼��ַ����ջû�У�����ʹ�ú�����װ��Ҫʹ�ö���ָ�������ص�һ������ֵ�͵�ַ��������������

typedef int ElemType;

typedef struct{
    ElemType data;
    struct ListStack *next;
}ListStack;
typedef ListStack* LinkStack;

//��ʼ��ջ
void ListStack_Init(LinkStack *pstack){
    *pstack = NULL;
}

//ѹջ
void ListStack_Push(LinkStack *headnode,ElemType dat){
    LinkStack newnode = (LinkStack)malloc(sizeof(ListStack));
    if(newnode == NULL){
        printf("�����ڴ�ʧ��\r\n");
        return;
    }
    //ʵ��Ϊ����ͷ�����뷨��ֻ������ʱ��ͷ���
    newnode->data = dat;
    newnode->next = *headnode;   //ָ���һ�����
    *headnode = newnode;         //ջ�ĵ�һ�����ı�
}

//��ջ
ElemType ListStack_Pop(LinkStack *pstack){
    ElemType pop_data = 0;
    LinkStack headnode = *pstack;
    if(*pstack == NULL){   //��ջ
        printf("��ջ\r\n");
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
