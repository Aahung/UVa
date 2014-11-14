#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;


int main() {
	int caseNum;
    cin >> caseNum;
    while (caseNum -- > 0) {
        int rowNum;
        cin >> rowNum;
        vector<long long> a(rowNum), b(rowNum), c(rowNum), d(rowNum);
        for (int i = 0; i < rowNum; i ++) {
            cin >> a[i] >> b[i] >> c[i] >> d[i];
        }
        vector<long long> left(rowNum * rowNum);
        vector<long long> right(rowNum * rowNum);
        for (int i = 0; i < rowNum; i ++) {
            for (int j = 0; j < rowNum; j ++) {
                left[i * rowNum + j] = a[i] + b[j];
                right[i * rowNum + j] = c[i] + d[j];
            }
        }
        // now we have two vector combining a + b -> left, c + d -> right;
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        int count = 0;
        int init = rowNum * rowNum - 1;
        for (int i = 0; i < rowNum * rowNum; i ++) {
            for (int j = init; j >= 0; j --) {
                long long result = left[j] + right[i];
                if (result == 0) {
                    count ++;
                } else if (result < 0) {
                    break;
                } else {
                    init = j - 1;
                }
            }
        }
        cout << count << endl;
        if (caseNum != 0) {
            cout << endl;
        }
    }
    
	return 0;
}
