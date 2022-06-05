#include<stdio.h>
#include<stdbool.h>  //head is a pointer to the first node
#include<stdlib.h>
struct list
{
    int data; struct list *next;
};

bool search(struct list *node,int n);
struct list *addtobeg(struct list *node,int n);
struct list *addtoend(struct list *node, int n);
void deletebeg(struct list **node); //pointer to pointer pass by reference, head is a variable pointer
void deleteend(struct list **node);
void deletemid(struct list **node, int n);
void addmid(struct list *node, int p, int n);
struct list *recrev(struct list *head);
struct list *iterev(struct list *head);

int main()
{
    struct list *head=(struct list *)malloc(sizeof(struct list));
    head->data=0; head->next=NULL;
    //int x =search(head,0); printf("%d ",x);
    //head = addtobeg(head,1); deleteend(&head);
    //int y = search(head,1); printf("%d ",y); int z= search(head,0); printf("%d ",z);
    //addmid(head,2,4); int a = search(head,4); printf("%d ", a);

    head = addtobeg(head,1);
    head = addtobeg(head,2);
    head = addtobeg(head,3);
    head = addtobeg(head,4);
   
    struct list *t; t=head;
    while(t->next)
    {
        printf("%d ", t->data);
        t=t->next;
    }

    head = recrev(head);
    while(t->next)
    {
        printf("%d ", t->data);t=t->next; 
    }

    return 0;
}

bool search(struct list *node, int n){
    while(node)
    {    
    if (node->data==n)
        return true;
    node=node->next ;
    }
    return false;
}
struct list *addtobeg(struct list *node, int n)
{
    struct list *temp = (struct list*)malloc(sizeof(struct list));
    temp->next=node;
    temp->data=n;
    return temp;
}
struct list *addtoend(struct list *node, int n)
{
    struct list *temp= (struct list*)malloc(sizeof(struct list));
    temp->data=n;
    temp->next=NULL;
    while(node)
    {
        if(node->next==NULL)
            node->next=temp;
    }
    return temp;
}
void deletebeg(struct list **node)
{
    struct list *temp=*node;
    if(*node){
        *node=(*node)->next;
        free(temp);
    }
}
void deleteend(struct list **node)
{
    if(*node)
    {
        if((*node)->next)
        {
            struct list *t= *node;
            while(t->next->next)
                t=t->next;
            free(t->next); t->next=NULL;    
            
        }
        else
            *node=NULL;
    }
}
void deletemid(struct list **node, int n)
{
    //if(search(n))

}
void addmid(struct list *node, int p, int n)
{
    struct list *temp = (struct list *)malloc(sizeof(struct list));
    int c =0;
    while(node && c!=p-1)
    {
        c++;
        node=node->next;
    }
    temp->data=n;
    temp->next=node->next;
    node->next=temp;

}

struct list *recrev(struct list *head)
{
    if(head && head->next)
    {
        struct list *temp=head; struct list *t;
        if(head->next)
        {
            head = recrev(head->next); //code doesnt go further until recursrion ends
            t=head;
            while(t->next)
                t=t->next;
            t->next=temp;
            temp->next=NULL;    

        }
    }
    return head;
}
struct list *iterev(struct list *head)
{
    struct list *c,*p,*n;
    *c=*head; p=NULL; 
    while(c)
    {
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    return p;
}

