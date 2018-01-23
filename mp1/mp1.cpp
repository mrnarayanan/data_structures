#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <string>
#include <iostream>

using namespace cs225;


void rotate(std::string inputFile, std::string outputFile) {
  // Part 2
  PNG * orig = new PNG();
  bool check = orig->readFromFile(inputFile);
  if (check == false)
    std::cout << "Reading image from file failed!\n";
  unsigned int height = orig->height();
  unsigned int width = orig->width();

  PNG * rot = new PNG(width, height);
  HSLAPixel * opix;
  HSLAPixel * rpix;
  int ht = (int) height;
  int wd = (int) width;
  for (int x = 0; x < wd; x++)
  {
    for (int y = 0; y < ht; y++)
    {
      opix = orig->getPixel(x, y);
      rpix = rot->getPixel(wd-1-x, ht-1-y);
      rpix->h = opix->h;
      rpix->s = opix->s;
      rpix->l = opix->l;
      rpix->a = opix->a;
    }
  }

  check = rot->writeToFile(outputFile);
  if (check == false)
    std::cout << "Writing image to file failed!\n";
  // end of function
}

PNG myArt(unsigned int width, unsigned int height) {
  PNG png(width, height);
  // Part 3
  int wd = (int) width;
  int ht = (int) height;
  HSLAPixel * pixel;
  HSLAPixel * prev;
  HSLAPixel * next;

  for (int x = 0; x < wd/2; x++) // top left red
  {
    for (int y = 0; y < ht/2; y++)
    {
      pixel = png.getPixel(x, y);
      pixel->h = 0;
      pixel->s = 1;
      pixel->l = 0.5;
      pixel->a = 1;
    }
  }

  for (int x = wd/2; x < wd; x++) // top right green
  {
    for (int y = 0; y < ht/2; y++)
    {
      pixel = png.getPixel(x, y);
      pixel->h = 120;
      pixel->s = 1;
      pixel->l = 0.5;
      pixel->a = 1;
    }
  }

  for (int x = 0; x < wd/2; x++) // bottom left blue
  {
    for (int y = ht/2; y < ht; y++)
    {
      pixel = png.getPixel(x, y);
      pixel->h = 240;
      pixel->s = 1;
      pixel->l = 0.5;
      pixel->a = 1;
    }
  }

  for (int x = wd/2; x < wd; x++) // bottom right yellow
  {
    for (int y = ht/2; y < ht; y++)
    {
      pixel = png.getPixel(x, y);
      pixel->h = 60;
      pixel->s = 1;
      pixel->l = 0.5;
      pixel->a = 1;
    }
  }

for (int x = wd/2 - wd/8; x <= wd/2 + wd/8; x++)
{
  for (int y = 0; y < ht; y++)
  {
    prev = png.getPixel(x-1, y);
    next = png.getPixel(x+1, y);
    pixel = png.getPixel(x, y);
    if (x < wd/2)
      pixel->l = prev->l + 0.01;
    else
      pixel->l = prev->l - 0.01;
  }
}

for (int x = 0; x < wd; x++)
{
for (int y = ht/2 - ht/8; y <= ht/2 + ht/8; y++)
  {
    prev = png.getPixel(x, y-1);
    next = png.getPixel(x, y+1);
    pixel = png.getPixel(x, y);
    if (y < ht/2)
      pixel->l = prev->l + 0.01;
    else
      pixel->l = prev->l - 0.01;
  }
}

  return png;
}
