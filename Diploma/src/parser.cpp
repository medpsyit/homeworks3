#include "../include/parser.h"

ini_parser::ini_parser(std::string file_name) {
    input.open(file_name);
    if (input.is_open()) {
        parse();
    }
    else {
        throw std::exception("\nFile cannot be opened!");
    }
}

ini_parser::~ini_parser() {
    if (input.is_open()) {
        input.close();
    }
}
void ini_parser::parse() {
    std::regex sec(R"(\s*\[Section\d+\]\s*)");
    std::regex var(R"(\S+[^[\[\]])");
    std::regex skip(R"(\s+)");

    std::string section, variable, value;

    std::string line;

    while (getline(input, line)) {
        std::stringstream sub_line(line);
        getline(sub_line, line, ';');
        if (!std::regex_match(line.cbegin(), line.cend(), skip)) {
            if (std::regex_search(line.cbegin(), line.cend(), sec)) {
                del_spaces(line);
                if (std::regex_match(line.cbegin(), line.cend(), sec)) {
                    section = line;
                    content[section];
                }
                else {
                    std::string error{ "\nWrong syntax on line " };
                    error = error + std::to_string(line_num) + '!';
                    const char* err = error.c_str();
                    throw std::exception(err);
                }
            }
            else {
                if (!line.empty()) {
                    if (line.find('=') == std::string::npos) {
                        std::string error{ "\nWrong syntax on line " };
                        error = error + std::to_string(line_num) + '!';
                        const char* err = error.c_str();
                        throw std::exception(err);
                    }
                    size_t eq = line.find('=');
                    std::string first = line.substr(0, eq);
                    std::string second = line.substr(eq + 1, line.length());
                    del_spaces(first);
                    if (std::regex_match(first.cbegin(), first.cend(), var)) {
                        variable = first;
                        content[section][variable];
                        if (!second.empty()) {
                            value = second;
                            content[section][variable] = value;
                        }
                    }
                    else {
                        std::string error{ "\nWrong syntax on line " };
                        error = error + std::to_string(line_num) + '!';
                        const char* err = error.c_str();
                        throw std::exception(err);
                    }
                }
            }
        }
        line_num++;
    }
}

std::string ini_parser::del_spaces(std::string current_string) {
    int index_first_sym{ 0 }, index_last_sym{ 0 };
    bool first_c = false;
    for (int i = 0; i < current_string.length(); i++)
    {
        if (!first_c) {
            if (std::isspace(current_string[i])) {
                index_first_sym++;
            }
        }
        if (!(std::isspace(current_string[i]))) {
            first_c = true;
            index_last_sym = i;
        }
    }
    current_string.erase(0, index_first_sym);
    current_string.erase((index_last_sym - index_first_sym + 1), current_string.length());
    return current_string;
}

void ini_parser::print_prompt(std::string section) {
    std::cout << "There is no such variable in the " << section
              << "!\nPerhaps you are sealed. \nList of existing variables:" << std::endl;
    for (const auto& element : content[section]) {
        std::cout << element.first << std::endl;
    }
}