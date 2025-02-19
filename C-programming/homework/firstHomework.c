#include <stdio.h>


void tempChecker(){
      float temperature;

    printf("Enter the current temperature: \n");

    scanf("%f", &temperature);

    if(temperature <= 0){
        printf("The temperature is: %f\n Therefore it is Freezing", temperature);
    } else if (temperature > 0 && temperature <= 10){
        printf("The temperature is: %f\n Therefore it is Cold", temperature);
    } else if (temperature > 10 && temperature <= 25){
        printf("The temperature is: %f\n Therefore it is Warm", temperature);
    } else {
        printf("The temperature is: %f\n Therefore it is Hot", temperature);
    }

    return;
}



void even_or_odd(){
    int even_count=0, odd_count=0;
    int number_to_count_from[10];

    for(int i=0; i<10; i++){
        printf("\n\n\nEnter the numbers you want to count to:\n");
        scanf("%d", &number_to_count_from[i]);
    }



    for(int i=0; i<10; i++){
        if(number_to_count_from[i]%2==0){
            even_count++;
        } else if(number_to_count_from[i]%2==1){
            odd_count++;
        }
    }
    printf("The numbers you entered are:\n");
    for(int i=0; i<10; i++){
        printf("%d, ", number_to_count_from[i]);
    }
    printf("\nThe number of even numbers is:%d\nWhile the number of odd numbers is:%d", even_count, odd_count);
}

int main(){
    // tempChecker();
    even_or_odd();
  


    return 0;
}
