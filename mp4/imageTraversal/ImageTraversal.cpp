#include <cmath>
#include <iterator>
#include <iostream>

#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 *
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );
}

/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator() {
  /** @todo [Part 1] */
//  current = it_->peek();
  it_ = NULL;
}

ImageTraversal::Iterator::Iterator(Point start, ImageTraversal * trav) {
  /** @todo [Part 1] */
  it_ = trav;
  current = start;
  starting = start;
  it_->add(current);
}

/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */
  while ( !(it_->empty()) && it_->check_visit(it_->peek().x, it_->peek().y) )
  {
    it_->pop();
  }

  if (!it_->empty()) {

    current = it_->pop();
  // right, below, left, above
  int x = current.x;
  int y = current.y;
  Point pr(x + 1, y);
  Point pb(x, y + 1);
  Point pl(x - 1, y);
  Point pa(x, y - 1);

  // bounds checking and checking if visited
  double tol = it_->get_tolerance();
  PNG image = it_->get_png();
  int width = image.width();
  int height = image.height();
  HSLAPixel cur = image.getPixel(starting.x,starting.y);

  if (x + 1 < width && tol >= calculateDelta(cur, image.getPixel(x+1,y)))
  {
    it_->add(pr);
  }
  if (y + 1 < height && tol >= calculateDelta(cur, image.getPixel(x,y+1)))
  {
    it_->add(pb);
  }
  if (x - 1 >= 0 && tol >= calculateDelta(cur, image.getPixel(x-1,y)))
  {
    it_->add(pl);
  }
  if (y - 1 >= 0 && tol >= calculateDelta(cur, image.getPixel(x,y-1)))
  {
    it_->add(pa);
  }

}

  while ( !(it_->empty()) && it_->check_visit(it_->peek().x, it_->peek().y) )
  {
    it_->pop();
  }

  if (!it_->empty())
    current = it_->peek();
  return *this;
}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return current;
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other)
{
  /** @todo [Part 1] */
  bool thisEmpty = false;
  bool otherEmpty = false;

  if (it_ == NULL) { thisEmpty = true; }
  if (other.it_ == NULL) { otherEmpty = true; }

  if (!thisEmpty)  { thisEmpty = it_->empty(); }
  if (!otherEmpty) { otherEmpty = other.it_->empty(); }

  if (thisEmpty && otherEmpty) return false; // both empty then the traversals are equal, return true
  else if ((!thisEmpty)&&(!otherEmpty)) return (it_ != other.it_); //both not empty then compare the traversals
  else return true; // one is empty while the other is not, return true
}
