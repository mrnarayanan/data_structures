/* Your code here! */
#ifndef SQUAREMAZE_H_
#define SQUAREMAZE_H_

#include "cs225/PNG.h"
#include <vector>
#include "dsets.h"
#include <iostream>

using namespace std;
using namespace cs225;

class SquareMaze
{
public:
  SquareMaze();
  void makeMaze(int width, int height);
  bool canTravel(int x, int y, int dir) const;
  void setWall(int x, int y, int dir, bool exists);
  vector<int> solveMaze();
  PNG * drawMaze() const;
  PNG * drawMazeWithSolution();
private:
  int width_;
  int height_;
  std::vector<std::vector<bool>> rightWalls;
  std::vector<std::vector<bool>> downWalls;
  std::vector<int> bottomRow;
  DisjointSets * forest;
  int convert(int x, int y);
  void traverse(int x, int y, vector<int> & v);
  bool pathfinder(int x, int y, vector<int> & v, int xd);
};

#endif
