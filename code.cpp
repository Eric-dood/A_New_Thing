//COMSC210 | Lab 31 | Eric-Giulio Hedes
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
const int SZ_SKILLS = 50, LISTSIZE = 10, MAXDAYS = 50;
const int WIDTH = 10;

//Include function prototypes
int selectDay();
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
    //Initialize the days variable
    int days = 0;
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

    //Ask the user how many days it should have
    
    //Begin a time-based simulation for building up skills
    //By using a for loop, go through 25 time intervals
    for (int i = 0; i < days; i++)
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

    //Return 0
    return 0;
}
//End of main function

//Define selectDay()
int selectDay() {
    //Define a temporary variable used for returning
    int temp;
    //Prompt the user to pick a day
    cout << "Select how many days should the skills change over time (Max " << MAXDAYS << "): " << endl;
    cout << "Choice --> ";
    cin >> temp;
    //Validation loop; a number picked beyond the limits is asked to try again
    while (temp < 1 || temp > MAXDAYS)
    {
        cout << "ERROR: Select a value between 1 and " << MAXDAYS << endl;
        cout << "Choice --> ";
        cin >> temp;
    }
    //If successful, return the value
    return temp;
}

//Define modifyHobby()
void modifyHobby(map<string, list<double>> &m, int choice) {
    //Increase skill value if building up, decrease if doing mistakes
    for (map<string, list<double>>::iterator it = m.begin(); it != m.end(); ++it) {
        for (auto &skillNum : it->second) {
            //Decrease or increase skill num; check if it's higher than 1
            if (skillNum > 1) skillNum += ((!choice) ? -1 : 1);
        }
    }
}

//Define printHobbies()
void printHobbies(map<string, list<double>> m)
{
    //Set the decimal precision to 1
    cout << fixed << setprecision(1);
    //Print the table elements
    cout << left << setw(WIDTH+5) << "Skill" << "|" << right << setw(WIDTH) << "Passion" << setw(WIDTH) << "Effort" << setw(WIDTH) << "Enjoyment" << endl;
    //Then by using a ranged loop, print out the elements & the skills themselves
    for (map<string, list<double>>::iterator it = m.begin(); it != m.end(); ++it)
    {
        cout << left << setw(WIDTH+5) << it->first << "|";
        for (auto skillNum : it->second)
            cout << right << setw(WIDTH) << skillNum;
        //Leave space
        cout << endl;
    }
}