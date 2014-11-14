#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    // struct the tree
    vector<vector<unsigned int> > tree = vector<vector<unsigned int> >();
    vector<unsigned int> depth_1 = vector<unsigned int>();
    depth_1.push_back(1);
    tree.push_back(depth_1);
    for (int i = 1; i < 20; ++i) {
        vector<unsigned int> depth_i = vector<unsigned int>();
        for (int j = 0; j < 1 << (i - 1); ++j) {
            depth_i.push_back(tree[i - 1][j] * 2);
        }
        for (int j = 0; j < 1 << (i - 1); ++j) {
            depth_i.push_back(tree[i - 1][j] * 2 + 1);
        }
        tree.push_back(depth_i);
    }
    int caseNum;
    cin >> caseNum;
    for (int i = 0; i < caseNum; ++i) {
        int depth, index;
        cin >> depth >> index;
        cout << tree[depth - 1][(index - 1) % (1 << (depth - 1))] << endl;
    }
    cin >> caseNum;
    return 0;
}