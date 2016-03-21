//
//  main.cpp
//  Duplicate Word Counter
//
//  Created by Mario Acchione on 2016-03-09.
//  Copyright © 2016 Mario Acchione. All rights reserved.
//

#include <iostream>
#include <string>
#include "runThroughFile.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    //declared variables
    static string fileName;
    static int total;
    
    // intro splash page with file input
    cout << "Welcome To The Duplicate Word Counter\n" << "Please enter your file name: ";
    cin >> fileName;
    cout << "Looking for duplicate words in " + fileName + "\n\n";
    cout << "Enter numbet of courses: ";
    string courseNumInput;
    cin >> courseNumInput;
    total = stoi(courseNumInput);
    cout << "Total number of courses " << total <<"\n";
    //run throught the file and sort
    runThroughFile(fileName, total);
    cout << "\nThank you for using the Duplicate Word Counter!\n";
    return 0;
}
