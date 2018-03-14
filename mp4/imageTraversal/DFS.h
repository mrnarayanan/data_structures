/**
 * @file DFS.h
 */

#ifndef DFS_H
#define DFS_H

#include <iterator>
#include <cmath>
#include <list>
#include <stack>
#include <vector>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

using namespace cs225;
using namespace std;

/**
 * A depth-first ImageTraversal.
 * Derived from base class ImageTraversal
 */
class DFS : public ImageTraversal {
public:
  DFS(const PNG & png, const Point & start, double tolerance);

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
  stack<Point> inTraversal;
  stack<Point> nextPoint;
  int width;
  int height;
  double tol;
  Point start_point;
  PNG image;
  vector< vector<int> > visited;
};

#endif
