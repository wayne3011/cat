#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
void nb_flag_handle(bool flagB, int ch, int *line);
void s_flag_handle(int ch, bool *skip);
void e_flag_handle();
void t_flag_handle();
void v_flag_handle(int *ch);