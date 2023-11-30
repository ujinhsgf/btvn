#include<iostream>
using namespace std;

int countParallelEdges(int V, int E, int edges[][2]) {
    int count = 0;
    for (int i = 0; i < E; i++) {
        for (int j = i + 1; j < E; j++) {
            if ((edges[i][0] == edges[j][0] && edges[i][1] == edges[j][1]) || (edges[i][0] == edges[j][1] && edges[i][1] == edges[j][0])) {
                count++;
            }
        }
    }
    return count;
}

int main(){
    int E,V,n;
    cin>>E>>V>>n;
    int a[n][2];
    for(int i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1];
    }
    int k=countParallelEdges(E,V,a);
    cout<< k;
    return 0;
}
