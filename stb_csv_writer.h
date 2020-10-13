#ifndef __STB_CSV_WRITER_H
#define __STB_CSV_WRITER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class stb_csv_writer
{
public:
  stb_csv_writer(string file);
  virtual ~stb_csv_writer();

  bool writeLine(string text);

private:
  ofstream __fstream;

};

#endif
