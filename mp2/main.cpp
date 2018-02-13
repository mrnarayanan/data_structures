#include "Image.h"
#include "StickerSheet.h"

int main() {

  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //
  Image space, ent1, ent2, ent3, output;
  space.readFromFile("space.png");
  ent1.readFromFile("nx01.png");
  ent2.readFromFile("ent.png");
  ent3.readFromFile("ent_d.png");
  ent1.scale(2);
  ent2.scale(1.5);
  ent3.scale(2);
  StickerSheet sheet(space, 3);
  sheet.addSticker(ent1, 1400, 100);
  sheet.addSticker(ent2, 100, 300);
  sheet.addSticker(ent3, 1000, 600);

  output = sheet.render();
  output.writeToFile("myImage.png");

  return 0;
}
