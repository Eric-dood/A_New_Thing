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
using namespace std::chrono;

//Include global constants
const int SZ_SKILLS = 50, LISTSIZE = 10, DAYS = 25;

//Include function prototypes
void modifyHobby(map<string, list<double>> &m, int choice);
void printHobbies(map<string, list<double>> m);

//Define the main function
int main()
{
    //Random seed generator
    srand(time(0));

    //Initialize a map to store all of the skill information containing lists of skills
    map<string, list<double>> personSkill;
    string skills[SZ_SKILLS];
    //Define the fstream variable that opens up files to read data about skills
    fstream file("skills.txt"), file2("names.txt");
    //If the skill file does not exist, print a message and exit
    if (!file.good())
        cout << "ERROR: skills.txt doesn't exist!" << endl;
    else //Otherwise read data and add up the variables inside the array itself
    {
        int i = 0;
        while (file >> skills[i++]);
        //Close the file
        file.close();
    }

    //Begin filling up some of the skills
    for (int i = 0; i < LISTSIZE; i++) {
        personSkill[skills[rand() % SZ_SKILLS]] =
        {
            double(rand() % 1000) / 10,
            double(rand() % 1000) / 10,
            double(rand() % 1000) / 10,
        };
    }

    //Begin a time-based simulation for building up skills
    //By using a for loop, go through 25 time intervals
    for (int i = 0; i < DAYS; i++)
    {
        cout << "DAY " << i + 1 << endl << "--------------------------------" << endl;
        auto start = high_resolution_clock::now();
        //Randomly decide if the person either builds up or doing mistakes on the skill
        int change = rand() % 2;
        //Call modifyHobby()
        modifyHobby(personSkill, change);
        //Print the changes a la "<person name>'s skill: <hobby> - points increased/decreased"
        printHobbies(personSkill);
        auto stop = high_resolution_clock::now();
        auto dur = duration_cast<nanoseconds>(stop - start);
        cout << "--------------------------------" << endl << "Time passed: " << dur.count() << " nanoseconds" << endl << endl;
    }

    //Wait/pause to simulate the passage of time intervals

    //Return 0
    return 0;
}
//End of main function

//Define modifyHobby()
void modifyHobby(map<string, list<double>> &m, int choice) {
    //Increase skill value if building up, decrease if doing mistakes
    //m.for_each()
}

//Define printHobbies()
void printHobbies(map<string, list<double>> m)
{
    cout << "Skill" << setw(5) << "|" << setw(10) << "Passion" << setw(10) << "Effort" << setw(10) << "Enjoyment" << endl;
    for (map<string, list<double>>::iterator it = m.begin(); it != m.end(); ++it)
    {
        cout << it->first << " | ";
        for (auto skillNum : it->second)
            cout << skillNum << " ";
        cout << endl;
    }
}