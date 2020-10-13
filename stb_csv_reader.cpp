#include "stb_csv_reader.h"

stb_csv_reader::stb_csv_reader(string fileName) :
  __fileStream(fileName.c_str())
{

}

stb_csv_reader::~stb_csv_reader()
{
  __fileStream.close();
}

bool stb_csv_reader::nextLine(string& text)
{
  return getline(__fileStream, text);
}
