#include "ConsoleParser.h"

void ConsoleParser::SetShortOption(const char* short_option) {
    memcpy(&short_name, &short_option, sizeof(short_option));
}

void ConsoleParser::SetLongOption(const std::string* long_option) {
    memcpy(&long_name, &long_option, sizeof(long_option));
}

bool ConsoleParser::SetOption(const int argc, const char** argv) {
    uint8_t j = 0;
    bool break_point = 0;

    for (uint32_t i = 1; i < argc; ++i) {
        if (argv[i][0] == '-') {
            std::string option = argv[i];
            bool is_correct_option = 0;
            j = 0;
            while (j < quantity_options) {
                if (option.substr(2, option.size() - 2) == long_name[j]
                    || (option[1] == short_name[j] && option.size() == 2)) {
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
