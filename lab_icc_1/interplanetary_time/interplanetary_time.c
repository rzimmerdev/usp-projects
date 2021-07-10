// Rafael Zimmer, 12542612

#include <stdio.h>

int main() {

	long int time;
	char planet[10];

	scanf("%ld %s", &time, planet);

	// Define reference variables, for referencing Earth default values
	int ref_days = (24 * 60 * 60), ref_hours = (60 * 60), ref_minutes = (60);

	// Switch specific planet time references
	switch (planet[0]) {
		case 'J':
			ref_days = 9 * ref_hours + 56 * ref_minutes;
			break;
		case 'V':
			ref_days = 243 * ref_days;
			break;
		case 'M':
			ref_days = 58 * ref_days + 16 * ref_hours;
			break;
	}

	printf("%ld segundos no planeta %s equivalem a:\n", time, planet);

	// Print formatted output
	int days = (int) (time / ref_days);
	int hours = (int) (time % ref_days) / ref_hours;
	int minutes = (int) ((time % ref_days) % ref_hours) / ref_minutes;
	int seconds = (int) ((time % ref_days) % ref_hours) % ref_minutes;
	printf("%d dias, %d horas, %d minutos e %d segundos", days, hours, minutes, seconds);

	return 0;
}