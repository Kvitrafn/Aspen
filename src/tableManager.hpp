#pragma once
#include "mud.h"
#include "conf.h"
#include <string>
#include <unordered_map>

template <class T>
class TableManager
{
protected:
    T _id;
    std::unordered_map<T, std::string> _vals;
    std::unordered_map<std::string, T> _strings;
public:
    TableManager(): _id(0)
    {
    }
    ~TableManager() = default;
    T Add(const std::string& val)
    {
        _id++;
        _vals[_id] = val;
        _strings[val] = _id;
    }
    std::string operator[](const T& val) const
    {
        return _vals[val];
    }
    T operator [](const std::string& val) const
    {
        return _strings[val];
    }
};
