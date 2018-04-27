/* Your code here! */
#include "maze.h"

/**
 * SquareMaze
 * DESCRIPTION:
 * INPUTS:
 * OUTPUTS:
 */
SquareMaze::SquareMaze()
{

}

/**
 * makeMaze
 * DESCRIPTION:
 * INPUTS: int width, int height
 * OUTPUTS: none
 */
void SquareMaze::makeMaze(int width, int height)
{
  width_ = width;
  height_ = height;

}

/**
 * canTravel
 * DESCRIPTION:
 * INPUTS: int x, int y, int dir
 * OUTPUTS:
 */
bool SquareMaze::canTravel(int x, int y, int dir) const
{


  return false; // change this
}

/**
 * setWall
 * DESCRIPTION:
 * INPUTS:
 * OUTPUTS:
 */
void SquareMaze::setWall(int x, int y, int dir, bool exists)
{

}

/**
 * solveMaze
 * DESCRIPTION:
 * INPUTS:
 * OUTPUTS:
 */
vector<int> SquareMaze::solveMaze()
{
  vector<int> v;




  return v;
}

/**
 * drawMaze
 * DESCRIPTION:
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
    for (int j = 0; i < height_; j++)
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
 * DESCRIPTION:
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
