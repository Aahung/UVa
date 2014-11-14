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

#define MAX_N 140000

using namespace std;

long long sum(long long a, long long b) {
    return a + b;
}

long long tree[2 * MAX_N];
long long arr[MAX_N];

void build_tree(int node, int lb, int ub) {
    if (lb > ub) return;
    
    if (lb == ub) {
        tree[node] = arr[lb];
        return;
    }
    
    build_tree(node * 2, lb, (lb + ub) / 2);
    build_tree(node * 2 + 1, (lb + ub) / 2 + 1, ub);
    
    tree[node] = sum(tree[node * 2], tree[node * 2 + 1]);
}

void update_tree(int node, int lb, int ub, int a, int b, int value) {
    if (lb > ub || lb > b || ub < a) // Current segment is not within range
        return;
    if (lb == ub) { // Leaf node
        tree[node] += value;
        return;
    }
    update_tree(node*2, lb, (lb+ub)/2, a, b, value); // Update left child
    update_tree(1+node*2, 1+(lb+ub)/2, ub, a, b, value); // Update right child
    tree[node] = sum(tree[node*2], tree[node*2+1]); // Update this node
}

long long query_tree(int node, int lb, int ub, int a, int b) {
    if (lb > ub || lb > b || ub < a) return 0; // Out of range
    if (a <= lb && ub <= b) { // Current segment is totally within [a, b]
        return tree[node];
    }
    long long q1 = query_tree(node*2, lb, (lb+ub)/2, a, b); // Query left child
    long long q2 = query_tree(1+node*2, 1+(lb+ub)/2, ub, a, b); // Query right child
    
    long long res = sum(q1, q2);
    return res;
}

int main() {
    int caseNum;
    cin >> caseNum;
    for (int case_i = 0; case_i < caseNum; ++case_i) {
        int n, c;
        cin >> n >> c;
        memset(arr, 0, 2 * MAX_N);
        //build_tree(1, 0, n - 1);
        for (int i = 0; i < c; ++i) {
            int type;
            cin >> type;
            if (type == 0) {
                // increase
                int a, b, v;
                cin >> a >> b >> v;
                update_tree(1, 0, n - 1, a - 1, b - 1, v);
            } else {
                // print
                int a, b;
                cin >> a >> b;
                cout << query_tree(1, 0, n - 1, a - 1, b - 1) << endl;
            }
        }
    }
    return 0;
}