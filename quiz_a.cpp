#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
    
    int caseNum;
    cin >> caseNum;
    while (caseNum -- > 0) {
        int m, c, te, r, tr, l;
        cin >> m >> c >> te >> r >> tr >> l;
        int times = c / m;
        if (c % m != 0) {
            times ++;
        }
        int cool_down_times = times / r;
        if (times % r == 0 && times != 0) {
            cool_down_times --;
        }
        int total_time =  times * te + cool_down_times * tr;
        cout << "The time is " << total_time << "s. ";
        if (total_time >= l || times == 0) {
            cout << ">:(" << endl;
        } else {
            cout << ":3" << endl;
        }
    }
    return 0;
}