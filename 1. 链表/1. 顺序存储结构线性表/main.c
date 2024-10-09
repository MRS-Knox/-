#include <stdio.h>
#include <stdlib.h>

typedef enum{ERROR = 0,SUCCESS,}Status;
#define BUFF_MAX  20
typedef struct {
    int listdata_buff[BUFF_MAX];
    int buff_length;
}Sqlist;
Sqlist Sqlist1;

//  ��ȡ�������е�iλ�õ����ݣ����ݴ����pdataָ��ı�����
Status Get_ListData(Sqlist *plist,int i,int *pdata){
    if(plist->buff_length == 0)     //�ձ�
        return ERROR;
    if(i > BUFF_MAX || i < 1 || i > plist->buff_length) //�ж���λ���Ƿ�Ϊ��Чλ��
        return ERROR;
    *pdata = plist->listdata_buff[i-1];
    return SUCCESS;
}

//  ���б��еĵ�location��λ�ò�������data
Status Insert_ListData(Sqlist *plist,int location,int data){
    int count = 0;
    if(plist->buff_length == BUFF_MAX)     //�����Ѿ�����
        return ERROR;
    if(location > BUFF_MAX || location < 1)   //��Ҫ�����λ����Ч
        return ERROR;
    if(location > plist->buff_length+1)    //λ�ò��ڵ�ǰ����֮�У�Ҳ����Ϊ��Чλ��
        return ERROR;
//    if(location == plist->buff_length+1){  //����������ĩβ
//        plist->listdata_buff[location-1] = data;
//        plist->buff_length++;
//        return SUCCESS;
//    }
    if(location <= plist->buff_length){  //���뵽�����м�
        for(count = plist->buff_length-1;count >= location-1;count--){  //��������ݺ���
            plist->listdata_buff[count+1] = plist->listdata_buff[count];
        }
    }
    plist->listdata_buff[location-1] = data;
    plist->buff_length++;
    return SUCCESS;
}

//  ���б��еĵ�location��λ������ɾ��
Status Delete_ListData(Sqlist *plist,int location){
    int count = 0;
    if(plist->buff_length == 0)     //�ձ�
        return ERROR;
    if(location < 1 || location > plist->buff_length)   //��Ҫɾ����λ����Ч
        return ERROR;
    for(count = location-1;count <= plist->buff_length-1;count++){  //���������ǰ��
        plist->listdata_buff[count] = plist->listdata_buff[count+1];
    }
    plist->buff_length--;
    return SUCCESS;
}


int mdata = 500;
int mdata2 = 0;
int main(){
    /*��ʼ����������*/
    for(Sqlist1.buff_length = 1;Sqlist1.buff_length <= 5;Sqlist1.buff_length++){
        Sqlist1.listdata_buff[Sqlist1.buff_length-1] = mdata;
        mdata++;
    }
    Sqlist1.buff_length = 5;
    /*��ѯ����ָ��λ�õ�����*/
    printf("/***************���Ҳ���**************/\n");
    if(SUCCESS == Get_ListData(&Sqlist1,15,&mdata)){
        printf("The fifteenth mdata is %d",mdata);
    }
    else{
        printf("LOCATION ERROR\n");
        Get_ListData(&Sqlist1,5,&mdata);
        printf("The fifth mdata is %d\n",mdata);
    }
    /*����ָ��λ�ò�������*/
    printf("/***************�������**************/\n");
    if(SUCCESS == Insert_ListData(&Sqlist1,10,15)){
        Get_ListData(&Sqlist1,10,&mdata);
        printf("The fifteenth mdata is %d",mdata);
    }
    else{
        printf("INSERT ERROR\n");
        if(SUCCESS == Insert_ListData(&Sqlist1,6,505)){
            for(mdata = 0;mdata < Sqlist1.buff_length;mdata++){
                printf("%d\n",Sqlist1.listdata_buff[mdata]);
            }
            if(SUCCESS == Get_ListData(&Sqlist1,6,&mdata))
                printf("%d\n",mdata);
        }
    }
    /*ɾ��ָ��λ�õ�����*/
    printf("/***************ɾ������**************/\n");
    if(SUCCESS == Delete_ListData(&Sqlist1,6)){
        for(mdata = 0;mdata < Sqlist1.buff_length;mdata++){
            printf("%d\n",Sqlist1.listdata_buff[mdata]);
        }
    }

    printf("/***************�������**************/\n");
    return 0;
}
