#include <string>

inline std::string date_to_string(int date)
{
  std::string y = std::to_string(date / 10000);
  std::string m = std::to_string((date % 10000) / 100);
  std::string d = std::to_string(date % 100);
  for (size_t i = 0; i < 4-y.size(); i++) {
    y = '0'+y;
  }
  for (size_t i = 0; i < 2-m.size(); i++) {
    m = '0'+m;
  }
  for (size_t i = 0; i < 2-d.size(); i++) {
    d = '0'+d;
  }
  return y + '-' + m + '-' +d;
}
