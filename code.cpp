//COMSC210 | Lab 30 | Eric-Giulio Hedes
//Include necessary headers for file handling, structures, and more
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <map>
#include <list>
#include <chrono>
using namespace std;

//Include global constants
const int SZ_SKILLS = 50;

//Define the main function
int main()
{
    //Initialize a map to store all of the skill information containing lists of skills
    map<string, list<int>> personSkill;
    string skills[SZ_SKILLS];
    //Define the fstream variable that opens up a file & open up the file to read data about skills
    fstream file("skills.txt");
    //If file does not exist, print a message and exit
    if (!file.good())
        cout << "ERROR: skills.txt doesn't exist!" << endl;
    else //Otherwise read data and add up the variables inside the map itself
    {
        int i = 0;
        while (file >> skills[i++]);
        //Close the file
        file.close();
    }

    //Begin a time-based simulation for building up skills
        //By using a for loop, go through 25 time intervals
            //Randomly decide if the person either builds up or doing mistakes on the skill
                //Increase skill value if building up, decrease if doing mistakes
            //Print the changes a la "<person name>'s skill: <hobby> - points increased/decreased"

    //Wait/pause to simulate the passage of time intervals

    //Return 0
    return 0;
}
//End of main function

//Define a function to simulate the changes of 
    //Declare the parameters: map of skills