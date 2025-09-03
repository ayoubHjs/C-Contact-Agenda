/*
    Contact Agenda
    ----------------------
    A simple contact management program written in C.

    Author: [Sandra Martin Elias]
    Date: [2025/09/01]
*/

#include <stdio.h>

// Define the contact structure
struct contactAgenda{
    char name[100];
    char phone[20];
    char email[100];
};

// Function prototypes
void showContacts(int numContacts, struct contactAgenda contacts[]);
void addContact(struct contactAgenda contacts[], int* numContacts, int maxContacts);
void deleteContact(struct contactAgenda contacts[], int* numContacts);
void clearInputBuffer();

int main() {
    int numContacts=0, maxContacts=100, choice;
    struct contactAgenda contacts[maxContacts];
    
    // Main menu loop
    while(1){
        printf("----- Contact Agenda Menu -----\n");
        printf("1. Show all Contacts\n");
        printf("2. Add a Contact\n");
        printf("3. Delete a Contact\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%i", &choice);
        clearInputBuffer(); // Clear input buffer to avoid issues with scanf

        // Handle user choice
        switch (choice)
        {
            case 1:
                showContacts(numContacts, contacts); // Show all contacts
                break;
            case 2:
                addContact(contacts, &numContacts, maxContacts); // Add a new contact
                break;
            case 3:
                deleteContact(contacts, &numContacts); // Delete a contact
                break;
            case 4:
                printf("Exiting. Thank you for using the Contact Agenda!\n"); 
                return 0; // Exit the program
            default:
                printf("Invalid option. Please try again.\n"); // Handle invalid input
                break;
        }
    }
}

void showContacts(int numContacts, struct contactAgenda contacts[]) { // Display all contacts
    if (numContacts==0) {
        printf("No contacts available.\n");
    } else {
        for (int i=0;i<numContacts;i++) {
            printf("Contact %d:\n", i+1);
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            printf("-----------------------\n");
        }
    }
}

void addContact(struct contactAgenda contacts[], int* numContacts, int maxContacts) { // Add a new contact
    if (*numContacts >= maxContacts) {
        printf("Contact list is full!\n");
        return;
    }

    // Get contact details from user
    printf("Enter contact name: ");
    scanf(" %[^\n]", contacts[*numContacts].name);
    clearInputBuffer();

    printf("Enter contact phone: ");
    scanf(" %[^\n]", contacts[*numContacts].phone);
    clearInputBuffer();

    printf("Enter contact email: ");
    scanf(" %[^\n]", contacts[*numContacts].email);
    clearInputBuffer();

    (*numContacts)++; // Increment the number of contacts
    printf("Contact added successfully!\n");
}

void deleteContact(struct contactAgenda contacts[], int* numContacts) { // Delete a contact
    int index;

    if (*numContacts == 0) {
        printf("No contacts to delete.\n");
    } else {
        printf("Enter contact number to delete (1-%d): ", *numContacts);
        scanf("%d", &index);
        clearInputBuffer();

        if (index < 1 || index > *numContacts) {
            printf("Invalid contact number.\n");
        }else {
            // Shift contacts to remove the specified contact
            for (int i=index; i<*numContacts;i++) {
                contacts[i-1]=contacts[i];
            }
            (*numContacts)--; // Decrement the number of contacts
            printf("Contact deleted successfully!\n");
        }
        }
}

void clearInputBuffer() { // Clear the input buffer to avoid issues with scanf
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}