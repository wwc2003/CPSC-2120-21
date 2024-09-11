/*
 * Name: William Cooper
 * Date Submitted: 3/11/2024
 * Lab Section: 001
 * Assignment Name: Hash Tables
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

struct point
{
    double x;
    double y;
};

// Function to calculate distance between two points
double pointDistanceCalc(point p1, point p2){
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

// Function to calculate minimum distance between a point and other points in a cell
double cellDistanceCalc(const int t, const vector<point>& cell, const vector<point>& otherCell, double min){
    for(int i = 0; i < otherCell.size(); i++){
        // If we have already checked this point or if it's the same as the current point, skip
        if((i >= t) && (cell[t].x == otherCell[i].x) && (cell[t].y == otherCell[i].y)){
            break;
        }

        double distance = pointDistanceCalc(cell[t], otherCell[i]);

        // Update minimum distance if this distance is smaller
        if(distance < min){
            min = distance;
        }
    }

    return min;
}

// Function to calculate minimum distance between points across cells
double tableCalc(vector<vector<vector<point>>> table, int size) {
    double smallestVal = sqrt(2);

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            // Accessing the current cell
            vector<point>& currTable = table[i][j];

            for(int t = 0; t < currTable.size(); t++) {
                // Calculate minimum distance between points in the same cell
                smallestVal = cellDistanceCalc(t, currTable, currTable, smallestVal);

                // Calculate minimum distance between points in adjacent cells

                // Right neighbor
                if((j + 1) < size) {
                    smallestVal = cellDistanceCalc(t, currTable, table[i][j + 1], smallestVal);
                }
                // Bottom neighbor
                if((i + 1) < size) {
                    smallestVal = cellDistanceCalc(t, currTable, table[i + 1][j], smallestVal);
                }
                // Bottom-right neighbor
                if(((j + 1) < size) && ((i + 1) < size)) {
                    smallestVal = cellDistanceCalc(t, currTable, table[i + 1][j + 1], smallestVal);
                }
                // Bottom-left neighbor
                if((j > 0) && ((i + 1) < size)) {
                    smallestVal = cellDistanceCalc(t, currTable, table[i + 1][j - 1], smallestVal);
                }
            }
        }
    }
    return smallestVal;
}

// Function to find the closest pair of points
double closestPair(string filename){
    vector<vector<vector<point>>> table;
    int lengthList;
    long size;

    // Read points from file and hash them into cells
    ifstream infile;
    infile.open(filename, ifstream::in);

    infile >> lengthList;
    size = static_cast<int>(sqrt(lengthList));
    table.resize(size, vector<vector<point>>(size));

    for(int i = 0; i < lengthList; i++){
        point thisP;
        infile >> thisP.x;
        infile >> thisP.y;

        table[static_cast<int>(thisP.y * size)][static_cast<int>(thisP.x * size)].push_back(thisP);
    }

    infile.close();

    // Calculate the closest pair of points
    return tableCalc(table, size);
}
