#include <iostream>
#include <vector>
using namespace std;

int getTermNum(long limit, long init);
int main(){
    long a, b;
    int caseNum = 1;
    while (cin >> a >> b) {
        if (a < 0 && b < 0)
            return 0;
        cout << "Case " << caseNum ++ << ": A = " << a << ", limit = " << b << ", number of terms = " << getTermNum(b, a) << endl;
    }
    return 0;
}

int getTermNum(long limit, long init) {
    int termNum = 1;
    while (init != 1) {
        if (init % 2 == 0) {
            init /= 2;
        } else {
            init *= 3;
            init += 1;
        }
        if (init > limit) {
            break;
        }
        termNum ++;
    }
    return termNum;
}