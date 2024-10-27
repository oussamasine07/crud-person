#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// declare needed variables
// person structure
typedef struct {
    int id;
    char name[50];
    int age;
    char adress[50];
} Person;



// create an array where we can store intstances of person
Person people[30];
char appState = 'H';
int currentPersonIdx = 0;
int countedPeople = 0;
int searchId;



// declare needed functions
// count how many people in the array
int countPeople ();
// create a function that reads All the all people
int getPeople();

// create a function that reads a single person
int getPerson( int id );

// create a function that create a person
int createPerson();

// create a function that updates a person
int updatePerson( int id );

// create a function that deletes a person
int deletePerson( int id );

int main()
{
    printf("Testing Crud\n");

    _Bool running = true;
    _Bool userCheck = true;

    do {

        switch (appState) {
            case 'H':
                printf("please enter one of these letters (C,B,R,U,D)\n");
                scanf("%s", &appState);

                do {
                    if (appState == 'C' || appState == 'R' || appState == 'B' || appState == 'U' || appState == 'D' || appState == 'Q') {
                        userCheck = false;
                    }
                    else {
                        printf("invalide charachter, you should type only (C,R,B,U,D) \n");
                        scanf("%s", &appState);
                    }
                } while (userCheck);

                break;
            case 'B':
                getPeople();
                break;
            case 'R':
                countedPeople = countPeople();
                if ( countedPeople == 0 ) {
                    printf("There is no one in this list, you have to add some one \n");
                    appState = 'C';
                }
                else {
                    printf("Please enter an ID of a person ");
                    scanf("%d", &searchId);
                    getPerson( searchId );
                }

                break;
            case 'C':
                createPerson();
                break;
            case 'U':
                countedPeople = countPeople();
                if ( countedPeople == 0 ) {
                    printf("There is no one in this list, you have to add some one \n");
                    appState = 'C';
                }
                else {
                    printf("Please enter an ID of a person ");
                    scanf("%d", &searchId);
                    updatePerson( searchId );
                }

                break;
            case 'D':
                countedPeople = countPeople();
                if ( countedPeople == 0 ) {
                    printf("There is no one in this list, you have to add some one \n");
                    appState = 'C';
                }
                else {
                    printf("Please enter an ID of a person or banch of ids of people \n");
                    printf("you can inter up to 50 people at once \n");

                    scanf("%d", &searchId);
                    deletePerson( searchId );
                }
                break;
            case 'Q':
                running = false;
        }

    } while( running );

    printf("app is done!");

    return 0;
}


int getPeople () {
    countedPeople = countPeople();

    if ( countedPeople == 0) {
        printf("There is no one in this list, you have to add some one \n");
        appState = 'C';
    }
    else {
        printf("*******************************************************\n");
        printf("********************* ALL POEPLE **********************\n");
        printf("*******************************************************\n");

        // print all people names
        for ( int i = 0; i < 30; i++ ) {
            if ( strlen( people[i].name ) > 0 ) {
                printf("=====================================================\n");
                printf("ID : %d\n", people[i].id);
                printf("NAME : %s\n", people[i].name);
                printf("AGE : %d\n", people[i].age);
                printf("ADRESS : %s\n", people[i].adress);
                printf("\n");
            }
            else {
                break;
            }
        }

        appState = 'H';
    }

}

int getPerson( int id ) {

    countedPeople = countPeople();
    int found = 0;

    if ( countedPeople == 0) {
        printf("There is no one in this list, you have to add some one \n");
        appState = 'C';
    }
    else {
        printf("********************************************************\n");
        printf("********************* PERSON INFO **********************\n");
        printf("********************************************************\n");

        // print all people names
        for ( int i = 0; i < 30; i++ ) {

            if ( people[i].id == id ) {
                printf("ID : %d\n", people[i].id);
                printf("NAME : %s\n", people[i].name);
                printf("AGE : %d\n", people[i].age);
                printf("ADRESS : %s\n", people[i].adress);
                found = 1;
                break;
            }
        }
        if ( !found ) {
            printf("the person you are looking for is not found\n");
        }
        appState = 'H';
        printf("\n");
    }
}

int createPerson() {

    printf("**********************************************************\n");
    printf("********************* CREATE PERSON **********************\n");
    printf("**********************************************************\n");

    char fullName[50], adress[50], checkAdding;
    int insertCount, age;
    _Bool adding = true;

    printf("How many people do you want to enter? ");
    scanf("%d", &insertCount);

    while ( adding ) {
        for ( int i = 0; i < insertCount; i++ ) {
            printf("enter full name ");
            scanf("%s", &fullName);

            printf("enter age ");
            scanf("%d", &age);

            printf("enter adress ");
            scanf("%s", &adress);

            // create a new person instance
            Person person;

            person.id = currentPersonIdx + 1;
            strcpy(person.name, fullName);
            person.age = age;
            strcpy(person.adress, adress);

            people[currentPersonIdx] = person;

            currentPersonIdx++;

        }

        printf("Do you want to add more people ? (type Y/N) ");
        scanf("%s", &checkAdding);

        if ( checkAdding == 'Y' ) {
            printf("How many people do you want to enter? ");
            scanf("%d", &insertCount);
        }
        else {
            printf("thanks for adding !! \n");
            appState = 'H';
            adding = false;
        }
    }





}

int updatePerson( int id ) {

    printf("**********************************************************\n");
    printf("********************* UPDATE PERSON **********************\n");
    printf("**********************************************************\n");

    char fullName[50], adress[50];
    int age, found = 0;

    for ( int i = 0; i < 30; i++ ) {
        // check if the user exists in the list or not
        if ( people[i].id == id ) {
            printf("enter full name ");
            scanf("%s", &fullName);

            printf("enter age ");
            scanf("%d", &age);

            printf("enter adress ");
            scanf("%s", &adress);

            strcpy(people[i].name, fullName);
            people[i].age = age;
            strcpy(people[i].adress, adress);

            found = 1;
            printf("Thank you for updating!!");
            break;
        }
    }

    if ( !found ) {
        printf("the person your looking to update is NOT FOUND!!");
    }

    appState = 'H';
    printf("\n");

}

int deletePerson ( int id ) {
    int found = 0;
    int i, idx = -1;
    char name[50], confirm;

    for ( i = 0; i < 30; i++ ) {
        if ( people[i].id != id ) {
            found = 1;
            idx = i;
            strcpy(people[i].name, name);
            break;
        }
    }

    if (!found) {
        printf("this person NOT FOUND\n");
    }
    else {
        printf("Are you sure you want to delete <<<<%s>>>> | type (Y/N) ", name);
        scanf("%s", &confirm);
        if ( confirm == 'Y' ) {
            if ( idx != -1 ) {
                for ( i = 0; i < 30; i++ ) {
                    people[i] = people[i+1];
                }
            }
        }
        else {
            printf("Deleting Canceled");
        }

    }

    appState = 'H';
}

int countPeople () {
    int count = 0;

    for ( int i = 0; i < 30; i++ ) {
        if ( strlen(people[i].name) > 0 ) {
            count++;
        }
    }

    return count;
}







