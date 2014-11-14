#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <queue>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

struct node {
    int rows, cols;
    int topleft_r, topleft_c;
    node * tl, * tr, * bl, * br;
};

void generate_tree(node * root) {
    if (root->rows <= 1 && root->cols <= 1) {
        return;
    }
    node * tl = new node {
        (int)ceil(root->rows / 2.0),
        (int)ceil(root->cols / 2.0),
        root->topleft_r,
        root->topleft_c,
        nullptr, nullptr, nullptr, nullptr
    };
    root->tl = tl;
    generate_tree(root->tl);
    if (root->rows > 1) {
        node * bl = new node {
            root->rows - (int)ceil(root->rows / 2.0),
            (int)ceil(root->cols / 2.0),
            root->topleft_r + (int)ceil(root->rows / 2.0),
            root->topleft_c,
            nullptr, nullptr, nullptr, nullptr
        };
        root->bl = bl;
        generate_tree(root->bl);
    }
    if (root->cols > 1) {
        node * tr = new node {
            (int)ceil(root->rows / 2.0),
            root->cols - (int)ceil(root->cols / 2.0),
            root->topleft_r,
            root->topleft_c + (int)ceil(root->cols / 2.0),
            nullptr, nullptr, nullptr, nullptr
        };
        root->tr = tr;
        generate_tree(root->tr);
    }
    if (root->rows > 1 && root->cols > 1) {
        node * br = new node {
            root->rows - (int)ceil(root->rows / 2.0),
            root->cols - (int)ceil(root->cols / 2.0),
            root->topleft_r + (int)ceil(root->rows / 2.0),
            root->topleft_c + (int)ceil(root->cols / 2.0),
            nullptr, nullptr, nullptr, nullptr
        };
        root->br = br;
        generate_tree(root->br);
    }
}

bool mat[200][200];

void print_tree(node * root, stringstream * ss) {
    bool same = true;
    bool first_val = mat[root->topleft_r][root->topleft_c];
    for (int r = root->topleft_r; r < root->rows + root->topleft_r; ++r) {
        for (int c = root->topleft_c; c < root->cols + root->topleft_c; ++c) {
            if (mat[r][c] != first_val) {
                // not same
                same = false;
                break;
            }
        }
        if (!same) {
            break;
        }
    }
    if (same) {
        *ss << ((first_val)? 1 : 0);
    } else {
        *ss << "D";
        print_tree(root->tl, ss);
        if (root->tr != nullptr) {
            print_tree(root->tr, ss);
        }
        if (root->bl != nullptr) {
            print_tree(root->bl, ss);
        }
        if (root->br != nullptr) {
            print_tree(root->br, ss);
        }
    }
}

void generate_matrix(node * root) {
    // require cin
    char input;
    cin >> input;
    if (input != 'D') {
        bool value = (input == '1')? true : false;
        for (int r = root->topleft_r; r < root->rows + root->topleft_r; ++r) {
            for (int c = root->topleft_c; c < root->cols + root->topleft_c; ++c) {
                mat[r][c] = value;
            }
        }
    } else {
        if (root->tl != nullptr) {
            generate_matrix(root->tl);
        }
        if (root->tr != nullptr) {
            generate_matrix(root->tr);
        }
        if (root->bl != nullptr) {
            generate_matrix(root->bl);
        }
        if (root->br != nullptr) {
            generate_matrix(root->br);
        }
    }
}

void delete_tree(node * root) {
    if (root) {
        if (root->tl != nullptr) {
            delete_tree(root->tl);
        }
        if (root->tr != nullptr) {
            delete_tree(root->tr);
        }
        if (root->bl != nullptr) {
            delete_tree(root->bl);
        }
        if (root->br != nullptr) {
            delete_tree(root->br);
        }
        delete root;
    }
}

int main() {
    char form;
    while (cin >> form && form != '#') {
        //
        int rows, cols;
        cin >> rows >> cols;
        // generate tree
        
        // root
        node * root = new node{
            rows,
            cols,
            0,
            0,
            nullptr,
            nullptr,
            nullptr,
            nullptr
        };
        // split
        generate_tree(root);
        if (form == 'B') {
            // fill the mat
            char tmp;
            for (int r = 0; r < rows; ++r) {
                for (int c = 0; c < cols; ++c) {
                    cin >> tmp;
                    if (tmp == '0') mat[r][c] = false;
                    else mat[r][c] = true;
                }
            }
            cout << "D" << setw(4) << rows << setw(4) << cols << endl;
            stringstream * ss = new stringstream;
            print_tree(root, ss);
            string outputs = (*ss).str();
            for (int i = 0; i < outputs.size(); ++i) {
                if (i > 0 && i % 50 == 0) {
                    cout << endl;
                }
                cout << outputs[i];
            }
            delete ss;
        } else {
            generate_matrix(root);
            cout << "B" << setw(4) << rows << setw(4) << cols << endl;
            for (int r = 0; r < rows; ++r) {
                for (int c = 0; c < cols; ++c) {
                    int i = r * rows + c;
                    if (i > 0 && i % 50 == 0) {
                        cout << endl;
                    }
                    cout << ((mat[r][c])? 1 : 0);
                }
            }
        }
        cout << endl;
        delete_tree(root);
    }
    return 0;
}