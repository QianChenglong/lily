#pragma once


#include <string>
#include <map>

#include <lily/defs.h>


NAME_BGN

class Error {
public:
    /**
     * translates error code to error string
     */
    static std::string toString(int error_code);

public:
    Error(int error_code, const std::string& error_msg);
    operator int();
    int operator==(const int right) const;

private:
    typedef std::map<int,std::string> ErrorMap;

private:
    static ErrorMap& get_error_map();

private:
    int error_code_;
    std::string error_string_;

};

#define ERR_DEF(error_name, error_code, error_string) static Error (error_name)((error_code), (error_string))

NAME_END
