#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool includeElement(vector<int>, int);
int main(){
    int guess;
    string str_a, str_b;
    while (1) {
        vector<int> collect = vector<int>(10);
        for (int i = 0; i < 10; i ++) {
            collect[i] = i + 1;
        }
        while (cin >> guess) {
            if (!guess) {
                return 0;
            }
            cin >> str_a >> str_b;
            if (str_a == "too") {
                if (str_b == "high") {
                    for (int i = 0; i < collect.size(); i ++) {
                        if (collect[i] >= guess) {
                            collect[i] = -1;
                        }
                    }
                }
                if (str_b == "low") {
                    for (int i = 0; i < collect.size(); i ++) {
                        if (collect[i] <= guess) {
                            collect[i] = -1;
                        }
                    }
                }
            }
            if (str_a == "right" && str_b == "on") {
                if (includeElement(collect, guess)) {
                    cout << "Stan may be honest" << endl;
                } else {
                    cout << "Stan is dishonest" << endl;
                }
                break;
            }
        }
    }
    return 0;
}

bool includeElement(vector<int> collect, int element) {
    bool has = false;
    for (int i = 0; i < collect.size(); i ++) {
        if (element == collect[i]) {
            has = true;
        }
    }
    return has;
}
