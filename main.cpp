#include "search_lib.h"

int main() {
  
    std::string filename = "name.txt"; // Замініть це ім'я файлу \ Replace this with the filename you want to search for.
    std::string foundFilePath = SearchLibrary::searchFile(filename);

    return 0;
}
