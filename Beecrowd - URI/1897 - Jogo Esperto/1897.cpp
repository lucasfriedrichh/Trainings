#include<iostream>
#include<map>
#include<queue>

using namespace std;
int bfs(int origem, int destino);

int main()
{
    int n,m;
    cin>>n>>m;
    cout<<bfs(n, m) - 1<<endl;

    return(0);
}

int bfs(int origem, int destino)
{
    queue<int> fila;
    map<int,int> marcacao;
    int vertice;
    fila.push(origem);
    marcacao[origem] = 1;
    if(origem == destino){
        return 1;
    }
    while(!fila.empty())
    {
        vertice = fila.front();

        if(marcacao[vertice*2]==0){
            fila.push(vertice*2);
            marcacao[vertice*2] = marcacao[vertice]+1;
        }
        if(marcacao[vertice*3]==0){
            fila.push(vertice*3);
            marcacao[vertice*3] = marcacao[vertice]+1;
        }
        if(marcacao[vertice/2]==0){
            fila.push(vertice/2);
            marcacao[vertice/2] = marcacao[vertice]+1;
        }
        if(marcacao[vertice/3]==0){
            fila.push(vertice/3);
            marcacao[vertice/3] = marcacao[vertice]+1;
        }
        if(marcacao[vertice+7]==0){
            fila.push(vertice+7);
            marcacao[vertice+7] = marcacao[vertice]+1;
        }
        if(marcacao[vertice-7]==0){
            fila.push(vertice-7);
            marcacao[vertice-7] = marcacao[vertice]+1;
        }
        if(marcacao[destino]>0)
            return marcacao[destino];
        fila.pop();
    }

}
