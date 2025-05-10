#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
typedef struct Node node;
node *insert(node *root, int e){
    if(root==NULL){
        node *nn=(node*)malloc(sizeof(node));
        nn->data=e;
        nn->left=nn->right=NULL;
        root=nn;
    }else if(e<root->data)
        root->left=insert(root->left, e);
    else if(e>root->data)
        root->right=insert(root->right, e);
    return root;
}
void post(node *root){
    if(root!=NULL){
        post(root->left);
        post(root->right);
        printf("%d ", root->data);
    }
}
int main(){
    node *root=NULL;
    int n, a;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a);
        root=insert(root, a);
    }
    post(root);
}