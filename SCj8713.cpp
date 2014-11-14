#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <queue>
#include <sstream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <string.h>

#define MAX_N 60000

using namespace std;

int max(int a, int b) {
    int m = ((a > b)? a : b);
    return m;
}

int tree[2 * MAX_N];
int arr[MAX_N];

void build_tree(int node, int lb, int ub) {
    if (lb > ub) return;
    
    if (lb == ub) {
        tree[node] = arr[lb];
        return;
    }
    
    build_tree(node * 2, lb, (lb + ub) / 2);
    build_tree(node * 2 + 1, (lb + ub) / 2 + 1, ub);
    
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

void update_tree(int node, int lb, int ub, int a, int b, int value) {
    if (lb > ub || lb > b || ub < a) // Current segment is not within range
        return;
    if (lb == ub) { // Leaf node
        tree[node] = value;
        return;
    }
    update_tree(node*2, lb, (lb+ub)/2, a, b, value); // Update left child
    update_tree(1+node*2, 1+(lb+ub)/2, ub, a, b, value); // Update right child
    tree[node] = max(tree[node*2], tree[node*2+1]); // Update this node
}

int query_tree(int node, int lb, int ub, int a, int b) {
    if (lb > ub || lb > b || ub < a) return -20000; // Out of range
    if (a <= lb && ub <= b) { // Current segment is totally within [a, b]
        return tree[node];
    }
    int q1 = query_tree(node*2, lb, (lb+ub)/2, a, b); // Query left child
    int q2 = query_tree(1+node*2, 1+(lb+ub)/2, ub, a, b); // Query right child
    
    int res = max(q1, q2);
    return res;
}

int nextpow2(int n) {
    float lo = log2(n);
    int int_lo = ceil(lo);
    return (1 << int_lo);
}

int main() {
    int n;
    cin >> n;
    memset(arr, 0, 2 * MAX_N);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    build_tree(1, 0, n - 1);
    int c;
    cin >> c;
    while (c-- > 0) {
        int t;
        cin >> t;
        if (t == 0) {
            int a, v;
            cin >> a >> v;
            update_tree(1, 0, n - 1, a - 1, a - 1, v);
        } else {
            int a, b;
            cin >> a >> b;
            cout << query_tree(1, 0, n - 1, a - 1, b - 1) << endl;
        }
    }
    return 0;
}