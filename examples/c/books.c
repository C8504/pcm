/* books.c -- saves structure contents in a file */

#include <stdio.h>
#include <stdlib.h>
#define MAXTITL   41
#define MAXAUTL   41
#define MAXBKS    100             /* maximum number of books */

struct book {                   /* set up book template    */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void)

{
    struct book library[MAXBKS]; /* array of structures     */
    int count = 0;
    int index, filecount;
    FILE * pbooks;
    int size = sizeof (struct book);

    if ((pbooks = fopen("books.dat", "a+b")) == NULL)
    {
        fputs("Can't open book.dat file\n",stderr);
        exit(1);
    }

    rewind(pbooks);            /* go to start of file     */
    while (count < MAXBKS &&  fread(&library[count], size,
                1, pbooks) == 1)
    {
        if (count == 0)
            puts("Current contents of book.dat:");
        printf("Title: %s by Author: %s Price: $%.2f\n\n",library[index].title,
            library[count].author, library[count].value);
        count++;
    }

    filecount = count;
    if (count == MAXBKS)
    {
        fputs("The book.dat file is full.", stderr);
        exit(2);
    }

    puts("Please add new book titles.");
    puts("Press [ctrl+d] at the start of a line to stop.");
    while (count < MAXBKS && fgets(library[count].title, MAXTITL ,stdin) != NULL
                          && library[count].title[0] != '\0')
    {
        puts("Now enter the author.");
        fgets(library[count].author, MAXAUTL, stdin);
        puts("Now enter the value.");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;                /* clear input line  */
         if (count < MAXBKS)
             puts("Enter the next title.");
    }

    if (count > 0)
    {
        puts("Here is the list of your books:");
        for (index = 0; index < count; index++)
            printf("Title: %s by Author: %s Price: $%.2f\n\n",library[index].title,
                   library[index].author, library[index].value);
        fwrite(&library[filecount], size, count - filecount,
                pbooks);
    }
    else
          puts("No books? Too bad.\n");

    puts("Bye.\n");
    fclose(pbooks);

    return 0;
}

