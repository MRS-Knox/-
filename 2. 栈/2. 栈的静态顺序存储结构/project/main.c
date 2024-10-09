#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

#define BUFF_MAX    50  //ջ�Ĵ�С
typedef struct{
    ElemType stack_buff[BUFF_MAX];
    int top;    //��¼ջ��λ��
}sStaticStack;
typedef sStaticStack* LinkStack; //�ض���sStaticStack*

sStaticStack stack1;    //����һ��ջ

//ջ��ʼ��
void StaticStack_Init(LinkStack pstack){
    pstack->top = -1;   //��-1��¼��ʱΪ��ջ
}

//ѹջ
void StaticStack_Push(LinkStack pstack,ElemType data){
    if(pstack->top == BUFF_MAX-1){ //ջ��
        return;
    }
    pstack->stack_buff[++pstack->top] = data;
}

//��ջ
ElemType StaticStack_Pop(LinkStack pstack){
    ElemType data = 0;
    if(pstack->top == -1){ //��ջ
        return;
    }
    data = pstack->stack_buff[pstack->top--];
//    pstack->top--;
    return data;
}


int main(){
    ElemType data = 0;
    StaticStack_Init(&stack1);
    for(int i = 0;i < 10;i++){
        StaticStack_Push(&stack1,(ElemType)i);
    }
    for(int i = 0;i < 10;i++){
        data = StaticStack_Pop(&stack1);
        printf("%d\r\n",data);
    }

    return 0;
}
