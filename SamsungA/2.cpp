#include<iostream>
using namespace std;

int countGraphs(int V, int E) {
    if (E > V * (V - 1) / 2 || E < V - 1) {
        return 0;
    }
    if (E == V - 1) {
        return 1;
    }
    if (V == 1 || E == 0) {
        return 1;
    }
    int ans = 0;
    for (int i = 1; i <= V; i++) {
        ans += countGraphs(V - i, E - i);
    }
    return ans;

}
int main(){
    int E,V;
    cin>>E>>V;
    int k=countGraphs(E,V);
    cout<< k;
    return 0;
}
