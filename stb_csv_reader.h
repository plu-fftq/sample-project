#ifndef __STB_CSV_READER_H
#define __STB_CSV_READER_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class stb_csv_reader
{
public:
  stb_csv_reader(string filePath);
  virtual ~stb_csv_reader();

  bool nextLine(string& text);

private:
  ifstream __fileStream;
};

#endif
