#define INVALID_FLAG -1
#define PARSE_FAILED -1
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
  bool flagB;
  bool flagE;
  bool flagN;
  bool flagS;
  bool flagT;
  bool flagV;
} Flags;
int parse_arguments(int argc, char **argv, Flags *flags, char ***files,
                    int *files_count);
int parse_flags(int argc, char **argv, Flags *flags);
int parse_filenames(int argc, char **argv, char **files);