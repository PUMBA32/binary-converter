#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define LENGTH 100

int main(void)
{
    for(;;) {
        char choice;
        char c;
        char str_number[LENGTH];
        int len;

        // getting number
        printf("\n\nEnter number:\n");
        for(len = 0; (c = getchar()) != '\n'; len++)
            str_number[len] = c;
        str_number[len] = '\0';
        printf("\n");

        printf("[1] - to decimal\n[2] - to binary\n[3] - exit;\n");
        scanf("%c", &choice);

        if(choice == '1') {  // from binary to decimal (2 -> 10)
            int result = 0;
            
            // converting number
            for (int i = len-1, n = 0; i >= 0; i--, n++) 
                if((str_number[i] - '0') == 1) 
                    result += pow(2, n);
                
            printf("\nResult: %d", result);
        }
        else if(choice == '2') {  // from decimal to binary (10 -> 2)
            int number = atoi(str_number);  // convert from STRING to INT
            int result_len = 0;
            char result[LENGTH];

            // converting number
            while(number > 0) {
                result[result_len++] = number % 2;
                number -= (number % 2 == 0) ? 0 : 1;
                number /= 2;
            }
            result[result_len] = '\0';

            // displaying converted number
            printf("\n\nResult:");
            for (int i = result_len-1; i >= 0; i--)
                printf("%d", result[i]);
        }
        else { 
            break;
        }
        while(getchar() != '\n');
    }
    return 0;
}

