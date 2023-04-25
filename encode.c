#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codecA.h"
#include "codecB.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <codec> <message>\n", argv[0]);
        exit(1);
    }

    char* codec_name = argv[1];
    char* message = argv[2];
    char encoded_text[1000];

    if (strcmp(codec_name, "codecA") == 0) {
        codecA_encode(message, encoded_text);
    } else if (strcmp(codec_name, "codecB") == 0) {
        codecB_encode(message, encoded_text);
    } else {
        fprintf(stderr, "Invalid codec name: %s\n", codec_name);
        exit(1);
    }

    printf("Encoded text: %s\n", encoded_text);

    return 0;
}