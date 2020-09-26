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
int findheight(struct node* curr)
{
    if(curr==NULL)
        return 0;
    else
    {
        int lh = findheight(curr->leftchild);
        int rh = findheight(curr->rightchild);

        return (lh > rh)? lh+1:rh+1;

    }
}
struct node* addnode(int arr[],struct node* root,int i, int n)
{
    if(i<n)
    {
        struct node* temp = createnode(arr[i]);
        root  = temp;

        root->leftchild = addnode(arr,root->leftchild,2*i+1,n);
        root->rightchild= addnode(arr,root->rightchild,2*i+2,n);

    }
    return root;

}
void printgivenlevel(struct node* curr, int level)
{
    if(curr==NULL)
     return;
    if(level==1)
        printf("(%d)",curr->data);
    else
    {
        printgivenlevel(curr->leftchild,level-1);
        printgivenlevel(curr->rightchild,level-1);
    }
}
void levelorder(struct node* curr)
{
    int height = findheight(curr);
    for(int i=1;i<=height;i++)
        printgivenlevel(curr,i);
}
void mirror(struct node* root)
{

    struct node* temp;
    if(root == NULL) return;
    else
    {
        mirror(root->leftchild);
        mirror(root->rightchild);

        swap(root->leftchild,root->rightchild);

    }

}
void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->leftchild);
        printf("%d ",root->data);
        inorder(root->rightchild);
    }
}
int iterativeheight(struct node* root)
{
    if(root == NULL)
        return 0;
    queue<struct node*> q;
    q.push(root);
    int width = 0;
    int height = 0;
    while(1)
    {
        int nodecount = q.size();
        width = max(nodecount, width);
        if(nodecount == 0)
            return height;
        height++;

        while(nodecount-- > 0)
        {
            struct node* node = q.front();
            q.pop();
            if(node->leftchild) q.push(node->leftchild);
            if(node->rightchild) q.push(node->rightchild);
        }
    }


}

int main()
{
    int arr[] = {10,24,12,14,1,4,84,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    root = addnode(arr,root,0,n);
    //levelorder(root);
    inorder(root);
    mirror(root);
    printf("\n");
    inorder(root);
    cout << endl;
    cout << findheight(root);
    cout << iterativeheight(root);
}
