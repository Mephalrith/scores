/*
This program takes a number of names and scores specified by the user,
saves them into a vector of structs, and sorts by the greatest score.
The output is a display of names and top scores, in sorted order.
*/

#include <iostream>
#include <vector>

using namespace std;

struct HighScore {
    char name[24];
    int score;
};

void getSize(int &size);

void initializeData(vector<HighScore> &scores);

void sortData(vector<HighScore> &scores);

vector<HighScore>::iterator indexOfLargest(const vector<HighScore> &scores, vector<HighScore>::iterator startingIndex);

void displayData(const vector<HighScore> &scores);

int main() {
    int size;
    getSize(size);

    vector<HighScore> scores(static_cast<unsigned long>(size));

    initializeData(scores);
    sortData(scores);
    displayData(scores);
}


/*
The getSize function is used to collect data to
determine the size of the vector.
*/
void getSize(int &size) {
    cout << "How many scores will you enter?: ";
    cin >> size;
}


/*
The initializeData function is used to collect data for the struct
items name and score.
*/
void initializeData(vector<HighScore> &scores) {
    int count = 1;

    for (auto &score : scores) {
        cout << "Enter the name for score #" << count << " (23 char lim): ";
        cin.ignore();
        cin.getline(score.name, 24);
        cout << "Enter the score for score #" << count << ": ";
        cin >> score.score;

        count++;
    }
    cout << endl;
}


/*
The sortData function is used to sort name and
score by highest score, also using the indexOfLargest function,
based on the number specified in size.
*/
void sortData(vector<HighScore> &scores) {
    vector<HighScore>::iterator largestIndex;
    auto iterEnd = scores.end();

    for (auto iterStart = scores.begin(); iterStart != iterEnd; iterStart++) {
        largestIndex = indexOfLargest(scores, iterStart);
        swap(*largestIndex, *iterStart);
    }
}


/*
The indexOfLargest function is used to help the sortData function,
searching through the given numbers in score to find the largest
number, using the size specified.
*/
vector<HighScore>::iterator indexOfLargest(const vector<HighScore> &scores, vector<HighScore>::iterator startingIndex) {
    auto targetIndex = startingIndex;

    for (auto count = startingIndex + 1; count != scores.end(); count++) {
        if (count->score > targetIndex->score) {
            targetIndex = count;
        }
    }
    return targetIndex;
}


/*
The displayData function announces the name and score of the
structs by order of largest score to smallest score and outputs
the data to the user.
*/
void displayData(const vector<HighScore> &scores) {

    cout << "Top Scorers:" << endl;
    for (const auto &score : scores) {
        cout << score.name << ": " << score.score << endl;
    }
}






/*
OUTPUT:

How many scores will you enter?: 4
Enter the name for score #1 (23 char lim): Suzy
Enter the score for score #1: 600
Enter the name for score #2 (23 char lim): Kim
Enter the score for score #2: 9900
Enter the name for score #3 (23 char lim): Armando
Enter the score for score #3: 8000
Enter the name for score #4 (23 char lim): Tim
Enter the score for score #4: 514

Top Scorers:
Kim: 9900
Armando: 8000
Suzy: 600
Tim: 514

Process finished with exit code 0
*/