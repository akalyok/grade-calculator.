#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    string studentName = "";
    int studentCount = 0;
    double totalClassAverageSum = 0.0;

    // Main loop to process multiple students until 'end' is entered
    while (true) {
        cout << "Student name (or end to finish): ";
        cin >> studentName;

        if (studentName == "end") {
            break;
        }

        int scoreSum = 0;

        // Read and validate 5 scores for the current student
        for (int i = 1; i <= 5; i++) {
            int currentScore = 0;

            while (true) {
                cout << "Score " << i << ": ";
                cin >> currentScore;

                // Bonus: handle non-numeric input safely
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid score. Enter a value from 0 to 100." << endl;
                } else if (currentScore < 0 || currentScore > 100) {
                    cout << "Invalid score. Enter a value from 0 to 100." << endl;
                } else {
                    break;
                }
            }

            scoreSum += currentScore;
        }

        // Calculate student average and determine letter grade
        double studentAverage = scoreSum / 5.0;
        char letterGrade = 'F';

        if (studentAverage >= 90.0) {
            letterGrade = 'A';
        } else if (studentAverage >= 75.0) {
            letterGrade = 'B';
        } else if (studentAverage >= 60.0) {
            letterGrade = 'C';
        } else {
            letterGrade = 'F';
        }

        cout << fixed << setprecision(1);
        cout << studentName << ": average " << studentAverage << ", grade " << letterGrade << endl;

        studentCount++;
        totalClassAverageSum += studentAverage;
    }

    // Output final class summary
    if (studentCount == 0) {
        cout << "No students entered" << endl;
    } else {
        double classAverage = totalClassAverageSum / studentCount;
        cout << fixed << setprecision(1);
        cout << "Students entered: " << studentCount << endl;
        cout << "Class average: " << classAverage << endl;
    }

    return 0;
}
