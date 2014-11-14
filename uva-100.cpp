//
//  main.cpp
//  strong int
//
//  Created by Xinhong LIU on 7/11/13.
//  Copyright (c) 2013 Xinhong LIU. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
typedef std::map<int, int> tIntIntMap;
typedef std::pair<int, int> tIntIntPair;

int getLength(unsigned int i, tIntIntMap & buffer){
	int length = 1, _i = i;
    tIntIntMap::const_iterator pos = buffer.find(_i);
    if (pos == buffer.end()) {
        while (i != 1){
            if (i % 2 == 1){
                i = (3 * i + 1) / 2;
                length += 2;
            }
            else{
                i = i / 2;
                length ++;
            }
        }
        buffer.insert(tIntIntPair(_i, length));
        return length;
    } else {
        return pos->second;
    }
}
int main()
{
    tIntIntMap buffer;
    unsigned int a, b, t;
	int max, length;
	while (scanf ("%d %d", &a, &b) != EOF){
		printf ("%d %d", a, b);
		if (a > b){
			t = a;
			a = b;
			b = t;
		}
		max = 0;
		for (int i = a; i <= b; i++){
			length = getLength(i, buffer);
			max = (max < length)? length : max;
		}
		printf (" %d\n", max);
	}
    return 0;
}

