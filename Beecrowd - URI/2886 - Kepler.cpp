#include <bits/stdc++.h>
using namespace std;
 
struct Circle {
    double x, y, r;
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int N;
    cin >> N;
    vector<Circle> circles(N);
    for (int i=0; i<N; i++){
        cin >> circles[i].x >> circles[i].y >> circles[i].r;
    }
 
    const double Dmax = sqrt(50.0*50.0 + 50.0*50.0);

    sort(circles.begin(), circles.end(), [](const Circle &a, const Circle &b){
        return a.r < b.r;
    });
 
    long long intersectPairs = 0;
    int activeStart = 0;
 
    for (int i = 0; i < N; i++){
        Circle cur = circles[i];
        while(activeStart < i && circles[activeStart].r < cur.r - Dmax)
            activeStart++;
 
        for (int j = activeStart; j < i; j++){
            Circle prev = circles[j];
            double dx = cur.x - prev.x;
            double dy = cur.y - prev.y;
            double d = sqrt(dx*dx+dy*dy);
            if(d <= cur.r - prev.r)
                continue;
            if(cur.r <= Dmax && prev.r <= Dmax && d >= cur.r + prev.r)
                continue;
 
            intersectPairs++;
            if(intersectPairs > N){ 
                cout << "greater" << "\n";
                return 0;
            }
        }
    }
 
    cout << (2LL * intersectPairs) << "\n";
    return 0;
}
