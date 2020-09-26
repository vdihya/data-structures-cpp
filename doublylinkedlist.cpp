#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* prev;
    struct node* next;
};
struct node* head = NULL;

void addfirst(int newdata)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = newdata;
    newnode->next = head;
    newnode->prev = NULL;
    if(head!=NULL)
        head->prev = newnode;
    head = newnode;
}

void addlast(int newdata)
{
    if(head==NULL) addfirst(newdata);
    else
    {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        struct node* temp = head;
        newnode->data = newdata;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = NULL;

    }

}

void addpos(int pos,int newdata)
{
    struct node* temp = head;
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    for(int i=0;i<pos-2 && temp->next!=NULL;i++)
        temp = temp->next;

    newnode->data = newdata;
    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;

}
void deletefirst()
{
    printf("\ndeleted: %d\n",head->data);
    head = head->next;

}

void deletelast()
{
    struct node* temp = head;
    struct node* temp1 = NULL;
    while(temp->next!=NULL)
    {
        temp1=temp;
        temp=temp->next;
    }
    printf("\ndeleted: %d\n",temp->data);

    temp1->next =NULL;
    delete(temp);

}

void deletepos(int pos)
{
    struct node* temp = head;
    for(int i=0;i<pos-2 && temp->next!=NULL;i++)
        temp = temp->next;
    printf("\ndeleted: %d\n",temp->next->data);
    temp->next = temp->next->next;
    temp->next->prev = temp;

}

void display()
{
    struct node* temp = head;
    struct node* lastnode = NULL;
    while(temp!=NULL)
    {
        printf("[%d]->",temp->data);
        lastnode = temp;
        temp=temp->next;
    }
    printf("NULL");
    /*printf("\nlist in reverse using prev pointer:\n");
    while(lastnode!=NULL)
    {
        printf("[%d]->",lastnode->data);
        lastnode= lastnode->prev;
    }
    printf("NULL");
*/
}
int main()
{

    addfirst(30);
    addfirst(20);
    addfirst(10);
    addfirst(40);
    addfirst(60);
    addlast(100);
    addlast(70);
    addpos(6,50);
    display();
    deletefirst();
    display();
    deletelast();
    display();
    deletepos(2);
    display();
    return 0;
}
