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


// declare variable count
int count;
char appState = 'H';

// create an array where we can store intstances of person
Person people[30];

// create an counter to keep track of people number inside the array
int countPeople ();


int homeApp ();

// create a function that reads All the all people
int getPeople();

// create a function that reads a single person
int getPerson( int id );

// create a function that create a person
int createPerson();

// create a function that updates a person
int updatePerson();

// create a function that deletes a person
int deletePerson();

int main()
{
    count = countPeople();

    printf("CRUD POEPLE\n");
    // ask the user what operation he want to effect
    /*
    printf("Please choose what operation you want to do \n");
    printf("C => type C to create a new person\n");
    printf("R => type R to get single person\n");
    printf("B => type B to get bulk of people\n");
    printf("U => type U to update a person\n");
    printf("D => type D to delete a person\n");
    */

    _Bool running = true;

    while ( running ) {

        if ( appState == 'H' ) {
            homeApp();
            printf("Type a charachter ");
            scanf("%s", &appState);
        }

        // validate characters

        _Bool crudProcess = true;
        do {
            if (appState == 'C' || appState == 'R' || appState == 'B' || appState == 'U' || appState == 'D') {
                crudProcess = false;
            }
            else {
                printf("invalide charachter, you should type only (C,R,B,U,D) \n");
                scanf("%s", &appState);
            }

        } while(crudProcess);

        // start a switch statement
        switch (appState) {
            case 'C':
                // call the create function
                createPerson();
                break;
            case 'R':
                // call the function that reads single person
                printf("**********************************************************\n");
                printf("********************* SINGLE PERSON **********************\n");
                printf("**********************************************************\n");

                int id;
                printf("Please enter an id of a person ");
                scanf("%d", &id);

                getPerson(id);
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

    }

    return 0;
}

int homeApp () {
    // ask the user what operation he want to effect
    printf("Please choose what operation you want to do \n");
    printf("C => type C to create a new person\n");
    printf("R => type R to get single person\n");
    printf("B => type B to get bulk of people\n");
    printf("U => type U to update a person\n");
    printf("D => type D to delete a person\n");
}

int getPeople () {
    printf("*******************************************************\n");
    printf("********************* ALL POEPLE **********************\n");
    printf("*******************************************************\n");
    if ( count > 0 ) {
        for ( int i = 0; i <= count; i++ ) {
            printf("%s | %d | %s \n", people[i].name, people[i].age, people[i].adress);
        }
    }
    else {
        printf("there no person yet ! ");
    }

}

int getPerson( int id ) {


    Person people[30] = {
        {1, "Alice", 30},
        {2, "Bob", 25},
        {3, "Charlie", 35}
    };

    printf("******** person info *********");
    for ( int i = 0; i <= count; i++ ){

        if (strlen(people[i].name) > 0) {
            if ( people[i].id == id ) {
                printf(" %s | %d | %s ", people[i].name, people[i].age, people[i].adress);
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

    printf("**********************************************************\n");
    printf("********************* CREATE PERSON **********************\n");
    printf("**********************************************************\n");

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
    people[count] = person;

    // encrement the counter by 1
    count++;

    // ask the user if he want to keep adding poeple
    printf("do you want to keep adding enter K to keep or H to get home app ");
    scanf("%s", &appState);

    if ( appState == 'K' ) {
        createPerson();
    }
    else {
        homeApp();
    }

}

int updatePerson() {
    printf("**********************************************************\n");
    printf("********************* UPDATE PERSON **********************\n");
    printf("**********************************************************\n");

    printf("Please enter an id of a person you want to update ");
    int id;
    scanf("%d", &id);

    char fullName[50], adress[50];
    int age;

    printf("enter full name ");
    scanf("%s", &fullName);

    printf("enter age ");
    scanf("%d", &age);

    printf("enter adress ");
    scanf("%s", &adress);

    for ( int i = 0; i < count; i++ ) {
        if (strlen(people[i].name) > 0) {
            if ( people[i].id == id ) {

                strcpy(people[i].name, fullName);
                people[i].age = age;
                strcpy(people[i].adress, adress);

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

int deletePerson() {
    printf("**********************************************************\n");
    printf("********************* DELETE PERSON **********************\n");
    printf("**********************************************************\n");

    printf("Please enter the id the person you want to delete ");
    int id;
    scanf("%id", &id);
    printf("deleting....\n");

    int i, idx = -1;

    for ( i = 0; i < count; i++ ) {
        if ( strlen(people[i].name) > 0 ) {
            if ( people[i].id != id ) {
                idx = i;
                break;
            }
        }
    }

    if ( idx != -1 ) {
        for ( i = 0; i < count; i++ ) {
            people[i] = people[i+1];
        }
    }

};

int countPeople () {
    int counter = 0;
    for (int i = 0; i < 30; i++) {
        if ( strlen(people[i].name) > 0 ) {
            counter++;
        }
    }

    return counter;
}


