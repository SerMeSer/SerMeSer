#include "file_search.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void searchFile(const char *path, const char *filename) {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;

    if ((dir = opendir(path)) != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            char fullPath[1024];
            snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);
            if (stat(fullPath, &statbuf) == 0) {
                if (S_ISDIR(statbuf.st_mode)) {
                    if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                        searchFile(fullPath, filename);
                    }
                } else if (S_ISREG(statbuf.st_mode)) {
                    if (strcmp(entry->d_name, filename) == 0) {
                        printf("File found: %s\n", fullPath);
                    }
                }
            }
        }
        closedir(dir);
    } else {
        perror("opendir");
        exit(EXIT_FAILURE);
    }
}