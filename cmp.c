#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1024

// Print the usage information for the program
void print_usage() {
    printf("Usage: cmp <file1> <file2> [-i] (to ignore uppercase) [-v] (to output equalization)\n");
}

// Compare the contents of two files and return whether they are the same or different
int compare_files(char* file1, char* file2, int ignore_case, int verbose) {
    FILE *fp1, *fp2;
    int ch1, ch2;

    fp1 = fopen(file1, "r");
    if (fp1 == NULL) {
        printf("Cannot open file %s\n", file1);
        exit(1);
    }

    fp2 = fopen(file2, "r");
    if (fp2 == NULL) {
        printf("Cannot open file %s\n", file2);
        exit(1);
    }

    int result = 0;

    // Read each character from both files and compare them
    while (1) {
        ch1 = fgetc(fp1);
        ch2 = fgetc(fp2);

        // If ignore_case is enabled, convert the characters to lowercase
        if (ignore_case) {
            ch1 = tolower(ch1);
            ch2 = tolower(ch2);
        }

        // If the characters are different, set the result to 1 and break out of the loop
        if (ch1 != ch2) {
            result = 1;
            break;
        }

        // If we have reached the end of both files, break out of the loop
        if (ch1 == EOF && ch2 == EOF) {
            break;
        }
    }

    // Close the files
    fclose(fp1);
    fclose(fp2);

    // If verbose is enabled, print the result of the comparison
    if (verbose) {
        if (result == 0) {
            printf("equal\n");
        } else {
            printf("distinct\n");
        }
    }

    // Return the result of the comparison
    return result;
}

// The entry point of the program
int main(int argc, char* argv[]) {
    // Check if the number of arguments is correct
    if (argc < 3) {
        print_usage();
        exit(1);
    }

    // Parse the arguments
    char* file1 = argv[1];
    char* file2 = argv[2];
    int ignore_case = 0;
    int verbose = 0;

    for (int i = 3; i < argc; i++) {
        if (strcmp(argv[i], "-i") == 0) {
            ignore_case = 1;
        } else if (strcmp(argv[i], "-v") == 0) {
            verbose = 1;
        } else {
            printf("Invalid flag: %s\n", argv[i]);
            print_usage();
            exit(1);
        }
    }

    // Compare the files and return the result
    int result = compare_files(file1, file2, ignore_case, verbose);
    return result;
}
