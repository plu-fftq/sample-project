#include "stb_utils.h"
#include "stb_csv_reader.h"
#include "stb_csv_writer.h"


void stb_utils::make_sample(int sample_size, const string& inFile, const string& outFile)
{
  stb_csv_reader csv_reader(inFile);
  stb_csv_writer csv_writer(outFile);

  string text;
  int cnt = 0;

  while(csv_reader.nextLine(text)) {
    csv_writer.writeLine(text);
    if (++cnt == sample_size+1) // Include header
      break;
  }
}

void stb_utils::parse_line(const string& text, vector<string>& tokens, const string& delimiter)
{
  size_t s0 = 0;
  size_t s1 = 0;
  while ((s1 = text.find(delimiter, s0)) != string::npos) {
    string item = text.substr(s0, s1 - s0);
    tokens.push_back(trim(item));
    s0 = s1 + delimiter.length();
  }

  tokens.push_back(text.substr(s0, text.length() - s0));
}

string& stb_utils::trim(string& str)
{
  size_t pos0 = str.find_first_not_of("\r\n\t ");
  if (pos0 == string::npos) {
    return (str = "");
  }

  str = str.substr(pos0);
  size_t pos1 = str.find_last_not_of("\r\n\t ");
  str = str.substr(0, pos1 + 1);

  return str;
}
