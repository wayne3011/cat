#include "arguments_parser.h"
int parse_arguments(int argc, char **argv, Flags *flags, char ***files,
                    int *files_count) {
  if (parse_flags(argc, argv, flags) == INVALID_FLAG) {
    printf("usage: cat [-benstv] [file ...]");
    return PARSE_FAILED;
  }

  if (optind < argc) {
    *files_count = argc - optind;
    *files = malloc(sizeof(char *) * (*files_count));
    parse_filenames(argc, argv, *files);
  } else {
    *files = NULL;
  }
  return 0;
}
int parse_flags(int argc, char **argv, Flags *flags) {
  int c;
  int long_option_index = 0;

  while (1) {
    static struct option long_opts[] = {{"number-nonblank", 0, 0, 'b'},
                                        {"number", 0, 0, 'n'},
                                        {"squeeze-blank", 0, 0, 's'},
                                        {0, 0, 0, 0}};
    c = getopt_long(argc, argv, "+bEensTtv", long_opts, &long_option_index);
    if (c == -1) break;
    switch (c) {
      case 'b':
        flags->flagB = true;
        flags->flagN = true;
        break;
      case 'E':
        flags->flagE = true;
        break;
      case 'e':
        flags->flagE = true;
        flags->flagV = true;
        break;
      case 'n':
        flags->flagN = true;
        break;
      case 's':
        flags->flagS = true;
        break;
      case 'T':
        flags->flagT = true;
        break;
      case 't':
        flags->flagT = true;
        flags->flagV = true;
        break;
      case 'v':
        flags->flagV = true;
        break;
      default:
        return INVALID_FLAG;
    }
  }
  return 0;
}
int parse_filenames(int argc, char **argv, char **files) {
  int i = 0;
  while (optind < argc) {
    files[i] = argv[optind++];
    i++;
  }
  return 0;
}