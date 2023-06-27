#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class lines {
public:
    int level;
    string line, temp_line, buffer;
    string parent;
    string tag;
    
    vector<string> values;
    bool isTagOpened;

    void analyze() {
        
        stringstream ss(line);
        while (!ss.eof()) {
            ss >> temp_line;
            if (temp_line[0] == '<') {
                if (temp_line[1] == '/') {
                    if (temp_line.erase(0, 2) == tag) {
                        isTagOpened = false;
                    }
                }
                else {
                    temp_line.erase(0, 1);
                    tag = temp_line;
                }                
            }            
            else if (temp_line[temp_line.length() - 1] == '>') {
                temp_line.pop_back();
                values.push_back(temp_line);
                isTagOpened = true;
            }
            else if (temp_line != "=") {
                values.push_back(temp_line);
            }
        }
    }

    lines() {
        parent = "none";
        line = "";
        level = 0;
        isTagOpened = false;
    }
};

int main() {
    int n, q;  
    string str;
    cin >> n >> q;
    getline(cin, str);

    vector<lines> lines_array(n);
    vector<string> queries_array(q);
    vector<string> element(n);

    for (int i = 0; i < n; i ++) {
        getline(cin, lines_array[i].line);
        lines_array[i].analyze();
    }

    for (int i = 0; i < q; i++) {
        getline(cin, queries_array[i]);
    }

    for (lines l : lines_array) {
        cout << l.line << endl;
    }

    for (string q : queries_array) {
        cout << q << endl;
    }

    return 0;
}
