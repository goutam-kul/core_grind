#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define task 
typedef struct Task {
    int id;
    char name[50];
    int priority;
    int duration;
    time_t created_time;
    struct Task *next;
} Task;

// Define priority queue 
typedef struct TaskScheduler {
    Task *head;
    int count;
} TaskScheduler;

// Function prameters
TaskScheduler* create_scheduler();
void destroy_scheduler(TaskScheduler *scheduler); 
Task* create_task(int id, const char *name, int priority, int duration);
void enqueue(TaskScheduler *scheduler, Task *task);
Task* dequeue(TaskScheduler *scheduler);
int is_empty(TaskScheduler *scheduler);
Task* peek_task(TaskScheduler *scheduler);
void display_queue(TaskScheduler* scheduler);
void execute_task(Task* task);
void interactive_mode();


// Create a new task scheduler 
TaskScheduler* create_scheduler() {
    TaskScheduler *scheduler = (TaskScheduler*)malloc(sizeof(TaskScheduler));
    if (!scheduler) {
        printf("Memory allocation failed for scheduler\n");
        return NULL;
    }

    scheduler->head = NULL;
    scheduler->count = 0;

    return scheduler;
}

// Create a new task 
Task* create_task(int id, const char *name, int priority, int duration) {
    Task *task = (Task*)malloc(sizeof(Task));
    if (!task) {
        printf("Memory allocation failed for task!\n");
        return NULL;
    }

    task->id = id;
    strncpy(task->name, name, sizeof(task->name) - 1);
    task->name[sizeof(task->name) -1] = '\0';
    task->priority = priority;
    task->duration = duration;
    task->created_time = time(NULL);
    task->next = NULL;

    return task;
}

// Add task to priority queue (sorted by priority, then by creation time) 
void enqueue(TaskScheduler *scheduler, Task *task) {
    if(!scheduler || !task) return;

    // If queue is empty or new task has higher priority than head
    if (!scheduler->head || scheduler->head->priority < task->priority ||
        (scheduler->head->priority == task->priority && scheduler->head->created_time > task->created_time)) {
            task->next = scheduler->head;
            scheduler->head = task;
    } else {
        // Find the correct position based on priority and created time 
        Task *current = scheduler->head;
        while (current->next && (current->next->priority > task->priority ||
            (current->next->priority == task->priority && task->next->created_time <= task->created_time))) {
                current = current->next;
        }
        task->next = current->next;
        current->next = task;
    }
    scheduler->count++;
    printf("✓ Task '%s' (ID: %d, priority: %d) added to queue", task->name, task->id, task->priority);
}

Task* dequeue(TaskScheduler *scheduler) {
    if(!scheduler || !scheduler->head) return NULL;

    Task *task = scheduler->head;
    scheduler->head = scheduler->head->next;
    scheduler->count--;
    task->next = NULL;

    return task;
}

// check if scheduler is empty 
int is_empty(TaskScheduler *scheduler) {
    return !scheduler || scheduler->count == 0;
}

// Clean up scheduler and all tasks 
void destroy_scheduler(TaskScheduler *scheduler) {
    if (!scheduler) return;

    while (!is_empty(scheduler)) {
        Task *task = dequeue(scheduler);
        if (task) {
            free(task);
        }
    }
    free(scheduler);
}

// Peek at the highest priority task without removing it 
Task* peek_task(TaskScheduler *scheduler) {
    if (!scheduler) return NULL;

    return scheduler->head;
}

// Display all tasks in the queue 
void display_queue(TaskScheduler *scheduler) {
    if (!scheduler) {
        printf("Scheduler not initialized\n");
        return;
    }

    if (is_empty(scheduler)) {
        printf("Scheduler is empty\n");
        return;
    }

    printf("\n Current Task Queue (%d tasks): \n", scheduler->count);
    printf("┌─────┬──────────────────────┬──────────┬──────────┬─────────────────────┐\n");
    printf("│ ID  │ Task Name            │ Priority │ Duration │ Created Time        │\n");
    printf("├─────┼──────────────────────┼──────────┼──────────┼─────────────────────┤\n");
    
    Task *current = scheduler->head;
    while (current) {
        char time_str[20];
        strftime(time_str, sizeof(time_str), "%H:%M:%S", localtime(&current->created_time));

        printf("| %-3d | %-20s | %-8d | %8d | %-19s |\n", 
            current->id, current->name, current->priority, current->duration, time_str);
        current = current->next;
    }
    printf("└─────┴──────────────────────┴──────────┴──────────┴─────────────────────┘\n");
}

// Simulate task execution 
void execute_task(Task* task) {
    if (!task) return;

    printf("\n Executin Task: %s (ID: %d)\n", task->name, task->id);
    printf("  Priority: %d | Duration: %ds\n", task->priority, task->duration);

    // Simulate work with a simple progress indicator
    printf("  Progress: [");
    for (int i = 0; i < 20; i++) {
        printf("█");
        fflush(stdout);
        // Do actual work here 
        // For now just simulating with small delay
        for (volatile int j = 0; j < 10000000; j++); // simple delay
    }
    printf("] complete!\n");
    printf("Task '%s' completed successfully\n", task->name);
}

void interactive_mode() {
    TaskScheduler *scheduler = create_scheduler();
    if (!scheduler) return;

    int choice, id = 1;
    char name[50];
    int priority, duration;

    printf("\n=== Interactive Task Scheduler ===\n");

    while (1) {
        printf("\n Task Scheduler Menu:\n");
        printf("1. Add task\n");
        printf("2. Execute next task\n");
        printf("3. View Queue\n");
        printf("4. Peek Next Task\n");
        printf("5. Exit\n");
        printf("Choose option (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter task name: ");
                scanf(" %99[^\n]", name);
                printf("Enter priority (1-5 higher = more urgent): ");
                scanf("%d", &priority);
                printf("Enter duration (seconds): ");
                scanf("%d", &duration);

                Task* task = create_task(id, name, priority, duration);
                if (task) {
                    enqueue(scheduler, task);
                }
                break;
            case 2:
                if (is_empty(scheduler)) {
                    printf("No tasks in the queue!\n");
                } else {
                    Task* task = dequeue(scheduler);
                    if (task) {
                        execute_task(task);
                        free(task);
                    }
                }
                break;
            case 3:
                display_queue(scheduler);
                break;
            case 4:
                if (is_empty(scheduler)) {
                    printf("NO tasks in queue!\n");
                } else {
                    Task* task = peek_task(scheduler);
                    printf("👁️  Next task: %s (ID: %d, Priority: %d)\n",
                           task->name, task->id, task->priority);
                }
                break;
            case 5:
                printf("Exiting scheduler...\n");
                destroy_scheduler(scheduler);
                return;
            default:
                printf("❌ Invalid choice! Please select 1-5.\n");
                break;
        }
    }
}

int main() {
    int mode;

    printf("Welcome to Priority Taks Scheduler!\n");
    printf("Choose mode: \n");
    printf("1. Demo Mode\n");
    printf("2. Interactive Mode\n");

    if (scanf("%d", &mode) != 1) {
        printf("Invalid input! Please enter 1-2\n");
        exit(1);
    }
    switch (mode) {
        case 1:
            // run_scheduler_demo();
            break;
        case 2:
            interactive_mode();
            break;
        default:
            printf("Invalid choice! Running demo mode.\n");
            // run_scheduler_demo();
    }
    return 0;
}