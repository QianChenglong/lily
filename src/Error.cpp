#include <assert.h>

#include <algorithm>

#include <lily/Error.h>

NAME_BGN

Error::Error(int error_code, const std::string &error_string):
    error_code_(error_code), error_string_(error_string)
{
#ifdef _DEBUG
    ErrorMap::iterator found = get_error_map().find(error_code);
    if (found != get_error_map().end()) {
        assert(found->second == error_string);
    }
#endif
    get_error_map()[error_code] = error_string_;
}

Error::operator int()
{
    return error_code_;
}

Error::ErrorMap &Error::get_error_map()
{
    static ErrorMap errMap;
    return errMap;
}

std::string Error::toString(int error_code)
{
    ErrorMap::iterator found = get_error_map().find(error_code);
    if (found == get_error_map().end()) {
        return "No such error code";
    } else {
        return found->second;
    }
}

int Error::operator==( const int right ) const
{
    return error_code_ == right;
}

NAME_END