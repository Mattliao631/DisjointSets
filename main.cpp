#include "DisjointSets.hpp"

using namespace std;

int main() {
    int a[10];
    for (int i = 0; i < 10; i++) {
        a[i] = i;
    }
    DisjointSets<int> ds;
    for (int i = 0; i < 10; i++) {
        ds.MakeSet(&a[i]);
    }

    ds.Union(&a[1], &a[2]);
    ds.Union(&a[2], &a[3]);
    ds.Union(&a[4], &a[5]);
    ds.Union(&a[6], &a[7]);
    ds.Union(&a[5], &a[6]);

    for (int i = 0; i < 10; i++) {
        ds.PrintSet(&a[i]);
        cout << endl;
    }
    cout << endl;
    
    ds.PrintAllSets();
    return 0;
}