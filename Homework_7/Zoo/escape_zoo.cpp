#include "escape_zoo.h"
#include <iostream>
#include <queue>
#include <deque>
#include <string>

using namespace std;

// matrix of integers

vector<vector<int>> make_matrix(grid const &M)
{

    vector<vector<int>> Matrix;
    int rows = M.size();
    int cols = M[0].size();
    for (int i = 0; i < rows; i++)
    {
        vector<int> v1;
        // cout<<"in make matrix"<<endl;
        for (int j = 0; j < cols; j++)
        {
            if (M[i][j] == 1) // can't move there
            {
                v1.push_back(-2);
            }
            else if (M[i][j] == 0)
            {
                v1.push_back(0);
            }
        }
        Matrix.push_back(v1);
    }
    return Matrix;
}

coordinate Check_cord(Heading orientation, coordinate Cord)
{
    coordinate C;
    if (orientation == North)
    {
        C.first = Cord.first - 1;
        C.second = Cord.second;
        return C;
    }
    else if (orientation == West)
    {
        C.first = Cord.first;
        C.second = Cord.second - 1;
        return C;
    }
    else if (orientation == South)
    {
        C.first = Cord.first + 1;
        C.second = Cord.second;
        return C;
    }
    else
    {
        C.first = Cord.first;
        C.second = Cord.second + 1;
        return C;
    }
}

Heading checkOrientation(Heading orientation)
{
    if (orientation == North)
    {
        return East;
    }
    else if (orientation == East)
    {
        return South;
    }
    else if (orientation == South)
    {
        return West;
    }
    else
    {
        return North;
    }
}

// bool canMove(vector<vector<int>> matrix, coordinate Cord, Heading orientation)
// {

// }

motion_plan escape(vector<vector<int>> matrix, coordinate Cord, Heading orientation, motion_plan movement)
{
    int rows = matrix.size();
    // cout<<"rows is: "<<rows<<endl;
    int cols = matrix[0].size();
    // cout<<"cols is: "<<cols<<endl;

    if (matrix[Cord.first][Cord.second] == -1)
    {
        cout << Cord.first << "," << Cord.second << endl;
        cout << "Already visited" << endl;
        return movement;
    }
    if (matrix[Cord.first][Cord.second] == -2)
    {
        cout << "Obsticle" << endl;
        return movement;
    }
    if (matrix[Cord.first][Cord.second] != 0)
    {
        cout << "Current path" << endl;
        return movement;
    }
    if (matrix[Cord.first][Cord.second] == 0)
    {
        cout << "Moveable area" << endl;
        // check if up is going out //escape
        motion_plan MP_straight;

        if (Cord.first + 1 > rows || Cord.second + 1 > cols || Cord.first - 1 < 0 || Cord.second - 1 < 0)
            matrix[Cord.first][Cord.second] = 1;
        // else:escape(matrix,up_corid,up_heading,motion_plan)
        else
        {
            cout << "orientation: " << orientation << endl;
            matrix[Check_cord(orientation, Cord).first][Check_cord(orientation, Cord).second] = -1; // changing his code here
            MP_straight = escape(matrix, Check_cord(orientation, Cord), orientation, movement);
        }

        // coordinate straight = Check_orientation(orientation, Cord); // up = matrix[coordinate up]
        // matrix[up cord ] = -1
        // left

        // check if left going out:;
        motion_plan MP_left;
        if (Cord.first + 1 > rows || Cord.second + 1 > cols || Cord.first - 1 < 0 || Cord.second - 1 < 0)
        {
            matrix[Cord.first][Cord.second] = 1;
            // matrx[coordinate] =1
        }
        // else escape(matrix,left_corid,left_heading,motion_plan)
        else
        {
            matrix[Check_cord(orientation, Cord).first][Check_cord(orientation, Cord).second] = -1;
            motion_plan MP_left = escape(matrix, Check_cord(orientation, Cord), checkOrientation(orientation), movement);
        }
        // left = matx[cordi]_-left]

        // pick min from straight and left and put it at matrix[Cord]
        // add(direction in motion plan returned by the min value escape according to which one is minimum) return motion plan
        if (MP_straight.size() < MP_left.size())
        {
            matrix[Cord.first][Cord.second] = MP_straight.size();
            movement.push_back(go_straight);
        }
        else
        {
            matrix[Cord.first][Cord.second] = MP_left.size();
            movement.push_back(go_left);
        }
    }
    return movement;
}
motion_plan escape_route(grid const &M, coordinate init_coordinate, Heading init_heading)
{
    vector<vector<int>> matrix = make_matrix(M);
    motion_plan init_motion_plan = {};
    // cout<<"here"<<endl;
    return escape(matrix, init_coordinate, init_heading, init_motion_plan);
}

int main()
{

     grid test1 = {
        {1,1,1,1,},
        {0,0,0,0,},
        {1,0,0,1,},
        {1,1,0,1,},
    };
    // grid test1 = {
    //     {1,1,1,1,},
    //     {0,0,0,0,},
    //     {1,0,0,1,},
    //     {1,1,0,1,},
    // };

    /*
    grid zoo = {
        {1, 1, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 0},
        {1, 0, 0, 1}

    };
    */
    // cout<<zoo[2][3]<<endl;
    coordinate C;
    C.first = 2;
    C.second = 2;

    Heading N = North;

    // cout<<zoo[1][0]<<endl;
    // cout<<C.first<<","<<C.second<<endl;
    // cout<<zoo[1].size()<<endl;
    // cout<<zoo[6][100]<<endl;
    // is_edge(zoo,C);
    // motion_plan path;
    escape_route(test1, C, North);
    // cout<<"size is: "<<path.size()<<endl;
    // path[0];
    // BFS(zoo, C, N);
}
