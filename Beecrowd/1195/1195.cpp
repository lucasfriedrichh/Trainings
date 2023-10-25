#include <bits/stdc++.h>

using namespace std;


struct tree{
    int value;
    tree* left, *right;
};

tree* arvore;

tree* insert(int val, tree* root) {
    if (root == nullptr) {
        root = new tree;
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



void pre(tree* tree){
    if (tree == nullptr){
        return;
    }
    cout << " " << tree->value;
    pre(tree->left);
    pre(tree->right);
}

void pos(tree* tree){
    if (tree == nullptr){
        return;
    }
    pos(tree->left);
    pos(tree->right);
    cout << " " << tree->value ;

}

void in(tree* tree){
    if (tree == nullptr){
        return;
    }
    
    in(tree->left);
    cout << " " << tree->value  ;
    in(tree->right);
}

int main(){
    int t, n;
    cin >> t;

    for(int i = 0; i < t; i++){
        arvore = nullptr;
        cin >> n;
        int temp;

        for (int j = 0; j < n; j++){
            cin >> temp;
            arvore = insert(temp, arvore);
        }

        cout << "Case " << i+1 << ":" << endl;
        cout << "Pre.:";
        pre(arvore);
        cout << endl;

        cout << "In..:";
        in(arvore);
        cout << endl;

        cout << "Post:";
        pos(arvore);
        cout << endl << endl;
        
    }

    return 0;
}
