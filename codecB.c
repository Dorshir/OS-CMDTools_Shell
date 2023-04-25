#include "codecB.h"

void codecB_encode(char* text, char* encoded_text) {
    int i = 0;
    while (text[i] != '\0') {
        encoded_text[i] = text[i] + 3;  // Add 3 to the ASCII value of the char
        i++;
    }
    encoded_text[i] = '\0';
}

void codecB_decode(char* encoded_text, char* text) {
    int i = 0;
    while (encoded_text[i] != '\0') {
        text[i] = encoded_text[i] - 3;  // Subtract 3 from the ASCII value of the char
        i++;
    }
    text[i] = '\0';
}
