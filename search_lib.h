#ifndef SEARCH_LIB_H
#define SEARCH_LIB_H

#include <string>
#include <vector>

class SearchLibrary {
public:
    static std::string searchFile(const std::string& name);
    static void stopSearch();
};

#endif // SEARCH_LIB_H
