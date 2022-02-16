#include <iostream>
#include <set>


using namespace std;

int main()
{
    int m, n, k;
    cin >> m >> n>> k;
    int result = 1;
    if(min(m, n) > 1)
        result = m+n;
    if(k == 0){
        cout << result;
        return 0;
    }
    int point_i, point_j;
    set<int > i_list [m];//заполненные, клеточки
    set<int > j_list [n];//заполненные
    bool prev_i, prev_j, post_i, post_j, prev_prev_i, post_post_i, prev_prev_j, post_post_j;
    bool prev_i_post_j, post_i_prev_j, prev_i_prev_j, post_i_post_j;
    for(int i = 0; i < k; i++){
        cin >> point_i >> point_j;
        point_i--;
        point_j--;
        //cout << "point j" << point_j-1<< " n = "<< n<< endl;
        if(point_j-1 < 0 || i_list[point_i].find(point_j-1) != i_list[point_i].end())
            prev_j = false;
        else
            prev_j = true;
        if(point_j + 1 >= n || i_list[point_i].find(point_j+1) != i_list[point_i].end())
            post_j = false;
        else
            post_j = true;
        if(point_j-2 < 0 || i_list[point_i].find(point_j-2) != i_list[point_i].end())
            prev_prev_j = false;
        else
            prev_prev_j = true;
        if(point_j+2>=n || i_list[point_i].find(point_j+2) != i_list[point_i].end())
            post_post_j = false;
        else
            post_post_j = true;

        if(point_i-1 < 0 || j_list[point_j].find(point_i-1) != j_list[point_j].end())
            prev_i = false;
        else
            prev_i = true;
        if(point_i+1 >=m || j_list[point_j].find(point_i+1) != j_list[point_j].end())
            post_i = false;
        else
            post_i = true;
         if(point_i-2 < 0 || j_list[point_j].find(point_i-2) != j_list[point_j].end())
            prev_prev_i = false;
        else
            prev_prev_i = true;
        if(point_i + 2 >= m ||j_list[point_j].find(point_i+2) != j_list[point_j].end())
            post_post_i = false;
        else
            post_post_i = true;

        if(point_i + 1 >= m || point_j+1 >= n || j_list[point_j+1].find(point_i+1) != j_list[point_j+1].end())
            post_i_post_j = false;
        else
            post_i_post_j = true;
        if(point_i - 1 < 0 || point_j+1 >= n || j_list[point_j+1].find(point_i-1) != j_list[point_j+1].end())
            prev_i_post_j = false;
        else
            prev_i_post_j = true;

        if(point_i - 1 < 0 || point_j - 1< 0 || j_list[point_j-1].find(point_i-1) != j_list[point_j-1].end())
            prev_i_prev_j = false;
        else
            prev_i_prev_j = true;
//cout << "..0"<< endl;
        if(point_i + 1 >= m || point_j-1 < 0 || j_list[point_j-1].find(point_i+1) != j_list[point_j-1].end())
            post_i_prev_j = false;
        else
            post_i_prev_j = true;
           // cout<< "..1\n";
        /*cout << prev_prev_i<< endl;
        cout<<prev_i_prev_j<< " "<< prev_i<< " "<< prev_i_post_j<< endl;
        cout<<prev_prev_j<<" "<< prev_j<< " "<< post_j << " "<< post_post_j<<endl;
        cout<<post_i_prev_j<<" "<<post_i<<" "<< post_i_post_j<< endl;
        cout << post_post_i;*/
        if(!(prev_i || prev_j || post_i || post_j)){
                //cout<< "MINUS1\n";
            result--;
        }
        if(post_i){
            result--;
            //cout<< "MINUS2\n";
            if(post_post_i || !(post_post_i||post_i_post_j||post_i_prev_j)){
                result++;
                //cout <<"PLUS1\n";
            }
            if(prev_i)
                if(prev_prev_i || !(prev_prev_i||prev_i_post_j||prev_i_prev_j)){
                        //cout <<"PLUS2\n";
                    result++;
                }
        }else if(prev_i){
            result--;
            //cout<< "MINUS3\n";
            if(prev_prev_i || !(prev_prev_i||prev_i_post_j||prev_i_prev_j)){
                    result++;
            //cout <<"PLUS3\n";
            }
        }
        if(post_j){
            result--;
            //cout<< "MINUS4\n";
            if(post_post_j || !(post_post_j||post_i_post_j||prev_i_post_j)){
                result++;
              //  cout <<"PLUS4\n";
            }
            if(prev_j)
                if(prev_prev_j || !(prev_prev_j||prev_i_prev_j||post_i_prev_j)){
                //        cout <<"PLUS5\n";
                    result++;
                }
        }else if(prev_j){
            result--;
            //cout<< "MINUS6\n";
            if(prev_prev_j || !(prev_prev_j||prev_i_prev_j||post_i_prev_j)){
              //      cout <<"PLUS6\n";
                    result++;
            }
        }
        i_list[point_i].insert(point_j);
        j_list[point_j].insert(point_i);

    }
    cout << result;
    return 0;
}
