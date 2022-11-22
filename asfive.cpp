/******************************************************************* ** 
** Program: asfive.cpp
** Author: Kaushik Dontula
** Date: 05/27/2022
** Description: this program is a resume builder. Taking inputs from the user and building a proper formatted resume for them.
** Input: strings, integers, characters. All inputs as strings or c strings.
** Output: a resume included in a txt file using the last name of the user 
*******************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <fstream>

using namespace std;

//the struct to store Education Background 
struct Edu {
char univ[128]; //a c-string to store the university name
char major[64]; //a c-string to store the major
int graduate_year; //graduation year
float GPA; //GPA
//additional members go here... 
};


/******************************************************************* 
** Function: error_char
** Description: This function error handles fro the university input
** Parameters: Edu 
** Pre-conditions: input has to be from Edu struct
** Post-conditions: returns false if the university name has numbers
*******************************************************************/
bool error_char(Edu &university){
    for(int i = 0; i < strlen(university.univ); i++){
        if (university.univ[i] >= 65 && university.univ[i] <= 122){
            return true;
        }
        else {
            return false;
        }
    }

}

/******************************************************************* 
** Function: void univ
** Description: gets university input from user
** Parameters: Edu &university
** Pre-conditions: takes university input from the user
** Post-conditions: returns the updates university input to the struct
*******************************************************************/
void univ(Edu &university){
    cout << endl << "Education background..." << endl;
    cout << "Enter a institution name: ";
    cin.getline(university.univ,128);
    //cout << "Your university is: " << university.univ << endl;
    error_char(university);

    while (error_char(university) == false){
        cout << "That was an invalid university, please try again: ";
        cin.getline(university.univ,128);
        error_char(university);
    }
}

/******************************************************************* 
** Function: error_major
** Description: error handles for numbers in the major
** Parameters: Edu major
** Pre-conditions: gets the major input from the user
** Post-conditions: returns false if the user inputs numbers as the major
*******************************************************************/
bool error_major(Edu &major1){
    for(int i = 0; i < strlen(major1.major); i++){
        if (major1.major[i] >= 65 && major1.major[i] <= 122){
            return true;
        }
        else {
            return false;
        }

    }

}

/******************************************************************* 
** Function: void major
** Description: gets user input for the major
** Parameters: Edu &major
** Pre-conditions: gets the major input from the user
** Post-conditions: returns the updated major input to the Edu struct
*******************************************************************/
void major(Edu &major1){
    cout << "Enter the major or pathway: ";
    cin.getline(major1.major,64);
    //cout << "Your desired major was: " << major1.major << endl;
    error_major(major1);

    while (error_major(major1) == false){
        cout << "That was an invalid major, please try again: ";
        cin.getline(major1.major,64);
        cout << "Your desired major was: " << major1.major << endl;
        error_major(major1);
    }
}

/******************************************************************* 
** Function: booo error_graduationyear
** Description: error handles for graduation year
** Parameters: Edu &grad_year
** Pre-conditions: gets the grad year input from the user
** Post-conditions: returns false if the grad year is letters or numbers that dont make sense
*******************************************************************/
bool error_graduationyear(Edu &grad_year){
    while (!(grad_year.graduate_year >1900 && grad_year.graduate_year<2100)){
        return false;
    }
    return true;
}

/******************************************************************* 
** Function: void graduate_year
** Description: gets the grad year input from the user
** Parameters: Edu &grad_year
** Pre-conditions: Edu &grad_year
** Post-conditions: updates the grad year in the struct based off user input
*******************************************************************/
void graduate_year(Edu &grad_year){
    cout << "Enter the year you graduated: ";
    cin >> grad_year.graduate_year;
    //cout << "Your graduation year was: " << grad_year.graduate_year << endl;

    while (error_graduationyear(grad_year)== false){
        cin.clear();
        cin.ignore(123, '\n');
        cout << "That was an invalid graduation year, please try again: ";
        cin >> grad_year.graduate_year;
        //cout << "Your graduation year was: " << grad_year.graduate_year << endl;
        error_graduationyear(grad_year);
    }
}

/******************************************************************* 
** Function: bool error_GPA
** Description: error handles for GPA
** Parameters: Edu &GPA
** Pre-conditions: getting user input for GPA
** Post-conditions: returns false if GPA is letters or not within a GPA range
*******************************************************************/
bool error_GPA(Edu &GPA){
    while (!(GPA.GPA <=4 && GPA.GPA>0)){
        return false;
    }
    return true;
}

/******************************************************************* 
** Function: void GPA
** Description: gets user input for GPA
** Parameters: Edu &GPA
** Pre-conditions: gets user input for GPA
** Post-conditions: updates the Edu struct with the updates GPA from user input
*******************************************************************/
void GPA(Edu &GPA){
    cout << "Enter your GPA: ";
    cin >> GPA.GPA;
    //cout << "Your GPA is: " << GPA.GPA << endl;
    while (error_GPA(GPA)== false){
        cin.clear();
        cin.ignore(123, '\n');
        cout << "That was an invalid GPA, please try again: ";
        cin >> GPA.GPA;
        //cout << "Your GPA  was: " << GPA.GPA << endl;
        error_GPA(GPA);
    }
}
















//the struct to store the basic information 
struct Basics {
char fname[64]; 
char lname[64]; 
char email[64]; 
Edu edu;
//a c-string to store the first name
//a c-string to store the last name
//a c-string to store the email address //an Edu object to store the ed. background
//additional members go here... 
};

/******************************************************************* 
** Function: error_fname
** Description: error handles for the firstname
** Parameters: Basics &firstname
** Pre-conditions: user input for firstname
** Post-conditions: returns false if the user input for firstname is all numbers
*******************************************************************/
bool error_fname(Basics &firstname ){
    while (strlen(firstname.fname)>63){
        return false;
    }
    for(int i = 0; i < strlen(firstname.fname); i++){
        if (firstname.fname[i] >= 65 && firstname.fname[i] <= 122){
            return true;
        }
        else {
            return false;
        }
    }
}

/******************************************************************* 
** Function: void first_name
** Description: gets first name input from the user
** Parameters: Basics &firstname
** Pre-conditions: gets user input for first name
** Post-conditions: updates the Basics struct with the user inputted firstname
*******************************************************************/
void first_name (Basics &firstname ){
    cout << endl << endl << "Basic backround..." << endl;
    cout << "Enter your first name: ";

    cin.getline(firstname.fname, 64);
    //cout << "Your first name is: " << firstname.fname << endl;

    while ( error_fname(firstname) == false){
        cout << "That was an invalid first name, try again: ";
        cin.getline(firstname.fname, 64);
    }

}

/******************************************************************* 
** Function: bool error_lname
** Description: error handles for the lastname
** Parameters: Basics &lname
** Pre-conditions: Basics &lname
** Post-conditions: return false if the lastname is all numbers
*******************************************************************/
bool error_lname(Basics &lastname ){
    for(int i = 0; i < strlen(lastname.lname); i++){
        if (lastname.lname[i] >= 65 && lastname.lname[i] <= 122){
            return true;
        }
        else {
            return false;
        }
    }
}

/******************************************************************* 
** Function: void last_name
** Description: gets the lastname from user input
** Parameters: Basics &lastname
** Pre-conditions: user input for lastname
** Post-conditions: updates the lastname in the struct basics based off user input
*******************************************************************/
void last_name (Basics &lastname) {
    cout << "Enter your last name: ";
    cin.getline(lastname.lname,64);
    //cout << "Your last name is: " << lastname.lname << endl;

    while ( error_lname(lastname) == false){
        cout << "That was an invalid last name, try again: ";
        cin.getline(lastname.lname, 64);
    }
}



/******************************************************************* 
** Function: void email
** Description: gets the email input from the user
** Parameters: Basics &email
** Pre-conditions: gets user input for email
** Post-conditions: updates Basics struct for the user input for the email
*******************************************************************/
void email (Basics &email) {
    cout << "Enter your email: ";
    cin.getline(email.email, 64);
}



















//the struct to store one work experience 
struct Exp {
char company[64]; 
char start_date[64]; 
char end_date[64]; 
char des[1024];
//a c-string to store the company name //a c-string to store the start date //a c-string to store the end date //the description of the work experience
//additional members go here... 
};



















//get each skill, as a string, from the user, and store them into the array of string, sk. The size of the array is sk_size.
/******************************************************************* 
** Function: get_skills
** Description: gets the skills from the user based off their user input
** Parameters: string sk[], int sk_size
** Pre-conditions: gets the sk_size
** Post-conditions: updates the struct based off the skills entered by the user
*******************************************************************/
void get_skills (string sk[], int sk_size){
    for (int i =0; i<sk_size; i++){
        cout << endl << "Enter your skill: ";
        string skill = " ";
        getline(cin,skill);

        sk[i] = skill;
    }
}



//get each work experience, as an Exp struct object, from the user, and store them into the array of Exp, ex. The size of the array is ex_size.
/******************************************************************* 
** Function: void get_exp
** Description: gets the user input for work experiences
** Parameters: exp ex[], int ex_size
** Pre-conditions: ex_size, the user input on how many experiences they want to add
** Post-conditions: updates the array and the struct with the user inputs for company, start date, end date, and description
*******************************************************************/
void get_exp (Exp ex[], int ex_size){


    for(int i=0;i<ex_size;i++){
        struct Exp s1;
        cout << endl << endl << "Work experience background... " << endl;
        cout << "Enter the company: ";
        cin.getline(s1.company, 64);

        cout << "Enter the start date: ";
        cin.getline(s1.start_date, 64);

        cout << "Enter the end date: ";
        cin.getline(s1.end_date, 64);

        cout << "Enter the job description: ";
        cin.getline(s1.des, 1024);

        ex[i] = s1;
    }
}

//the function to build the resume with all user inputs. Create your own design of resume template here. Be creative! :)
/******************************************************************* 
** Function: void build_resume
** Description: this function builds the resume and outputs a text file
** Parameters: ofstream& f, Basics b, Exp ex[], int ex_size, string sk[], int sk_size
** Pre-conditions:  f, two, ex, ex_size, sk,  sk_size
** Post-conditions: builds the file name with the last name
*******************************************************************/
void build_resume (ofstream& f, Basics b, Exp ex[], int ex_size, string sk[], int sk_size){
    string extension = ".txt";
    extension.c_str();
    string filename = b.lname + extension;
    
    ofstream fout;
	fout.open(filename.c_str(), ios::app); 
		if (!fout.is_open()){
			cout << "Error opening the file" << endl;
			return;
		}
    
    fout << endl << endl << "Basic Information: " << endl <<  '\t' << b.fname << " " << b.lname << endl << '\t' << b.email << endl << endl;
    fout << endl << "Education Background: " << endl << '\t' << "University: " << b.edu.univ << endl << '\t' << "Major: " << b.edu.major << endl;
    fout << '\t' << "Graduation year: " << b.edu.graduate_year << endl << '\t' << "GPA: " << fixed << setprecision(2) << b.edu.GPA << endl << endl << endl << "Work Experience: " << endl;

    for (int i= 0; i < ex_size; i++){
        fout << '\t' << ex[i].company << endl;
        fout << '\t' <<'(' << ex[i].start_date;
        fout << ' ' << '-' << ' ' << ex[i].end_date << ')' << endl;
        fout << '\t' << '\t' << ex[i].des << endl << endl;
    }


    fout << endl << endl << "Skills:" << endl;
    for (int i = 0;i<sk_size;i++){
        fout << '\t' << sk[i] << endl;
    }
	fout.close(); 
}

/******************************************************************* 
** Function: void check_sksize
** Description: this function error handles for the size of skills array
** Parameters: int sk_size
** Pre-conditions: sk_size
** Post-conditions: returns updated sk-size if it doesnt work
*******************************************************************/
void check_sksize(int &sk_size){
    while (!(sk_size < 11 && sk_size > 0)){
        cout << "This is not a valid skill amount, enter another number (1-10): ";
        cin >> sk_size;
        cin.clear();
        cin.ignore(1024, '\n');

        while (cin.fail()){
            cout << "This is not a valid skill amount, enter another number (1-10): ";
            cin >> sk_size;
            cin.clear();
            cin.ignore(1024, '\n');
        }
    }
}

/******************************************************************* 
** Function: void check_exsize
** Description: this function error handles for the size of experience array
** Parameters: int ex_size
** Pre-conditions: ex_size
** Post-conditions: returns updated ex_size if it doesnt work
*******************************************************************/
void check_exsize(int &ex_size){
    while (!(ex_size < 6 && ex_size > 0)){
        cout << "This is not a valid experience amount, enter another number (1-5): ";
        cin >> ex_size;
        cin.clear();
        cin.ignore(1024, '\n');

        while (cin.fail()){
        cout << "This is not a valid experience amount, enter another number (1-5): ";
        cin >> ex_size;
        cin.clear();
        cin.ignore(1024, '\n');
        }
    }
}

/******************************************************************* 
** Function: basics_func
** Description: falls all the functions to construct the basic struct
** Parameters: Basics &two
** Pre-conditions: basics declaration
** Post-conditions: returns the value of the basics struct 
*******************************************************************/ 

void basics_func(Basics &two){
    //struct Basics two;
    first_name(two);
    last_name(two);
    email (two);
}

/******************************************************************* 
** Function: edu_func
** Description: calls all the functions to construct the edu struct
** Parameters: edu &one
** Pre-conditions: edu declaration
** Post-conditions: returns the value of the edu struct 
*******************************************************************/ 
void edu_func(Edu &one){
    univ(one);
    major(one);
    graduate_year(one);
    GPA(one);
}

/******************************************************************* 
** Function: handle_another conversion
** Description: error handles the input for another conversion
** Parameters: string from user input for anotherconversion
** Pre-conditions: string version of anotherconversion
** Post-conditions: void function just to see if it is a valid input or not 
*******************************************************************/

void handle_another(string &anotherconversion){
    while (!((anotherconversion[0] == '1' && anotherconversion.length() == 1) || (anotherconversion[0] == '0' && anotherconversion.length() == 1))){
        cout << "That was an invalid input please input 0 or 1: ";
        cin >> anotherconversion;
    }
    while (anotherconversion[0] == '1' && anotherconversion.length() == 1){
        return;
    }
    while (anotherconversion[0] == '0' && anotherconversion.length() == 1)
        return;
}


//int main has 3 extra lines due to the do while loop, and having to use cin.clear() and cin.ignore() to account for the enter input after each getline
int main(){
        
    string playagain;
    do{
        int sk_size = 0;
        int ex_size;
        struct Basics two;
        struct Edu one;
        Exp ex[5];
        string sk[10] = "";


        basics_func(two);
        edu_func(one);
        two.edu = one;

        cout << "How many skills would you like to add (max: 10): ";
        cin >> sk_size;
        cin.ignore();
        cin.clear();
        check_sksize(sk_size);
        get_skills(sk, sk_size);


        cout << endl << "How many work experiences do you want to add (max: 5): ";
        cin >> ex_size;
        cin.ignore();
        cin.clear();
        check_exsize(ex_size);
        get_exp(ex,ex_size);


        ofstream fout;
        build_resume (fout, two, ex, ex_size, sk, sk_size);

        cout << endl << "Would you like to create another (1-yes, 0-no): ";
        cin >> playagain;
        cin.ignore();
        cin.clear();
        handle_another(playagain);

    }while (playagain[0] == '1');
    return 0;
}
