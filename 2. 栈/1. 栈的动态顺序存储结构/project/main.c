#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;   //���������ض���
#define INCREASESTACK_SIZE  10  //һ������ʮ��ElemType

/******************ջ�Ĵ���***************************/
typedef struct{
    ElemType *bottom;    //ָ��ջ��
    ElemType *top;       //ָ��ջ��
    int stack_size;     //ջ�Ĵ�С
}sqStack;

typedef sqStack* LinkStack;
sqStack test_stack; //����һ������ջ

//����һ����ջ
void CreateStack(LinkStack pstack,int size){
    pstack->bottom = (ElemType*)malloc(size*sizeof(ElemType));
    if(pstack->bottom == NULL){
        printf("�ڴ�����ʧ��\r\n");
        return NULL;
    }
    pstack->top = pstack->bottom;   //��ջ��Ҫ��ջ��ָ��ָ��ջ��
    pstack->stack_size = size;      //��¼ջ�Ĵ�С
}

/******************ջ��Ԫ�ؽ�����ʹ�ú�ʣ�������ļ���***************************/
//ջ������ջ��С
void IncreaseStack(LinkStack pstack){
    pstack->bottom = (ElemType*)realloc(pstack->bottom,(INCREASESTACK_SIZE+pstack->stack_size)*sizeof(ElemType));
    if(pstack->bottom == NULL){
        printf("�ڴ�����ʧ��\r\n");
        return NULL;
    }
//    pstack->top = pstack->bottom + pstack->stack_size;    //�����ﲻ����������䣬�ûᵼ����һ���洢λ��û�д�������
    pstack->stack_size += INCREASESTACK_SIZE;
}

//ѹջ��Ԫ�ؽ�ջ
void PullStack(LinkStack pstack,ElemType data){
    if(pstack->top - pstack->bottom >= pstack->stack_size - 1){     //�ж�ջ�Ƿ���
        IncreaseStack(pstack);
    }
    *pstack->top = data;
    pstack->top++;
}

//��ջ��Ԫ�س�ջ
ElemType PopStack(LinkStack pstack){
    ElemType data = 0;
    if(pstack->top == pstack->bottom){   //��ջ
        return -1;
    }
    pstack->top--;
    data = *pstack->top;
    return data;
}

//����ջ��ʣ������
int CalStack_Surplus(LinkStack pstack){
    int surplus_capacity = 0;
    surplus_capacity = pstack->top - pstack->bottom;
    surplus_capacity = pstack->stack_size - surplus_capacity;
    return surplus_capacity;
}

//����ջ��ʹ������
int CalStack_Use(LinkStack pstack){
    int use_capacity = 0;
    //ֵ��ע�����ָ������õ����������ٸ�Ԫ�أ����ǵ�ַ���ʶ����������Ϊ(pstack->top - pstack->bottom)/ElemType
    use_capacity = pstack->top - pstack->bottom;
    return use_capacity;
}


/******************���ջ������ջ***************************/
//���ջ����
void ClearStack(LinkStack pstack){
    pstack->top = pstack->bottom;  //��ջ��ָ��ָ��ջ��ָ��
}

//����ջ����
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
//    printf("==================����ջ����ջ��ֵ====================\r\n");
    CreateStack(&test_stack,50);
    for(ElemType i = 1;i <= 60;i++){
        PullStack(&test_stack,i);
    }
    printf("ʣ��������%d\n",CalStack_Surplus(&test_stack));   //��ӡջ��ʣ������
    printf("ʹ��������%d\n",CalStack_Use(&test_stack));       //��ӡջ��ʹ������
    while(1){
        data = PopStack(&test_stack);
        if(data == -1)
            break;
        printf("%d\n",data);
    }
//    printf("==================���ջ====================\r\n");
//    ClearStack(&test_stack);
//    while(1){
//        data = PopStack(&test_stack);
//        if(data == -1)
//            break;
//        printf("%d\n",data);
//    }
//    printf("%d\n",CalStack_Surplus(&test_stack));
//    printf("==================����ջ====================\r\n");
//    DestroyStack(&test_stack);
    return 0;
}
