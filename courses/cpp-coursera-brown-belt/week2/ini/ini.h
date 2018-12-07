#include <unordered_map>
#include <string>
#include <iostream>


namespace Ini {
  using Section = std::unordered_map<std::string, std::string>;

  class Document {
  public:
    Section& AddSection(std::string name);
    const Section& GetSection(const std::string& name) const;
    Section& GetSection(const std::string& name);
    size_t SectionCount() const;

  private:
    std::unordered_map<std::string, Section> sections;
  };

  std::pair<std::string_view, std::string_view> Split(std::string_view line, char by);
  std::string_view Lstrip(std::string_view line);
  Document Load(std::istream& input);
}

namespace Ini {
  Section LoadSection(std::istream& input);
}
