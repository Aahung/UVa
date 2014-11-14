#include <iostream>
#include <vector>
using namespace std;
int main(){
    int caseNum = 1;
    int remaining;
    while (cin >> remaining) {
        if (remaining < 0) {
            return 0;
        }
        vector<int> solve = vector<int>(12);
        vector<int> create = vector<int>(12);
        int count = 0;
        while (count < 12) {
            cin >> create[count];
            count ++;
        }
        count = 0;
        while (count < 12) {
            cin >> solve[count];
            count ++;
        }
        cout << "Case " << caseNum << ":" << endl;
        caseNum ++;
        for (int i = 0; i < 12; i ++) {
            remaining -= solve[i];
            if (remaining >= 0) {
                cout << "No problem! :D" << endl;
            } else {
                cout << "No problem. :(" << endl;
                remaining += solve[i];
            }
            remaining += create[i];
        }
    }
    return 0;
}