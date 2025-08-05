#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

bool testFile1(){ // open file, the question history one
    std::ifstream file("question-history.txt");
    // validate
    if (!file.is_open()) {
        return false;
    }
    file.close();
    return true;
}

bool testFile2(){ // open file, the question list one
    std::ifstream file("question-list.txt");
    // validate
    if (!file.is_open()) {
        return false;
    }
    file.close();
    return true;
}

void showFirstMessage (){
    cout << "==============================" << endl;
    cout << "View Daily Couple's Question:" << endl;
    cout << "==============================" << endl;
    cout << "1. Answer the Question of the Day" << endl;
    cout << "2. View Past Answers" << endl;
    cout << "Which feature would you like to access? (1-2)" << endl;
}

void showDQmessage (){
    cout << "==============================" << endl;
    cout << "View Daily Couple's Question:" << endl;
    cout << "==============================" << endl;
    cout << "Here is your question of the day!" << endl;
}

int askDailyQuestion(){
    bool valid = false;
    char input;
    int output;
    do {
        showFirstMessage ();
        cin >> input; 
        if (input == '1' || input == '2'){
            valid = true;
            output = input - '0';
        }
        else {
            cout << "This is an invalid input. Please input 1 or 2." << endl;
        }
    } while (valid == false);
    return output;
}

void getString(string& question){
    std::ifstream file("question-list.txt");
    std::string line;
    int counter = 0;
    int random;
    int index = 1;

    while (std::getline(file, line)) { // count the number of the quiz
        counter++;
    }
    file.close();

    srand(time(0));
    random = rand() % counter + 1; //number of the question is counter

    std::ifstream myFile("question-list.txt");
    // read from file
    while (std::getline(myFile, line)) {
        if (index == random){
            question = line;
            std::cout << question << std::endl;
        }
        index++;
    }
    myFile.close();
}

int countLines(){
    int counter = 0;
    std::ifstream file("question-history.txt");
    std::string line;

    while (std::getline(file, line)) { // count the number of the quiz
        counter++;
    }

    if (counter % 2 == 1) {
        cout << "The history has an error to store the data." << endl;
    }
    
    file.close();
    return counter;
}

void task1(){
    string question, answer, line;
    int random;
    int counter = countLines();

    showDQmessage ();

    getString(question);

    // get answer
    cout << "Answer: ";
    cin >> answer;

    // store the data
    fstream myfile;
    myfile.open ("question-history.txt", ios::app);

    if (counter == 0){
        myfile << question;
    }
    else {
    myfile << "\n" << question;
    }
    myfile << "\n" << answer;
    myfile.close();
}

void getStrings(string& question1, string& answer1, string& question2, string& answer2, string& question3, string& answer3, int currentNum){
    int current = currentNum;
    int lineNum = 1;
    std::ifstream file("question-history.txt");
    std::string line;

    while (std::getline(file, line)) { // update the strings
        if (current == lineNum){
            question1 = line;
        }
        else if (current + 1 == lineNum){
            answer1 = line;
        }
        else if (current + 2 == lineNum){
            question2 = line;
        }
        else if (current + 3 == lineNum){
            answer2 = line;
        }
        else if (current + 4 == lineNum){
            question3 = line;
        }
        else if (current + 5 == lineNum){
            answer3 = line;
        }
        lineNum++;
    }
    
    file.close();
}

void showPastEntries (string q1, string  q2, string q3){
    string question1 = q1;
    string question2 = q2;
    string question3 = q3;

    cout << "===============================" << endl;
    cout << "View Entries in Daily Question:" << endl;
    cout << "===============================" << endl;
    cout << "1. " << question1 << endl;
    cout << "2. " << question2 << endl;
    cout << "3. " << question3 << endl;
    cout << "4. Next Page" << endl;
    cout << "5. Go Back" << endl;
    cout << "Which feature would you like to access? (1-5)" << endl;
}

void task2(){
    bool valid = false;
    char input;
    int num;
    string question1 = "Empty";
    string question2 = "Empty";
    string question3 = "Empty";
    string answer1 = "Empty";
    string answer2 = "Empty";
    string answer3 = "Empty";

    int counter = countLines(); // number of the lines on the history
    int current = 1; // where 
    getStrings(question1, answer1, question2, answer2, question3, answer3, current);
    do {

    showPastEntries (question1, question2, question3);
    cin >> input;

    num = input - '0';
    if (num == 1){
        cout << question1 << endl;
        cout << "Answer: " << answer1 << endl;
        valid = true;
    }
    else if (num == 2){
        cout << question2 << endl;
        cout << "Answer: " << answer2 << endl;
        valid = true;
    }
    else if (num == 3){
        cout << question3 << endl;
        cout << "Answer: " << answer3 << endl;
        valid = true;
    }
    else if (num == 4){ // go to the next questoins
        valid = false;
        if (counter - 5 <= current){ // ex. counter = 6 or 4 or 2 or 0, current = 1
            cout << "I can't move further" << endl;
        }
        else if (counter - 7 == current){ // ex. counter = 8, current = 1
            current = counter - 5;
            getStrings(question1, answer1, question2, answer2, question3, answer3, current);
        }
        else if (counter - 9 == current){ // ex. counter = 10, current = 1 
            current = counter - 5;
            getStrings(question1, answer1, question2, answer2, question3, answer3, current);
        }
        else{ // ex. counter = 12, current = 1
            current = current + 6;
            getStrings(question1, answer1, question2, answer2, question3, answer3, current);
        }
    }
    else if (num == 5){ // go to back to the questions
        valid = false;
        if (current == 1){
            cout << "I can't go back " << endl;
        }
        else if (current == 3){
            current = 1;
            getStrings(question1, answer1, question2, answer2, question3, answer3, current);
        }
        else if (current == 5){
            current = 1;
            getStrings(question1, answer1, question2, answer2, question3, answer3, current);
        }
        else{
            current = current - 6;
            getStrings(question1, answer1, question2, answer2, question3, answer3, current);
        }
    }
    else {
        cout << "This is an invalid input. Please enter a 1 to 5 integer." << endl;
    }
    } while (valid == false);
}

int microServiceA() {
    // validate the file opening error
    if (testFile1() == false){
        return 1;
    }
    else if (testFile2() == false){
        return 2;
    }
    else {
        // succeed
        if (askDailyQuestion() == 1){ // 1. Answer the Question of the Day
            task1();
        }
        else { // 2. View Past Answers
            task2();
        }
    }
    // end the process
    return 0;
}

int main (){ // test function to call the microService A program
    int valid = microServiceA();
    if (valid == 1){
        std::cerr << "It failed to open the question-history.txt" << std::endl;
    }
    else if (valid == 2){
        std::cerr << "It failed to open the question-list.txt" << std::endl;
    }
    else {
        cout << "The program ends. Thank you!" << endl;
        return 0;
    }
}