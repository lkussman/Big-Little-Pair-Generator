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
private:
    unordered_map<string, vector<string>> Bigs;
    unordered_map<string, vector<string>> Littles;
    vector<pair<string, string>> duos;
};
