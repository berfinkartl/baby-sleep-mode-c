#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CONTACTS 100
#define MAX_MSG 256

// ---------------- STRUCTS ----------------
typedef struct {
    char name[50];
    char phone[20];
} Contact;

// ---------------- GLOBAL VARIABLES ----------------
Contact contacts[MAX_CONTACTS];
int contact_count = 0;

char messageTemplate[MAX_MSG] = "Baby is sleeping. I will call you later.";

// ---------------- FUNCTION DECLARATIONS ----------------
void addContact();
void listContacts();
void updateMessageTemplate();
void activateBabySleepMode();
void saveContactsToFile();
void loadContactsFromFile();
void saveTemplateToFile();
void loadTemplateFromFile();

// ---------------- MAIN MENU ----------------
int main() {
    loadContactsFromFile();
    loadTemplateFromFile();

    int choice;

    while (1) {
        printf("\n===== Baby Sleep Mode System =====\n");
        printf("1. Add Contact\n");
        printf("2. List Contacts\n");
        printf("3. Update Message Template\n");
        printf("4. Activate Baby Sleep Mode\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar(); // buffer clear

        switch (choice) {
            case 1: addContact(); break;
            case 2: listContacts(); break;
            case 3: updateMessageTemplate(); break;
            case 4: activateBabySleepMode(); break;
            case 5:
                saveContactsToFile();
                saveTemplateToFile();
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option.\n");
        }
    }
}

// ---------------- FUNCTIONS ----------------

// Add contact
void addContact() {
    if (contact_count >= MAX_CONTACTS) {
        printf("Contact list full!\n");
        return;
    }

    printf("Enter name: ");
    fgets(contacts[contact_count].name, 50, stdin);
    contacts[contact_count].name[strcspn(contacts[contact_count].name, "\n")] = 0;

    printf("Enter phone: ");
    fgets(contacts[contact_count].phone, 20, stdin);
    contacts[contact_count].phone[strcspn(contacts[contact_count].phone, "\n")] = 0;

    contact_count++;
    printf("Contact added successfully.\n");
}

// List contacts
void listContacts() {
    printf("\n--- Contact List ---\n");
    if (contact_count == 0) {
        printf("No contacts saved.\n");
        return;
    }
    for (int i = 0; i < contact_count; i++) {
        printf("%d) %s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

// Update message template  **(NEW)**
void updateMessageTemplate() {
    printf("\nCurrent message template:\n");
    printf("\"%s\"\n", messageTemplate);

    printf("\nEnter new message: ");
    fgets(messageTemplate, MAX_MSG, stdin);
    messageTemplate[strcspn(messageTemplate, "\n")] = 0;

    printf("Message template updated.\n");
}

// Activate baby sleep mode
void activateBabySleepMode() {
    printf("\n--- Baby Sleep Mode Activated ---\n");
    printf("Sending message to all contacts...\n\n");

    for (int i = 0; i < contact_count; i++) {
        printf("To %s (%s): %s\n", contacts[i].name, contacts[i].phone, messageTemplate);
    }
}

// Save contacts
void saveContactsToFile() {
    FILE *f = fopen("contacts.txt", "w");
    if (!f) return;

    for (int i = 0; i < contact_count; i++) {
        fprintf(f, "%s;%s\n", contacts[i].name, contacts[i].phone);
    }
    fclose(f);
}

// Load contacts
void loadContactsFromFile() {
    FILE *f = fopen("contacts.txt", "r");
    if (!f) return;

    char line[100];

    while (fgets(line, sizeof(line), f)) {
        line[strcspn(line, "\n")] = 0;

        char *name = strtok(line, ";");
        char *phone = strtok(NULL, ";");

        if (name && phone) {
            strcpy(contacts[contact_count].name, name);
            strcpy(contacts[contact_count].phone, phone);
            contact_count++;
        }
    }
    fclose(f);
}

// Save template
void saveTemplateToFile() {
    FILE *f = fopen("template.txt", "w");
    if (!f) return;

    fprintf(f, "%s", messageTemplate);
    fclose(f);
}

// Load template
void loadTemplateFromFile() {
    FILE *f = fopen("template.txt", "r");
    if (!f) return;

    fgets(messageTemplate, MAX_MSG, f);
    fclose(f);
}
