//
// Created by Komp on 28.09.2025.
//

#ifndef LABWORK1_READFILE_H
#define LABWORK1_READFILE_H

#include <string>
#include <vector>

class ReadFile {
    public:

    static std::vector<std::pair<std::string, std::string>> ReadDictionary(const std::string& filename);

    static bool FileExists(const std::string& filename);
};

#endif //LABWORK1_READFILE_H