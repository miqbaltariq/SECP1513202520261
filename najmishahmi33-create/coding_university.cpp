
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void getInput(string [], int [], int [], int [], int);
long calTotal(int [], int);
int getLowest(int [], int);
int getHighest(int[] , int);

int main()
{
    //declaring all involved arrays
    int SIZE=20;
    string name[SIZE];
    int intake[SIZE];
    int enrolment[SIZE];
    int output[SIZE];

    //Task 5
    getInput(name,intake,enrolment,output,SIZE);

    //Task 6
    // calculate total for each categories
    int total_intake = calTotal(intake,SIZE);
    int total_enrolment = calTotal(enrolment,SIZE);
    int total_output = calTotal(output,SIZE);
    
    // calculate average for each categories
    double average_intake = static_cast<double>(total_intake)/SIZE;
    double average_enrolment = static_cast<double>(total_enrolment)/SIZE;
    double average_output = static_cast<double>(total_output)/SIZE;

    //Task 7
    // find university with highest intake
    int highIndex_intake = getHighest(intake,SIZE);
    int high_intake = intake[highIndex_intake];
    string highIntake_name = name[highIndex_intake];
    
    // find university with highest enrolment
    int highIndex_enrolment = getHighest(enrolment,SIZE);
    int high_enrolment = enrolment[highIndex_enrolment];
    string highEnrolment_name = name[highIndex_enrolment];
    
    // find university with highest output
    int highIndex_output = getHighest(output,SIZE);
    int high_output = output[highIndex_output];
    string highOutput_name = name[highIndex_output];
    
    // find university with lowest intake
    int lowIndex_intake = getLowest(intake,SIZE);
    int low_intake = intake[lowIndex_intake];
    string lowIntake_name = name[lowIndex_intake];
    
    // find university with lowest enrolment
    int lowIndex_enrolment = getLowest(enrolment,SIZE);
    int low_enrolment = enrolment[lowIndex_enrolment];
    string lowEnrolment_name = name[lowIndex_enrolment];
    
    // find university with lowest output
    int lowIndex_output = getLowest(output,SIZE);
    int low_output = output[lowIndex_output];
    string lowOutput_name = name[lowIndex_output];

    // find range of number for each categories
    int range_intake = high_intake - low_intake;
    int range_enrolment = high_enrolment - low_enrolment;
    int range_output = high_output - low_output;

    //Task 5
    //create object named outFile and open file named "output.txt"
    ofstream outFile;
    outFile.open("output.txt");

    // formatting output
    outFile << "          NUMBER OF STUDENTS' INTAKE, ENROLMENT AND OUTPUT" << endl;
    outFile << "                   IN PUBLIC UNIVERSITIES (2015)" << endl << endl;
    outFile << "--------------------------------------------------------------------" << endl;
    outFile << right << setw(12) << "UNIVERSITY" ;
    outFile << setw(22) << "INTAKE" ;
    outFile << setw(17) << "ENROLMENT" ;
    outFile << setw(13) << "OUTPUT" << endl;
    outFile << "--------------------------------------------------------------------" << endl;

    // print all the input informations
    for( int i=0; i<SIZE; i++)
    {
        outFile << "    " << left << setw(15) << name[i] << right << setw(15) << intake[i] ;
        outFile << setw(15) << enrolment[i] << setw(15) << output[i] << endl;
    }

    outFile << "--------------------------------------------------------------------" << endl;
    
    // print total
    outFile << "    " << left << setw(15) << "TOTAL" << fixed << setprecision(2) << right 
    << setw(15) << total_intake << setw(15) << total_enrolment << setw(15) << total_output << endl;
    
    // print average
    outFile << "    " << left << setw(15) << "AVERAGE" << fixed << setprecision(2) << right 
    << setw(15) << average_intake << setw(15) << average_enrolment << setw(15) << average_output << endl;
    
    outFile << "--------------------------------------------------------------------" << endl << endl;

    // print lowest value of each categories 
    outFile << left << setw(43) << "THE LOWEST NUMBER OF STIDENTS' INTAKE" << "= " << low_intake 
    << " (" << lowIntake_name << ")" << endl;
    outFile << left << setw(43) << "THE LOWEST NUMBER OF STIDENTS' ENROLMENT" << "= " << low_enrolment 
    << " (" << lowEnrolment_name << ")" << endl;
    outFile << left << setw(43) << "THE LOWEST NUMBER OF STIDENTS' OUTPUT" << "= " << low_output 
    << " (" << lowOutput_name << ")" << endl << endl;
    
    // print highest value of each categories
    outFile << left << setw(43) << "THE HIGHEST NUMBER OF STUDENTS' INTAKE" << "= " << high_intake
    << " (" << highIntake_name << ")" << endl;
    outFile << left << setw(43) << "THE HIGHEST NUMBER OF STUDENTS' ENROLMENT" << "= " << high_enrolment
    << " (" << highEnrolment_name << ")" << endl;
    outFile << left << setw(43) << "THE HIGHEST NUMBER OF STUDENTS' OUTPUT" << "= " << high_output
    << " (" << highOutput_name << ")" << endl << endl;

    //print range for each categories
    outFile << left << setw(43) << "THE RANGE OF NUMBER OF STUDENTS' INTAKE" << "= " << range_intake << endl;
    outFile << left << setw(43) << "THE RANGE OF NUMBER OF STUDENTS' ENROLMENT" << "= " << range_enrolment << endl;
    outFile << left << setw(43) << "THE RANGE OF NUMBER OF STUDENTS' OUTPUT" << "= " << range_output << endl;
}

//Task 1
void getInput(string name[], int intake[], int enrolment[], int output[], int SIZE)
{
    ifstream inFile;
    inFile.open("input.txt");

    if(!inFile)
    {
        cout << "Input file could not be opened! Terminating!" << endl;
        return ;
    }

    for( int i=0; i<SIZE; i++)
    {
        inFile >> name[i] >> intake[i] >> enrolment[i] >> output[i]; 
    }
    inFile.close();
    return;
}

//Task 2
long calTotal(int data[], int SIZE)
{
    long total=0;
    for( int i=0; i<SIZE; i++)
    {
        total+= data[i];
    }
    return total;
}

//Task 3
int getLowest(int data[], int SIZE )
{
    int lowIndex=0;
    for (int i=1; i<SIZE; i++)
    {
        if(data[i]<data[lowIndex])
        {
            lowIndex=i;
        }
    }
    return lowIndex;
}

//Task 4
int getHighest(int data[], int SIZE)
{
    int highIndex=0;
    for (int i=1; i<SIZE; i++)
    {
        if(data[i]>data[highIndex])
        {
            highIndex=i;
        }
    }
    return highIndex;
}


