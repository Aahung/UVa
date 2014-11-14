#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;


unsigned int count_border_pos (unsigned int length) {
    int order = 0;
    unsigned int pos = 0;
    while (length >= pow(10, order) ) {
        pos += (length - pow(10, order) + 1);
        order ++;
    }
    return pos;
}

vector<unsigned int> derive_largest_num (unsigned int offset) {
    unsigned int largest_num = 0;
    unsigned int _offset = 0;
    while (_offset < offset) {
        _offset += (floor( log10(++largest_num)) + 1);
    }
    vector<unsigned int> out(2);
    out[0] = --largest_num;
    out[1] = _offset - (floor( log10(++largest_num)) + 1);
    return out;
}

int main() {
    int caseNum;
    cin >> caseNum;
    while (caseNum -- > 0) {
        unsigned int pos;
        cin >> pos;
        unsigned int left_border_length = 0;
        unsigned int left_border_pos = 0;
        while (left_border_pos < pos) {
            left_border_length ++;
            left_border_pos += count_border_pos(left_border_length);
        }
        left_border_pos -= count_border_pos(left_border_length);
        left_border_length --;
        unsigned int offset = pos - left_border_pos;
        vector<unsigned int> output = derive_largest_num(offset);
        unsigned int left_num = output[0];
        unsigned int left_num_offset = output[1];
        unsigned int this_num = left_num + 1;
        unsigned int this_offset = offset - left_num_offset;
        unsigned int this_offset_invert = floor( log10(this_num)) + 1 - this_offset;
        while (this_offset_invert > 0) {
            this_num /= 10;
            this_offset_invert --;
        }
        cout << this_num % 10 << endl;
    }
    
    return 0;
}
