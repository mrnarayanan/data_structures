#include <iterator>
#include <cmath>
#include <list>
#include <stack>
#include <iostream>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "DFS.h"

/**
 * Initializes a depth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 * @param png The image this DFS is going to traverse
 * @param start The start point of this DFS
 * @param tolerance If the current point is too different (difference larger than tolerance) with the start point,
 * it will not be included in this DFS
 */
DFS::DFS(const PNG & png, const Point & start, double tolerance) {
  /** @todo [Part 1] */
  width = png.width();
  height = png.height();
  start_point = start;
  tol = tolerance;
  image = png;
  //inTraversal.push(start_point);

  // create visited double dimension vector
  visited.resize(width);
  for (int i = 0; i < width; i++)
    visited[i].resize(height);
  for (int i = 0; i < width; i++)
  {
    for (int j = 0; j < height; j++)
      visited[i][j] = 0;
  }

}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator DFS::begin() {
  /** @todo [Part 1] */
  DFS * trav = new DFS(image, start_point, tol);
  return ImageTraversal::Iterator(start_point, trav);
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator DFS::end() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator();
  // return NULL;
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void DFS::add(const Point & point) {
  /** @todo [Part 1] */
  if (point == start_point)
  {
    inTraversal.push(point);
    pop();
  //  return;
  }
  // right, below, left, above
  int x = point.x;
  int y = point.y;
  Point pr(x + 1, y);
  Point pb(x, y + 1);
  Point pl(x - 1, y);
  Point pa(x, y - 1);

  // bounds checking and checking if visited
//  int count = 0;
  if (x + 1 < width && visited[x+1][y] == 0)
  {
    inTraversal.push(pr);
//    count++;
  }
  if (y + 1 < height && visited[x][y+1] == 0)
  {
    inTraversal.push(pb);
//    count++;
  }
  if (x - 1 >= 0 && visited[x-1][y] == 0)
  {
    inTraversal.push(pl);
//    count++;
  }
  if (y - 1 >= 0 && visited[x][y-1] == 0)
  {
    inTraversal.push(pa);
//    count++;
  }

  // for (int i = 0; i < count; i++) // executes up to 4 times
  // {
  //   inTraversal.push(nextPoint.top());
  //   nextPoint.pop();
  // }

}

/**
 * Removes and returns the current Point in the traversal.
 */
Point DFS::pop() {
  /** @todo [Part 1] */
  if (empty())
  {
    Point neg(999999,999999);
    return neg;
  }
  else
  {
    Point ret = inTraversal.top();
    inTraversal.pop();
    visited[ret.x][ret.y] = 1;
    return ret;
  }
}

Point DFS::pop_novisit() {
  /** @todo [Part 1] */
  if (empty())
  {
    Point neg(999999,999999);
    return neg;
  }
  else
  {
    Point ret = inTraversal.top();
    inTraversal.pop();
    return ret;
  }
}

/**
 * Returns the current Point in the traversal.
 */
Point DFS::peek() const {
  /** @todo [Part 1] */
  if (empty())
  {
    Point neg(999999,999999);
    return neg;
  }
  else
  {
    Point ret = inTraversal.top();
    return ret;
  }
}

/**
 * Returns true if the traversal is empty.
 */
bool DFS::empty() const {
  /** @todo [Part 1] */
  if (inTraversal.empty())
    return true;
  else
    return false;
}

double DFS::get_tolerance()
{
  return tol;
}

PNG DFS::get_png()
{
  return image;
}

Point DFS::get_start()
{
  return start_point;
}
