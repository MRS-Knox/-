#include <stdio.h>
#include <stdlib.h>

typedef enum{ERROR = 0,SUCCESS,}Status;
#define BUFF_MAX  20
typedef struct {
    int listdata_buff[BUFF_MAX];
    int buff_length;
}Sqlist;
Sqlist Sqlist1;

//  获取在链表中第i位置的数据，数据存放在pdata指向的变量中
Status Get_ListData(Sqlist *plist,int i,int *pdata){
    if(plist->buff_length == 0)     //空表
        return ERROR;
    if(i > BUFF_MAX || i < 1 || i > plist->buff_length) //判断其位置是否为有效位置
        return ERROR;
    *pdata = plist->listdata_buff[i-1];
    return SUCCESS;
}

//  在列表中的第location个位置插入数据data
Status Insert_ListData(Sqlist *plist,int location,int data){
    int count = 0;
    if(plist->buff_length == BUFF_MAX)     //链表已经满了
        return ERROR;
    if(location > BUFF_MAX || location < 1)   //需要插入的位置无效
        return ERROR;
    if(location > plist->buff_length+1)    //位置不在当前链表之中，也定义为无效位置
        return ERROR;
//    if(location == plist->buff_length+1){  //插入在链表末尾
//        plist->listdata_buff[location-1] = data;
//        plist->buff_length++;
//        return SUCCESS;
//    }
    if(location <= plist->buff_length){  //插入到链表中间
        for(count = plist->buff_length-1;count >= location-1;count--){  //后面的数据后移
            plist->listdata_buff[count+1] = plist->listdata_buff[count];
        }
    }
    plist->listdata_buff[location-1] = data;
    plist->buff_length++;
    return SUCCESS;
}

//  将列表中的第location个位置数据删除
Status Delete_ListData(Sqlist *plist,int location){
    int count = 0;
    if(plist->buff_length == 0)     //空表
        return ERROR;
    if(location < 1 || location > plist->buff_length)   //需要删除的位置无效
        return ERROR;
    for(count = location-1;count <= plist->buff_length-1;count++){  //后面的数据前移
        plist->listdata_buff[count] = plist->listdata_buff[count+1];
    }
    plist->buff_length--;
    return SUCCESS;
}


int mdata = 500;
int mdata2 = 0;
int main(){
    /*初始化链表数据*/
    for(Sqlist1.buff_length = 1;Sqlist1.buff_length <= 5;Sqlist1.buff_length++){
        Sqlist1.listdata_buff[Sqlist1.buff_length-1] = mdata;
        mdata++;
    }
    Sqlist1.buff_length = 5;
    /*查询链表指定位置的数据*/
    printf("/***************查找操作**************/\n");
    if(SUCCESS == Get_ListData(&Sqlist1,15,&mdata)){
        printf("The fifteenth mdata is %d",mdata);
    }
    else{
        printf("LOCATION ERROR\n");
        Get_ListData(&Sqlist1,5,&mdata);
        printf("The fifth mdata is %d\n",mdata);
    }
    /*链表指定位置插入数据*/
    printf("/***************插入操作**************/\n");
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
    /*删除指定位置的数据*/
    printf("/***************删除操作**************/\n");
    if(SUCCESS == Delete_ListData(&Sqlist1,6)){
        for(mdata = 0;mdata < Sqlist1.buff_length;mdata++){
            printf("%d\n",Sqlist1.listdata_buff[mdata]);
        }
    }

    printf("/***************程序结束**************/\n");
    return 0;
}
