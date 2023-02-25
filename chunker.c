#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>

#ifdef __APPLE__
    #define PRINTF_FMT "%016llx,%zu\n"
    #define PRINTF_CAST (unsigned long long)
#else
    #define PRINTF_FMT "%016lx,%zu\n"
    #define PRINTF_CAST (unsigned long)
#endif

#define FINGERPRINT_LENGTH 8

// Efficient non-cryptographic fingerprinting function
void fingerprint(const uint8_t *data, char *fingerprint) {
    memset(fingerprint, 0, FINGERPRINT_LENGTH);

    uint64_t hash = 5381;
    int c;
    while ((c = *data++))
        hash = ((hash << 5) + hash) + c;

    memcpy(fingerprint, &hash, sizeof(uint64_t));
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <chunk size>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Parse chunk size from command line argument
    int chunk_size = atoi(argv[1]);
    if (chunk_size <= 0) {
        fprintf(stderr, "Chunk size must be at least 1\n");
        exit(EXIT_FAILURE);
    }

    // Allocate buffer to hold input data
    uint8_t *buffer = (uint8_t *) malloc(chunk_size);
    if (buffer == NULL) {
        fprintf(stderr, "Failed to allocate memory for buffer\n");
        exit(EXIT_FAILURE);
    }

    // Process input data in chunks
    size_t bytes_read;
    char fp[FINGERPRINT_LENGTH];
    while ((bytes_read = fread(buffer, 1, chunk_size, stdin)) > 0) {
        fingerprint(buffer, fp);
        printf(PRINTF_FMT, PRINTF_CAST *((uint64_t *)fp), bytes_read);
    }

    free(buffer);

    return 0;
}