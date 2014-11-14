#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

int main() {
    vector<unsigned int> col(0);
    for (int i = 0; i < 32; i ++) {
        for (int j = 0; j < 20; j ++) { //3^20 > 2 ^ 31
            unsigned long result = pow(2,i) * pow(3,j);
            if (result <= 2147483648) {
                col.push_back((unsigned int)result);
            }
        }
    }
    sort(col.begin(), col.end());
	while (1) {
        int num;
        cin >> num;
        if (num == 0) {
            return 0;
        }
        for (int i = 0; true; i ++) {
            if (col[i] >= num) {
                cout << col[i] << endl;
                break;
            }
        }
    }
    
	return 0;
}
