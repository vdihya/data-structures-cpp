#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* next;
};
node *head = NULL;
void addloop(int loopdata)
{
    node* loopnode = (node*)malloc(sizeof(node));
    node* temp = head;
    loopnode->data = loopdata;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = loopnode;
    loopnode->next =  temp;

}
void addfirst(int newdata)
{
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = newdata;
    newnode->next = head;
    head = newnode;

}
void addlast(int newdata)
{
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = newdata;
    node* temp = head;
    if(head==NULL)
    {
        newnode->next = head;
        head = newnode;
    }

    else
    {

    while(temp->next!=NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->next = NULL;

    }

}
void addpos(int newdata, int pos)
{
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = newdata;
    node* temp = head;
    for(int i=0;i<pos-2 && temp->next!=NULL;i++)

        temp=temp->next;
    newnode->next = temp->next;
    temp->next = newnode;

}
void addpos2(node* posnode, int newdata)
{
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = newdata;
    newnode->next = posnode->next;
    posnode->next = newnode;

}
void deletefirst()
{
    printf("\ndeleted first: %d",head->data);
    head = head->next;

}
void deleteend()
{
    node *temp = head;
    node* t;
    while(temp->next != NULL)
    {
        t = temp;
        temp= temp->next;
    }
    t->next = NULL;
    free(temp);
}
void deletepos(int pos)
{
    struct node* temp = head;
    for(int i=0;i<pos-2 && temp->next!=NULL;i++)
        temp = temp->next;
    printf("\ndeleted: %d", temp->next->data);
    temp->next = temp->next->next;

}
void deleteelement(int deldata)
{
    node* temp = head;
    while(temp->next->data!=deldata)
    {
        temp = temp->next;
    }
    printf("\nthe first occurrence of %d has been deleted",deldata);
    temp->next = temp->next->next;

}
void display()
{

     node *temp =head;
    printf("\n");
    while(temp!=NULL)
    { printf("%d->",temp->data);
        temp = temp->next;
    }
}
void reversal(node* from, int to)
{
    node* prev = NULL;
    node *next = NULL;
    node * current = from;

    while(current!=NULL && to-- >1)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head= prev;
}

void reversefrom(int start, int to)
{
    node* temp = head;
    for(int i=0;i<start-1 && temp->next!=NULL;i++)
        temp = temp->next;
    reversal(temp, to);
}
void middle()
{
    node* fast = head;
    node* slow = head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    printf("\nmiddle element is:%d\n",slow->data);

}
void loop()
{
    //detection
    node* fast = head;
    node* slow = head;
    while(fast!=NULL && fast->next!=NULL && slow!=NULL)
    {

        fast=fast->next->next;
        slow= slow->next;
        if(slow->data ==fast->data)
        {
            printf("loop exists! removing loop...");
            struct node* temp = head;
            while(temp->next != slow->next)
            {
                temp = temp->next;
                slow =slow->next;
            }
            slow->next = NULL;
            display();
        }
        else continue;

    }

}
void nodeswap()
{
    node* temp1 = head;
    node* temp2 = head;
    node* secondlast = NULL;
    while(temp1->next!=NULL)
    {
         secondlast= temp1;
        temp1=temp1->next; // puts last node in temp1


    }   head = temp1;
    head->next =  temp2->next;
    secondlast->next = temp2;
    temp2->next = NULL;


}
int main()
{
    addlast(10);
    addlast(20);
    addlast(30);
    addlast(40);
    addlast(100);
    addlast(120);
    addlast(300);
    addpos(20,4);
    display();
    //deleteelement(20);
    reversefrom(2,5);
    display();
    //middle();
    //nodeswap();
    //display();
   addloop(90);

   addloop(820);
    //loop();
    //removeloop();
    //display();
    return 0;
}
