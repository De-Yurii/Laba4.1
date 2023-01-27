#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void) {
	char smbls[] = { 'A', 'E', 'I', 'O', 'U', 'Y' };
	int freq_of_use[6] = { 0 };

	char some[100];
	printf("Enter your sentence: ");
	fgets(some, 100, stdin);
	
	int length = strlen(some);
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < 6; j++) {
			if (toupper(some[i]) == smbls[j]) {
				freq_of_use[j] += 1;
			}

		}
	}
	printf("\n");
	printf("Frequency of loud letters: \n");

	// Frequency only loud
	int suma = 0;
	for (int i = 0; i < 6; i++) {
		suma += freq_of_use[i];
	}
	float frequency_list[6] = { 0 };
	float frequency;
	for (int i = 0; i < 6; i++) {

		frequency = 1.0 * freq_of_use[i] / suma;
		frequency_list[i] = frequency;

	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5 - i; j++)
		{
			if (frequency_list[j + 1] > frequency_list[j])
			{
				frequency_list[j] = frequency_list[j] + frequency_list[j + 1];
				frequency_list[j + 1] = frequency_list[j] - frequency_list[j + 1];
				frequency_list[j] = frequency_list[j] - frequency_list[j + 1];
				smbls[j] = smbls[j] + smbls[j + 1];
				smbls[j + 1] = smbls[j] - smbls[j + 1];
				smbls[j] = smbls[j] - smbls[j + 1];
			}
		}
	}
	for (int i = 0; i < 21; i++) {
		printf("=");
	}
	printf("\n");
	for (int i = 0; i < 6; i++) {
		printf("| %c | %12f || \n", smbls[i], frequency_list[i]);
	}
	for (int i = 0; i < 21; i++) {
		printf("=");
	}
	return 0;
}

