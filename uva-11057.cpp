#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

////change two's position and check the change
//T3S4 - T4S3
using namespace std;

int main(){
    int bookNum;
    while (cin >> bookNum) {
        vector<int> book = vector<int>(bookNum);
        for (int i = 0; i < bookNum; i ++) {
            cin >> book[i];
        }
        int money;
        cin >> money;
        sort(book.begin(), book.end());//sort
        vector<int> small = vector<int>();
        vector<int> large = vector<int>();
        for (int i = 0; i < bookNum; i ++) {
            if (book[i] > money / 2) {
                large.push_back(book[i]);
            } else {
                small.push_back(book[i]);
            }
        }
        sort(small.begin(), small.end(), std::greater<int>());
        int aSmall = 0, aLarge = money;
        if (money % 2 == 0 && small[0] == money / 2 && small[1] == money / 2) {
            aSmall = aLarge = money / 2;
        }
        for (int i = 0; i < small.size(); i ++) {
            for (int j = 0; j < large.size(); j ++) {
                if (small[i] + large[j] == money) {
                    if ((large[j] - small[i]) < (aLarge - aSmall)) {
                        aLarge = large[j];
                        aSmall = small[i];
                    } else {
                        break;
                    }
                } else if (small[i] + large[j] > money) {
                    break;
                }
            }
        }
        cout << "Peter should buy books whose prices are " << aSmall << " and " << aLarge << "." << endl << endl;
    }
    return 0;
}