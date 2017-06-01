//
//  main.cpp
//  cs130a pa1
//
//  Created by James wang on 4/26/17.
//  Copyright © 2017 James wang. All rights reserved.
//

#include <iostream>
#include "prog1.hpp"

using namespace std;

int main() {
    
        string command;
        string wholeLine;
        string toInt;
        int value;
        
        // read first line (int)
        int size;
        cin >> size;
        TableHeap test;
        // read second line(int)
        int times;
        cin >> times;
        // for loop
        cin.ignore();
        for (int i = 0; i < times; i++) {
            getline(cin, wholeLine);
            //      cout << "The command is: " << wholeLine <<  endl;
            
            if (wholeLine.compare(0,6,"insert") == 0) {
                toInt = wholeLine.substr(7,wholeLine.length()-1);
                value = stoi(toInt);
                test.insert_hash(value);
            }
            if ((wholeLine.compare(0,6,"delete") == 0) && (wholeLine.compare(0,9,"deleteMax") != 0)) {
                toInt = wholeLine.substr(7,wholeLine.length()-1);
                value = stoi(toInt);
                test.delete_num_hash(value);
            }
            if (wholeLine.compare(0,9,"deleteMax") == 0) {
                test.matchmax();
               
            }
            if (wholeLine.compare(0,6,"lookup") == 0) {
                toInt = wholeLine.substr(7,wholeLine.length()-1);
                value = stoi(toInt);
                test.lookup_hash(value);
            }
            if (wholeLine.compare(0,5,"print") == 0) {
                test.print_all();
            }
        }
    
    return 0;
  

    
}

