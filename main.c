#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// person structure
typedef struct {
    int id;
    char name[50];
    int age;
    char adress[50];
} Person;

// create an array where we can store intstances of person
Person people[30];

// create an counter to keep track of people number inside the array
int countPerson = 5;

// create a function that reads All the all people
int getPeople();

// create a function that reads a single person
int getPerson();

// create a function that create a person
int createPerson();

// create a function that updates a person
int updatePerson();

// create a function that deletes a person
int deletePerson();

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
            scanf("%s", &crudType);
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
            getPerson();
            break;
        case 'B':
            // call the function that reads bulk poeple
            getPeople();
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

int getPeople () {
    printf("*******************************************************\n");
    printf("********************* ALL POEPLE **********************\n");
    printf("*******************************************************\n");
    if ( countPerson > 0 ) {
        for ( int i = 0; i <= countPerson; i++ ) {
            printf("%s | %d | %s \n", people[i].name, people[i].age, people[i].adress);
        }
    }
    else {
        printf("there no person yet ! ");
    }

}

int getPerson() {
    printf("**********************************************************\n");
    printf("********************* SINGLE PERSON **********************\n");
    printf("**********************************************************\n");

    Person people[30] = {
        {1, "Alice", 30},
        {2, "Bob", 25},
        {3, "Charlie", 35}
    };

    int id;
    printf("Please enter an id of a person ");
    scanf("%d", &id);

    for ( int i = 0; i <= countPerson; i++ ){

        if (strlen(people[i].name) > 0) {
            if ( people[i].id == id ) {
                printf("found...");
                break;
            }
            else {
                printf("person not found");
                break;
            }
        }
        else {
            printf("the list of poeple still empty\n");
            break;
        }


    }
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
    strcpy(person.adress, adress);

    // insert into people
    people[countPerson] = person;

    // encrement the counter by 1
    countPerson++;

}




