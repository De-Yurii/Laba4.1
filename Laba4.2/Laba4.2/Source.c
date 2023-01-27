#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <time.h>
void get_time(FILE* log_file) {
    time_t now = time(NULL);
    struct tm* local_time = localtime(&now);
    now = time(NULL);
    local_time = localtime(&now);
    int hours = local_time->tm_hour;


    fprintf(log_file, "[%d.", local_time->tm_year + 1900);
    if ((local_time->tm_mday) < 10) {
        fprintf(log_file, "0%d.", local_time->tm_mday);
    }
    else {
        fprintf(log_file, "%d.", local_time->tm_mday);
    }
    if ((local_time->tm_mon + 1) < 10) {
        fprintf(log_file, "0%d ", local_time->tm_mon + 1);
    }
    else {
        fprintf(log_file, "%d ", local_time->tm_mon + 1);
    }
    fprintf(log_file, "%d:", local_time->tm_hour);
    if (local_time->tm_min < 10) {
        fprintf(log_file, "0%d:", local_time->tm_min);

    }
    else {
        fprintf(log_file, "%d:", local_time->tm_min);
    }

    if (local_time->tm_sec < 10) {
        fprintf(log_file, "0%d]", local_time->tm_sec);

    }
    else {
        fprintf(log_file, "%d] ", local_time->tm_sec);
    }
}
int main(void) {
    FILE* file;
    FILE* log_file;
    double x, y;
    char string_file[100] = { 0 };
    char format;
    log_file = fopen("log.txt", "a");
    if (log_file == NULL) {
        printf("Can't open an log_file");
    }
    else {
        get_time(log_file);
        fprintf(log_file, " Program start\n");
        printf("Enter your input file: ");
        gets(string_file);
        printf("Enter format of result(b or t): ");
        scanf("%c", &format);
        char* ptr = string_file;

        
        file = fopen(ptr, "rb");
        if (file == NULL) {
            get_time(log_file);
            fprintf(log_file, " Can't open an input file\n");
            printf(" Can't open an input file");
        }
        else {
            fread(&x, sizeof(double), 1, file);
            get_time(log_file);
            fprintf(log_file, " Opening %s file. Parametrs: X = %lf\n", string_file, x);
            y = sqrt(x) - x / (x + 1) + 0.2 * x;
            if (x >= 0) {
                
                if (format == 'b') {
                    FILE* output = fopen("output.bin", "w");
                    get_time(log_file);
                    fprintf(log_file, " Result is %lf\n", y);
                    fwrite(&y, sizeof(float), 1, output);
                    get_time(log_file);
                    fprintf(log_file, " Output file output.bin saved\n");
                    fclose(output);
                }
                else if (format == 't') {
                    FILE* output = fopen("output.txt", "w");
                    get_time(log_file);
                    fprintf(log_file, " Result is %lf", y);
                    fprintf(output, "%f", y);
                    get_time(log_file);
                    fprintf(log_file, " Output file output.txt saved\n");
                    fclose(output);
                }
            }
            else {
                get_time(log_file);
                fprintf(log_file, " Incorect input, program crash\n");
            }
            get_time(log_file);
            fprintf(log_file, " Program end\n");
            fclose(file);
            fclose(log_file);
        }    
    }
    return 0;
}