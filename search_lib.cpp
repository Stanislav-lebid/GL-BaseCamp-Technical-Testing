#include "search_lib.h"
#include <thread>
#include <mutex>
#include <atomic>
#include <filesystem>

namespace fs = std::filesystem;

namespace {
    std::mutex mutex;
    std::atomic<bool> stopFlag(false);

    void searchFileRecursive(const std::string& name, const fs::path& directory) {
        if (stopFlag)
            return;

        for (const auto& entry : fs::directory_iterator(directory)) {
            if (entry.is_directory()) {
                std::thread(searchFileRecursive, name, entry.path()).detach();
            } else if (entry.is_regular_file() && entry.path().filename().string() == name) {
                std::lock_guard<std::mutex> lock(mutex);
                std::cout << "Found file: " << entry.path() << std::endl;
                stopFlag = true;
            }
        }
    }
}

std::string SearchLibrary::searchFile(const std::string& name) {
    stopFlag = false;
    std::thread(searchFileRecursive, name, "/").detach();
    return "";
}

void SearchLibrary::stopSearch() {
    stopFlag = true;
}
