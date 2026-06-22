#ifndef INIPARCER
#define INIPARCER
#include <algorithm>
#include <cmath>
#include <exception>
#include <fstream>
#include <iostream>
#include <locale>
#include <map>
#include <memory>
#include <memory_resource>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class parcer {
private:
  unordered_map<string, unordered_map<string, string>> data;
  const string filename;
  string trim(string &line);

public:
  parcer();
  parcer(const string &file_name);
  const string &getString(const string &section, const string &key) const;
  int getDouble(const string &section, const string &key);
  int getInt(const string &section, const string &key) const;
  void load(const string &file_name);
  void setData(const string &section, const string &key, const string &value);
};
#endif