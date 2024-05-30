/**
 * Ввести номер месяца и вывести название времени года.
 * **/ 

#include <stdio.h>

int main() {
    int month;
    if ( 1 != scanf("%d", &month) ) {
        printf("Error");
        return 1;
    }

    char const *season;
    switch(month) {
        case 1:
        case 2:
        case 12:
            season = "winter";
            break;

        case 3:
        case 4:
        case 5:
            season = "spring";
            break;

        case 6:
        case 7:
        case 8:
            season = "summer";
            break;

        case 9:
        case 10:
        case 11:
            season = "autumn";
            break;
        
        default:
            printf("Error");
            return 2;
    }
    printf("%s\n", season);
    return 0;
}