#include<stdio.h>
#include<stdlib.h>

struct binary_tree

{
    int data;
    struct binary_tree *left,*right;
}*root=NULL;

typedef struct binary_tree TREE;

void ins(int x){
    TREE *nn=(TREE *)malloc(sizeof(TREE));
    nn->data=x;
    nn->left=nn->right=NULL;
    if(root==NULL){
        root=nn;
    }
    else{
        TREE *temp=root;
        while(1){
            if(x<temp->data){
                if(temp->left==NULL){
                    temp->left=nn;
                    break;
                }
                else{
                    temp=temp->left;
                }
        }
        else{
            if(temp->right==NULL){
            temp->right=nn;
            break;
            }
            else{
                temp=temp->right;
            }
    }
}
}}

//inorder trav

void dis(TREE *temp){      
    if(temp==NULL) return;
    dis(temp->left);
    printf("%d ",temp->data);
    dis(temp->right);

}

void preorder(TREE *temp){
    if(temp==NULL) return;
    printf("%d ",temp->data);
    preorder(temp->left);
    preorder(temp->right);
}


void postorder(TREE *temp){
    if(temp==NULL) return;
    postorder(temp->left);
    postorder(temp->right);
    printf("%d ",temp->data);
}


void del(int ele){
    TREE *temp=root;
    while(1){
        if(temp->data>ele){
            temp=temp->left;
        }
        else if(temp->data==ele){
            temp->left->right=temp->right;
            temp=temp->left;
            break;
        }
        else{
            temp=temp->right;
        }
    }
}

int main(){
    ins(5);
    ins(3);
    ins(7);
    ins(2);
    ins(4);
    ins(6);
    printf("inorder ");
    dis(root);
    printf("\npreoder ");
    preorder(root);
    printf("\nPostorder ");
    postorder(root);
    int n;
    scanf("%d",&n);
    del(n);
    dis(root);
}
