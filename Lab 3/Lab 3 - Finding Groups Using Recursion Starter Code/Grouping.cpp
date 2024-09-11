/*
 * Name:
 * Date Submitted:
 * Lab Section:
 * Assignment Name:
 */

#include "Grouping.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Implement the (parameterized) constructor and findGroup functions below
// Constructor that reads grid from a file and initializes groups
Grouping::Grouping(string fileName){
ifstream myFile;
myFile.open(fileName, ifstream::in);
char fileVal = NULL;



 for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++)
    {
        myFile >> fileVal;
        if(fileVal == 'X'){
            grid[i][j] = 1;
        }
        else
        {
            grid[i][j] = 0;
        }
    }
 }

 for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++)
    {
        if(grid[i][j] == 1)
        {
            myGroup.clear();
            findGroup(i,j);
            groups.push_back(myGroup);
        }
    }
}
}

// Recursive function to find a group of connected squares
void Grouping::findGroup(int r, int c) {
if(r < 0 || r > 9 || c < 0 || c > 9)
{
    return;
}
if(grid[r][c] != 1)
{
    return;
}

myGroup.push_back(GridSquare(r,c));
grid[r][c] = 0;
findGroup( r + 1, c);
findGroup( r - 1, c);
findGroup( r, c + 1);
findGroup( r, c - 1);
}




//Simple main function to test Grouping
//Be sure to comment out main() before submitting
/* int main()
{
    Grouping input1("input1.txt");
    input1.printGroups();
    
    return 0;
}
*/
//Do not modify anything below

GridSquare::GridSquare() : row(0), col(0) {} //Default constructor, (0,0) square

GridSquare::GridSquare(int r, int c) : row(r), col(c) {} //(r,c) square

//Compare with == operator, used in test cases
bool GridSquare::operator== (const GridSquare r) const
{
    if ((row == r.row) && (col == r.col))
    {
        return true;
    }
    return false;
}

int GridSquare::getRow() //return row value
{
    return row;
}

int GridSquare::getCol() //return column value
{
    return col;
}

//Output using << operator, used in Grouping::printGroups()
//Function definition for <ostream> << <GridSquare>
ostream& operator<< (ostream& os, const GridSquare obj)
{
    os << "(" << obj.row << "," << obj.col << ")";
    return os;
}

Grouping::Grouping() : grid{},groups() {} //Default constructor, no groups

void Grouping::printGroups() //Displays grid's groups of squares
{
      cout << "Number of groups: " << groups.size() << endl; // Debug output

    for(int g=0; g<groups.size(); g++) {
        cout << "Group " << g+1 << ": ";
        for(int s=0; s<groups[g].size(); s++) {
            cout << " " << groups[g][s];
        }
        cout << endl;
    }

     for(int g=0; g<groups.size(); g++) {
        cout << "Group " << g+1 << " size: " << groups[g].size() << endl; // Debug output

        cout << "Group " << g+1 << ": ";
        for(int s=0; s<groups[g].size(); s++) {
            cout << " " << groups[g][s];
        }
        cout << endl;
    }


    for(int g=0; g<groups.size(); g++)
    {
        cout << "Group " << g+1 << ": ";
        for(int s=0; s<groups[g].size(); s++)
        {
            cout << " " << groups[g][s];
        }
        cout << endl;
    }
}

vector<vector<GridSquare>> Grouping::getGroups() //Needed in unit tests
{
    return groups;
}