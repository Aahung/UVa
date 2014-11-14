
//  Created by Xinhong LIU on someday.
//  Copyright (c) 2013 Xinhong LIU. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string tmp1, tmp2;
    map<string, string> col;
    while (cin >> tmp1 >> tmp2) {
        pair<string, string> pr = pair<string, string>(tmp2, tmp1);
        col.insert(pr);
        cin.get();
        if (cin.peek() == '\n') {
            break;
        }
    }
    while (cin >> tmp1) {
        if (col.find(tmp1) == col.end()) {
            cout << "eh" << endl;
        } else
            cout << col[tmp1] << endl;
    }
    return 0;
}

