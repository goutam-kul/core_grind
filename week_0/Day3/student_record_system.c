#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100
#define NUM_GRADES 3
#define NUM_STUDENTS 1

typedef struct {
    char name[MAX_NAME];
    int id;
    float grades[NUM_GRADES];
} Student;

void input_student(Student *student);
void save_students(Student *students, int count, const char *filename);
void load_students(Student *students, int count, const char *filename);
int is_valid_grade(float grade);
void display_student(Student *student);

int main() {
    Student students[NUM_STUDENTS];
    
    // Take NUM_STUDENTS inputs 
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("\nStudent %d:\n", i + 1);
        input_student(&students[i]);
    }
    
    // Save the records 
    const char filename[30];
    printf("Enter file name to load/save students: ");
    scanf("%s", filename);
    save_students(students, NUM_STUDENTS, filename);

    // clear student array and simulate loading from file 
    memset(students, 0, sizeof(students));

    // Load and display students from file
    printf("Loading records from %s...\n", filename); 
    load_students(students, NUM_STUDENTS, filename);

    // Display the loaded records 
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("\nStudent: %d\n", i + 1);
        display_student(&students[i]);
    }

    return 0;
}

void input_student(Student *student) {
    printf("Enter name (max 100 characters): ");
    fgets(student->name, MAX_NAME, stdin);
    // Remove new line characters if present 
    student->name[strcspn(student->name, "\n")] = '\0';

    do {
        printf("Enter id (positive integer): ");
        scanf("%d", &student->id);
        if (student->id <= 0) {
            printf("Error: Id must be a positive integer\n");
        }
    } while (student->id <= 0);
    // clear buffer 
    getchar();

    for (int i = 0; i < NUM_GRADES; i++) {
        do {
            printf("Enter grade %d [0-100]: ", i + 1);
            scanf("%f", &student->grades[i]);
            if (!is_valid_grade(student->grades[i])) {
                printf("Error: grade must be between 0 and 100\n");
            }
        } while (!is_valid_grade(student->grades[i]));  
    }
    while (getchar() != '\n');
}

void save_students(Student *students, int count, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: File does not exist.\n");
        exit(1);
    }

    size_t written = fwrite(students, sizeof(Student), count, file);
    if (written != count) {
        printf("Error: Couldn't load all records.\n");
        fclose(file);
        exit(1);
    }

    printf("Successfully saved %d records from %s\n", count, file);
    fclose(file);
}

void load_students(Student *students, int count, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: File does not exist\n");
        exit(1);
    }

    size_t read = fread(students, sizeof(Student), count, file);
    if (read != count) {
        printf("Error: Could not read all records.\n");
        fclose(file);
        exit(1);
    }

    printf("Successfully loaded %d records from %s\n", count, file);
    fclose(file);
}

void display_student(Student *student) {
    printf("Name: %s |", student->name);
    printf("ID: %d |", student->id);
    for (int i = 0; i < NUM_GRADES; i++) {
        printf("Grade %d: %.2f |", i + 1, student->grades[i]);
    }
}

int is_valid_grade(float grade) {
    return grade >= 0 && grade <= 100; 
}