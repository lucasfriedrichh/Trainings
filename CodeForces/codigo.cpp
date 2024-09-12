#include <bits/stdc++.h>

using namespace std;

#define MAX 212345

struct nodes{
    long long litros;
    int originalName, parent, left, right;
    nodes(): litros(0), originalName(0), parent(0), left(0), right(0){}
};


int main(){
    int n;
    cin >> n;
    vector<nodes> mapa(MAX);
    for(int i=1; i<=n; i++){
        cin >> mapa[i].litros;
        mapa[i].originalName=i;
    }
    int newId = n;
    int rio1, rio2, proxOrig;
    for(int i=1; i<n; i++){
        newId++;
        cin >> rio1 >> rio2;
        if(mapa[rio1].litros > mapa[rio2].litros){
            proxOrig = mapa[rio1].originalName;
        }else{
            proxOrig = mapa[rio2].originalName;
        }
        mapa[newId].litros = mapa[rio1].litros + mapa[rio2].litros;
        mapa[newId].originalName = proxOrig;
        mapa[newId].left = rio1;
        mapa[newId].right = rio2;
        mapa[rio1].parent = newId;
        mapa[rio2].parent = newId;
    }
    cout << mapa[n+n-1].originalName << '\n';
    int q; cin >> q;
    int src, chuva;
    for(int i=0; i<q; i++){
        cin >> src >> chuva;
        while(mapa[src].parent!=0){
            //cout << "to preso\n";
            mapa[src].litros += chuva;
            if(mapa[mapa[src].parent].right!=src){
                if(mapa[src].litros > mapa[mapa[mapa[src].parent].right].litros){
                    mapa[mapa[src].parent].originalName = mapa[src].originalName;
                }else{
                    mapa[mapa[src].parent].originalName = mapa[mapa[mapa[src].parent].right].originalName;
                }
            }else{
                if(mapa[src].litros > mapa[mapa[mapa[src].parent].left].litros){
                    mapa[mapa[src].parent].originalName = mapa[src].originalName;
                }else{
                    mapa[mapa[src].parent].originalName = mapa[mapa[mapa[src].parent].left].originalName;
                }
            }
            src = mapa[src].parent;
        }
        cout << mapa[n+n-1].originalName << '\n';
    }
}