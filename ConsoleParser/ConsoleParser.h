#ifndef CPP_LIB__CONSOLEPARSER_H_
#define CPP_LIB__CONSOLEPARSER_H_

#include <iostream>

class ConsoleParser {
public:
    struct Option{
        char short_name;
        std::string long_name;
    };

    ConsoleParser(uint8_t quantity_options);
    void SetNameOption(Option* opt);
    bool SetOption(int argc, char** argv);
    const std::string* GetSettings() const;

private:
    uint8_t quantity_options;
    std::string* settings;
    Option* option;
};


#endif //CPP_LIB__CONSOLEPARSER_H_
