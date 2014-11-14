#include <iostream>
#include <vector>
#include <algorithm>
////change two's position and check the change
//T3S4 - T4S3
using namespace std;

bool largerThan(vector<int> &a, vector<int> &b) {
    if (a[0] * b[1] > a[1] * b[0]) {
        return true;
    } else
        return false;
}
int main(){
    int caseNum;
    cin >> caseNum;
    while (1) {
        if (caseNum == 0) {
            return 0;
        }
        int jobNum;
        cin >> jobNum;
        vector<vector<int> > jobCol = vector<vector<int> >(jobNum, vector<int>(3));
        for (int i = 0; i < jobNum; i ++) {
            cin >> jobCol[i][0] >> jobCol[i][1];
            jobCol[i][2] = i + 1;
        }
        ///finish get input
        for (int i = 0; i < jobNum; i ++) {
            for (int j = 0; j < jobNum - 1; j ++) {
                if (largerThan(jobCol[j], jobCol[j + 1])) {
                    vector<int> temp = jobCol[j];
                    jobCol[j] = jobCol[j + 1];
                    jobCol[j + 1] = temp;
                }
            }
        }
        ///finish sort;
        for (int i = 0; i < jobNum; i ++) {
            if (i != 0) {
                cout << " ";
            }
            cout << jobCol[i][2];
        }
        cout << endl;
        if (-- caseNum == 0) {
            return 0;
        }
        cout << endl;
    }
    
    return 0;
}