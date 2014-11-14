#include <iostream>
#include <vector>
using namespace std;


int main(){
    int N;
    while (cin >> N) {
        if (N == 0) {
            return 0;
        }
        int min_m = 100;
        for (int m = 1; m < N; m ++) {
            int count = 0, ini = 0;
            vector<int> col(N);
            for (int i = 0; i < N; i ++) {
                col[i] = i + 1;
            }
            while (col.size() > 1) {
                col.erase(col.begin() + ini);
                ini += (m - 1);
                while (ini >= col.size()) {
                    ini -= col.size();
                }
                count ++;
            }
            if (col[0] == 13) {
                min_m = (m < min_m)? m : min_m;
            }
        }
        cout << min_m << endl;
    }
    return 0;
}

