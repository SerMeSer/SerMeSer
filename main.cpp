#include <stdio.h>
#include "file_search.h"

int main() {
    const char *path = "C:/Users/HP8570w/Desktop/Code"; 
    const char *filename = "example.txt"; 
    searchFile(path, filename);
    return 0;
}