#include <err.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "arguments_parser.h"
#include "flag_handlers.h"

int cat_with_flags(FILE *fp, Flags flags);
void process_files(char **filenames, int files_count, Flags flags);

int main(int argc, char *argv[]) {
  Flags flags = {0, 0, 0, 0, 0, 0};
  char **filenames = NULL;
  int files_count = 0;
  int err = parse_arguments(argc, argv, &flags, &filenames, &files_count);
  if (err == PARSE_FAILED) return 1;
  process_files(filenames, files_count, flags);
  free(filenames);
}

void process_files(char **filenames, int files_count, Flags flags) {
  if (filenames == NULL) cat_with_flags(stdin, flags);
  for (int i = 0; i < files_count; i++) {
    if (strcmp(filenames[i], "-") == 0)
      cat_with_flags(stdin, flags);
    else {
      FILE *fp = fopen(filenames[i], "r");
      if (fp == NULL) {
        warn("%s", filenames[i]);
      } else {
        cat_with_flags(fp, flags);
        fclose(fp);
      }
    }
  }
}

int cat_with_flags(FILE *fp, Flags flags) {
  int ch, prev, line_number = 1;
  bool skip = false;

  if (fp == stdin && feof(fp)) clearerr(fp);

  for (prev = '\n'; (ch = getc(fp)) != EOF; prev = ch) {
    if (prev == '\n') {
      if (flags.flagS) {
        if (skip && ch == '\n') {
          continue;
        }
        s_flag_handle(ch, &skip);
      }
      if (flags.flagN) nb_flag_handle(flags.flagB, ch, &line_number);
    }
    if (ch == '\n') {
      if (flags.flagE) e_flag_handle();
      putchar('\n');
    } else if (ch == '\t') {
      if (flags.flagT)
        t_flag_handle();
      else
        putchar('\t');
    } else {
      if (flags.flagV) v_flag_handle(&ch);
      putchar(ch);
    }
  }
  return 0;
}