#ifndef __STB_UTILS_H
#define __STB_UTILS_H

#include <string>
#include <vector>

using namespace std;

class stb_utils
{
public:
  static void make_sample(int sample_size = 3000, const string& inFile = "./customers.csv", const string& outFile = "./samples.csv");
  static void parse_line(const string& text, vector<string>& tokens, const string& delimiter = ",");
  static string& trim(string& str);
};

#endif
