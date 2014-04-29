#include <iostream>
#include <cstdlib>
#include "TextQuery.h"
using namespace std;
void print_results(const set<line_no>& locs,
				const string& sought, const TextQuery &file)
{
		typedef set<line_no> line_nums;
		line_nums::size_type size = locs.size();
		cout<<"\n"<<sought<<" occurs "<<size<<" "<<endl;
		line_nums::const_iterator it = locs.begin();
		for(;it != locs.end();++it){
				cout<<"\t(line"<<(*it)+1<<")"<<file.text_line(*it) <<endl;
		}
}
ifstream& open_file(ifstream &in,const string &file)
{
		in.close();
		in.clear();
		in.open(file.c_str());
		return in;
}
int main(int argc, char **argv)
{
		ifstream infile;
		if(argc<2 || !open_file(infile, argv[1])){
				cerr<<" no input file!"<<endl;
				return EXIT_FAILURE;
		}
		TextQuery tq;
		tq.read_file(infile);
		while(true){
				cout<<"enter word to look for,or q to quit:";
				string s;
				cin>>s;
				if(!cin || s == "q")
						break;
				set<line_no> locs = tq.run_query(s);
				print_results(locs, s, tq);
		}

		return 0;
}
