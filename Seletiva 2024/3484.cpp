#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
    node *left, *right;
    node() : left(nullptr), right(nullptr){}
    node(int _data) : data(_data), left(nullptr), right(nullptr){}
} node;

[[nodiscard]] node* insert(node* root, int val){
    if(!root){
        root = new node(val);
        return root;
    }
    if(root->data < val)
        root->right = insert(root->right, val);
    if(root->data > val)
        root->left = insert(root->left, val);
    return root;
}

void minval(vector<int> &ans1, vector<int> &vi){
    sort(vi.begin(), vi.end());
    // cout << "--------------------------\n";
    // for(auto &e : vi)
    //     cout << e << " ";
    // cout << "\n";
    ans1.push_back(vi[0]);
    vi.clear();
}

[[nodiscard]] vector<int> BFS(node* root){
    queue<pair<node*, int>> q;
    vector<int> vi, actual;
    int last = 0;
    q.push({root, 0});
    while(!q.empty()){
        auto p = q.front(); q.pop();
        // cout << "Sou o p.first: " << p.first->data << " | P.second: " << p.second << "\n";
        if(p.second != last){
            minval(vi, actual);
            actual.push_back(p.first->data);
            last = p.second;
        }
        else
            actual.push_back(p.first->data);
        if(p.first->left)
            q.push({p.first->left, p.second + 1});
        if(p.first->right)
            q.push({p.first->right, p.second + 1});
    }
    if(actual.size())
        minval(vi, actual);
    return vi;
}

// void inorder(node *root){
//     if(root){
//         inorder(root->left);
//         cout << root->data << "\n";
//         inorder(root->right);
//     }
// }

int main(){
    int n; cin >> n;
    node* t = nullptr;
    while(n--){
        int h; cin >> h;
        t = insert(t, h);
    }
    // inorder(t);
    vector<int> ans = BFS(t);
    for(size_t i = 0; i < ans.size(); i++)
        cout << i << " " << ans[i] << "\n";
    return 0;
}