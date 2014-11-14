#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

int main() {
	int caseNum;
    cin >> caseNum;
    while (caseNum -- > 0) {
        int coinTypeNum;
        cin >> coinTypeNum;
        vector<unsigned int> coinCol(coinTypeNum);
        for (int i = 0; i < coinTypeNum; i ++) {
            cin >> coinCol[i];
        }
        //        finish input
        int max = 0;
        int sum = 0;
        for (int i = 0; i < coinTypeNum - 1; i ++) {
            if (sum < min(coinCol[i], coinCol[i + 1] - coinCol[i])) {
                sum += coinCol[i];
                max ++;
            }
        }
        cout << max + 1 << endl;
    }
    
	return 0;
}
