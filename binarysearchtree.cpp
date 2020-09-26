#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* leftchild;
    struct node* rightchild;
}; struct node *root = NULL;
struct node* createnode(int newdata)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = newdata;
    newnode->leftchild = newnode->rightchild = NULL;
    return newnode;

}
struct node* addchild(struct node* current, int newdata)
{
    if(current==NULL)
        return createnode(newdata);
    if(newdata < current->data)
    current->leftchild = addchild(current->leftchild,newdata);
    else
    current->rightchild = addchild(current->rightchild,newdata);
    return current;
}
void inorder(struct node* root)
{
    if(root == NULL)
        return;
    else
    {
        inorder(root->leftchild);
        printf("( %d )",root->data);
        inorder(root->rightchild);
    }

}
void preorder(struct node* root)
{
    if(root == NULL)
        return;
    else
    {
        printf("( %d )",root->data);
        preorder(root->leftchild);
        preorder(root->rightchild);
    }

}
void postorder(struct node* root)
{
    if(root == NULL)
        return;
    else
    {
        postorder(root->leftchild);
        postorder(root->rightchild);
        printf("( %d )",root->data);
    }
}
void inorderstack()
{
    stack<struct node*> s;
    struct node* current = root;
    while(current!=NULL || s.empty() == false)
    {
        while(current!=NULL)
        {
            s.push(current);
            current = current->leftchild;
        }

        current = s.top();
        s.pop();
        printf("( %d )",current->data);
        current = current->rightchild;
    }
}
void preorderstack()
{
    stack<struct node*> s;
    struct node* current = root;
    while(current!=NULL || s.empty() == false)
    {
        while(current!=NULL)
        {
            printf("( %d )",current->data);
            if(current->rightchild) s.push(current->rightchild);
            current = current->leftchild;
        }

        current = s.top();
        s.pop();
    }
}
const char* searchnode(struct node* current,int key)
{
    if(current)
    {
        if(current->data==key)
            return "key exists in tree";
        else if(key > current->data)
            searchnode(current->rightchild,key);
        else
           searchnode(current->leftchild,key);
    }
    else
        return "key does not exist";
}
struct node* minnoderighttree(struct node* curr)
{
    while(curr && curr->leftchild!=NULL)
        curr= curr->leftchild;

    return curr;
}
struct node* deletenode(struct node* curr,int key)
{
    if(curr==NULL)
        return curr;
    if(key > curr->data)
        curr->rightchild = deletenode(curr->rightchild,key);
    else if(key < curr->data)
        curr->leftchild = deletenode(curr->leftchild,key);
    else
    {
        if(curr->leftchild==NULL)
            return curr->rightchild;
        else if(curr->rightchild==NULL)
            return curr->leftchild;
        else
        {
            struct node* temp = minnoderighttree(root->rightchild);
            curr->data = temp->data;
            root->rightchild = deletenode(root->rightchild,temp->data);

        }
    }
    return curr;
}


int main()
{
    root = addchild(root,50);
    root = addchild(root,30);
    root = addchild(root,20);
    root = addchild(root,40);
    root = addchild(root,70);
    root = addchild(root,60);
    root = addchild(root,80);

    //inorder(root);
    //preorder(root);
    //postorder(root);
    //inorderstack();
    //preorderstack();

    //printf("\n%s",searchnode(root,40));
    //postorder(deletenode(root,50));
    //postorder(deletenode(root,60));
    return 0;

}
