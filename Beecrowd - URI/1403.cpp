#include<bits/stdc++.h>
using namespace std;

template <typename T1, typename T2>
struct less_second {
    typedef pair < T1, T2 > type;
    bool operator ()(type const& a, type const& b) const {
        if(a.second != b.second)
        return a.second > b.second;

        return a.first < b.first;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m,p = 0;
    int t;
    while(cin >> n >> m and (n+m) != 0){
    int k = 0 , p = 0;
    map < int , int > ans;
    for(int i = 0; i < n*m ; i++){
          cin >> t;
          ans[t]++;
     }

     vector < pair < int, int > > ans1(ans.begin(), ans.end());
     sort(ans1.begin(), ans1.end(), less_second < int, int >());
     vector < pair < int, int > > :: iterator it = ans1.begin();
     it++;

     for(;it != ans1.end() ; it++,p = 1){
             if(k == 0) k = it->second ;
             if( k == (it->second)){
             cout << it->first << " " ;
             }else{
                break;
             }
        }
         cout << endl;
    }
    return 0;
}