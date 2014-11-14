#include <iostream>
#include <vector>
#include <algorithm>
////change two's position and check the change
//T3S4 - T4S3
using namespace std;

int main(){
    int sNum;
    int caseOrder = 0;
    while (cin >> sNum) {
        if (sNum == 0) {
            return 0;
        }
        vector<vector<int> > sCol = vector<vector<int> >(sNum, vector<int>(2));
        for (int i = 0; i < sNum; i ++) {
            cin >> sCol[i][0] >> sCol[i][1];
        }
        //finish input
        for (int j = 0; j < sCol.size(); j ++) {
            for (int i = 0; i < sCol.size() - 1; i ++) {
                if (sCol[i][1] < sCol[i + 1][1]) {
                    vector<int> temp = sCol[i];
                    sCol[i] = sCol[i + 1];
                    sCol[i + 1] = temp;
                }
            }
        }
        int maxTime = 0;
        for (int i = 0; i < sCol.size(); i ++) {
            int time = 0;
            for (int j = 0; j <= i; j ++) {
                time += sCol[j][0];
            }
            time += sCol[i][1];
            maxTime = (maxTime < time)? time : maxTime;
        }
        cout << "Case " << ++ caseOrder << ": " << maxTime << endl;
    }
    
    return 0;
}