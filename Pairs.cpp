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
    fin.open("Test1Littles.txt");
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
    

    fin.open("Test1.txt");
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
    
    cout << "hi"; 
}
