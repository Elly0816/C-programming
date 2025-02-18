#include <stdio.h>

int main()
{
    int course_start_hour = 9, course_end_hour = 11;

    char courses[] = " Software Development - Learn programming languages, databases, and web development.\n Networking & Cybersecurity - Understand the backbone of secure systems.\n Mobile & Web App Development - Build real-world applications.\n Artificial Intelligence & Data Science - Explore the future of technology.";
    char name[] = "Michael";
    char advice[] = " Be Consistent - Coding requires daily practice. Stay engaged and apply what you learn.\n Ask Questions - Don't hesitate to seek help from your instructors and peers.\n Work on Projects - Build real applications to solidify your skills.\n Network & Collaborate - Connect with fellow students and professionals in the field.\n Stay Curious & Keep Learning - Technology evolves rapidly; stay updated!";
    // printf("Dear sir/ma, \n\tI am \"Elly\", and I'm writing to apply for a scholarship at Aptech");
    printf("Welcome to Aptech! Congratulations on Your New Journey\n\n");
    printf("Dear %s,\n", name);
    printf("\tCongratulations on joining Aptech! You're about to embark on an exciting journey into the world of technology, and we're thrilled to have you on board.\n\n");
    printf("Your Courses & Lecture Schedule:\n\n");
    printf("As a new student, you'll be diving into: \n%s\n\n", courses);
    printf("Your lectures will be held from %d AM to %d AM (Monday to Friday), so be sure to manage your time effectively.\n\n", course_start_hour, course_end_hour);
    printf("Advice for Success at Aptech:\n%s\n\n", advice);
    printf("Wishing you a fantastic learning experience ahead! If you ever need guidance, feel free to reach out.\n\n");
    printf("Best regards,");
    printf("\nEleazar.");

    return 0;
}