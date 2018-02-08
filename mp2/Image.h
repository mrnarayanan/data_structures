/**
 * @file Image.h
 * Contains your declaration of the interface for the Image class.
 */

#ifndef IMAGE_H_
#define IMAGE_H_

#include "cs225/PNG.h"
#include <cmath>

using namespace cs225;

class Image : public PNG
{
public:
  void lighten();
  void lighten(double);
  void darken();
  void darken(double);
  void saturate();
  void saturate(double);
  void desaturate();
  void desaturate(double);
  void grayscale();
  void rotateColor(double);
  void illinify();
  void scale(double);
  void scale(unsigned, unsigned);
};

#endif
