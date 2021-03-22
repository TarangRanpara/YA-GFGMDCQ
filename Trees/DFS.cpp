#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    vector<Node *> children;

    Node(){
        data = 0;
    }

    Node(int value){
        data = value;
    }

    void insert_node(int data){
        children.push_back(new Node(data));
    }
};

vector<int> res;
vector<int> dfs(Node *root){
    res.push_back(root->data);
    for(int i=0; i<root->children.size(); i++)
        dfs(root->children[i]);

    return res;
}

int main(){
    Node *root = new Node();
    /*
    root->children.push_back(new Node(1));
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(3));

    root->children[0]->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(5));

    root->children[0]->children[1]->children.push_back(new Node(6));
    root->children[0]->children[1]->children.push_back(new Node(7));
    */

    root->insert_node(1);
    root->insert_node(2);
    root->insert_node(3);

    root->children[0]->insert_node(4);
    root->children[0]->insert_node(5);

    root->children[2]->insert_node(6);
    root->children[2]->insert_node(7);

    root->children[0]->children[1]->insert_node(8);
    root->children[0]->children[1]->insert_node(9);

    root->children[2]->children[0]->insert_node(10);

    dfs(root);
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<endl;
    return 0;
}
