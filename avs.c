#include<stdio.h>
#include<stdlib.h>
struct node
{
    int n;
    struct node *nxt,*prev;
};
struct node *cnode(struct node *head, int n)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->n = n;
    newnode->nxt = NULL;
    newnode->prev = NULL;
    if(head == NULL)
    {
        return newnode;
    }
    struct node *temp = head;
    while(temp->nxt != NULL)
    {
        temp = temp->nxt;
    }
    temp->nxt = newnode;
    newnode->prev = temp;
    return head;
}
void searchele(struct node *head, int n)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        if(temp->n == n)
        {
            printf("%d\n",temp->n);
            break;
        }
        else
        {
            temp = temp->nxt;
        }
    }
}
int main()
{
    int n, num;
    struct node *head = NULL;
    scanf("%d",&n);
    if(n==0)
    {
        printf("Empty list!\n");
        return 0; 
    }
    for(int i = 0; i< n; i++)
    {
        scanf("%d",&num);
        head = cnode(head,num);
    }
    scanf("%d",&num);
    searchele(head,num);
    return 0; 
}