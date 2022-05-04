#include <stdio.h>

#ifndef ARQ_PERSON_H
#define ARQ_PERSON_H

typedef struct Person_t person;

/*
 * Total size in bytes of person structure.
 *
 * @return: Integer sum of each field size in bytes.
 */
int person_size();

/*
 * Prints person information from inputted pointer to person struct.
 *
 * @params:
 *          person *to_print: Pointer to Person_t with fields to be printed.
 */
void print_person(person *to_print);

/*
 * Scans a single person from stdin into a new person pointer,
 * as well as scanning each individual field and filling user info.
 *
 * @return: Pointer to scanned person.
 */
person *scan_person();

/*
 * Reads and allocates memory for a new person, as well as
 * person field information from given file pointer.
 *
 * @params:
 *          FILE *fp: Pointer to file from which to read person from,
 *                    at any file stream offset.
 * @return: Pointer to read person from file.
 */
person *read_person(FILE *fp);

/*
 * Uses func:write_str to write each individual person field, filling
 * remaining space with empty characters into specified file, as well
 * as writting age to a 4-byte space.
 *
 * @params:
 *          person *new_person: Person_t pointer from which to get every field pointer
 *                              from, as to be written to file.
 *          FILE *fp: File pointer at specific offset to write each field at.
 */
void write_person(person *new_person, FILE *fp);

/*
 * Gets total number of registries of the Person_t type (with fixed byte size)
 * currently stored inside the given file.
 *
 * @params:
 *          FILE *fp: File pointer to get total size in bytes from, and
 *                    divide by total size of Person_t registry.
 * @return: Total count of registries in file.
 */
int get_total_registers(FILE *fp);

#endif //ARQ_PERSON_H
