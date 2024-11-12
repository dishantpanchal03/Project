#include <iostream>
#include <fstream>
#include <cstdio>
#include <dirent.h>
#include <cstring>
#include <sys/stat.h>

void listDirectoryContents(const std::string& path) {
    DIR* dir = opendir(path.c_str());
    if (dir == nullptr) {
        std::cout << "Failed to open directory: " << path << std::endl;
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        std::cout << entry->d_name << std::endl;
    }

    closedir(dir);
}

void createFile(const std::string& filename) {
    FILE* file = fopen(filename.c_str(), "w");
    if (file) {
        std::cout << "File created successfully: " << filename << std::endl;
        fclose(file);
    } else {
        std::cout << "Failed to create file: " << filename << std::endl;
    }
}

void deleteFile(const std::string& filename) {
    if (remove(filename.c_str()) == 0) {
        std::cout << "File deleted: " << filename << std::endl;
    } else {
        std::cout << "Failed to delete file: " << filename << std::endl;
    }
}

void renameFile(const std::string& oldName, const std::string& newName) {
    if (rename(oldName.c_str(), newName.c_str()) == 0) {
        std::cout << "File renamed from " << oldName << " to " << newName << std::endl;
    } else {
        std::cout << "Error renaming file: " << strerror(errno) << std::endl;
    }
}

void readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        std::cout << "Reading file: " << filename << std::endl;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cout << "Failed to open file: " << filename << std::endl;
    }
}

int main() {
    std::string path;
    int choice;
    std::string filename, newFilename;

    while (true) {
        std::cout << "\nFile Manager\n";
        std::cout << "1. List directory contents\n";
        std::cout << "2. Create a file\n";
        std::cout << "3. Delete a file\n";
        std::cout << "4. Rename a file\n";
        std::cout << "5. Read a file\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter directory path to list: ";
                std::cin.ignore();  // Ignore the newline left by previous input
                std::getline(std::cin, path);
                listDirectoryContents(path);
                break;

            case 2:
                std::cout << "Enter filename to create: ";
                std::cin.ignore();  // Ignore the newline left by previous input
                std::getline(std::cin, filename);
                createFile(filename);
                break;

            case 3:
                std::cout << "Enter filename to delete: ";
                std::cin.ignore();  // Ignore the newline left by previous input
                std::getline(std::cin, filename);
                deleteFile(filename);
                break;

            case 4:
                std::cout << "Enter the current filename: ";
                std::cin.ignore();  // Ignore the newline left by previous input
                std::getline(std::cin, filename);
                std::cout << "Enter the new filename: ";
                std::getline(std::cin, newFilename);
                renameFile(filename, newFilename);
                break;

            case 5:
                std::cout << "Enter filename to read: ";
                std::cin.ignore();  // Ignore the newline left by previous input
                std::getline(std::cin, filename);
                readFile(filename);
                break;

            case 6:
                std::cout << "Exiting program...\n";
                return 0;

            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}
