#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int countDirectedAcyclicGraphs(int V) {
  return pow(2, V - 1);
}

int main() {
  int V;
  cin >> V;
  cout << countDirectedAcyclicGraphs(V) << endl;
  return 0;
}

