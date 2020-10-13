#include "stb_csv_writer.h"

stb_csv_writer::stb_csv_writer(string file) :
  __fstream(file)
{
}

stb_csv_writer::~stb_csv_writer()
{
  __fstream.close();
}

bool stb_csv_writer::writeLine(string text)
{
  if (!__fstream.good())
    return false;

  __fstream << text.c_str() << endl;
  return true;
}
