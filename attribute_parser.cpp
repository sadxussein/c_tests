#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <regex>
#include <map>

using namespace std;

/*
 * 1. Read and parse lines, also create child-parent relations
 * 2. Read and parse queries, also check child-parent relations
 */

struct attrs {
    string key, value;
};

int main() {
    int n, q;
    string str;
    cin >> n >> q;
    getline(cin, str);
    
    vector<string> queries(q);
    map<string, vector<attrs>> lines;
    map<string, string> parents;
    string prev_tag = "None";
    string line, query;
    
	// 1. Read and parse lines, also create child-parent relations
    for (int i=0; i<n; i++) {
        getline(cin, line);        
        regex words(R"(\"([^\"]*)\"|\b\w+\b)");
        sregex_token_iterator it(line.begin(), line.end(), words), end;
        string tag;
        if (line[1] != '/') {	// if not closing tag
            if (it != end) {	// parsing by regex
                tag = it->str();
                parents[tag] = prev_tag;
                prev_tag = tag;
                ++it;
            }
            while (it != end) {	// parsing by regex
                attrs atr;
                atr.key = it->str();
                ++it;
                atr.value = it->str();
                if (atr.value[0] == '"') {
                    atr.value = atr.value.substr(1, atr.value.length()-2);
                }
                ++it;
                lines[tag].push_back(atr);
            }
        }
        else {	// if tag closes we change previous parent to its parent
            tag = it->str();
            prev_tag = parents[tag];
        }
    }
    
	// 2. Read and parse queries, also check child-parent relations
    for (int i=0; i<q; i++) {
        getline(cin, query);
        vector<string> tags;
        string tag;
        string attr;
        int pos = query.find('.');
        tags.push_back("None");
        while (pos != string::npos) {	// parsing dots
            tags.push_back(query.substr(0, pos));
            query.erase(0, pos+1);
            pos = query.find('.');
        }
        pos = query.find('~');
        if (pos != string::npos) {		// final separation of last tag from attribute
            tags.push_back(query.substr(0, pos));
            query.erase(0, pos+1);
            attr = query;
        } 
        
		// in this here part we check child-parent relations
        bool tags_match = true;
        auto tags_it = tags.end();
        --tags_it;
        auto parents_it = parents.find(*tags_it);
        --tags_it;
        while (tags_match && tags_it != tags.begin()) {
            if (!(parents_it->second == *tags_it)) {
                tags_match = false;
            }
            parents_it = parents.find(*tags_it);
            --tags_it;
        }
        if (tags_match && tags_it == tags.begin()) {
            if (!(parents_it->second == *tags_it)) {
                tags_match = false;
            }
        }
        
		// final check
        string res = "Not Found!";
        if (tags_match) {
            for (string s : tags) {            
                auto sit = lines.find(s);
                if (sit != lines.end()) {
                    for (attrs a : sit->second) {
                        if (attr == a.key) {
                            res = a.value;
                        }
                    }
                }
            }
        }        
        cout << res << endl;
    }
}