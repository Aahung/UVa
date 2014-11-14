#include <iostream>
#include <vector>
using namespace std;
int main(){
    int a, b, count = 1;
    while (cin >> a >> b) {
        if (a * b == 0)
            return 0;
        if (count > 1) {
            cout << endl;
        }
        vector<vector<int> > mat = vector<vector<int> >(a + 2, vector<int>(b + 2, 0));
        char temp;
        int row = 1, col = 1;
        while (cin >> temp) {
            if (temp == '*') {
                mat[row][col] = -10;
                mat[row - 1][col - 1] ++;
                mat[row - 1][col] ++;
                mat[row - 1][col + 1] ++;
                mat[row][col - 1] ++;
                mat[row][col + 1] ++;
                mat[row + 1][col - 1] ++;
                mat[row + 1][col] ++;
                mat[row + 1][col  + 1] ++;
            }
            col ++;
            if (col == b + 1) {
                col = 1;
                row ++;
            }
            if (row == a + 1) {
                /// end
                cout << "Field #" << count << ":" << endl;
                for (int _row = 1; _row <= a; _row ++) {
                    for (int _col = 1; _col <= b; _col ++) {
                        if (mat[_row][_col] < 0) {
                            cout << '*';
                        } else {
                            cout << mat[_row][_col];
                        }
                    }
                    cout << endl;
                }
                count ++;
                break;
            }
        }
    }
    return 0;
}