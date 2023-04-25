#include "codecA.h"

void codecA_encode(char* text, char* encoded_text) {
    int i = 0;
    while (text[i] != '\0') {
        if (islower(text[i])) {
            encoded_text[i] = toupper(text[i]);
        } else if (isupper(text[i])) {
            encoded_text[i] = tolower(text[i]);
        } else {
            encoded_text[i] = text[i];
        }
        i++;
    }
    encoded_text[i] = '\0';
}

void codecA_decode(char* encoded_text, char* text) {
    codecA_encode(encoded_text, text);  // Since codecA is reversible, decoding is the same as encoding
}
