#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string currentLine, newLine, friendIndicator;
    
    getline(cin, currentLine);
    getline(cin, newLine);
    getline(cin, friendIndicator);
    
    vector<string> currentFriends;
    istringstream issCurrent(currentLine);
    string name;
    while(issCurrent >> name){
        currentFriends.push_back(name);
    }
    
    vector<string> newFriends;
    istringstream issNew(newLine);
    while(issNew >> name){
        newFriends.push_back(name);
    }
    
    if(friendIndicator == "nao"){
        currentFriends.insert(currentFriends.end(), newFriends.begin(), newFriends.end());
    } else {
        auto it = find(currentFriends.begin(), currentFriends.end(), friendIndicator);
        if(it != currentFriends.end()){
            currentFriends.insert(it, newFriends.begin(), newFriends.end());
        }
    }
    
    for(auto s : currentFriends){
        cout << s << " ";
    }
    cout << '\n';
    
    return 0;
}
