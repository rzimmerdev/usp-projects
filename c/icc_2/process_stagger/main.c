/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 21/11/2021
 *  Project for Introduction to Computer Science II - SCC0201, "Trabalho 03: Simulador de Escalonador"
*/

#include <stdio.h>
#include <stdlib.h>

#include "lib/algorithms/sorting.h"
#include "lib/algorithms/binary_search.h"

#include "lib/structures/linked_list.h"

typedef struct Process_t {

    int id;
    int starting_time;
    int remaining_time;
    int priority;

} process;

/*
 *  Function for comparing priorities between two processes, given void pointers
 *  If priorities are equal, prioritize the lowest id
 *
 *  @Input:
 *          void pointer to process objects: void *,
 *  @Return:
 *          1 if first process has lower priority
 *          0 if first process has bigger priority
 */
int compare_priorities(void *first, void *second);

/*
 *  Scan processes from stdin, returning array with ordered saved processes.
 *
 *  @Input:
 *          pointer to array size counter: int *,
 *  @Return:
 *          array of void pointers, containing all scanned processes: void **
 */
void **scan_processes(int *total_processes);

/*
 *  Allocates memory for process struct, and inserts process into end of process array,
 *  reallocating memory for new pointer.
 *  Increments process_id until no other process has the same id in process_array
 *
 *  @Input:
 *         pointer to array of void pointers to process structs: void ***,
 *         pointer to total elements in array: int *,
 *         pointer to originally scanned process_id: int *
 */
void create_process(void ***process_array, int *total_processes, int *processes_id);

/*
 *  Executes first process at header in core, and printing current clock
 *  and process id if finished executing (no execution time remaining)
 *
 *  @Input:
 *         core list to step: linked_list *,
 *         total elements of list: int,
 */
void step_core(linked_list *core, const int *clock);

int main() {

    int total_processes = 0;
    void **all_processes = scan_processes(&total_processes);

    linked_list *core = create_list();

    int processes_queued = 0;
    int clock = 0;

    // Keep stepping core if not empty, or while any processes left in input plan
    while(view_header(core) || processes_queued < total_processes) {

        // For any processes queued with starting time before current clock, insert
        // into correct position, based on process priority in core
        while (processes_queued < total_processes &&
               ((process *) *(all_processes + processes_queued))->starting_time <= clock) {

            add_node(core, *(all_processes + processes_queued), compare_priorities);
            processes_queued++;
        }

        clock++;

        if (view_header(core)) {
            step_core(core, &clock);
            increment_header(core);
        }
    }

    free(all_processes);
    free_list(core, free);

    return 0;
}

int compare_starting_time(void *first, void *second) {
    if (((process *) first)->starting_time < ((process *) second)->starting_time) {
        return 1;
    } else if (((process *) first)->starting_time == ((process *) second)->starting_time) {
        if (((process *) first)->priority > ((process *) second)->priority) {
            return 1;
        } else if (((process *) first)->priority == ((process *) second)->priority) {
            return (((process *) first)->id < ((process *) second)->id);
        }
    }

    return 0;
}

int compare_priorities(void *first, void *second) {

    if (((process *) first)->priority < ((process *) second)->priority) {
        return 1;
    } else if (((process *) first)->priority == ((process *) second)->priority) {
        return ((process *) first)->id > ((process *) second)->id;
    }

    return 0;
}

void **scan_processes(int *total_processes) {
    *total_processes = 0;
    void **all_processes = malloc(*total_processes * sizeof(process *));
    int *processes_id = malloc(sizeof(int));

    int all_inputs_read;

    // Scan current line until last character read is at EOF
    do {
        processes_id = realloc(processes_id, (*total_processes + 1) * sizeof(int));
        create_process(&all_processes, total_processes, processes_id);

        char new_line;
        all_inputs_read = scanf("%c", &new_line);
        if (new_line == '\r') getchar();

    } while (all_inputs_read != EOF);

    merge_sort(all_processes, *total_processes, compare_starting_time);

    free(processes_id);

    return all_processes;
};

void create_process(void ***process_array, int *total_processes, int *processes_id) {

    process *new_process = malloc(sizeof(process));

    scanf("%d %d %d %d", &new_process->id, &new_process->starting_time,
          &new_process->remaining_time, &new_process->priority);

    // Use binary search to find if id already exists in sorted array of processes id's.
    while (binary_search(processes_id, *total_processes, 0, new_process->id) != -1) {
        new_process->id += 1;
    }

    processes_id[*total_processes] = new_process->id;
    insertion_sort(processes_id, *total_processes);

    *process_array = realloc(*process_array, ++(*total_processes) * sizeof(process *));
    *(*process_array + (*total_processes) - 1) = new_process;
}

void step_core(linked_list *core, const int *clock) {
    process *current_process = ((process *) view_header(core));
    current_process->remaining_time--;
    if (current_process->remaining_time == 0) {
        printf("%d %d\n", current_process->id, *clock - 1);
        remove_header(core, free);
    }
}
