#include <iterator>
#include <cmath>
#include <list>
#include <queue>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "BFS.h"

using namespace cs225;

/**
 * Initializes a breadth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 * @param png The image this BFS is going to traverse
 * @param start The start point of this BFS
 * @param tolerance If the current point is too different (difference larger than tolerance) with the start point,
 * it will not be included in this BFS
 */
BFS::BFS(const PNG & png, const Point & start, double tolerance) {
  /** @todo [Part 1] */
  width = png.width();
  height = png.height();
  start_point = start;
  tol = tolerance;
  image = png;

  // create visited double dimension vector
  visited.resize(width);
  for (unsigned i = 0; i < width; i++)
    visited[i].resize(height);
  for (unsigned i = 0; i < width; i++)
  {
    for (unsigned j = 0; j < height; j++)
      visited[i][j] = 0;
  }


}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator BFS::begin() {
  /** @todo [Part 1] */
  add(start_point);
  return ImageTraversal::Iterator();
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator BFS::end() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator();
  //return NULL;
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void BFS::add(const Point & point) {
  /** @todo [Part 1] */
  // right, below, left, above
  Point pr(point.x + 1, point.y);
  Point pb(point.x, point.y + 1);
  Point pl( ((int) point.x) - 1, point.y);
  Point pa(point.x, ((int) point.y) - 1);

  // bounds checking and checking if visited
  int count = 0;
  if (point.x + 1 < width && visited[point.x+1][point.y] == 0)
  {
    nextPoint.push(pr);
    count++;
  }
  if (point.y + 1 < height && visited[point.x][point.y+1] == 0)
  {
    nextPoint.push(pb);
    count++;
  }
  if ( ((int) point.x) - 1 >= 0 && visited[point.x-1][point.y] == 0)
  {
    nextPoint.push(pl);
    count++;
  }
  if ( ((int) point.y) - 1 >= 0 && visited[point.x][point.y-1] == 0)
  {
    nextPoint.push(pa);
    count++;
  }

  for (int i = 0; i < count; i++) // executes up to 4 times
  {
    inTraversal.push(nextPoint.front());
    nextPoint.pop();
  }
}

/**
 * Removes and returns the current Point in the traversal.
 */
Point BFS::pop() {
  /** @todo [Part 1] */
  if (empty())
  {
    Point neg(-1,-1);
    return neg;
  }
  else
  {
    Point ret = inTraversal.front();
    inTraversal.pop();
    visited[ret.x][ret.y] = 1;
    return ret;
  }
}

Point BFS::pop_novisit() {
  /** @todo [Part 1] */
  if (empty())
  {
    Point neg(-1,-1);
    return neg;
  }
  else
  {
    Point ret = inTraversal.front();
    inTraversal.pop();
    return ret;
  }
}

/**
 * Returns the current Point in the traversal.
 */
Point BFS::peek() const {
  /** @todo [Part 1] */
  if (empty())
  {
    Point neg(-1,-1);
    return neg;
  }
  else
  {
    Point ret = inTraversal.front();
    return ret;
  }
}

/**
 * Returns true if the traversal is empty.
 */
bool BFS::empty() const {
  /** @todo [Part 1] */
  if (inTraversal.empty())
    return true;
  else
    return false;
}

double BFS::get_tolerance()
{
  return tol;
}

PNG BFS::get_png()
{
  return image;
}

Point BFS::get_start()
{
  return start_point;
}
