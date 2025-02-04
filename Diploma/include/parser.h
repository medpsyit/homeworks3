#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <exception>
#include <map>
#include <regex>

class ini_parser {
public:
    ini_parser(std::string file_name);
    ~ini_parser();

private:
    std::ifstream input;
    std::map<std::string, std::map<std::string, std::string>> content;
    int line_num{ 1 };

    void parse();
    std::string del_spaces(std::string current_string);
    void print_prompt(std::string section);

public:
    template<class T> T get_value(std::string search) {
        size_t dot = search.find('.');
        std::string f_section = "[Section" + search.substr(0, dot) + ']';
        std::string f_variable = search.substr(dot + 1, search.length());

        if (content.find(f_section) == content.end()) {
            throw std::exception("\nIncorrect section!");
        }

        if (content[f_section].find(f_variable) == content[f_section].end()) {
            print_prompt(f_section);
            throw std::exception("\nIncorrect variable!");
        }

        return content[f_section][f_variable];
    }

    template<> int get_value(std::string search) {
        std::regex int_r(R"(\s*\d+\s*)");

        size_t dot = search.find('.');
        std::string f_section = "[Section" + search.substr(0, dot) + ']';
        std::string f_variable = search.substr(dot + 1, search.length());

        if (content.find(f_section) == content.end()) {
            throw std::exception("\nIncorrect section!");
        }

        if (content[f_section].find(f_variable) == content[f_section].end()) {
            print_prompt(f_section);
            throw std::exception("\nIncorrect variable!");
        }

        std::string tmp_val = content[f_section][f_variable];
        bool found_int = regex_match(tmp_val.cbegin(), tmp_val.cend(), int_r);

        if (found_int) {
            int tmp = std::stoi(tmp_val);
            return tmp;
        }
        else {
            throw std::exception("\nVariable is not int type!");
        }
    }

    template<> double get_value(std::string search) {
        std::regex dbl_r(R"(\s*\d+.\d+\s*)");

        size_t dot = search.find('.');
        std::string f_section = "[Section" + search.substr(0, dot) + ']';
        std::string f_variable = search.substr(dot + 1, search.length());

        if (content.find(f_section) == content.end()) {
            throw std::exception("\nIncorrect section!");
        }

        if (content[f_section].find(f_variable) == content[f_section].end()) {
            print_prompt(f_section);
            throw std::exception("\nIncorrect variable!");
        }

        std::string tmp_val = content[f_section][f_variable];
        bool found_dbl = regex_match(tmp_val.cbegin(), tmp_val.cend(), dbl_r);

        if (found_dbl) {
            double tmp = std::stod(tmp_val);
            return tmp;
        }
        else {
            throw std::exception("\nVariable is not double type!");
        }
    }
};

#endif /* PARSER_H */

