/**
 * @file BFS.h
 */

#ifndef BFS_H
#define BFS_H

#include <iterator>
#include <cmath>
#include <list>
#include <queue>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

using namespace cs225;

/**
 * A breadth-first ImageTraversal.
 * Derived from base class ImageTraversal
 */
class BFS : public ImageTraversal {
public:
  BFS(const PNG & png, const Point & start, double tolerance);

  ImageTraversal::Iterator begin();
  ImageTraversal::Iterator end();

  void add(const Point & point);
  Point pop();
  Point pop_novisit();
  Point peek() const;
  bool empty() const;
  double get_tolerance();
  PNG get_png();
  Point get_start();

private:
  /** @todo [Part 1] */
  /** add private members here*/
  queue<Point> inTraversal;
  queue<Point> nextPoint;
  int width;
  int height;
  double tol;
  Point start_point;
  PNG image;
  vector< vector<int> > visited;
};

#endif
