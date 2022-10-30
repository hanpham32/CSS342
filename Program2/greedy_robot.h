/*
Project 2 - CSS342
Hannah Pham
10/28/2022
greedy_robot.h
*/
#include <string>
#include "point.h"
#include <vector>
using namespace std;

#ifndef GREEDY_ROBOT_H_
#define GREEDY_ROBOT_H_

class GreedyRobot
{
public:
    GreedyRobot(int max_distance, Point robot, Point treasure);

    // getters
    int max_distance() const;
    Point get_robot_location() const;
    Point get_treasure_location() const;

    void FindPath(Point treasure, int max_distance);
    void FindPath(Point current_location, Point treasure, string current_path);
    bool isDirectionValid(string s, char direction, int max_distance) const;
    void PrintPath() const;

private:
    const int max_distance_;
    const Point robot_;
    const Point treasure_;
    int steps_needed_;
    vector<string> paths_;
    int total_paths_;
};
#endif