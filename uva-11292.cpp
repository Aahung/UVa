#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int d_num, k_num;
    while (cin >> d_num >> k_num) {
        if (d_num == 0 && k_num == 0) {
            return 0;
        }
        vector<int> d_size = vector<int>(d_num);
        vector<int> k_size = vector<int>(k_num);
        for (int i = 0; i < d_num; i ++) {
            cin >> d_size[i];
        }
        for (int i = 0; i < k_num; i ++) {
            cin >> k_size[i];
        }
        if (d_num > k_num) {
            cout << "Loowater is doomed!" << endl;
        } else {
            sort(d_size.begin(), d_size.end());
            sort(k_size.begin(), k_size.end());
            int money = 0;
            int killed = 0;
            for (int i = 0; i < d_size.size(); i ++) {
                for (int j = 0; j < k_size.size(); j ++) {
                    if (d_size[i] <= k_size[j]) {
                        money += k_size[j];
                        killed ++;
                        k_size.erase(k_size.begin() + j);
                        break;
                    }
                }
            }
            if (killed < d_num) {
                cout << "Loowater is doomed!" << endl;
            } else
                cout << money << endl;
        }
    }
    return 0;
}