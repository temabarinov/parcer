#include "iniparcer.h"

parcer::parcer() {}
parcer::parcer(const string &file_name) { this->load(file_name); }
const string &parcer::getString(const string &section,
                                const string &key) const {

  return data.at(section).at(key);
}
int parcer::getDouble(const string &section, const string &key) {
  return stod(getString(section, key));
}
int parcer::getInt(const string &section, const string &key) const {
  return stoi(getString(section, key));
}
string parcer::trim(string &line) {
  auto it1 = line.find_first_not_of(" \n\t\r");
  auto it2 = line.find_last_not_of(" \n\t\r");
  if (it1 == string::npos) {
    return "";
  }
  return line.substr(it1, it2 - it1 + 1);
}
void parcer::setData(const string &section, const string &key,
                     const string &value) {
  this->data[section].emplace(std::move(key), std::move(value));
}
void parcer::load(const string &file_name) {
  string file = file_name;
  ifstream FILE(file);
  string line;
  if (!FILE.is_open()) {
    cout << "File not open ";
    return;
  }
  string actualSection{};

  while (getline(FILE, line)) {

    string actualkey{};
    string actualvalue{};
    trim(line);
    if (line.empty() || line[0] == ';' || line[0] == '#') {
      continue;
    }
    if (line.front() == '[' && line.back() == ']') {
      actualSection = line.substr(1, line.size() - 2);
      continue;
    }
    if (line.find("=") != string::npos) {
      actualkey = line.substr(0, line.find("="));
      actualkey = trim(actualkey);
      actualvalue = line.substr(line.find("=") + 1);
      actualvalue = trim(actualvalue);
      parcer::setData(actualSection, std::move(actualkey),
                      std::move(actualvalue));
      continue;
    }
  }
}
