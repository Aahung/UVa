//
//  main.cpp
//  testing1
//
//  Created by Xinhong LIU on 17/5/14.
//  Copyright (c) 2014 Xinhong LIU. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <list>
#include <string>
#include <stack>

using namespace std;

#define MAXL 81
int dis[MAXL][MAXL];

stack<string> output = stack<string>();

int dp(string t, string l, int ti, int li) {
    if (dis[ti][li] != -1) {
        return dis[ti][li];
    }
    if (ti == 0 && li == 0) {
        dis[ti][li] = 0;
        return 0;
    }
    if (ti == 0) {
        dis[ti][li] = dp(t, l, ti, li - 1) + 1;
        return dis[ti][li];
    }
    if (li == 0) {
        dis[ti][li] = dp(t, l, ti - 1, li) + 1;
        return dis[ti][li];
    }
    if (t[ti - 1] == l[li - 1]) {
        dis[ti][li] = dp(t, l, ti - 1, li - 1);
        return dis[ti][li];
    }
    int r = dp(t, l, ti - 1, li - 1) + 1;
    int d = dp(t, l, ti - 1, li) + 1;
    int i = dp(t, l, ti, li - 1) + 1;
    int m = min(min(r, i), d);
    dis[ti][li] = m;
    return m;
}

void print(string t, string l, int ti, int li) {
    if (ti == 0 && li == 0) {
        return;
    }
    if (ti == 0) {
        output.push("Insert " + to_string(li) + "," + l[li - 1]);
        print(t, l, ti, li - 1);
        return;
    }
    if (li == 0) {
        output.push("Delete " + to_string(li + 1));
        print(t, l, ti - 1, li);
        return;
    }
    if (t[ti - 1] == l[li - 1]) {
        print(t, l, ti - 1, li - 1);
        return;
    }
    int r = dis[ti - 1][li - 1];
    int d = dis[ti - 1][li];
    int i = dis[ti][li - 1];
    int m = min(min(r, i), d);
    if (r == m) {
        output.push("Replace " + to_string(li) + "," + l[li - 1]);
        print(t, l, ti - 1, li - 1);
    } else if (d == m) {
        output.push("Delete " + to_string(li + 1));
        print(t, l, ti - 1, li);
    } else {
        output.push("Insert " + to_string(li) + "," + l[li - 1]);
        print(t, l, ti, li - 1);
    }
    return;
}

int main() {
    string top, left;
    bool blank = false;
    while (true) {
        if (cin.peek() == EOF) {
            break;
        }
        getline(cin, top);
        getline(cin, left);
        if (blank) {
            cout << endl;
            blank = false;
        }
        for (int i = 0; i < MAXL; ++i) {
            for (int j = 0; j < MAXL; ++j) {
                dis[i][j] = -1;
            }
        }
        int step = dp(top, left, top.size(), left.size());
        cout << step << endl;
        print(top, left, top.size(), left.size());
        int count = 0;
        while (!output.empty()) {
            cout << ++count << " " << output.top() << endl;
            output.pop();
        }
        blank = true;
    }
    return 0;
}