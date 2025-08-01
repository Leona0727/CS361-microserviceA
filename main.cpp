#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {  // ask how to test?

    // validate open file error
    if (openFile1() == false || openFile2() == false){
        return 1;
    }

    // succeed
    if (askDailyQuestion() == 1){ // Answer the Question of the Day
        task1();
    };

    else { // 2. View Past Answers
        task2();
    };

    // end the process
    return 0;
}

bool openFile1(){
    // open file
    std::ifstream file("question-history.txt");
    // validate
    if (!file.is_open()) {
        std::cerr << "It failed to open the file." << std::endl;
        return false;
    }
    std::string line;
    // read from file by line
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    // close file
    file.close();
    return true;
}

bool openFile2(){
    // open file
    std::ifstream file("question-list.txt");
    // validate
    if (!file.is_open()) {
        std::cerr << "It failed to open the file." << std::endl;
        return false;
    }
    std::string line;
    // read from file by line
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    // close file
    file.close();
    return true;
}

int askDailyQuestion(){
    bool valid = false;
    char input;
    int output;
    do {
    cout << "==============================" << endl;
    cout << "View Daily Couple's Question:" << endl;
    cout << "==============================" << endl;
    cout << "1. Answer the Question of the Day" << endl;
    cout << "2. View Past Answers" << endl;
    cout << "Which feature would you like to access? (1-2)" << endl;
    cin >> input; 
    if (input == 1 || input == 2){
        valid = true;
        output = input - '0';
    }
    else {
        cout << "This is an invalid input. Please input 1 or 2." << endl;
    }

    } while (valid == false);
    return output;
}

void task1(){
    string question;
    string answer;
    int counter = 0;
    int random;

    cout << "==============================" << endl;
    cout << "View Daily Couple's Question:" << endl;
    cout << "==============================" << endl;
    cout << "Here is your question of the day!" << endl;

    // retrieve the question?
    // open file
    std::ifstream file("question-list.txt");
    // validate
    if (!file.is_open()) {
        std::cerr << "It failed to open the file." << std::endl;
    }
    std::string line;

    while (std::getline(file, line)) { // count the number of the quiz
        counter++;
    }
    srand(time(0));
    random = rand() % counter + 1; //number of the question is counter

    // read from file
    int i = 1;
    while (std::getline(file, line)) {
        if (i == random){
        std::cout << line << std::endl;
        question = line;
        }
        i++;
    }
    // close file
    file.close();

    // get answer
    cout << "Answer: ";
    cin >> answer;

    // store the data
    ofstream myfile;
    myfile.open ("question-history.txt");
    myfile << question << "\n";
    myfile << answer << "\n";
    myfile.close();
}

void task2(){
    bool valid = false;
    char input;
    int num;
    string question1;
    string question2;
    string question3;
    string answer1;
    string answer2;
    string answer3;

    do {
    cout << "===============================" << endl;
    cout << "View Entries in Daily Question:" << endl;
    cout << "===============================" << endl;
    cout << "1. " << question1 << endl;
    cout << "2. " << question2 << endl;
    cout << "3. " << question3 << endl;
    cout << "4. Next Page" << endl;
    cout << "5. Go Back" << endl;
    cout << "Which feature would you like to access? (1-5)" << endl;
    cin >> input;

    num = input - '0';
    if (num = 1){
        cout << question1 << endl;
        cout << "Answer: " << answer1 << endl; // how to get answer?
        valid = true;
    }
    else if (num = 2){
        cout << question2 << endl;
        cout << "Answer: " << answer2 << endl;
        valid = true;
    }
    else if (num = 3){
        cout << question3 << endl;
        cout << "Answer: " << answer3 << endl;
        valid = true;
    }
    else if (num = 4){
        valid = false;
        question1 = ;
        question2 = ;
        question3 = ;
    }
    else if (num = 5){
        valid = false;
        question1 = ;
        question2 = ;
        question3 = ;
    }
    else {
        cout << "This is an invalid input. Please enter a 1 to 5 integer." << endl;
    }
    } while (valid = false);
}
