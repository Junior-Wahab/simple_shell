#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>

// The updated struct definition
typedef struct info {
    int readfd;
} info_t;

// Checks if the shell is in interactive mode
bool interactive(info_t *info) {
    return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

// Checks if a character is a delimiter
bool is_delim(char c, const char *delim) {
    while (*delim) {
        if (*delim++ == c) {
            return true;
        }
    }
    return false;
}

// Checks if a character is alphabetic
bool is_alpha(int c) {
    return isalpha(c);
}

// Converts a string to an integer
int atoi(const char *s) {
    return atoi(s);
}
