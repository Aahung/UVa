#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

////change two's position and check the change
//T3S4 - T4S3
using namespace std;

vector<int> findStr(vector<vector<char> > col, string str){
    int diff[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    for (int i = 0; i < col.size(); i ++) {
        for (int j = 0; j < col.size(); j ++) {
            if (col[i][j] == str[0]) {
                for (int k = 0; k < 8; k ++) {
                    int pos[] = {i, j};
                    bool found = true;
                    for (int w = 1; w < str.length(); w ++) {
                        pos[0] += diff[k][0];
                        pos[1] += diff[k][1];
                        if (pos[0] < 0 || pos[0] >= col.size() || pos[1] < 0 || pos[1] > col.size() || col[pos[0]][pos[1]] != str[w]) {
                            found = false;
                            break;
                        }
                    }
                    if (found) {
                        vector<int> output = vector<int>(4);
                        output[0] = i + 1;
                        output[1] = j + 1;
                        output[2] = pos[0] + 1;
                        output[3] = pos[1] + 1;
                        return output;
                    }
                }
            }
        }
    }
    vector<int> temp = vector<int>(4);
    temp[0] = temp[1] = temp[2] = temp[3] = -1;
    return temp;
}
int main(){
    int sideLength;
    cin >> sideLength;
    vector<vector<char> > col = vector<vector<char> >(sideLength, vector<char>(sideLength));
    for (int i = 0; i < sideLength; i ++) {
        for (int j = 0; j < sideLength; j ++) {
            cin >> col[i][j];
        }
    }
    vector<string> strCol = vector<string>();
    string temp;
    while (cin >> temp) {
        if (temp == "0") {
            break;
        }
        strCol.push_back(temp);
    }
    //finish get input
    for (int i = 0; i < strCol.size(); i ++) {
        vector<int> pos = findStr(col, strCol[i]);
        if (pos[0] == -1 && pos[1] == -1) {
            cout << "Not found" << endl;
        } else {
            cout << pos[0] << "," << pos[1] << " "
            << pos[2] << "," << pos[3] << endl;
        }
    }
    return 0;
}