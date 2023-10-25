#include <bits/stdc++.h>
using namespace std;


struct Node{
    int value;
    Node *left, *right;
};

Node* tree;

void bfs(Node* tree){
    bool f = true;
    if(tree == nullptr) return;
    queue<Node*> fila;
    fila.push(tree);
    while(!fila.empty()){
        if(f){ 
            cout << fila.front()->value; 
            f = false;
        }
        else cout << " " << fila.front()->value;
        Node* next = fila.front();
        fila.pop();
        if(next->left){
            fila.push(next->left);
        }
        if(next->right){
            fila.push(next->right);
        }
    }
}



Node* insert(int val, Node* root) {
    if (root == nullptr) {
        root = new Node;
        root->value = val;
        root->left = nullptr;
        root->right = nullptr;
    } else if (root->value < val) {
        root->right = insert(val, root->right);
    } else {
        root->left = insert(val, root->left);
    }

    return root;
}

int main() {
    int t, size, temp;
    cin >> t;
    for(int i = 1; i<=t;i++){
        tree = nullptr;
        cin >> size;
        for (int i = 0; i < size; i++){
            cin >> temp;
            tree = insert(temp, tree);
        }
        cout << "Case "<< i << ":"<< endl;
        bfs(tree);
        cout << endl << endl;
    }
    return 0;
}