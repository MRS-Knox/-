#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

#define BUFF_MAX    50  //栈的大小
typedef struct{
    ElemType stack_buff[BUFF_MAX];
    int top;    //记录栈顶位置
}sStaticStack;
typedef sStaticStack* LinkStack; //重定义sStaticStack*

sStaticStack stack1;    //定义一个栈

//栈初始化
void StaticStack_Init(LinkStack pstack){
    pstack->top = -1;   //用-1记录此时为空栈
}

//压栈
void StaticStack_Push(LinkStack pstack,ElemType data){
    if(pstack->top == BUFF_MAX-1){ //栈满
        return;
    }
    pstack->stack_buff[++pstack->top] = data;
}

//弹栈
ElemType StaticStack_Pop(LinkStack pstack){
    ElemType data = 0;
    if(pstack->top == -1){ //空栈
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
