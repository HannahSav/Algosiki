#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stdlib.h>

using namespace std;

map<string, vector<int> > all_var; //<имя переменной: значения >
map< int,set<string> > used_this_level;//level, names
int level;

bool ifNumber(string word){
    if(word[0]!='-'&&(word[0] > '9' || word[0] < '0')) return false;
	for(int i = 1; i<word.size(); i++)
		if(word[i] > '9' || word[i] < '0')
    		return false;
	return true;
}

void remade_vec(string name, int last_num, set<string> &used_set){
    //cout<< last_num<<" - last num\n";
    vector<int> replace_vec;
    replace_vec.clear();
    if(all_var.find(name)!=all_var.end()){
        replace_vec = all_var[name];
        if(used_set.find(name) != used_set.end())
            replace_vec.pop_back();
    }
    replace_vec.push_back(last_num);
    //cout<< "+++"<< replace_vec.size()<<" "<<replace_vec[replace_vec.size()-1]<< endl;
    //replace_vec.push_back(last_num);
    all_var[name] = replace_vec;
}

int main() {
	string str;
	string str1;
	string str2;
	vector<int> replace_vec;
	set<string> used_set;
	level = 0;
	map<string, vector<int> >::iterator it;
	map<int, set<string> >::iterator it_level;
	vector<int> :: iterator it_vec;
	while(getline(cin, str)){
	    replace_vec.clear();
		if(str[0] == '{'){
			level++;
			used_this_level.insert({level-1, used_set});
			used_set.clear();
		}
		else {
			if(str[0] == '}'){
				for(set<string>::iterator i=used_set.begin(); i != used_set.end(); i++){
                        string s = *i;
                        it = all_var.find(s);
                        //if((it->second).size() > 1)
                        all_var[s].pop_back();
                        if(all_var[s].size()==0)
                            all_var.erase(s);
				}
				used_set = used_this_level.find(level-1)->second;
				if(used_this_level.find(level) != used_this_level.end()){
                    it_level = used_this_level.find(level);
                    used_this_level.erase(it_level);
				}
				level--;
			}
			else{
				str1 = "";
				str2 = "";
				int i = 0;
				while(str[i]!='='){
					str1+=str[i];
					i++;
				}
				str2 = str.substr(i+1, str.size()-1);
				if(ifNumber(str2)){
                    remade_vec(str1, atoi(str2.c_str()), used_set);
				}
				else{
					int now_number;
					if(all_var.find(str2)==all_var.end()){
                        now_number = 0;
					}
					else{
                        replace_vec = all_var[str2];
                        now_number = replace_vec[replace_vec.size()-1];
					}
                    remade_vec(str1, now_number, used_set);

					cout <<now_number<<endl;
				}
				//cout<<">>>"<< str1<<" "<< all_var[str1].size()<<" "<< all_var[str1][all_var[str1].size()-1]<< endl;
				used_set.insert(str1);
			}
		}
	}
	return 0;
}
