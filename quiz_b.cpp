#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
    
    int caseNum = 0;
    char tmp1[256] = "";
    char tmp2[256] = "";
    char tmp3[256] = "";
    while (cin.getline(tmp1, 256) && cin.getline(tmp2, 256) && cin.getline(tmp3, 256)) {
        string un = "";
        un += tmp1;
        string key = "";
        key += tmp2;
        char *pEnd;
        long long offset = strtol(tmp3, &pEnd,10);;
        // do cal
        if (caseNum != 0) {
            //cout << endl;
        }
        
        
        
        for (int i = 0; i < un.length(); i ++) {
            if (un[i] == ' ') {
                break;
            }
            for (int j = 0; j < key.length(); j ++) {
                if (un[i] == key[j]) {
                    int newJ = j + offset % key.length();
                    while (newJ >= key.length()) {
                        newJ -= key.length();
                    }
                    un[i] = key[newJ];
                    break;
                }
            }
        }
        
        cout << un;
        
        cout << endl;
        caseNum ++;
    }
    return 0;
}