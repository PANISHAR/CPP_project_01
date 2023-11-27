#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class FindGrade {
private:
    float ct1, ct2, mid, finalExam, attendance, assignment;
    float totalMarks, percentage;
    string grade, message;

public:
    void getMarks();
    void calculateMarks();
    void calculateGrade();
    void generateMessage();
    void displayGrade();
} obj;

int main() {
    cout << "-----------------------------" << endl;
    cout << "  Welcome to Grade Calculator" << endl;
    cout << "-----------------------------" << endl;

    obj.getMarks();
    obj.calculateMarks();
    obj.calculateGrade();
    obj.generateMessage();
    obj.displayGrade();

    return 0;
}

void FindGrade::getMarks() {
    cout << "Enter obtained marks of Attendance out of (10): ";
    cin >> attendance;
    cout << "Enter obtained marks of Assignment out of (10): ";
    cin >> assignment;
    cout << "Enter obtained marks of Class Test 01 out of (10): ";
    cin >> ct1;
    cout << "Enter obtained marks of Class Test 02 out of (10): ";
    cin >> ct2;

    // Calculate the average of Class Test 01 and Class Test 02
    double averageCT = (ct1 + ct2) / 2.0;
    
    // Assign the average to ct1
    ct1 = averageCT;

    cout << "Enter obtained marks of Midterm out of (30): ";
    cin >> mid;
    cout << "Enter obtained marks of Final exam out of (40): ";
    cin >> finalExam;

    cout << endl;
}

void FindGrade::calculateMarks() {
    totalMarks = ct1  + mid + finalExam + attendance + assignment;
    percentage = (totalMarks / 100.0) * 100.0;
}

void FindGrade::calculateGrade() {
    if (percentage >= 80.0)
        grade = "A+";
    else if (percentage <=79.0 && percentage >= 75.0)
        grade = "A";
    else if (percentage >= 65.0 && percentage <=74.0)
        grade = "A-";
    else if (percentage >= 60.0 && percentage <=64.0)
        grade = "B+";
    else if (percentage <= 59.0 && percentage >= 55.0 )
        grade = "B-";
        else if (percentage >= 50.0 && percentage <=54.0)
        grade = "C";
        else if(percentage >=40.0 && percentage <=49.0)
        grade = "D";
        
    else
        grade = "Fail";
}

void FindGrade::generateMessage() {
    if (grade == "Fail") {
        message = "Don't worry, failure is the stepping stone to success. Learn from your mistakes and keep going!\n";
      
       
    } 
    else if (grade == "A" or grade == "A+") {
        message = "Congratulations! You've done exceptionally well. Keep up the good work!";
    } else if (grade == "B+" || grade == "A-" or grade == "B") {
        message = "Good job! You've performed well. Keep striving for improvement.";
       
    } else {
        message = "Ops! You need to work hard. Keep up the effort!";
        
    }
}

void FindGrade::displayGrade() {
    cout << "\n-----------------------------" << endl;
    cout << "       Grade Report          " << endl;
    cout << "-----------------------------" << endl;
    cout << fixed << setprecision(2);
    cout << "Total Marks: " << totalMarks << endl;
    cout << "Percentage: " << percentage << "%" << endl;
    cout << "Grade: " << grade << endl;
    cout << "Message: " << message << endl;
    cout << "-----------------------------" << endl;
}
