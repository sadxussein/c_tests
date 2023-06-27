#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <regex>

using namespace std;

/*class lines {
public:
	lines() {
		parent = nullptr;
		isOpened = true;
		level = 0;
	}
	void set_parent(lines* p) {	// parent setter
		parent = p;
	}
	lines* get_parent() {
		return parent;
	}
	void set_tag(string t) {
	}
	string get_tag() {
		return tag;
	}
	void set_level(int l) {
		level = l;
	}
	int get_level() {
		return level;
	}
	void parse_elements(string str) {
		regex words("\\w+");
		sregex_token_iterator it(str.begin(), str.end(), words), end;
		while (it != end) {
			values.push_back(it->str());
			++it;
		}
		tag = values[0];
		cout << "stored values: ";
		for (string v : values) {
			cout << v << " ";
		}
		cout << endl;
	}
	void close() {
		isOpened = false;
	}
private:
	lines* parent;	// parent pointer
	vector<string> values;
	string tag;
	int level;
	bool isOpened;
};*/

int main() {
	int n, q;
	string str;
	cin >> n >> q;
	getline(cin, str);	// this line is required to read 1 empty line before reading input, otherwise it 'eats' first line of user input
	
	vector<string> lines(n), queries(q);
	string query;
	
/*	vector<string> queries(q);
	vector<lines> lines_v;
	lines* parent_line = nullptr;
	int level = 0;


	for (int i=0; i<n; i++) {
		lines line;
		getline(cin, str);
		if (i == 0) {
			line.parse_elements(str);	// parse values from string
			lines_v.push_back(line);	// add new first line and it is opened by default
			parent_line = &lines_v.back();
			cout << parent_line->get_tag() << endl;
		} else {
			if (str[1] != '/') {
				line.parse_elements(str);
				line.set_parent(parent_line);	// set parent inside lines vector
				level++;
				line.set_level(level);		// set nesting level				
				lines_v.push_back(line);
//				parent_line = &lines_v.back();			// set pointer to parent

			}
			else {
				line.parse_elements(str);
				for (lines l : lines_v) {
					if (line.get_tag() == l.get_tag()) {
						l.close();
						if (level > 0) {
							parent_line = l.get_parent();
						}
						else {
							parent_line = nullptr;
						}
						level--;
						break;
					}
				}
			}
		}
	}*/

	for (int i=0; i<n; i++) {
		getline(cin, lines[i]);
	}

	for (int i=0; i<q; i++) {
		int pos = 0;
        getline(cin, query);
		vector<string> tags;
		string tag, key;
		while ((pos = query.find('.')) != string::npos) {
			tags.push_back(query.substr(0, pos));
			query.erase(0, pos+1);
			cout << query << endl;
		}
		if (tags.size() != 0) {
			pos = tags.back().find('~');
			key = tags.back().substr(pos);
		}
		else {
			tag = 
		}
		
		for (string s : tags) {
			cout << s << " ";
		}
		cout << key << endl;
    }
}
