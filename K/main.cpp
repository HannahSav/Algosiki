#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int the_ask;
    set<vector<int> > space_length, space_start; //пустые отрезки(длина, начало.. начало, длина)
    map<int, vector<int> > ask_info; //запросник(номер: начало, длина)
    vector<int> vec;
    vec.push_back(m);
    vec.push_back(1);
    space_length.insert(vec);
    vec.clear();
    vec.push_back(1);
    vec.push_back(m);
    space_start.insert(vec);
    int using_start;
    int using_length;
    vector<int> new_one, del;
    int new_len, new_start;
    vector<int> post_vec, prev_vec;
    set<vector<int> >::iterator it;
    for (int i = 0; i < n; i++) {
        cin >> the_ask;
        if (the_ask > 0) {
            if (space_length.size() == 0 || the_ask > (*--space_length.end())[0])
                cout << "-1" << endl;
            else {
                cout << (*--space_length.end())[1] << endl;
                using_length = (*--space_length.end())[0];
                using_start = (*--space_length.end())[1];
                ask_info[i].push_back((*--space_length.end())[1]);
                ask_info[i].push_back(the_ask);
                space_length.erase(*--space_length.end());
                vec.clear();
                vec.push_back(using_start);
                vec.push_back(using_length);
                space_start.erase(vec);
                if (using_length != the_ask) {
                    vec.clear();
                    vec.push_back(using_length - the_ask);
                    vec.push_back(using_start + the_ask);
                    space_length.insert(vec);
                    vec.clear();
                    vec.push_back(using_start + the_ask);
                    vec.push_back(using_length - the_ask);
                    space_start.insert(vec);
                }
            }
        }
        else {
            if (ask_info.find(-1 * the_ask - 1) != ask_info.end()) {
                vec.clear();
                vec = ask_info[-1 * the_ask - 1];
                new_start = vec[0];
                new_len = vec[1];
                if (space_start.size() != 0) {
                    new_one.clear();
                    new_one.push_back(new_start);
                    new_one.push_back(new_len);
                    if (space_start.lower_bound(new_one) == space_start.end() || space_start.size() < 2) {
                        post_vec = *(--space_start.end());
                        cout<< post_vec[0]<< " "<<post_vec[1]<< endl;
                        prev_vec = *(--space_start.end());
                    }
                    else {
                            cout<< "2..";
                        post_vec = *space_start.lower_bound(new_one);
                        if (post_vec != *space_start.begin())
                            prev_vec = *(--space_start.lower_bound(new_one));
                        else
                            prev_vec = post_vec;
                    }
                    if (vec[0] + vec[1] == post_vec[0]) {
                        new_len += post_vec[1];
                        del.clear();
                        del.push_back(post_vec[1]);
                        del.push_back(post_vec[0]);
                        space_length.erase(del);
                        space_start.erase(post_vec);
                    }
                    if (prev_vec[0] + prev_vec[1] == vec[0]) {
                        new_len += prev_vec[1];
                        new_start = prev_vec[0];
                        del.clear();
                        del.push_back(prev_vec[1]);
                        del.push_back(prev_vec[0]);
                        space_length.erase(del);
                        space_start.erase(prev_vec);
                    }
                }
                new_one.clear();
                new_one.push_back(new_len);
                new_one.push_back(new_start);
                space_length.insert(new_one);
                new_one.clear();
                new_one.push_back(new_start);
                new_one.push_back(new_len);
                space_start.insert(new_one);
                ask_info.erase(-1 * the_ask - 1);
            }
        }
    }

    return 0;
}
