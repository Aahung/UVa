#include <iostream>
#include <vector>
using namespace std;
int main(){
    int a, count;
    cin >> count;
    while (cin >> a) {
        vector<vector<int> > mat = vector<vector<int> >(a + 2, vector<int>(a + 2, 0));
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
            if (col == a + 1) {
                col = 1;
                if (++ row == a + 1){
                    /// start checking whether game is over
                    bool touchedMine = false;
                    vector<char> maskBackup = vector<char>(a * a);
                    for (int _row = 1; _row <= a; _row ++) {
                        for (int _col = 1; _col <= a; _col ++) {
                            //read masks
                            char temp_mask;
                            cin >> temp_mask;
                            maskBackup[(_row - 1) * a + _col - 1] = temp_mask;
                            if (temp_mask == 'x' && mat[_row][_col] < 0)
                                touchedMine = true;
                        }
                    }
                    //starting output game result
                    for (int _row = 1; _row <= a; _row ++) {
                        for (int _col = 1; _col <= a; _col ++) {
                            //read masks
                            char temp_mask;
                            temp_mask = maskBackup[(_row - 1) * a + _col - 1];
                            if (mat[_row][_col] < 0 && touchedMine) {
                                cout << '*'; // this is still 10189 stuff
                            } else {
                                if (temp_mask == 'x')
                                    cout << mat[_row][_col];
                                else
                                    cout << '.';
                            }
                        }
                        cout << endl;
                    }
                    //check case number
                    if (-- count == 0) return 0;
                    cout << endl;
                    break;
                }
            }
        }
    }
    return 0;
}