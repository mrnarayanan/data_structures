#include <iostream>
#include "dsets.h"
#include "maze.h"
#include "cs225/PNG.h"

using namespace std;

int main()
{
    // Write your own main here
    SquareMaze maze;
    maze.makeMaze(15,15);
    PNG * pic = maze.drawMaze();
    pic->writeToFile("murutest.PNG");
    return 0;
}
