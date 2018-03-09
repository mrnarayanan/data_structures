#include <iterator>
#include <cmath>
#include <list>
#include <stack>

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
}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator DFS::begin() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator();
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator DFS::end() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator();
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void DFS::add(const Point & point) {
  /** @todo [Part 1] */
  // right, below, left, above
  Point pr(point.x + 1, point.y);
  Point pb(point.x, point.y + 1);
  Point pl(point.x - 1, point.y);
  Point pa(point.x, point.y - 1);

  // bounds checking
  int count = 0;
  if (point.x + 1 < width)
  {
    nextPoint.push(pr);
    count++;
  }
  if (point.y + 1 < height)
  {
    nextPoint.push(pb);
    count++;
  }
  if (point.x - 1 >= 0)
  {
    nextPoint.push(pl);
    count++;
  }
  if (point.y - 1 >= 0)
  {
    nextPoint.push(pa);
    count++;
  }

  for (int i = 0; i < count; i++) // execute 4 times
  {
    inTraversal.push(nextPoint.top());
    nextPoint.pop();
  }

}

/**
 * Removes and returns the current Point in the traversal.
 */
Point DFS::pop() {
  /** @todo [Part 1] */
  Point ret = inTraversal.top();
  inTraversal.pop();
  return ret;
}

/**
 * Returns the current Point in the traversal.
 */
Point DFS::peek() const {
  /** @todo [Part 1] */
  Point ret = inTraversal.top();
  return ret;
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
