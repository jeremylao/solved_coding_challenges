#include <string>
#include <iostream>

auto const data = R"data(
auto const preamble_begin =
  "#include <string>\n#include <iostream>\n\n"
  "auto const data = R\"data(";

auto const preamble_end = ")data\";\n";

auto const program = std::string{} + preamble_begin + data 
  + preamble_end + data;

int main()
{ 
  using namespace std;
  cout << program << endl;
}
)data";

auto const preamble_begin =
  "#include <string>\n#include <iostream>\n\n"
  "auto const data = R\"data(";

auto const preamble_end = ")data\";\n";

auto const program = std::string{} + preamble_begin + data 
  + preamble_end + data;

int main()
{ 
  using namespace std;
  cout << program << endl;
}
