/**
 * @file StickerSheet.h
 * Contains your declaration of the interface for the StickerSheet class.
 */
#ifndef STICKERSHEET_H_
#define STICKERSHEET_H_

#include "Image.h"

class StickerSheet
{
public:
  StickerSheet(const Image & pic, unsigned num);
  StickerSheet(const StickerSheet & other);
  ~StickerSheet();
  const StickerSheet & operator=(const StickerSheet & other);
  void changeMaxStickers(unsigned num);
  int addSticker(Image & sticker, unsigned x, unsigned y);
  bool translate(unsigned index, unsigned x, unsigned y);
  void removeSticker(unsigned index);
  Image * getSticker(unsigned index) const;
  Image render() const;
private:
  void _copy(const StickerSheet & other);
  void _delete();
  unsigned max_;
  Image * base_;
  Image ** arr_;
  unsigned * xcor_;
  unsigned * ycor_;
};

#endif
