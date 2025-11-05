#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASHSIZE 101
#define MAXWORD 100

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s) {
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s) {
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    return NULL;
}

char *strdup_c(const char *s) {
    char *p = (char *) malloc(strlen(s) + 1);
    if (p) strcpy(p, s);
    return p;
}

struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL) {
        np = (struct nlist *) malloc(sizeof(*np));
        np->name = strdup_c(name);
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else
        free((void *) np->defn);
    np->defn = strdup_c(defn);
    return np;
}

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

int getword(char *word, int lim) {
    int c;
    char *w = word;
    while (isspace(c = getchar()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c) && c != '_') {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
        if (!isalnum(*w = getchar()) && *w != '_') {
            ungetc(*w, stdin);
            break;
        }
    *w = '\0';
    return word[0];
}

/* Simple #define processor */
int main(void) {
    char word[MAXWORD];
    struct nlist *p;

    while (getword(word, MAXWORD) != EOF) {
        if (strcmp(word, "#define") == 0) {
            char name[MAXWORD], defn[MAXWORD];
            getword(name, MAXWORD);
            getword(defn, MAXWORD);
            install(name, defn);
        } else if (strcmp(word, "#undef") == 0) {
            char name[MAXWORD];
            getword(name, MAXWORD);
            undef(name);
        } else if ((p = lookup(word)) != NULL) {
            printf("%s", p->defn);
        } else {
            printf("%s", word);
        }
        if (isspace(word[strlen(word) - 1]))
            putchar(' ');
    }
    return 0;
}
