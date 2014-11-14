#include <iostream>
#include <vector>
#include <algorithm>
////change two's position and check the change
//T3S4 - T4S3
using namespace std;

int main(){
    int caseNum, stoneNum, distance, caseNo = 0;
    cin >> caseNum;
    while (cin >> stoneNum >> distance) {
        vector<int> stonePos = vector<int>(stoneNum + 2);
        stonePos[0] = 0;
        stonePos[stoneNum + 1] = distance;
        vector<bool> stoneIsSmall = vector<bool>(stoneNum + 2);
        for (int i = 1; i < stoneNum + 1; i ++) {
            string temp;
            cin >> temp;
            stoneIsSmall[i] = (temp[0] == 'S');
            temp.erase(temp.begin(), temp.begin() + 2);
            stonePos[i] = atoi(temp.c_str());
        }
        //finish input
        int maxDis = 0;
        for (int i = 0; i < stoneNum + 1; i ++) {
            maxDis = (maxDis < (stonePos[i + 1] - stonePos[i]))? (stonePos[i + 1] - stonePos[i]) : maxDis;
        }
        for (int i = 1; i < stoneNum + 1; i ++) {
            if (stoneIsSmall[i]) {
                maxDis = (maxDis < (stonePos[i + 1] - stonePos[i - 1]))? (stonePos[i + 1] - stonePos[i - 1]) : maxDis;
            }
        }
        cout << "Case " << ++ caseNo << ": " << maxDis << endl;
    }
    return 0;
}