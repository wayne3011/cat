#include "flag_handlers.h"
void t_flag_handle() {
  putchar('^');
  putchar('I');
}

void e_flag_handle() { putchar('$'); }
void s_flag_handle(int ch, bool *skip) {
  if (ch == '\n' && *skip == 0)
    *skip = 1;
  else if (ch != '\n')
    *skip = 0;
}
void nb_flag_handle(bool flagB, int ch, int *line) {
  if (!flagB || ch != '\n') {
    printf("%6d\t", *line);
    (*line)++;
  }
}

void v_flag_handle(int *ch) {
  if (!isascii(*ch) && !isprint(*ch)) {
    putchar('M');
    putchar('-');
    *ch = toascii(*ch);
  }
  if (iscntrl(*ch)) {
    putchar('^');
    if (*ch == '\177')
      *ch = '?';
    else
      *ch = *ch + 64;
  }
}
