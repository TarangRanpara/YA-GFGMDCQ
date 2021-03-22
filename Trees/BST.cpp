#include <bits/stdc++.h>

using namespace std;

class BStree{
public:
    int data;
    BStree *left, *right;

    BStree(){
        data = 0;
        left = NULL;
        right = NULL;
    }

    BStree(int value){
        data = value;
        left = NULL;
        right = NULL;
    }

    BStree* insert(BStree *root, int value){
        if(root == NULL)
            return new BStree(value);

        if(value > root->data)
            root->right = insert(root->right, value);
        else
            root->left = insert(root->left, value);

        return root;
    }

    void inorder(BStree *root){
        if(root == NULL)
            return;

        inorder(root->left);
        cout<<root->data<<endl;
        inorder(root->right);
    }

};

int main(){
    BStree *root = NULL, b = NULL;

    root = b.insert(root, 10);
    b.insert(root, 5);
    b.insert(root, 15);
    b.insert(root, 2);
    b.insert(root, 5);
    b.insert(root, 13);
    b.insert(root, 22);
    b.insert(root, 14);

    b.inorder(root);
}
