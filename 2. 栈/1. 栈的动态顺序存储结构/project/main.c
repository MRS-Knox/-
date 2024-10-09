#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;   //基本类型重定义
#define INCREASESTACK_SIZE  10  //一次增长十个ElemType

/******************栈的创建***************************/
typedef struct{
    ElemType *bottom;    //指向栈底
    ElemType *top;       //指向栈顶
    int stack_size;     //栈的大小
}sqStack;

typedef sqStack* LinkStack;
sqStack test_stack; //定义一个测试栈

//创建一个空栈
void CreateStack(LinkStack pstack,int size){
    pstack->bottom = (ElemType*)malloc(size*sizeof(ElemType));
    if(pstack->bottom == NULL){
        printf("内存申请失败\r\n");
        return NULL;
    }
    pstack->top = pstack->bottom;   //空栈需要把栈顶指针指向栈底
    pstack->stack_size = size;      //记录栈的大小
}

/******************栈的元素进出、使用和剩余容量的计算***************************/
//栈满扩容栈大小
void IncreaseStack(LinkStack pstack){
    pstack->bottom = (ElemType*)realloc(pstack->bottom,(INCREASESTACK_SIZE+pstack->stack_size)*sizeof(ElemType));
    if(pstack->bottom == NULL){
        printf("内存申请失败\r\n");
        return NULL;
    }
//    pstack->top = pstack->bottom + pstack->stack_size;    //我这里不适用这条语句，用会导致有一个存储位置没有存入数据
    pstack->stack_size += INCREASESTACK_SIZE;
}

//压栈即元素进栈
void PullStack(LinkStack pstack,ElemType data){
    if(pstack->top - pstack->bottom >= pstack->stack_size - 1){     //判断栈是否满
        IncreaseStack(pstack);
    }
    *pstack->top = data;
    pstack->top++;
}

//弹栈即元素出栈
ElemType PopStack(LinkStack pstack){
    ElemType data = 0;
    if(pstack->top == pstack->bottom){   //空栈
        return -1;
    }
    pstack->top--;
    data = *pstack->top;
    return data;
}

//计算栈的剩余容量
int CalStack_Surplus(LinkStack pstack){
    int surplus_capacity = 0;
    surplus_capacity = pstack->top - pstack->bottom;
    surplus_capacity = pstack->stack_size - surplus_capacity;
    return surplus_capacity;
}

//计算栈的使用容量
int CalStack_Use(LinkStack pstack){
    int use_capacity = 0;
    //值得注意的是指针相减得到的是相距多少个元素，而非地址，故而下列相减即为(pstack->top - pstack->bottom)/ElemType
    use_capacity = pstack->top - pstack->bottom;
    return use_capacity;
}


/******************清空栈和销毁栈***************************/
//清空栈操作
void ClearStack(LinkStack pstack){
    pstack->top = pstack->bottom;  //将栈顶指针指向栈底指针
}

//销毁栈操作
void DestroyStack(LinkStack pstack){
    for(int i = 0;i < pstack->stack_size;i++){
        free(pstack->bottom);
        pstack->bottom++;
    }
    pstack->bottom = NULL;
    pstack->top = NULL;
    pstack->stack_size = 0;
}


int main(){
    ElemType data;
//    printf("==================创建栈并给栈赋值====================\r\n");
    CreateStack(&test_stack,50);
    for(ElemType i = 1;i <= 60;i++){
        PullStack(&test_stack,i);
    }
    printf("剩余容量：%d\n",CalStack_Surplus(&test_stack));   //打印栈的剩余容量
    printf("使用容量：%d\n",CalStack_Use(&test_stack));       //打印栈的使用容量
    while(1){
        data = PopStack(&test_stack);
        if(data == -1)
            break;
        printf("%d\n",data);
    }
//    printf("==================清空栈====================\r\n");
//    ClearStack(&test_stack);
//    while(1){
//        data = PopStack(&test_stack);
//        if(data == -1)
//            break;
//        printf("%d\n",data);
//    }
//    printf("%d\n",CalStack_Surplus(&test_stack));
//    printf("==================销毁栈====================\r\n");
//    DestroyStack(&test_stack);
    return 0;
}
