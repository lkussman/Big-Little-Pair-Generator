//
//  Pairs.hpp
//  BigLittlePairing
//
//  Created by Lily Kussman on 7/10/23.
//

#ifndef Pairs_hpp
#define Pairs_hpp
#include <iostream>
#include <vector>
#include <stdio.h>
#include <vector>
#include <getopt.h>
#include <cstdint>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;
#include <stdio.h>
#endif /* Pairs_hpp */

class Pairs {
public:
    void read_in();
    void first_pairs();
    void second_pairs();
    void third_pairs();
    void fourth_pairs();
    void fifth_pairs();
    void sixth_pairs();
    void seventh_pairs();
    void eighth_pairs();
    void random_pairs();
    void write_out();
private:
    unordered_map<string, vector<string>> Bigs;
    unordered_map<string, vector<string>> Littles;
    vector<vector<string>> duos;
};
