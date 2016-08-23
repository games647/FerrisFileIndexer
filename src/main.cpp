#include <cstdlib>
#include <iostream>
#include <string.h>
#include <dirent.h>
#include <fstream>
#include <map>
#include <sys/stat.h>
#include <c++/vector>
#include <algorithm>

std::ifstream::pos_type filesize(char *filename) {
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}

bool isFolder(char *filename) {
    struct stat info;

    if (stat(filename, &info) != 0)
        return false;
    else if (info.st_mode & S_IFDIR)
        return true;
    else
        return false;
}

void scanFolder(std::vector<std::pair<std::string, int>> *fileVector, const char *dirName) {
    DIR *pDIR;
    struct dirent *entry;
    if (pDIR = opendir(dirName)) {
        while (entry = readdir(pDIR)) {
            char *fileName = entry->d_name;
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                if (isFolder(fileName)) {
                    //found another folder scan deeper
                    scanFolder(fileVector, fileName);
                } else {
                    std::string str = dirName;
                    str.append("/");
                    fileVector->push_back({str.append(fileName), filesize(fileName)});
                }
            }
        }

        closedir(pDIR);
    }
}

void listFile() {
    std::vector<std::pair<std::string, int>> fileVector;
    scanFolder(&fileVector, ".");

    std::sort(fileVector.begin(), fileVector.end(), [](auto &left, auto &right) {
        //reverse order show the highest on first
        return left.second > right.second;
    });

    //sort by file size
    for (auto pair: fileVector)
        std::cout << pair.second << " bytes " << pair.first << '\n';
}

int main() {
    listFile();
    return 0;
}