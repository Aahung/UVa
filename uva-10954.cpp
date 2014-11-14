
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
    while (1) {
        int num;
        cin >> num;
        if (num == 0) {
            return 0;
        }
        vector<int> col(num);
        for (int i = num - 1; i >= 0; i --) {
            cin >> col[i];
        }
        int cost = 0;
        while (col.size() > 1) {
            sort(col.begin(), col.end());
            int tmp = col[0] + col[1];
            cost += tmp;
            col[1] = tmp;
            col.erase(col.begin());
        }
        cout << cost << endl;
    }
    return 0;
}

