
//  Created by Xinhong LIU on someday.
//  Copyright (c) 2013 Xinhong LIU. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int caseNum;
    cin >> caseNum;
    cin.get();
    while (caseNum-- > 0) {
        vector<string> col;
        string tmp;
        getline(cin, tmp);
        while(getline(cin, tmp)){
            col.insert(col.end(), tmp);
            if (cin.peek() == '\n') {
                break;
            }
        }
        sort(col.begin(), col.end());
        string init = "-1";
        int count = 0;
        for (int i = 0; i < col.size(); i ++) {
            if (col[i] != init) {
                if (init != "-1") {
                    
                    cout << setprecision(4) << fixed << count * 100.0 / col.size() <<  endl;
                }
                cout << col[i] << " "; //name
                init = col[i];
                count = 0;
            }
            count ++;
            if (i == col.size() - 1) {
                cout << setprecision(4) << fixed << count * 100.0 / col.size() <<  endl;
            }
        }
    }
    return 0;
}

