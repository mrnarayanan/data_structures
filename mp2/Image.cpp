#include "Image.h"

using namespace cs225;

void Image::lighten()
{
  lighten(0.1);
}

void Image::lighten(double factor)
{
  for (unsigned x = 0; x < width(); x++)
  {
    for (unsigned y = 0; y < height(); y++)
    {
      HSLAPixel & pixel = getPixel(x,y);
      if (pixel.l + factor > 1)
        pixel.l = 1;
      else
        pixel.l += factor;
    }
  }
}

void Image::darken()
{
  darken(0.1);
}

void Image::darken(double factor)
{
  for (unsigned x = 0; x < width(); x++)
  {
    for (unsigned y = 0; y < height(); y++)
    {
      HSLAPixel & pixel = getPixel(x,y);
      if (pixel.l - factor < 0)
        pixel.l = 0;
      else
        pixel.l -= factor;
    }
  }
}

void Image::saturate()
{
  saturate(0.1);
}

void Image::saturate(double factor)
{
  for (unsigned x = 0; x < width(); x++)
  {
    for (unsigned y = 0; y < height(); y++)
    {
      HSLAPixel & pixel = getPixel(x,y);
      if (pixel.s + factor > 1)
        pixel.s = 1;
      else
        pixel.s += factor;
    }
  }
}

void Image::desaturate()
{
  desaturate(0.1);
}

void Image::desaturate(double factor)
{
  for (unsigned x = 0; x < width(); x++)
  {
    for (unsigned y = 0; y < height(); y++)
    {
      HSLAPixel & pixel = getPixel(x,y);
      if (pixel.s - factor < 0)
        pixel.s = 0;
      else
        pixel.s -= factor;
    }
  }
}

void Image::grayscale()
{
  for (unsigned x = 0; x < width(); x++)
  {
    for (unsigned y = 0; y < height(); y++)
    {
      HSLAPixel & pixel = getPixel(x,y);
      pixel.s = 0;
    }
  }
}

void Image::rotateColor(double factor)
{
  for (unsigned x = 0; x < width(); x++)
  {
    for (unsigned y = 0; y < height(); y++)
    {
      HSLAPixel & pixel = getPixel(x,y);
      int scale = (int) (pixel.h + factor);
      int mult = scale / 360;
      if (pixel.h + factor < 0)
        pixel.h = (pixel.h + factor + 360) - 360*mult;
      else
        pixel.h = (pixel.h + factor) - 360*mult;
    }
  }
}

void Image::illinify()
{
  for (unsigned x = 0; x < width(); x++)
  {
    for (unsigned y = 0; y < height(); y++)
    {
      HSLAPixel & pixel = getPixel(x,y);
      double hue = pixel.h;
      double blue = 216.0;
      double orange = 11.0;
      double bd1 = abs(hue-blue);
      double bd2 = 360 - bd1;
      double od1 = abs(hue-orange);
      double od2 = 360 - od1;
      double bdm = fmin(bd1,bd2);
      double odm = fmin(od1,od2);
      double md = fmin(bdm,odm);
      if (md == bd1 || md == bd2)
        pixel.h = blue;
      else
        pixel.h = orange;
    }
  }
}

void Image::scale(double scale)
{
  unsigned wid = (unsigned) (width() * scale);
  unsigned hgt = (unsigned) (height() * scale);

  Image img;
  img.resize(wid,hgt);

  for (unsigned x = 0; x < img.width(); x++)
  {
    for (unsigned y = 0; y < img.height(); y++)
    {
      HSLAPixel & dest = img.getPixel(x,y);
      double scw = (double) width() / wid;
      double sch = (double) height() / hgt;
      unsigned xi = (unsigned) (x * scw);
      unsigned yi = (unsigned) (y * sch);
      HSLAPixel & source = getPixel(xi,yi);
      dest = source;
    }
  }

  // pixel copy loop
  resize(wid,hgt);
  for (unsigned x = 0; x < img.width(); x++)
  {
    for (unsigned y = 0; y < img.height(); y++)
    {
      HSLAPixel & source = img.getPixel(x,y);
      HSLAPixel & dest = getPixel(x,y);
      dest = source;
    }
  }

}

void Image::scale(unsigned h, unsigned w)
{
  // keep width the same, change height to preserve aspect ratio
  double ratio = (double) height() / width();
  unsigned wid = w;
  unsigned hgt = (unsigned) (wid * ratio);

  Image img;
  img.resize(wid,hgt);

  for (unsigned x = 0; x < img.width(); x++)
  {
    for (unsigned y = 0; y < img.height(); y++)
    {
      HSLAPixel & dest = img.getPixel(x,y);
      double scw = (double) width() / wid;
      double sch = (double) height() / hgt;
      unsigned xi = (unsigned) (x * scw);
      unsigned yi = (unsigned) (y * sch);
      HSLAPixel & source = getPixel(xi,yi);
      dest = source;
    }
  }

  // pixel copy loop
  resize(wid,hgt);
  for (unsigned x = 0; x < img.width(); x++)
  {
    for (unsigned y = 0; y < img.height(); y++)
    {
      HSLAPixel & source = img.getPixel(x,y);
      HSLAPixel & dest = getPixel(x,y);
      dest = source;
    }
  }

}
