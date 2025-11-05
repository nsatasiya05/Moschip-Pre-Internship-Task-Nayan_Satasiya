#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

/* Node in the hash table */
struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

static struct nlist *hashtab[HASHSIZE]; /* Hash table */

/* Hash function */
unsigned hash(char *s) {
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

/* Lookup: find name in table */
struct nlist *lookup(char *s) {
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    return NULL;
}

/* strdup replacement */
char *strdup_c(const char *s) {
    char *p = (char *) malloc(strlen(s) + 1);
    if (p) strcpy(p, s);
    return p;
}

/* Install: put (name, defn) in table */
struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup_c(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else
        free((void *) np->defn);

    if ((np->defn = strdup_c(defn)) == NULL)
        return NULL;
    return np;
}

/* undef: remove a name from table */
void undef(char *name) {
    struct nlist *np, *prev = NULL;
    unsigned hashval = hash(name);
    for (np = hashtab[hashval]; np != NULL; prev = np, np = np->next) {
        if (strcmp(name, np->name) == 0) {
            if (prev == NULL)
                hashtab[hashval] = np->next;
            else
                prev->next = np->next;
            free(np->name);
            free(np->defn);
            free(np);
            return;
        }
    }
}

/* Test the undef() */
int main(void) {
    install("PI", "3.14");
    install("E", "2.718");
    install("MAX", "1000");

    printf("Before undef:\n");
    printf("PI = %s\n", lookup("PI")->defn);
    printf("E = %s\n", lookup("E")->defn);
    printf("MAX = %s\n", lookup("MAX")->defn);

    undef("E");

    printf("\nAfter undef(E):\n");
    printf("PI = %s\n", lookup("PI")->defn);
    printf("E = %s\n", lookup("E") ? lookup("E")->defn : "undefined");
    printf("MAX = %s\n", lookup("MAX")->defn);

    return 0;
}
