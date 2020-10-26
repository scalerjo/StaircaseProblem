/*******************************************************************************
 * Name        : stairclimber.cpp
 * Author      : 
 * Date        : 
 * Description : Lists the number of ways to climb n stairs.
 * Pledge      :
 ******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

void extend(vector<vector<int>> &v1, const vector<vector<int>> &v2) {
    v1.reserve(v1.size() + v2.size());
    v1.insert(end(v1), begin(v2), end(v2));
}

vector< vector<int> > get_ways(int num_stairs) {

    vector<vector<int>> ways;

    if (num_stairs <= 0){
        vector<int> empty;
        ways.push_back(empty);
    }
    else {
        for (int i = 1; i < 4; i++){
            if (num_stairs >= i){
                vector<vector<int>> result = get_ways(num_stairs-i);
                for (unsigned int j = 0; j < result.size(); j++){
                    auto pos = result[j].begin() + 0;
                    result[j].insert(pos, i);
                }
                extend(ways, result);
            }
        }
    }
    return ways;




}

int num_digits(const int n1){
    int n = n1;
    int counter = 0;
    while (n > 0) { 
        n = n / 10; 
        counter++;
    }
    return counter;
}
void display_ways(const vector< vector<int> > &ways) {
    // TODO: Display the ways to climb stairs by iterating over
    // the vector of vectors and printing each combination.
    int largest = num_digits(ways.size());
    for (unsigned int i = 0; i < ways.size(); i++){
        int current = num_digits(i+1);
        for (int i = current; i < largest; i++){
            cout << " ";
        }
        cout << i+1 << ". " << "[";
        for (unsigned int j = 0; j < ways[i].size()-1; j++){
            cout << ways[i][j] << ", ";
        }
        cout << ways[i][ways[i].size()-1] << "]" << endl;
    }
}
bool digits(const string &s) {

    for (unsigned int i = 0; i < s.length(); i++){
        if (!isdigit(s[i])){
            return false;
        }
    }
    return true;
}

int main(int argc, char * const argv[]) {
    if (argc != 2){
        cerr << "Usage: ./stairclimber <number of stairs>" << endl;
        return 1;
    }
    else if (!digits(argv[1])){
        cerr << "Error: Number of stairs must be a positive integer." << endl;

    }
    else if (stoi(argv[1]) < 0){
        cerr << "Error: Number of stairs must be a positive integer." << endl;
    }
    else {
        vector<vector<int>> ways = get_ways(stoi(argv[1]));

        if (ways.size() == 1){
            cout << ways.size() << " way to climb " << argv[1] << " stair." << endl;
        }
        else {
            cout << ways.size() << " ways to climb " << argv[1] << " stairs." << endl;
        }
        display_ways(ways);
    }
}
