#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// person structure
typedef struct {
    int id;
    char name[50];
    int age;
    char adresse[50];
} Person;



// create a function that reads multiple people
void getPeole (Person people[]);

// create a function that reads a single person
int createPerson();

// create an array where we can store intstances of person
Person people[30];

// create a function that updates a person

// create a function that deletes a person

int main()
{
    printf("CRUD POEPLE\n");

    // ask the user what operation he want to effect
    printf("Please choose what operation you want to do \n");
    printf("C => type C to create a new person\n");
    printf("R => type R to get single person\n");
    printf("B => type B to get bulk of people\n");
    printf("U => type U to update a person\n");
    printf("D => type D to delete a person\n");

    char crudType;

    printf("Type a charachter ");
    scanf("%c", &crudType);

    // validate characters

    _Bool crudProcess = true;
    do {
        if (crudType == 'C' || crudType == 'R' || crudType == 'B' || crudType == 'U' || crudType == 'D') {
            crudProcess = false;
        }
        else {
            printf("invalide charachter, you should type only (C,R,B,U,D) \n");
            scanf("%s²", &crudType);
        }

    } while(crudProcess);


    // start a switch statement
    switch (crudType) {
        case 'C':
            // call the create function
            printf("creating....\n");
            createPerson();
            break;
        case 'R':
            // call the function that reads single person
            break;
        case 'B':
            // call the function that reads bulk poeple
            break;
        case 'U':
            // call the function that updates a user
            break;
        case 'D':
            // call the function that deletes a single person
            break;
    }


    return 0;
}

int createPerson() {
    char fullName[50], adress[50];
    int age;

    printf("enter full name ");
    scanf("%s", &fullName);

    printf("enter age ");
    scanf("%d", &age);

    printf("enter adress ");
    scanf("%s", &adress);

    // create a new person
    Person person;

    strcpy(person.name, fullName);
    person.age = age;
    strcpy(person.adresse, adress);

    // insert into people

}




