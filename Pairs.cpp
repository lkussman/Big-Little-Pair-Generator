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
    //ADD ERROR READING
//    cout << "Enter your file name for the littles: " << '\n';
//    cin >> file;
    
    //open the file
    fin.open("Test1Littles");
  //  fin.open(file);
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
    //ADD ERROR READING
 //    cout << "Enter your file name for the big: " << '\n';
   //  cin >> file;
    

    fin.open("Test1");
  //  fin.open(file);
    
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
    second_pairs();
    third_pairs();
   
    
    cout << "hi"; 
}

void Pairs::first_pairs() {
    
    auto iter = Littles.begin();
    
    while (iter != Littles.end()) {
        
        string first_pick = iter->second[0];
        string other_pick = Bigs[first_pick][0];
    
        if (iter->first == other_pick) {
            
            pair<string, string> pairing;
            
            pairing.first = first_pick;
            pairing.second = Bigs[first_pick][0];
            
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

void Pairs::second_pairs() {
    
    // loop through the Bigs and if their first choice has put them either second or third then pair
    
    auto iter = Bigs.begin();
    
    while (iter != Bigs.end()) {
        
        
        string first_pick = iter->second[0];
        
        if (Littles.find(first_pick) == Littles.end()) {
            ++iter;
           
        }
        else {
            
            string other_pick = Littles[first_pick][1];
            string other_pick2 = Littles[first_pick][2];
            
        
            if (iter->first == other_pick) {
                
                pair<string, string> pairing;
                
                pairing.first = first_pick;
                pairing.second = other_pick;
                
                duos.push_back(pairing);
                
                auto temp = iter->first;
                iter++;
                
                Bigs.erase(temp);
                Littles.erase(first_pick);
                
            }
            else if (iter->first == other_pick2) {
                
                
                pair<string, string> pairing;
                
                pairing.first = first_pick;
                pairing.second = other_pick2;
                
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
                
                pair<string, string> pairing;
                
                pairing.first = first_pick;
                pairing.second = other_pick;
                
                duos.push_back(pairing);
                
                auto temp = iter->first;
                iter++;
                
                Littles.erase(temp);
                Bigs.erase(first_pick);
                
            }
            else if (iter->first == other_pick2) {
                
                
                pair<string, string> pairing;
                
                pairing.first = first_pick;
                pairing.second = other_pick2;
                
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


