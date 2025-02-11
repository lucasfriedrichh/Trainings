#include <iostream>
#include <vector>

using namespace std;

int main(){
    while (true){
        int n;
        cin >> n;
        if(!n)break;

        for(int i=0; i < n; i++){

            int opcao, flag = 0;
            vector<int> list;

            for(int j=0; j<5; j++){            
                int cor;
                cin >> cor;
                list.push_back(cor);
            }

            for(int k=0; k<5; k++){
                if (list[k] <= 127){
                    opcao = k;
                    flag+=1;
                }
            }

             if(flag==1){
                if(opcao==0) cout << "A" << endl;
                if(opcao==1) cout << "B" << endl;
                if(opcao==2) cout << "C" << endl;
                if(opcao==3) cout << "D" << endl;
                if(opcao==4) cout << "E" << endl;
                
            }

            if(flag>1 || flag==0)
                cout << "*" << endl;
                
        }
    }

    return 0;
}