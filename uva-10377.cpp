#include <iostream>
#include <string>
#include <vector>
using namespace std;

char turnRight(char direction) {
    switch (direction) {
        case 'N':
            return 'E';
            break;
        case 'E':
            return 'S';
            break;
        case 'S':
            return 'W';
            break;
        case 'W':
            return 'N';
            break;
    }
    return -1;
}
char turnLeft(char direction) {
    switch (direction) {
        case 'N':
            return 'W';
            break;
        case 'E':
            return 'N';
            break;
        case 'S':
            return 'E';
            break;
        case 'W':
            return 'S';
            break;
    }
    return -1;
}
int main(){
    int caseNum;
    cin >> caseNum;
    while (caseNum > 0) {
        int a, b;
        cin >> a >> b;
        vector<vector<bool> > maze = vector<vector<bool> >(a, vector<bool>(b));
        char temp;
        int row = 0, col = 0; // for reading maze
        while ((temp = cin.get())) {
            while (temp == '\n') {
                temp = cin.get();
            }
            maze[row][col] = (temp == '*');
            if (++ col == b) {
                col = 0;
                if (++ row == a) {
                    break;
                }
            }
        }
        //for starting simulation
        char direction = 'N';
        cin >> row >> col;
        while ((temp = cin.get())) {
            while(temp == '\n' || temp == ' ') {
                temp = cin.get();
            }
            if (temp == 'R') {
                direction = turnRight(direction);
            }
            if (temp == 'L') {
                direction = turnLeft(direction);
            }
            if (temp == 'Q') {
                break;
            }
            if (temp == 'F') {
                switch (direction) {
                    case 'N':
                        if (maze[-- row][col]) {
                            row ++;
                        }
                        break;
                    case 'E':
                        if (maze[row][++ col]) {
                            col --;
                        }
                        break;
                    case 'S':
                        if (maze[++ row][col]) {
                            row --;
                        }
                        break;
                    case 'W':
                        if (maze[row][-- col]) {
                            col ++;
                        }
                        break;
                }
            }
        }
        cout << row + 1 << ' ' << col + 1 << ' ' << direction << endl;
        if (-- caseNum > 0) {
            cout << endl;
        }
    }
    return 0;
}
