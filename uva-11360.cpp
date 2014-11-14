#include <iostream>
#include <vector>
using namespace std;


int main(){
    int caseNum;
    cin >> caseNum;
    for (int i = 1; i <= caseNum; i ++) {
        cout << "Case #" << i << endl;
        int a;
        cin >> a;
        vector< vector<int> > matrix = vector< vector<int> >(a, vector<int>(a));
        for (int row = 0; row < a; row ++) {
            for (int col = 0; col < a; col ++) {
                char temp;
                cin >> temp;
                matrix[row][col] = (int)temp - 48;
            }
        }
        int operationNum;
        cin >> operationNum;
        for (int j = 0; j < operationNum; j ++) {
            string _operator;
            cin >> _operator;
            if (_operator == "transpose") {
                vector< vector<int> > _temp = vector< vector<int> >(a, vector<int>(a));
                for (int row = 0; row < a; row ++) {
                    for (int col = 0; col < a; col ++) {
                        _temp[row][col] = matrix[col][row];
                    }
                }
                matrix = _temp;
            } else if (_operator == "row") {
                int _a, _b;
                cin >> _a >> _b;
                vector<int> temp(a);
                temp = matrix[_a - 1];
                matrix[_a - 1] = matrix[_b - 1];
                matrix[_b - 1] = temp;
            } else if (_operator == "col") {
                int _a, _b;
                cin >> _a >> _b;
                //vector< vector<int> > _temp = vector< vector<int> >(a, vector<int>(a));
                for (int row = 0; row < a; row ++) {
                    int temp = matrix[row][_a - 1];
                    matrix[row][_a - 1] = matrix[row][_b - 1];
                    matrix[row][_b - 1] = temp;
                }
            } else if (_operator == "inc") {
                for (int row = 0; row < a; row ++) {
                    for (int col = 0; col < a; col ++) {
                        if (++ matrix[row][col] == 10)
                            matrix[row][col] = 0;
                    }
                }
            } else if (_operator == "dec") {
                for (int row = 0; row < a; row ++) {
                    for (int col = 0; col < a; col ++) {
                        if (-- matrix[row][col] == -1)
                            matrix[row][col] = 9;
                    }
                }
            }
        }
        for (int row = 0; row < a; row ++) {
            for (int col = 0; col < a; col ++) {
                cout << matrix[row][col];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

