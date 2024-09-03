#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<vector<int>> dis = {{0,1,2,3},{1,0,2,3},{1,2,0,3},{1,2,3,0}};
    vector<int> cities = {0,1,2,3};

    int min_path = INT8_MAX;

    do{
        int k = 0;
        int curr_path = 0;

        for(int i=0;i<cities.size();i++){
            curr_path += dis[k][cities[i]];
            k = cities[i];
        }

        curr_path += dis[k][0];
        min_path = min(curr_path,min_path);
    }while(next_permutation(cities.begin(),cities.end()));

    cout << min_path;
}