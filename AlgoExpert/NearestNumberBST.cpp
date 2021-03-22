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

int absc(int value){
    return (value > 0)?value:-1*value;
}

int findClosest(BStree *root, int target, int closest){
    if(root == NULL)
        return closest;

    if(absc(target - closest) > absc(target - root->data)){
        closest = root->data;
        //cout<<"closest"<<closest<<endl;
    }

    if(target < root->data)
        return findClosest(root->left, target, closest);

    else if(target > root->data)
        return findClosest(root->right, target, closest);

    else
        closest;
}

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

    cout<<"Inorder Traversal"<<endl;
    b.inorder(root);


    int ele =2;
    cout<<"closest of "<<ele<<" is "<<findClosest(root, ele, INT_MAX);
    return 0;
}
