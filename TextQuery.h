#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <set>
using namespace std;

typedef vector<string>::size_type line_no;
class TextQuery{
public:
		void read_file(ifstream& is){
				store_file(is);
				build_map();
		}
		set<line_no> run_query(const string &) const;
		string text_line(line_no) const;

private:
		void store_file(ifstream&);
		void build_map();
		vector<string> lines_of_text;
		map< string,set<line_no> > word_map;
};
#endif
