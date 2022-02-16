#include <iostream>
#include <queue>
#include <deque>
#include <map>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int n, k, p;
    int car;
    cin >> n >> k>> p;
    vector<int> traffic_jam;
    //deque<int> pos;
    vector <deque<int> > cars_positions;
    cars_positions.resize(n+1);
    for(int i = 0; i < p; i++)
    {
        cin >> car;
        //pos.clear();
        traffic_jam.push_back(car);
        cars_positions[car].push_back(i);
        /*if(cars_positions.find(car) == cars_positions.end())
        {
            pos.push_back(i);
            cars_positions[car] = pos;
        }
        else{
            cars_positions[car].push_back(i);
        }*/
    }
    set<int> bad_set;
    set<int> now_cars;
    int car_pos;
    int now_car;
    int ans = 0;
    int i = 0;
    //cout << endl;
    while(i < p && now_cars.size()<k){
        //cout<< "now_cars = "<< now_cars.size()<< endl;
        now_car = traffic_jam[i];
        if(now_cars.count(now_car))
            bad_set.erase(i);
        else{
            now_cars.insert(now_car);
            ans++;
            //cout << i << endl;
        }
        cars_positions[now_car].pop_front();
        if(cars_positions[now_car].size() == 0){
            bad_set.insert(i);
          //  cout << "finish "<< now_car<< endl;
        }
        else
            bad_set.insert(cars_positions[now_car].front());
        //cout << now_car <<":"<<cars_positions.at(now_car).front();
        i++;
    }
   // cout << endl;
   // cout << "The next step:"<< endl;
    int delete_car_pos;
    int new_car;
    int del_car;
    set<int>::iterator it;
    for(int j = i; j < p; j++){
        new_car = traffic_jam[j];
        /*
        cout<< "\nNOW:"<< j<<endl<<"it's bad set: "<< endl;
        it = bad_set.begin();
        cout<< *it<< " ";
        for(int q = 0; q < bad_set.size() - 1; q++){
                it++;
            cout<<*it<<" ";
        }
        cout<< endl<<"it's now_cars: "<< endl;
        it = now_cars.begin();
        cout<< *it<< " ";
        for(int q = 0; q < now_cars.size() - 1; q++){
                it++;
            cout<<*it<<" ";
        }
        //cout<< "begin = "<<*bad_set.begin()<<endl;
        for (int q = 4; q <= 4; q++){
            cout << q<< ":";
            for(int w = 0; w < cars_positions.at(q).size(); w++)
                cout << cars_positions.at(q)[w]<< " ";
            cout<< endl;
        }
        */


        if (*bad_set.begin() < j)
            delete_car_pos = *bad_set.begin();
        else{
            //cout << "from the end"<< endl;
            it = bad_set.end();
            --it;
            delete_car_pos = *it;
        }
        //cout << delete_car_pos;
        del_car = traffic_jam[delete_car_pos];
        //cout << "del = "<< del_car<<" new = "<< new_car<<endl<< "del_pos = "<< delete_car_pos<< endl;
        if(!now_cars.count(new_car))
        {
            ans++;
            //cout << j << endl;
            now_cars.erase(del_car);
            now_cars.insert(new_car);
            bad_set.erase(delete_car_pos);
        }
        else{
            bad_set.erase(cars_positions[new_car].front());
        }
        cars_positions[new_car].pop_front();
        if(cars_positions[new_car].size() == 0){
            bad_set.insert(j);
            //cout << "finish "<< new_car<< endl;
            }
        else
            bad_set.insert(cars_positions[new_car].front());
    }
    cout <<ans;
    return 0;
}

/*
3 2 6
1
2
3
2
1
3
5

5 2 8
5
5
4
4
3
5
4
3
*/
