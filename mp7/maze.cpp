/* Your code here! */
#include "maze.h"

/**
 * SquareMaze
 * DESCRIPTION: SquareMaze constructor
 * INPUTS: none
 * OUTPUTS: none
 */
SquareMaze::SquareMaze()
{
  forest = NULL;
}

/**
 * makeMaze
 * DESCRIPTION: sets up maze with new dimensions, inits wall vectors
 * INPUTS: int width, int height
 * OUTPUTS: none
 */
void SquareMaze::makeMaze(int width, int height)
{
  width_ = width;
  height_ = height;
  rightWalls.resize(width_);
  downWalls.resize(width_);
  bottomRow.resize(width_);
  for (int i = 0; i < width_; i++)
  {
    rightWalls[i].resize(height_);
    downWalls[i].resize(height_);
    bottomRow[i] = 0;
  }
  for (int i = 0; i < width_; i++)
  {
    for (int j = 0; j < height_; j++)
    {
      rightWalls[i][j] = true;
      downWalls[i][j] = true;
    }
  }
  if (forest != NULL)
  {
    delete forest;
  }
  forest = new DisjointSets();
  forest->addelements(width_ * height_);
  int random;
  int index, target;
  int n = 1;
  int i,j;
  while (n < width_ * height_)
  {
    i = rand() % width_;
    j = rand() % height_;
    random = rand() % 2;
    if (random == 0 && i + 1 < width_) // try to remove right wall
    {
      index = convert(i,j);
      target = convert(i+1,j);
      if (forest->find(index) != forest->find(target))
      {
        rightWalls[i][j] = false;
        forest->setunion(index, target);
        n++;
      }
    }
    if (random == 1 && j + 1 < height_) // try to remove down wall
    {
      index = convert(i,j);
      target = convert(i,j+1);
      if (forest->find(index) != forest->find(target))
      {
        downWalls[i][j] = false;
        forest->setunion(index, target);
        n++;
      }
    }
  }
  delete forest;
  forest = NULL;
}

/**
 * canTravel
 * DESCRIPTION: checks bounds and walls to see if can move in that direction
 * INPUTS: int x, int y, int dir
 * OUTPUTS: true if can move in that direction, false if not
 */
bool SquareMaze::canTravel(int x, int y, int dir) const
{
  if (dir == 0) // right
  {
    if (x+1 >= width_ || rightWalls[x][y]) // stepping off maze or if there is wall
      return false;
    else
      return true;
  }
  else if (dir == 1) // down
  {
    if (y+1 >= height_ || downWalls[x][y]) // stepping off maze or if there is wall
      return false;
    else
      return true;
  }
  else if (dir == 2) // left
  {
    if (x-1 < 0 || rightWalls[x-1][y]) // stepping off maze or if there is wall
      return false;
    else
      return true;
  }
  else if (dir == 3) // up
  {
    if (y-1 < 0 || downWalls[x][y-1]) // stepping off maze or if there is wall
      return false;
    else
      return true;
  }
  else // unrecognized dir
  {
    return false;
  }
}

/**
 * setWall
 * DESCRIPTION: sets wall vectors to whether wall exists in specified location and direction
 * INPUTS: int x, int y, int dir, bool exists
 * OUTPUTS: none
 */
void SquareMaze::setWall(int x, int y, int dir, bool exists)
{
    if (dir == 0) // right
    {
      if (exists)
        rightWalls[x][y] = true;
      else
        rightWalls[x][y] = false;
    }
    else if (dir == 1) // down
    {
      if (exists)
        downWalls[x][y] = true;
      else
        downWalls[x][y] = false;
    }
    else
    {
      return;
    }
}

/**
 * solveMaze
 * DESCRIPTION: places destination and determines path to solve maze
 * INPUTS: none
 * OUTPUTS: vector of direction ints - path to solve maze
 */
vector<int> SquareMaze::solveMaze()
{
  vector<int> directions;
  traverse(0, 0, directions); // start square is always (0,0)

  // find square in bottom row with longest path length
  int index = 0; // will store x coordinate of destination in bottom row
  for (int i = 0; i < (int) bottomRow.size(); i++)
  {
    if (bottomRow[i] > bottomRow[index]) // tiebreaker automatically handled
    {
      index = i;
    }
  }

  vector<int> ret;
  pathfinder(0, 0, ret, index); // populate ret with path to exit
  return ret;
}

/**
 * drawMaze
 * DESCRIPTION: draws maze without solution in PNG image
 * INPUTS: none
 * OUTPUTS: pointer to PNG with drawn unsolved maze
 */
PNG * SquareMaze::drawMaze() const
{
  PNG * maze_pic_ = new PNG(width_*10+1,height_*10+1); // create new PNG
  // blacken top side and left side except entrance
  for (int i = 0; i < height_*10+1; i++)
  {
    HSLAPixel & pix = maze_pic_->getPixel(0,i);
    pix.l = 0;
  }
  for (int i = 10; i < width_*10+1; i++)
  {
    HSLAPixel & pix = maze_pic_->getPixel(i,0);
    pix.l = 0;
  }

  // create walls for each maze square
  for (int i = 0; i < width_; i++)
  {
    for (int j = 0; j < height_; j++)
    {
      if (!canTravel(i,j,0)) // right wall
      {
        for (int k = 0; k <= 10; k++)
        {
          HSLAPixel & pix = maze_pic_->getPixel((i+1)*10,j*10+k);
          pix.l = 0;
        }
      }
      if (!canTravel(i,j,1)) // bottom wall
      {
        for (int k = 0; k <= 10; k++)
        {
          HSLAPixel & pix = maze_pic_->getPixel(i*10+k,(j+1)*10);
          pix.l = 0;
        }
      }
    }
  }

  return maze_pic_;
}

/**
 * drawMazeWithSolution
 * DESCRIPTION: draws maze with solution in PNG image
 * INPUTS: none
 * OUTPUTS: pointer to PNG with drawn solved maze
 */
PNG * SquareMaze::drawMazeWithSolution()
{
  PNG * maze_pic_ = drawMaze();
  vector<int> v = solveMaze();
  int x = 5, y = 5; // starting pixels
  int i = 0, j = 0; // maze square to find destination square
  int dir;
  for (unsigned n = 0; n < v.size(); n++)
  {
    dir = v[n];

    // right
    if (dir == 0)
    {
      for (int k = 0; k <= 10; k++)
      {
        HSLAPixel & pix = maze_pic_->getPixel(x+k,y);
        pix.h = 0;
        pix.s = 1;
        pix.l = 0.5;
        pix.a = 1;
      }
      x += 10;
      i++;
    }

    // down
    else if (dir == 1)
    {
      for (int k = 0; k <= 10; k++)
      {
        HSLAPixel & pix = maze_pic_->getPixel(x,y+k);
        pix.h = 0;
        pix.s = 1;
        pix.l = 0.5;
        pix.a = 1;
      }
      y += 10;
      j++;
    }

    // left
    else if (dir == 2)
    {
      for (int k = 0; k <= 10; k++)
      {
        HSLAPixel & pix = maze_pic_->getPixel(x-k,y);
        pix.h = 0;
        pix.s = 1;
        pix.l = 0.5;
        pix.a = 1;
      }
      x -= 10;
      i--;
    }

    // up
    else if (dir == 3)
    {
      for (int k = 0; k <= 10; k++)
      {
        HSLAPixel & pix = maze_pic_->getPixel(x,y-k);
        pix.h = 0;
        pix.s = 1;
        pix.l = 0.5;
        pix.a = 1;
      }
      y -= 10;
      j--;
    }

    else
    {
      // do nothing
    }
  }

  // draw exit
  for (int k = 1; k <= 9; k++)
  {
    HSLAPixel & pix = maze_pic_->getPixel(i*10+k, (j+1)*10);
    pix.l = 1;
  }

  return maze_pic_;
}

// helper function to convert double dimensions to single dimension
int SquareMaze::convert(int x, int y)
{
    return x * height_ + y;
}

// helper function to perform traversal on maze to place exit
void SquareMaze::traverse(int x, int y, vector<int> & v)
{
  if (y == height_ - 1) // reached bottom row
  {
    bottomRow[x] = v.size();
  }

  if (canTravel(x, y, 0)) // right
	{
		v.push_back(0);
		rightWalls[x][y] = true; // prevent from going back, mark as "visited"
		traverse(x + 1, y, v); // go right
		v.pop_back();
		rightWalls[x][y] = false; // restore maze to original configuration
	}

	if (canTravel(x, y, 1)) // down
	{
		v.push_back(1);
		downWalls[x][y] = true; // prevent from going back, mark as "visited"
    traverse(x, y + 1, v); // go down
		v.pop_back();
		downWalls[x][y] = false; // restore maze to original configuration
	}

	if (canTravel(x, y, 2)) // left
	{
		v.push_back(2);
		rightWalls[x-1][y] = true; // prevent from going back, mark as "visited"
		traverse(x - 1, y, v); // go left
		v.pop_back();
		rightWalls[x-1][y] = false; // restore maze to original configuration
	}

	if (canTravel(x, y, 3)) // up
	{
		v.push_back(3);
		downWalls[x][y-1] = true; // prevent from going back, mark as "visited"
		traverse(x, y - 1, v); // go up
		v.pop_back();
		downWalls[x][y-1] = false; // restore maze to original configuration
	}
}

// helper function to find path to maze exit
bool SquareMaze::pathfinder(int x, int y, vector<int> & v, int xd)
{
	if (x == xd && y == height_ - 1) // reached destination square
  {
    return true;
  }

	if (canTravel(x, y, 0)) // right
	{
		v.push_back(0);
		rightWalls[x][y] = true; // mark as "visited"
		if (pathfinder(x + 1, y, v, xd))
		{
			rightWalls[x][y] = false; // restore maze to original configuration
			return true;
		}
    else
    {
      v.pop_back(); // took wrong turn
  		rightWalls[x][y] = false; // restore maze to original configuration
    }
	}

	if (canTravel(x, y, 1)) // down
	{
		v.push_back(1);
		downWalls[x][y] = true; // mark as "visited"
		if (pathfinder(x, y + 1, v, xd))
		{
			downWalls[x][y] = false; // restore maze to original configuration
			return true;
		}
    else
    {
      v.pop_back(); // took wrong turn
      downWalls[x][y] = false; // restore maze to original configuration
    }
	}

	if (canTravel(x, y, 2)) // left
	{
		v.push_back(2);
		rightWalls[x-1][y] = true; // mark as "visited"
		if (pathfinder(x - 1, y, v, xd))
		{
			rightWalls[x-1][y] = false; // restore maze to original configuration
			return true;
		}
    else
    {
      v.pop_back(); // took wrong turn
      rightWalls[x-1][y] = false; // restore maze to original configuration
    }
	}

	if (canTravel(x, y, 3)) // up
	{
		v.push_back(3);
		downWalls[x][y-1] = true; // mark as "visited"
		if (pathfinder(x, y - 1, v, xd))
		{
			downWalls[x][y-1] = false; // restore maze to original configuration
			return true;
		}
    else
    {
      v.pop_back(); // took wrong turn
      downWalls[x][y-1] = false; // restore maze to original configuration
    }
	}
	return false;
}
