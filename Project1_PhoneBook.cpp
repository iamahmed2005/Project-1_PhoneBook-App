#include<stdio.h>
#include<string.h>

char Phone[100][100];
char Name[100][100];
int n = 0;

void ContactAdding() {

    printf("Enter name: ");
    scanf("%s", Name[n]);

    printf("Enter phone: ");
    scanf("%s", Phone[n]);

    n++;
    printf("Contact has been added.\n");
}

void ContactDeletion() {

    char NameDel[100];
    int Found = 0;

    printf("Enter a name to delete from your contact: ");
    scanf("%s", NameDel);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(Name[i], NameDel) == 0)
        {
            for (int j = i; j < n-1; j++)
            {
                strcpy(Name[j], Name[j+1]);
                strcpy(Phone[j], Phone[j+1]);
            }
            n--;
            Found = 1;
            printf("Contact Deleted Successfully.\n");
            break;
        }
    }
    
    if (Found == 0)
    {
        printf("Your contact is not found.\n");
    }
}

void SearchUsingName() {

    char item[100];
    int Found = 0;

    printf("Enter name to search: ");
    scanf("%s", item);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(Name[i], item) == 0)
        {
            printf("Contact Found: %s  --  %s\n", Name[i], Phone[i]);
            Found = 1;
            break;
        }   
    }

    if (Found == 0)
    {
        printf("Given name is not found.\n");
    }  
}

void SearchUsingNumber() {

    char KEY[20];
    int found = 0;

    printf("Enter a phone number to search: ");
    scanf("%s", KEY);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(Phone[i], KEY) == 0)
        {
            printf("Contact Found: %s  --  %s\n", Name[i], Phone[i]);
            found = 1;
            break;
        }  
    }
    
    if (found == 0)
    {
        printf("Given number is not found.\n");
    }
}

void ContactDisplay() {

    if (n == 0)
    {
        printf("No contact has been saved.");
        return;
    }
    
    printf("\n All Contacts Here: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d. %s -- %s \n", i+1, Name[i], Phone[i]);
    }
}


int main() {

    int Choice;

    for(;;) {

        printf("\nPhone Book:\n");
        printf("1. Add a Contact\n");
        printf("2. Delete a Contact\n");
        printf("3. Search a Contact using Name\n");
        printf("4. Search a Contact using Number\n");
        printf("5. Display Contacts\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &Choice);
        
        switch (Choice)
        {
        case 1:
            ContactAdding();
            break;
        case 2:
            ContactDeletion();
            break;
        case 3:
            SearchUsingName();
            break;
        case 4:
            SearchUsingNumber();
            break;
        case 5:
            ContactDisplay();
            break;
        case 6:
            printf("Exiting from Phonebook.\n");
        return 0;
        
        
        default:
            printf("Choice is Invalid. Please try again.\n");
        }
    }
    return 0;
}