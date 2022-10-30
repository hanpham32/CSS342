/*
Project 2 - CSS342
Hannah Pham
10/28/2022
greedy_robot.cpp
*/

#include <iostream>
#include <string>
#include <math.h>
#include "greedy_robot.h"
#include "point.h"
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc == 6)
    {
        int max_distance = stoi(argv[1]);
        int robot_x = stoi(argv[2]);
        int robot_y = stoi(argv[3]);
        int treasure_x = stoi(argv[4]);
        int treasure_y = stoi(argv[5]);
        Point treasure = Point(treasure_x, treasure_y);
        GreedyRobot robot = GreedyRobot(max_distance, Point(robot_x, robot_y), treasure);
        robot.FindPath(treasure, max_distance);
        robot.PrintPath();
    }
    else
    {
        cout << "Please pass 5 arguments" << endl;
    }
    return 0;
}

GreedyRobot::GreedyRobot(int max_distance, Point robot, Point treasure)
    : max_distance_(max_distance), robot_(robot), treasure_(treasure)
{
    total_paths_ = 0;
}

void GreedyRobot::FindPath(Point treasure, int max_distance)
{
    Point robot = get_robot_location();
    steps_needed_ = abs(robot.x() - treasure.x()) + abs(robot.y() - treasure.y());
    FindPath(robot, treasure, "");
}
void GreedyRobot::FindPath(Point current_location, Point treasure, string current_path)
{
    if (current_path.length() > steps_needed_)
    {
        current_path = current_path.substr(0, current_path.size() - 2);
    }
    if (current_location == treasure)
    {
        paths_.push_back(current_path);
        total_paths_ += 1;
        return;
    }
    /* Avoid needless attempts into the wrong direction by checking for expected direction AND validity */
    if (treasure.y() > current_location.y() && isDirectionValid(current_path, 'N', max_distance_))
    {
        FindPath(Point(current_location.x(), current_location.y() + 1), treasure, current_path + "N");
    }
    if (treasure.y() < current_location.y() && isDirectionValid(current_path, 'S', max_distance_))
    {
        FindPath(Point(current_location.x(), current_location.y() - 1), treasure, current_path + "S");
    }
    if (treasure.x() > current_location.x() && isDirectionValid(current_path, 'E', max_distance_))
    {
        FindPath(Point(current_location.x() + 1, current_location.y()), treasure, current_path + "E");
    }
    if (treasure.x() < current_location.x() && isDirectionValid(current_path, 'W', max_distance_))
    {
        FindPath(Point(current_location.x() - 1, current_location.y()), treasure, current_path + "W");
    }
}
bool GreedyRobot::isDirectionValid(string s, char direction, int max_distance) const
{
    if (s.size() < max_distance)
        return true;
    string sub = s.substr(s.size() - max_distance);
    if (sub.size() == 1)
    {
        if (sub[0] == direction)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    for (int i = 1; i < sub.size(); i++)
    {
        if (sub[i] == sub[0] && sub[0] == direction)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    return true;
}
void GreedyRobot::PrintPath() const
{
    for (int i = 0; i < paths_.size(); i++)
    {
        cout << paths_[i] << endl;
    }
    cout << "Number of paths: " << paths_.size() << endl;
}
int GreedyRobot::max_distance() const
{
    return max_distance_;
}
Point GreedyRobot::get_robot_location() const
{
    return robot_;
}
Point GreedyRobot::get_treasure_location() const
{
    return treasure_;
}