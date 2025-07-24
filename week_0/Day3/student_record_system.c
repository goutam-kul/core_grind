#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_GPA 4.0
#define NUM_STUDENTS 5

typedef struct {
    char name[MAX_NAME];
    int roll;
    int semester;
    float gpa;
} Student;

// function prototypes 
void input_student(Student *student);
void save_students(Student *students, int count, const char *filename);
void load_students(Student *student, int count, const char *filename);
void display_student(const Student *student);
void clear_input_buffer();
int is_valid_gpa(float gpa);

int main() {
    Student students[NUM_STUDENTS];

    // Input 5 student records
    printf("Enter details for %d students:\n", NUM_STUDENTS);
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("\nStudent %d: \n", i);
        input_student(&students[i]);
    }

    // Save students to file
    const char filename[100];
    printf("Enter filename to save/load students: ");
    scanf("%s", filename);
    save_students(students, NUM_STUDENTS, filename);

    // Clear students array & simulate loading from file 
    memset(students, 0, sizeof(students));

    // Load and display students from file
    printf("Loading students from %s...\n", filename);
    load_students(students, NUM_STUDENTS, filename);

    // Display loaded students 
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("\nStudents: %d\n", i);
        display_student(&students[i]);
    }
    return 0;
}

void input_student(Student *student) {
    printf("Enter name (max %d characters): ",MAX_NAME - 1);
    
    // Consume buffer 
    // clear_input_buffer();
    fgets(student->name, MAX_NAME, stdin);
    // Remove new line character if present
    student->name[strcspn(student->name, "\n")] = '\0';

    do {
        printf("Enter roll (positive integer): ");
        scanf("%d", &student->roll);
        if (student->roll <= 0) {
            printf("Error: Roll number must positive\n");
        }
    } while (student->roll <= 0);

    getchar();

    do {
        printf("Enter semester (positive integer): ");
        scanf("%d", &student->semester);
        if (student->semester <= 0) {
            printf("Error: Semester must be positive\n");
        }
    } while (student->semester <= 0);

    getchar();

    do {
        printf("Enter GPA: ");
        scanf("%f", &student->gpa);
        if (!is_valid_gpa(student->gpa)) {
            printf("Error: GPA must be between 0 and 4\n");;
        }
    } while (!is_valid_gpa(student->gpa));
    getchar();
}

void save_students(Student *students, int count, const char* filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: Could not open file %s for writing\n", filename);
        exit(1);
    }

    size_t written = fwrite(students, sizeof(Student), count, file);
    if (written != count) {
        printf("Error: Failed to write all student records\n");
        fclose(file);
        exit(1);
    }

    printf("Successfully saved %d students to %s\n", count, filename);
    fclose(file);
}

void load_students(Student *students, int count, const char* filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL){
        printf("Error: Could not open file %s for reading.\n",filename);
        exit(1);
    }
    size_t read = fread(students, sizeof(Student), count, file);
    if (read != count) {
        printf("Error: Failed to read all the records\n");
        fclose(file);
        exit(1);
    }

    printf("Successfully loaded %d students from %s.\n", count, filename);
    fclose(file);
}

void display_student(const Student *student) {
    printf("Name: %s |", student->name);
    printf("Roll: %d |", student->roll);
    printf("Semester: %d |", student->semester);
    printf("GPA: %f |", student->gpa);
}

int is_valid_gpa(float gpa) {
    return gpa > 0.0 && gpa <= 4.0;
}

// void clear_input_buffer() {
//     int c;
//     while ((c = getchar() != '\n' &&  c!= EOF));
// }