#include <stdio.h>
#include <stdlib.h>

struct DNode {
    int data;
    struct DNode *prev, *next;
};
struct CNode {
    int data;
    struct CNode *next;
};

struct DNode *dhead = NULL;
struct CNode *chead = NULL;

struct DNode* createDNode(int data) {
    struct DNode *n = (struct DNode*)malloc(sizeof(struct DNode));
    n->data = data;
    n->prev = n->next = NULL;
    return n;
}
struct CNode* createCNode(int data) {
    struct CNode *n = (struct CNode*)malloc(sizeof(struct CNode));
    n->data = data;
    n->next = NULL;
    return n;
}

void insertFirstD(int d) {
    struct DNode *n = createDNode(d);
    if (dhead) dhead->prev = n;
    n->next = dhead;
    dhead = n;
}
void insertLastD(int d) {
    struct DNode *n = createDNode(d);
    if (!dhead) { dhead = n; return; }
    struct DNode *t = dhead;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
}
void insertAfterD(int key,int d){
    struct DNode *t=dhead;
    while(t&&t->data!=key)t=t->next;
    if(!t)return;
    struct DNode *n=createDNode(d);
    n->next=t->next;
    if(t->next)t->next->prev=n;
    t->next=n;
    n->prev=t;
}
void insertBeforeD(int key,int d){
    struct DNode *t=dhead;
    while(t&&t->data!=key)t=t->next;
    if(!t)return;
    struct DNode *n=createDNode(d);
    n->prev=t->prev;
    n->next=t;
    if(t->prev)t->prev->next=n;else dhead=n;
    t->prev=n;
}
void deleteD(int key){
    struct DNode *t=dhead;
    while(t&&t->data!=key)t=t->next;
    if(!t)return;
    if(t->prev)t->prev->next=t->next;else dhead=t->next;
    if(t->next)t->next->prev=t->prev;
    free(t);
}
void searchD(int key){
    struct DNode *t=dhead;int p=1;
    while(t){if(t->data==key){printf("Found at %d\n",p);
     return;
    }
     t=t->next;p++;}
     printf("Not found\n");
}
void displayD(){
    struct DNode *t=dhead;
    if(!t){printf("Empty\n");return;}
    while(t){printf("%d ",t->data);t=t->next;}
    printf("\n");
}

void insertFirstC(int d){
    struct CNode *n=createCNode(d);
    if(!chead){chead=n;chead->next=chead;return;}
    struct CNode *t=chead;
    while(t->next!=chead)t=t->next;
    n->next=chead;
    t->next=n;
    chead=n;
}
void insertLastC(int d){
    struct CNode *n=createCNode(d);
    if(!chead){chead=n;chead->next=chead;return;}
    struct CNode *t=chead;
    while(t->next!=chead)t=t->next;
    t->next=n;
    n->next=chead;
}
void insertAfterC(int key,int d){
    if(!chead)return;
    struct CNode *t=chead;
    do{
        if(t->data==key){struct CNode *n=createCNode(d);
        n->next=t->next;
        t->next=n;return;
        }
        t=t->next;
    }while(t!=chead);
}
void insertBeforeC(int key,int d){
    if(!chead)return;
    struct CNode *n=createCNode(d);
    if(chead->data==key){
        struct CNode *t=chead;
        while(t->next!=chead)t=t->next;
        n->next=chead;
        t->next=n;
        chead=n;
        return;
    }
    struct CNode *t=chead;
    do{
        if(t->next->data==key){
          n->next=t->next;
          t->next=n;return;
        }
        t=t->next;
    }while(t!=chead);
}
void deleteC(int key){
    if(!chead)return;
    struct CNode *t=chead,*p=NULL;
    if(chead->data==key&&chead->next==chead){
      free(chead);chead=NULL;
      return;}
    if(chead->data==key){
        struct CNode *last=chead;
        while(last->next!=chead)
          last=last->next;
        last->next=chead->next;
        struct CNode *del=chead;
        chead=chead->next;
        free(del);
        return;
    }
    do{
        if(t->data==key){
          p->next=t->next;
          free(t);
          return;}
        p=t;t=t->next;
    }while(t!=chead);
}
void searchC(int key){
    if(!chead){printf("Empty\n");return;}
    struct CNode *t=chead;int p=1;
    do{
        if(t->data==key){
          printf("Found at %d\n",p);
          return;}
        t=t->next;p++;
    }while(t!=chead);
    printf("Not found\n");
}
void displayC(){
    if(!chead){printf("Empty\n");
               return;}
    struct CNode *t=chead;
    do{printf("%d ",t->data);
       t=t->next;}
      while(t!=chead);
    printf("\n");
}

int main(){
    int type,choice,data,key;
    while(1){
        printf("Enter type of linked list: ");
        scanf("%d",&type);
        if(type==3)exit(0);
        while(1){
            printf("\n1.InsertFirst\n2.InsertLast\n3.InsertAfter\n4.InsertBefore\n5.Delete\n6.Search\n7.Display\n8.Back\nEnter choice: ");
            scanf("%d",&choice);
            if(choice==8)break;
            printf("Enter data/key when needed\n");
            switch(type){
                case 1:
                    if(choice==1){scanf("%d",&data);insertFirstC(data);}
                    else if(choice==2){scanf("%d",&data);insertLastC(data);}
                    else if(choice==3){scanf("%d%d",&key,&data);insertAfterC(key,data);}
                    else if(choice==4){scanf("%d%d",&key,&data);insertBeforeC(key,data);}
                    else if(choice==5){scanf("%d",&key);deleteC(key);}
                    else if(choice==6){scanf("%d",&key);searchC(key);}
                    else if(choice==7)displayC();
                    break;
                case 2:
                    if(choice==1){scanf("%d",&data);insertFirstD(data);}
                    else if(choice==2){scanf("%d",&data);insertLastD(data);}
                    else if(choice==3){scanf("%d%d",&key,&data);insertAfterD(key,data);}
                    else if(choice==4){scanf("%d%d",&key,&data);insertBeforeD(key,data);}
                    else if(choice==5){scanf("%d",&key);deleteD(key);}
                    else if(choice==6){scanf("%d",&key);searchD(key);}
                    else if(choice==7)displayD();
                    break;
            }
        }
    }
}
