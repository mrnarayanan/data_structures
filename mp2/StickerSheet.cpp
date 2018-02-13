#include "StickerSheet.h"

StickerSheet::StickerSheet(const Image & pic, unsigned num)
{
  base_ = new Image();
  *base_ = pic;
  max_ = num;
  arr_ = new Image*[max_];
  xcor_ = new unsigned[max_];
  ycor_ = new unsigned[max_];
  for (unsigned i = 0; i < max_; i++)
    arr_[i] = NULL;
}

StickerSheet::StickerSheet(const StickerSheet & other)
{
  _copy(other);
}

StickerSheet::~StickerSheet()
{
  _delete();
}

const StickerSheet & StickerSheet::operator=(const StickerSheet & other)
{
  _delete();
  _copy(other);
  return *this;
}

void StickerSheet::changeMaxStickers(unsigned num)
{
  Image ** temp = new Image*[max_];
  unsigned * tempx = new unsigned[max_];
  unsigned * tempy = new unsigned[max_];
  for (unsigned i=0; i<max_; i++)
  {
    temp[i] = arr_[i];
    tempx[i] = xcor_[i];
    tempy[i] = ycor_[i];
  }

  if (arr_ != NULL)
  {
    delete[] arr_;
    arr_ = NULL;
  }
  if (xcor_ != NULL)
  {
    delete[] xcor_;
    xcor_ = NULL;
  }
  if (ycor_ != NULL)
  {
    delete[] ycor_;
    ycor_ = NULL;
  }

  arr_ = new Image*[num];
  for (unsigned i = 0; i < num; i++)
    arr_[i] = NULL;
  xcor_ = new unsigned[num];
  ycor_ = new unsigned[num];

  unsigned lim = 0;
  if (num >= max_) // copying into equal or bigger array
    lim = max_;
  else // copying into smaller array
    lim = num;

  for (unsigned i = 0; i < lim; i++)
  {
    arr_[i] = temp[i];
    xcor_[i] = tempx[i];
    ycor_[i] = tempy[i];
  }

  max_ = num;
  delete[] temp;
  delete[] tempx;
  delete[] tempy;
}

int StickerSheet::addSticker(Image & sticker, unsigned x, unsigned y)
{
  bool flag = false;
  unsigned i;
  for (i = 0; i < max_ ; i++)
  {
    if (arr_[i] == NULL)
    {
      flag = true;
      break;
    }
  }

  if (flag == false)
    return -1;
  else
  {
    arr_[i] = &sticker;
    xcor_[i] = x;
    ycor_[i] = y;
    return i;
  }
}

bool StickerSheet::translate(unsigned index, unsigned x, unsigned y)
{
  if (index >= max_ || arr_[index] == NULL)
    return false;
  else
  {
    xcor_[index] = x;
    ycor_[index] = y;
    return true;
  }
}

void StickerSheet::removeSticker(unsigned index)
{
  if (index < max_)
  {
    arr_[index] = NULL;
    xcor_[index] = 0;
    ycor_[index] = 0;
  }
}

Image * StickerSheet::getSticker(unsigned index) const
{
  if (index >= max_)
    return NULL;
  else
    return arr_[index];
}

Image StickerSheet::render() const
{
  Image output;

  // create canvas
  unsigned baseW = base_->width();
  unsigned baseH = base_->height();
  unsigned extraW = 0;
  unsigned extraH = 0;
  for (unsigned i = 0; i < max_ ; i++)
  {
    if (arr_[i] != NULL)
    {
      if (arr_[i]->width() + xcor_[i] >= baseW && arr_[i]->width() + xcor_[i] - baseW > extraW)
        extraW = arr_[i]->width() + xcor_[i] - baseW;
      if (arr_[i]->height() + ycor_[i] >= baseH && arr_[i]->height() + ycor_[i] - baseH > extraH)
        extraH = arr_[i]->height() + ycor_[i] - baseH;
    }
  }
  output.resize(baseW + extraW, baseH + extraH);

  // draw background image
  for (unsigned x = 0; x < baseW; x++)
  {
    for (unsigned y = 0; y < baseH; y++)
    {
      HSLAPixel & source = base_->getPixel(x,y);
      HSLAPixel & dest = output.getPixel(x,y);
      dest = source;
    }
  }

  // draw each sticker
  for (unsigned i = 0; i < max_ ; i++)
  {
    if (arr_[i] != NULL)
    {
      for (unsigned x = 0; x < arr_[i]->width(); x++)
      {
        for (unsigned y = 0; y < arr_[i]->height(); y++)
        {
          HSLAPixel & source = arr_[i]->getPixel(x,y);
          HSLAPixel & dest = output.getPixel(x+xcor_[i],y+ycor_[i]);
          if (source.a != 0)
            dest = source;
        }
      }
    }
  }

  return output;
}

void StickerSheet::_copy(const StickerSheet & other)
{
  if (this != &other)
  {
    base_ = new Image();
    *base_ = *(other.base_);
    max_ = other.max_;
    arr_ = new Image*[max_];
    xcor_ = new unsigned[max_];
    ycor_ = new unsigned[max_];
    for (unsigned i = 0; i < max_; i++)
    {
      arr_[i] = other.arr_[i];
      xcor_[i] = other.xcor_[i];
      ycor_[i] = other.ycor_[i];
    }
  }
}

void StickerSheet::_delete()
{
  if (arr_ != NULL)
  {
    delete[] arr_;
    arr_ = NULL;
  }
  if (xcor_ != NULL)
  {
    delete[] xcor_;
    xcor_ = NULL;
  }
  if (ycor_ != NULL)
  {
    delete[] ycor_;
    ycor_ = NULL;
  }
  if (base_ != NULL)
  {
    delete base_;
    base_ = NULL;
  }
}
