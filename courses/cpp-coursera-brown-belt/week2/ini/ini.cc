#include <ini.h>
#include <algorithm>

using namespace std;

namespace Ini {
  string_view Lstrip(string_view line) {
    while (!line.empty() && isspace(line[0])) {
      line.remove_prefix(1);
    }
    return line;
  }

  pair<string_view, string_view> Split(string_view line, char by) {
    size_t pos = line.find(by);
    string_view left = line.substr(0, pos);

    if (pos < line.size() && pos + 1 < line.size()) {
      return {left, line.substr(pos + 1)};
    } else {
      return {left, string_view()};
    }
  }

  Section& Document::AddSection(string name){
    return sections[name];
  }

  Section& Document::GetSection(const string& name) {
    return sections.at(name);
  }

  const Section& Document::GetSection(const string& name) const {
    return sections.at(name);
  }

  size_t Document::SectionCount() const {
    return sections.size();
  }

  Document Load(istream& input){
    Document doc;
    string current_section = "";

    for(string line; getline(input, line);){
      if(line.find('[') != string::npos && line.find('=') == string::npos){
        size_t start = line.find_first_of('[') + 1;
        size_t count = line.find_first_of(']') - start;

        if(count == 0) {
          continue;
        }

        doc.AddSection(line.substr(start, count));
        current_section = line.substr(start, count);
      }
      if(line.find_first_of('=') != string::npos && !line.empty()){
        doc.GetSection(current_section).insert(Split(line,'='));
      }
    }
    return doc;
  }
}




