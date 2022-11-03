#ifndef CPP_LIB__CONSOLEPARSER_H_
#define CPP_LIB__CONSOLEPARSER_H_

#include <iostream>

class ConsoleParser {
private:
    char* short_name;
    std::string* long_name;
    std::string* settings;
    uint8_t quantity_options;
public:
    bool break_point = 0;
    ConsoleParser(uint8_t quantity_options);
    void SetShortOption(const char* short_option);
    void SetLongOption(const std::string* long_option);
    bool SetOption(const int argc, const char** argv);
    const std::string* GetSettings() const;
};


#endif //CPP_LIB__CONSOLEPARSER_H_
