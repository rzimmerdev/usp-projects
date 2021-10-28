#ifndef SHELL_SORT_SHELL_TOOLS_H
#define SHELL_SORT_SHELL_TOOLS_H

// Shell structure, containing shell diameter, color and texture
typedef struct shell Shell_t;

// Dynamically allocate shell type and scan in struct values
Shell_t *scan_shell();

// Print shell attributes to console
void print_shell(Shell_t *shell);

// Frees shell texture pointer, color pointer and shell type pointer
void free_shell(Shell_t *shell);

// Performs insertion sort on virtual sublists of shell_list,
// starting at sublist size = 2 (total lists = total_shells / 2) up to sublist size = total_shells
void shell_sort(Shell_t **shell_list, int total_shells);

#endif
