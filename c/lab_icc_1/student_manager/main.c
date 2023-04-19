// Rafael Zimmer, n12542612
// Project for Introduction Lab for CompSci - Adding Padding to Centered Image
// 26/07/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct containing basic info about students
typedef struct {

	int id;
	char *name;
	int course_id;
	int age;

} Student;

char *read_line();

int get_course_id(char **courses, int total_courses, char *course_name);
int add_course(char ***courses, int *total_courses, char *course_name);

Student get_student(Student *students, int total_students, int student_id);

int main() {

	// Dynamically allocate total number of students and name of courses
	int total_courses = 0;
	char **courses = malloc(total_courses * sizeof(char *));

	int current_id, total_students = 0;
	Student *students = (Student *) malloc(total_students * sizeof(Student));

	// Scan until end of new students inputs
	while (scanf("%d ", &current_id) && current_id != -1 ) {

		// Scan each attribute of student, as well as adding student course to list of courses
		char *current_name = read_line(); scanf(" ");
		char *current_course = read_line(); scanf(" ");
		int current_course_id = add_course(&courses, &total_courses, current_course);
		int current_age;
		scanf("%d ", &current_age);

		Student current_student = { .id = current_id, .name = current_name, .course_id = current_course_id, .age = current_age };

		students = realloc(students, ++total_students * sizeof(Student));
		students[total_students - 1] = current_student;

	}

	int command;

	// Scan until end of user inputted commands
	while (scanf("%d ", &command) && command != -1 ) {

		// Switch selected command, and print respective filtered output
		switch (command) {

			// In case command is to print specific student, filter by uuid (Unique user identifier)
			case (1): {

				int search_id;
				scanf("%d ", &search_id);
				Student current_student = get_student(students, total_students, search_id);

				printf("Nome: %s\n", current_student.name);
				printf("Curso: %s\n", courses[current_student.course_id]);
				printf("N USP: %d\n", current_student.id);
				printf("IDADE: %d\n\n", current_student.age);

			} break;

			// In case command is to print all users under specific course, filter by course name
			case (2): {

				char *course_name = read_line(); scanf(" ");

				int course_id = get_course_id(courses, total_courses, course_name);
				free(course_name);

				for (int i = 0; i < total_students; i++) {

					if (students[i].course_id == course_id) {
						printf("Nome: %s\n", students[i].name);
						printf("Curso: %s\n", courses[course_id]);
						printf("N USP: %d\n", students[i].id);
						printf("IDADE: %d\n\n", students[i].age);
					}
				}

			} break;

			// Print all inputted users, without filters
			case (3): {

				for (int i = 0; i < total_students; i++) {

					printf("Nome: %s\n", students[i].name);
					printf("Curso: %s\n", courses[students[i].course_id]);
					printf("N USP: %d\n", students[i].id);
					printf("IDADE: %d\n\n", students[i].age);

				}

			} break;

		}
	}

	// Free dynamically allocated array for students, as well as students names
	for (int i = 0; i < total_students; i++) {
		free(students[i].name);
	} free(students);

	// Free dynamically allocated array for course names, as well as individual course names
	for (int i = 0; i < total_courses; i++) {
		free(courses[i]);
	} free(courses);

	return 0;

};

// Function for returning student information, filtering by uuid
//
// Parameters: array of listed students, number of students in array, int for user id
// Returns: Student struct
Student get_student(Student *students, int total_students, int student_id) {

	for (int i = 0; i < total_students; i++) {

		if (students[i].id == student_id) return students[i];

	} return students[-1];

}

// Function for returning id for course in course array, filtered by course name
//
// Parameters: array of course names, total number of course names in array, string for course name to filter by
// Returns: int for course id, representing its index in array, or -1 if not present in array
int get_course_id(char **courses, int total_courses, char *course_name) {

	for (int i = 0; i < total_courses; i++) {

		if (strcmp(course_name, courses[i]) == 0) return i;

	} return -1;

}

// Function implementing get_course_id to verify if course already exists in course names array, otherwise
// add course to end of course array, incrementing its size and return index of new course
//
// Parameters: pointer to array of courses, pointer to number of total courses, string for course name
// Returns: total_courses - 1, representing index of new course, or position of course in array, in case it exists
int add_course(char ***courses, int *total_courses, char *course_name) {

	if (get_course_id(*courses, *total_courses, course_name) == -1) {

		*courses = realloc(*courses, (++*total_courses) * sizeof(char *));
		(*courses)[*total_courses - 1] = course_name;
		return *total_courses - 1;

	} else return get_course_id(*courses, *total_courses, course_name);

}

char *read_line() {

	// Declare line array, with dynamic size
	char *line = NULL;
	char current_char = -1;

	int index = 0, string_size = 0;

	// Keep reading until current character is NULL character (set by program)
	while (current_char) {

		// Scan character and see if is EOF or \n, then stop reading line and add null character to end of string
		if (!scanf("%c", &current_char) || current_char == '\n' || current_char == '\r') {
			current_char = 0;
		}

		// Increment size only if increment does not overflow current indexing of characters
		if (string_size++ <= index) {
			line = ( char* ) realloc(line, string_size);

		}

		*(line + index++) = current_char;

	}

	// Return pointer to dynamically allocated string
	return line;
}