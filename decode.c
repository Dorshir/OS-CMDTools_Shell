#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codecA.h"
#include "codecB.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <codec> <encoded_message>\n", argv[0]);
        exit(1);
    }

    char* codec_name = argv[1];
    char* encoded_text = argv[2];
    char decoded_text[1000];

    if (strcmp(codec_name, "codecA") == 0) {
        codecA_decode(encoded_text, decoded_text);
    } else if (strcmp(codec_name, "codecB") == 0) {
        codecB_decode(encoded_text, decoded_text);
    } else {
        fprintf(stderr, "Invalid codec name: %s\n", codec_name);
        exit(1);
    }

    printf("Decoded text: %s\n", decoded_text);

    return 0;
}