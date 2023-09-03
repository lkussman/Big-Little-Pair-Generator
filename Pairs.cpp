//
//  Pairs.cpp
//  BigLittlePairing
//
//  Created by Lily Kussman on 7/10/23.
//

#include "Pairs.hpp"


void Pairs::read_in() {
    ifstream fin;
    string file;
    
    //User write in file name
    cout << "Enter your file name for the littles: " << '\n';
    cin >> file;
    
    //open the file
    fin.open(file);
    string little_prefs;
    vector<string> prefs;
    
    //read in the data from our littles file into the map
    while (getline(fin, little_prefs)) {
        string my_little = little_prefs;
        string pref = " ";
        prefs.resize(5);
        for (int i = 0; i < 5; i++) {
            getline(fin, pref);
            prefs[i] = pref;
        }
        Littles[my_little] = prefs;
    }
    
    fin.close();
    
    //User write in file name
    cout << "Enter your file name for the big: " << '\n';
    cin >> file;
    

    fin.open(file);
    
    //read in the data from our big file into the map
    while (getline(fin, little_prefs)) {
        string my_bigs = little_prefs;
        string pref = " ";
        prefs.resize(5);
        for (int i = 0; i < 5; i++) {
            getline(fin, pref);
            prefs[i] = pref;
        }
        Bigs[my_bigs] = prefs;
    }
    
    // pair up all the people who put each other first
    first_pairs();
    //pair up people who wanted each other as second or third choices
    second_pairs();
    third_pairs();
    //pair up people who have each other as their second choice
    fourth_pairs();
   //pair up when the big as 2 and the little as 3
    fifth_pairs();
    //pair up when the little has 2 and the big has 3
    sixth_pairs();
    //pair up when they are 3 and 3
    seventh_pairs();
    //anyone who is on each others list
    eighth_pairs();
    //pair the leftovers
    random_pairs();
    //write the pairs out to a new file
    write_out();
}

void Pairs::first_pairs() {
    
    auto iter = Littles.begin();
    
    //loop through the littles
    while (iter != Littles.end()) {
        //find the littles first pick and who the corresponding Big put in as their first pick
        string first_pick = iter->second[0];
        
        //check if the first pic is deleted
        if (Bigs.find(first_pick) == Bigs.end()) {
            iter++;
        }
        
        else {
            string other_pick = Bigs[first_pick][0];
            
            //if they chose each other, make them a pair and remove them both from their maps
            if (iter->first == other_pick) {
                //big and little pairing
                vector<string> pairing;
                pairing.resize(2);
                
                pairing[0] = first_pick;
                pairing[1] = Bigs[first_pick][0];
                
                duos.push_back(pairing);
                
                auto temp = iter->first;
                iter++;
                
                Littles.erase(temp);
                Bigs.erase(first_pick);
                
            }
            else {
                iter++;
            }
        }
    }
}

void Pairs::second_pairs() {
    
    auto iter = Bigs.begin();
    //loop through all the bigs
    while (iter != Bigs.end()) {
        
        string first_pick = iter->second[0];
        
        if (Littles.find(first_pick) == Littles.end()) {
            ++iter;
           
        }
        else {
            
            string other_pick = Littles[first_pick][1];
            string other_pick2 = Littles[first_pick][2];
            
        
            if (iter->first == other_pick) {
                
                vector<string> pairing;
                pairing.resize(2);
                
                pairing[0] = other_pick;
                pairing[1] = first_pick;
                
                duos.push_back(pairing);
                
                auto temp = iter->first;
                iter++;
                
                Bigs.erase(temp);
                Littles.erase(first_pick);
                
            }
            else if (iter->first == other_pick2) {
                
                
                vector <string> pairing;
                pairing.resize(2);
                
                pairing[0] = first_pick;
                pairing[1] = other_pick2;
                
                duos.push_back(pairing);
                
                auto temp = iter->first;
                iter++;
                
                Bigs.erase(temp);
                Littles.erase(first_pick);
            
            }
            else {
                iter++;
            }
        }
    }
}

void Pairs::third_pairs() {
    
    auto iter = Littles.begin();
    
    while (iter != Littles.end()) {
    
        string first_pick = iter->second[0];
        
        
        if (Bigs.find(first_pick) == Bigs.end()) {
            ++iter;
            
        }
        else {
        
            string other_pick = Bigs[first_pick][1];
            string other_pick2 = Bigs[first_pick][2];
            
        
            if (iter->first == other_pick) {
                
                vector<string> pairing;
                pairing.resize(2);
                
                pairing[0] = first_pick;
                pairing[1] = other_pick;
                
                duos.push_back(pairing);
                
                auto temp = iter->first;
                iter++;
                
                Littles.erase(temp);
                Bigs.erase(first_pick);
                
            }
            else if (iter->first == other_pick2) {
                
                
                vector<string> pairing;
                pairing.resize(2);
                
                pairing[0] = first_pick;
                pairing[1] = other_pick2;
                
                duos.push_back(pairing);
                
                auto temp = iter->first;
                iter++;
                
                Littles.erase(temp);
                Bigs.erase(first_pick);
            
            }
            else {
                iter++;
            }
        }
    }
}

void Pairs::fourth_pairs() {
    auto iter = Littles.begin();
    
    //loop through the littles
    while (iter != Littles.end()) {
        //find the littles second pick and who the corresponding Big put in as their second pick
        string second_pick = iter->second[1];
        
        //check if the first pic is deleted
        if (Bigs.find(second_pick) == Bigs.end()) {
            iter++;
        }
        
        else {
            string other_pick = Bigs[second_pick][1];
            
            //if they chose each other, make them a pair and remove them both from their maps
            if (iter->first == other_pick) {
                //big and little pairing
                vector<string> pairing;
                pairing.resize(2);
                
                pairing[0] = second_pick;
                pairing[1] = Bigs[second_pick][1];
                
                duos.push_back(pairing);
                
                auto temp = iter->first;
                iter++;
                
                Littles.erase(temp);
                Bigs.erase(second_pick);
                
            }
            else {
                iter++;
            }
        }
    }
}

void Pairs::fifth_pairs() {
    auto iter = Bigs.begin();
    //loop through all the bigs
    //bigs second choice littles third
    while (iter != Bigs.end()) {
        
        string first_pick = iter->second[1];
        
        if (Littles.find(first_pick) == Littles.end()) {
            ++iter;
           
        }
        else {
            
            string other_pick = Littles[first_pick][2];
        
            if (iter->first == other_pick) {
                
                vector<string> pairing;
                pairing.resize(2);
                
                pairing[0] = other_pick;
                pairing[1] = first_pick;
                
                duos.push_back(pairing);
                
                auto temp = iter->first;
                iter++;
                
                Bigs.erase(temp);
                Littles.erase(first_pick);
                
            }
            else {
                iter++;
            }
        }
    }
}

void Pairs::sixth_pairs() {
    auto iter = Littles.begin();
    //loop through all the bigs
    while (iter != Littles.end()) {
        
        string first_pick = iter->second[1];
        
        if (Bigs.find(first_pick) == Bigs.end()) {
            ++iter;
           
        }
        else {
            
            string other_pick = Bigs[first_pick][2];
        
            if (iter->first == other_pick) {
                
                 vector<string> pairing;
                pairing.resize(2);
                
                pairing[0] = first_pick;
                pairing[1] = other_pick;
                
                duos.push_back(pairing);
                
                auto temp = iter->first;
                iter++;
                
                Littles.erase(temp);
                Bigs.erase(first_pick);
                
            }
            else {
                iter++;
            }
        }
    }
}

void Pairs::seventh_pairs() {
    //bigs third and littles third
    auto iter = Littles.begin();
    
    //loop through the littles
    while (iter != Littles.end()) {
        //find the littles second pick and who the corresponding Big put in as their second pick
        string second_pick = iter->second[2];
        
        //check if the first pic is deleted
        if (Bigs.find(second_pick) == Bigs.end()) {
            iter++;
        }
        
        else {
            string other_pick = Bigs[second_pick][2];
            
            //if they chose each other, make them a pair and remove them both from their maps
            if (iter->first == other_pick) {
                //big and little pairing
               vector<string> pairing;
                pairing.resize(2);
                
                pairing[0] = second_pick;
                pairing[1] = Bigs[second_pick][2];
                
                duos.push_back(pairing);
                
                auto temp = iter->first;
                iter++;
                
                Littles.erase(temp);
                Bigs.erase(second_pick);
                
            }
            else {
                iter++;
            }
        }
    }
}
void Pairs::eighth_pairs() {
    //if anyone is on each others lists, pair them
    auto iter = Bigs.begin();
    
    string pick;
    while(iter != Bigs.end()) {
        for (int i = 0; i < 5; i++) {
            pick = iter->second[i];
            if (Littles.find(pick) == Littles.end()) {
                continue;
            }
            else {
                bool is_pick = false;
                for (int j = 0; j < 5; j++) {
                    if (Littles[pick][j] == iter->first) {
                        vector<string> pairing;
                        pairing.resize(2);
                        
                        pairing[0] = iter->first;
                        pairing[1] = pick;
                        
                        duos.push_back(pairing);
                        
                        auto temp = iter->first;
                        iter++;
                        
                        Bigs.erase(temp);
                        Littles.erase(pick);
                        is_pick = true;
                        break;
                    }
                }
            }
        }
        iter++;
    }
    duos.size();
}

void Pairs::random_pairs() {
    while (!Bigs.empty() && !Littles.empty()) {
        vector<string> pairing;
        pairing.resize(2);
        
        pairing[0] = Bigs.begin()->first;
        pairing[1] = Littles.begin()->first;
        
        duos.push_back(pairing);
        
        Bigs.erase(Bigs.begin()->first);
        Littles.erase(Littles.begin()->first);
    }
    //there are more bigs than littles, add to a family
    int count = 1;
    while (!Bigs.empty()) {
        duos[duos.size() - count].push_back(Bigs.begin()->first);
        Bigs.erase(Bigs.begin()->first);
        count++;
    }
    //if there are more littles than bigs, add to a family
    while (!Littles.empty()) {
        duos[duos.size() - count].push_back(Littles.begin()->first);
        Littles.erase(Littles.begin()->first);
        count++;
    }
}

void Pairs::write_out() {
    ofstream fout;
    string file;
    //User write in file name
    cout << "Enter your file name for the littles: " << '\n';
    cin >> file;
    
    //open the file
    fout.open(file);
    for (int i = 0; i < duos.size(); i++) {
        for (int j = 0; j < duos[i].size(); j++) {
            fout << duos[i][j] << " ";
        }
        fout << '\n';
    }
}
