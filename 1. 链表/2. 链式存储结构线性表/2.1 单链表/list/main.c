#include <stdio.h>
#include <stdlib.h>

typedef enum{ERROR = 0,SUCCESS}Status;

//定义一个结点
struct LNode{
    int data;
    struct LNode *next;
}LNode;
typedef struct LNode* LinkList;  //LinkList = struct LNode*

/**********************链表建立和插入**********************/
//创建一个空表
LinkList CreatList(){
    //headlist 指针在申请成功内存后变成了一个结构体变量
    LinkList headlist = (LinkList)malloc(sizeof(LNode));
    if(headlist == NULL){   //内存不足，申请失败
        printf("内存申请失败\r\n");
        return NULL;
    }
    //给变量初始化，其中头结点的数据域通常不赋值
//    headlist->data = 1;
    headlist->next = NULL;
    return headlist;
}

//创建结点
LinkList CreatNode(int dat){
    LinkList newnode = (LinkList)malloc(sizeof(LNode));
    newnode->data = dat;
    newnode->next = NULL;
    return newnode;
}

//通过头插法插入结点
void InsertNode_ByHead(LinkList headnode,int dat){
    LinkList newnode = CreatNode(dat);
    //以下两行代码顺序不能变，不然会丢数据
    newnode->next = headnode->next;
    headnode->next = newnode;
}

//通过尾插法插入结点
void InsertNode_ByTail(LinkList headnode,int dat){
    LinkList newnode = CreatNode(dat);
    LinkList plisttail = headnode;      //需要指向当前链表的末尾
    while(plisttail->next != NULL){     //寻找链表尾部
        plisttail = plisttail->next;
    }
    plisttail->next = newnode;
}

//在任意位置插入结点
void InsertNode_ByAnyLocation(LinkList headnode,int dat,int location){
    LinkList new_node = CreatNode(dat);
    LinkList plist = headnode->next;
    LinkList plistfront = headnode;
    int length = 1;
    if((headnode->next == NULL && location != 1) || (location < 1))    //空表且插入位置不为1或者错误位置
        return;
    while(length++ != location){
        if(plist->next == NULL && length != location)
            return;
        plistfront = plist;
        plist = plist->next;
    }
    new_node->next = plist;
    plistfront->next = new_node;
}

/**********************链表查找**********************/
//按指定位置查找数据，错误位置返回-1,正确位置返回数据
int SearchList_ByLocation(LinkList headnode,int location){
    LinkList plist = headnode;
    if(location < 1)    //错误位置，位置太小
        return -1;
    for(int i = 1;i <= location;i++){
        if(plist->next == NULL)     //错误位置，位置太大，必须得放在上面
            return -1;
        plist = plist->next;
    }
    return plist->data;
}

//查找指定数据的位置，无此数据返回-1,正确数据返回位置
int SearchList_ByData(LinkList headnode,int search_data){
    LinkList plist = headnode->next;
    int length = 1;
    if(headnode->next == NULL)  //空表
        return -1;
    while(plist->data != search_data){
        if(plist->next == NULL)         //链表中没有此数据
            return -1;
        plist = plist->next;
        length++;
    }
    return length;
}

/**********************链表删除**********************/
//删除指定数据的结点
void DeleteList_PointData(LinkList headnode,int dat){
    LinkList nodenext  = headnode->next;
    LinkList nodefront = headnode;
    if(nodenext == NULL){
        printf("空链表无法删除\r\n");
        return;
    }
    while(nodenext->data != dat){
        nodefront = nodenext;
        nodenext  = nodefront->next;
        if(nodenext == NULL){
            printf("链表中无此数据\r\n");
            return;
        }
    }
    nodefront->next = nodenext->next;
    free(nodenext);
}

//删除指定位置的结点
void DeleteList_PointLocation(LinkList headnode,int location){
    LinkList plist = headnode->next;
    LinkList plistfront = headnode;
    int length = 1;
    if((location < 1) && (headnode->next == NULL)){
        printf("未知错误或空链表导致的无法删除\r\n");
        return;
    }
    while(length++ != location){
        if(plist->next == NULL){
            printf("无此位置\r\n");
            return;
        }
        plistfront = plist;
        plist = plist->next;
    }
    plistfront->next = plist->next;
    free(plist);
}

/**********************链表打印即遍历链表**********************/
//打印结点数据
void PrintList(LinkList headnode){
	//指向头结点的下一个结点是因为头结点数据域无数据或不需要打印
    LinkList pmove = headnode->next;
    while(pmove){	//判断pmove是否指向NULL
        printf("%d\n",pmove->data);
        pmove = pmove->next;
    }
}

int main(){
    LinkList head = CreatList();    //用于头插法
    LinkList tail = CreatList();    //用于尾插法
    LinkList empty_list = CreatList();    //空表
    printf("=================头插法====================\n");
    for(int i = 10;i > 0;i--){
        InsertNode_ByHead(head,i);
    }
    PrintList(head);
    printf("=================删除链表中的数据10==================\n");
    DeleteList_PointData(head,10);
    PrintList(head);
    printf("=================尾插法====================\n");
    for(int i = 1;i <= 10;i++){
        InsertNode_ByTail(tail,i);
    }
    PrintList(tail);
    printf("=================查找第八位数据====================\n");
    printf("%d\r\n",SearchList_ByLocation(tail,8));
    printf("=================查找8的位置====================\n");
    printf("%d\r\n",SearchList_ByData(tail,8));
    printf("=================在第八位插入100并打印队列====================\n");
    InsertNode_ByAnyLocation(tail,100,8);
    PrintList(tail);
    printf("=================删除第8位数据====================\n");
    DeleteList_PointLocation(tail,8);
    PrintList(tail);
    return 0;
}


