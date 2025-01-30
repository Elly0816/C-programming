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
    int even_count=0, odd_count=0, number_to_count_from;

    printf("\n\n\nEnter the number you want to count to:\n");
    scanf("%d", &number_to_count_from);

    for(int i=1; i<=number_to_count_from; i++){
        if(i%2==0){
            even_count++;
        } else if(i%2==1){
            odd_count++;
        }
    }

    printf("The number of even numbers is:%d\nWhile the number of odd numbers is:%d", even_count, odd_count);
}

int main(){
    tempChecker();
    even_or_odd();
  


    return 0;
}
