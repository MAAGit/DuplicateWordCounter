//
//  runThroughFile.cpp
//  Duplicate Word Counter
//
//  Created by Mario Acchione on 2016-03-20.
//  Copyright © 2016 Mario Acchione. All rights reserved.
//

#include "runThroughFile.hpp"


void runThroughFile(string fileName, int numOfCourses){
    //declared variables
    ifstream myFile(fileName);
    string line;
    vector<string> clipID;
    vector<int> uses;
    int totalClips = 0;
    int totalDuplicates = 0;
    int uniqueClips = 0;
    string id;
    bool flag = false;
    //open the file and get a line of text
    if(myFile.is_open()){
        while(getline(myFile, line)){
            //cout << "line: " << line << "\n";//testing output
            //deal with the line if it is a clip id
            if(line != "" && line.substr(line.size()-4, line.size()) == ".mp4"){
                totalClips++;
                if(clipID.empty()){ //just add the first entry
                    clipID.push_back(line.substr(0, line.size()-4));
                    uses.push_back(1);
                    uniqueClips++;
                }
                else{//otherwise, check for duplicate entries and update the list with the info
                    id = line.substr(0, line.size()-4);
                    for(int i = 0; i < clipID.size(); i++){
                        if(id == clipID.at(i)){
                            totalDuplicates++;
                            uses.at(i)++;
                            flag = true;
                            break;
                        }
                    }
                    if(flag){
                        flag = false;
                        continue;
                    }
                    clipID.push_back(line.substr(0, line.size()-4));
                    uses.push_back(1);
                    uniqueClips++;
                }
            }
        }
        myFile.close();
    }
    else{
        cout << "Unable to open file";
    }
    
    //display the results
    cout << "Total Clips Used: " << totalClips << "\n";
    cout << "Total Number of Unique Clips: " << uniqueClips << "\n";
    cout << "Total Number of Duplicate Clips: " << totalDuplicates << "\n";
    cout << "Clips and their uses:\n";
    for(int i = 0; i < clipID.size(); i++){
        cout << clipID.at(i) << ": " << uses.at(i) << "\n";
    }
}