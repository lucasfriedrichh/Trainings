// Print de arvore com BFS, sem espaco no final

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    Node *left, *right;
};

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
        if(next->left)
            fila.push(next->left);
        
        if(next->right){
            fila.push(next->right);
        }
    }
}

