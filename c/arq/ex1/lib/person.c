#include <stdio.h>
#include <stdlib.h>
#include "string_tools.h"


typedef struct Person_t {

    char first_name[51];
    char last_name[51];
    char email[81];
    char nationality[51];
    int age;

} person;

/*
 * Total size in bytes of person structure.
 *
 * @return: Integer sum of each field size in bytes.
 */
int person_size() {
    int struct_size =
            sizeof((person *)0)->first_name +
            sizeof((person *)0)->last_name +
            sizeof((person *)0)->email +
            sizeof((person *)0)->nationality +
            sizeof(int);

    return struct_size;
}

/*
 * Prints person information from inputted pointer to person struct.
 *
 * @params:
 *          person *to_print: Pointer to Person_t with fields to be printed.
 */
void print_person(person *to_print) {

    printf("Firstname: %s\n"
           "Lastname: %s\n"
           "Email: %s\n"
           "Nationality: %s\n"
           "Age: %d\n",
           to_print->first_name,
           to_print->last_name,
           to_print->email,
           to_print->nationality,
           to_print->age
    );
}

/*
 * Scans a single person from stdin into a new person pointer,
 * as well as scanning each individual field and filling user info.
 *
 * @return: Pointer to scanned person.
 */
person *scan_person() {

    person *new_person = malloc(sizeof(person));

    scan_fixed(new_person->first_name);
    scan_fixed(new_person->last_name);
    scan_fixed(new_person->email);
    scan_fixed(new_person->nationality);
    scanf("%d ", &(new_person->age));

    return new_person;
}

/*
 * Reads and allocates memory for a new person, as well as
 * person field information from given file pointer.
 *
 * @params:
 *          FILE *fp: Pointer to file from which to read person from,
 *                    at any file stream offset.
 * @return: Pointer to read person from file.
 */
person *read_person(FILE *fp) {
    person *new_person = malloc(sizeof(person));

    read_fixed(new_person->first_name, sizeof(new_person->first_name), fp);
    read_fixed(new_person->last_name, sizeof(new_person->last_name), fp);
    read_fixed(new_person->email, sizeof(new_person->email), fp);
    read_fixed(new_person->nationality, sizeof(new_person->nationality), fp);
    fread(&new_person->age, sizeof(int), 1, fp);

    return new_person;
}

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
void write_person(person *new_person, FILE *fp) {

    write_fixed(new_person->first_name, sizeof(new_person->first_name), fp);
    write_fixed(new_person->last_name, sizeof(new_person->last_name), fp);
    write_fixed(new_person->email, sizeof(new_person->email), fp);
    write_fixed(new_person->nationality, sizeof(new_person->nationality), fp);
    fwrite(&(new_person->age), sizeof(int), 1, fp);
}

/*
 * Gets total number of registries of the Person_t type (with fixed byte size)
 * currently stored inside the given file.
 *
 * @params:
 *          FILE *fp: File pointer to get total size in bytes from, and
 *                    divide by total size of Person_t registry.
 * @return: Total count of registries in file.
 */
int get_total_registers(FILE *fp) {

    fseek(fp, 0, SEEK_END);
    int num_registers = ftell(fp) / person_size();
    fseek(fp, 0, SEEK_SET);

    return num_registers;
}