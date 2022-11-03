#include "ConsoleParser.h"

void ConsoleParser::SetNameOption(Option* option) {
    this->option = option;
}

bool ConsoleParser::SetOption(int argc, char** argv) {
    uint8_t j = 0;

    for (uint32_t i = 1; i < argc; ++i) {
        if (argv[i][0] == '-') {
            std::string argument = argv[i];
            bool is_correct_option = 0;
            j = 0;
            while (j < quantity_options) {
                if (argument.substr(2, argument.size() - 2) == option[j].long_name
                    || (argument[1] == option[j].short_name && argument.size() == 2)) {
                    is_correct_option = 1;
                    break;
                }
                j++;
            }
            if (!is_correct_option) {
                std::cout << "Wrong option\n";
                return false;
            }
        } else {
            settings[j] = argv[i];
        }
    }

    return true;
}

const std::string* ConsoleParser::GetSettings() const {
    return settings;
}

ConsoleParser::ConsoleParser(uint8_t quantity_options) {
    this->quantity_options = quantity_options;
    settings = new std::string[quantity_options];
}