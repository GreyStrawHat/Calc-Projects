#ifndef RETURN_SOLVED_H
#define RETURN_SOLVED_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "equation_types.h"
#include "parse_solved_file.h"
#include "filecalc.h"

Solved_Equation *return_solved_struct(Unsolved_Equation *Equation, char *output_dir_arg);

#endif