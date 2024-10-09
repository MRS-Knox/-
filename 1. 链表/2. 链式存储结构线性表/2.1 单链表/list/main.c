#include <stdio.h>
#include <stdlib.h>

typedef enum{ERROR = 0,SUCCESS}Status;

//����һ�����
struct LNode{
    int data;
    struct LNode *next;
}LNode;
typedef struct LNode* LinkList;  //LinkList = struct LNode*

/**********************�������Ͳ���**********************/
//����һ���ձ�
LinkList CreatList(){
    //headlist ָ��������ɹ��ڴ������һ���ṹ�����
    LinkList headlist = (LinkList)malloc(sizeof(LNode));
    if(headlist == NULL){   //�ڴ治�㣬����ʧ��
        printf("�ڴ�����ʧ��\r\n");
        return NULL;
    }
    //��������ʼ��������ͷ����������ͨ������ֵ
//    headlist->data = 1;
    headlist->next = NULL;
    return headlist;
}

//�������
LinkList CreatNode(int dat){
    LinkList newnode = (LinkList)malloc(sizeof(LNode));
    newnode->data = dat;
    newnode->next = NULL;
    return newnode;
}

//ͨ��ͷ�巨������
void InsertNode_ByHead(LinkList headnode,int dat){
    LinkList newnode = CreatNode(dat);
    //�������д���˳���ܱ䣬��Ȼ�ᶪ����
    newnode->next = headnode->next;
    headnode->next = newnode;
}

//ͨ��β�巨������
void InsertNode_ByTail(LinkList headnode,int dat){
    LinkList newnode = CreatNode(dat);
    LinkList plisttail = headnode;      //��Ҫָ��ǰ�����ĩβ
    while(plisttail->next != NULL){     //Ѱ������β��
        plisttail = plisttail->next;
    }
    plisttail->next = newnode;
}

//������λ�ò�����
void InsertNode_ByAnyLocation(LinkList headnode,int dat,int location){
    LinkList new_node = CreatNode(dat);
    LinkList plist = headnode->next;
    LinkList plistfront = headnode;
    int length = 1;
    if((headnode->next == NULL && location != 1) || (location < 1))    //�ձ��Ҳ���λ�ò�Ϊ1���ߴ���λ��
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

/**********************�������**********************/
//��ָ��λ�ò������ݣ�����λ�÷���-1,��ȷλ�÷�������
int SearchList_ByLocation(LinkList headnode,int location){
    LinkList plist = headnode;
    if(location < 1)    //����λ�ã�λ��̫С
        return -1;
    for(int i = 1;i <= location;i++){
        if(plist->next == NULL)     //����λ�ã�λ��̫�󣬱���÷�������
            return -1;
        plist = plist->next;
    }
    return plist->data;
}

//����ָ�����ݵ�λ�ã��޴����ݷ���-1,��ȷ���ݷ���λ��
int SearchList_ByData(LinkList headnode,int search_data){
    LinkList plist = headnode->next;
    int length = 1;
    if(headnode->next == NULL)  //�ձ�
        return -1;
    while(plist->data != search_data){
        if(plist->next == NULL)         //������û�д�����
            return -1;
        plist = plist->next;
        length++;
    }
    return length;
}

/**********************����ɾ��**********************/
//ɾ��ָ�����ݵĽ��
void DeleteList_PointData(LinkList headnode,int dat){
    LinkList nodenext  = headnode->next;
    LinkList nodefront = headnode;
    if(nodenext == NULL){
        printf("�������޷�ɾ��\r\n");
        return;
    }
    while(nodenext->data != dat){
        nodefront = nodenext;
        nodenext  = nodefront->next;
        if(nodenext == NULL){
            printf("�������޴�����\r\n");
            return;
        }
    }
    nodefront->next = nodenext->next;
    free(nodenext);
}

//ɾ��ָ��λ�õĽ��
void DeleteList_PointLocation(LinkList headnode,int location){
    LinkList plist = headnode->next;
    LinkList plistfront = headnode;
    int length = 1;
    if((location < 1) && (headnode->next == NULL)){
        printf("δ֪�����������µ��޷�ɾ��\r\n");
        return;
    }
    while(length++ != location){
        if(plist->next == NULL){
            printf("�޴�λ��\r\n");
            return;
        }
        plistfront = plist;
        plist = plist->next;
    }
    plistfront->next = plist->next;
    free(plist);
}

/**********************�����ӡ����������**********************/
//��ӡ�������
void PrintList(LinkList headnode){
	//ָ��ͷ������һ���������Ϊͷ��������������ݻ���Ҫ��ӡ
    LinkList pmove = headnode->next;
    while(pmove){	//�ж�pmove�Ƿ�ָ��NULL
        printf("%d\n",pmove->data);
        pmove = pmove->next;
    }
}

int main(){
    LinkList head = CreatList();    //����ͷ�巨
    LinkList tail = CreatList();    //����β�巨
    LinkList empty_list = CreatList();    //�ձ�
    printf("=================ͷ�巨====================\n");
    for(int i = 10;i > 0;i--){
        InsertNode_ByHead(head,i);
    }
    PrintList(head);
    printf("=================ɾ�������е�����10==================\n");
    DeleteList_PointData(head,10);
    PrintList(head);
    printf("=================β�巨====================\n");
    for(int i = 1;i <= 10;i++){
        InsertNode_ByTail(tail,i);
    }
    PrintList(tail);
    printf("=================���ҵڰ�λ����====================\n");
    printf("%d\r\n",SearchList_ByLocation(tail,8));
    printf("=================����8��λ��====================\n");
    printf("%d\r\n",SearchList_ByData(tail,8));
    printf("=================�ڵڰ�λ����100����ӡ����====================\n");
    InsertNode_ByAnyLocation(tail,100,8);
    PrintList(tail);
    printf("=================ɾ����8λ����====================\n");
    DeleteList_PointLocation(tail,8);
    PrintList(tail);
    return 0;
}


