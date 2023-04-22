#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1024

void print_usage() {
    printf("Usage: cmp <file1> <file2> [-i] (to ignore uppercase) [-v] (to output equalization)\n");
}

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

    while (1) {
        ch1 = fgetc(fp1);
        ch2 = fgetc(fp2);

        if (ignore_case) {
            ch1 = tolower(ch1);
            ch2 = tolower(ch2);
        }

        if (ch1 == EOF && ch2 == EOF) {
            break;
        }

        if (ch1 != ch2) {
            result = 1;
            break;
        }
    }

    fclose(fp1);
    fclose(fp2);

    if (verbose) {
        if (result == 0) {
            printf("equal\n");
        } else {
            printf("distinct\n");
        }
    }

    return result;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        print_usage();
        exit(1);
    }

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

    int result = compare_files(file1, file2, ignore_case, verbose);
    return result;
}