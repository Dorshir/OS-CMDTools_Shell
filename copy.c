#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Print the usage information for the program
void print_usage() {
    printf("Usage: copy <file1> <file2> [-f] [-v]\n");
}

// Copy the contents of a source file to a destination file
int copy_file(char* src, char* dst, int force, int verbose) {
    FILE *fp1, *fp2;
    char buffer[1024];
    size_t n;

    // Open the source file for reading
    fp1 = fopen(src, "r");
    if (fp1 == NULL) {
        printf("Cannot open file %s\n", src);
        exit(1);
    }

    // If the destination file already exists and force is not enabled, return an error
    fp2 = fopen(dst, "r");
    if (fp2 != NULL && !force) {
        printf("File %s already exists. Use -f to force overwrite.\n", dst);
        fclose(fp1);
        fclose(fp2);
        return 1;
    }

    // Open the destination file for writing
    fp2 = fopen(dst, "w");
    if (fp2 == NULL) {
        printf("Cannot create file %s\n", dst);
        fclose(fp1);
        exit(1);
    }

    // Read from the source file and write to the destination file
    while ((n = fread(buffer, 1, sizeof(buffer), fp1)) > 0) {
        if (fwrite(buffer, 1, n, fp2) != n) {
            printf("Error writing to file %s\n", dst);
            fclose(fp1);
            fclose(fp2);
            return 1;
        }
    }

    // Close the files
    fclose(fp1);
    fclose(fp2);

    // If verbose is enabled, print a success message
    if (verbose) {
        printf("success\n");
    }

    // Return 0 to indicate success
    return 0;
}

// The entry point of the program
int main(int argc, char* argv[]) {
    // Check if the number of arguments is correct
    if (argc < 3) {
        print_usage();
        exit(1);
    }

    // Parse the arguments
    char* src = argv[1];
    char* dst = argv[2];
    int force = 0;
    int verbose = 0;

    for (int i = 3; i < argc; i++) {
        if (strcmp(argv[i], "-f") == 0) {
            force = 1;
        } else if (strcmp(argv[i], "-v") == 0) {
            verbose = 1;
        } else {
            printf("Invalid flag: %s\n", argv[i]);
            print_usage();
            exit(1);
        }
    }

    // Copy the source file to the destination file and return the result
    int result = copy_file(src, dst, force, verbose);
    return result;
}
