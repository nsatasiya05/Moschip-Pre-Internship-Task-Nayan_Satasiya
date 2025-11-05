#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100
#define NOISE_WORDS 10

/* Linked list of line numbers */
struct linklist {
    int lnum;
    struct linklist *next;
};

/* Binary tree node for words */
struct tnode {
    char *word;
    struct linklist *lines;
    struct tnode *left;
    struct tnode *right;
};

int noise_word(char *w);
struct tnode *addtree(struct tnode *p, char *w, int linenum);
void treeprint(struct tnode *p);
char *strdup_c(const char *s);
int getword(char *word, int lim);

/* List of noise words */
char *noisewords[NOISE_WORDS] = {
    "the","and","is","in","of","to","a","it","that","for"
};

int main(void)
{
    struct tnode *root = NULL;
    char word[MAXWORD];
    int linenum = 1;

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]) && !noise_word(word))
            root = addtree(root, word, linenum);
        if (strchr(word, '\n'))
            linenum++;
    }
    treeprint(root);
    return 0;
}

int noise_word(char *w)
{
    for (int i = 0; i < NOISE_WORDS; i++)
        if (strcmp(w, noisewords[i]) == 0)
            return 1;
    return 0;
}

/* Add a word or update existing node */
struct tnode *addtree(struct tnode *p, char *w, int linenum)
{
    int cond;
    if (p == NULL) {
        p = (struct tnode *) malloc(sizeof(struct tnode));
        p->word = strdup_c(w);
        p->lines = (struct linklist *) malloc(sizeof(struct linklist));
        p->lines->lnum = linenum;
        p->lines->next = NULL;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
        struct linklist *t = p->lines;
        while (t->next != NULL && t->lnum != linenum)
            t = t->next;
        if (t->lnum != linenum) {
            t->next = (struct linklist *) malloc(sizeof(struct linklist));
            t->next->lnum = linenum;
            t->next->next = NULL;
        }
    } else if (cond < 0)
        p->left = addtree(p->left, w, linenum);
    else
        p->right = addtree(p->right, w, linenum);
    return p;
}

/* Print tree in alphabetical order */
void treeprint(struct tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%-15s :", p->word);
        struct linklist *t = p->lines;
        while (t != NULL) {
            printf(" %d", t->lnum);
            t = t->next;
        }
        printf("\n");
        treeprint(p->right);
    }
}

char *strdup_c(const char *s)
{
    char *p = (char *) malloc(strlen(s) + 1);
    if (p) strcpy(p, s);
    return p;
}

/* getword: read next word or character */
int getword(char *word, int lim)
{
    int c;
    char *w = word;
    while (isspace(c = getchar())) {
        if (c == '\n') { *w++ = '\n'; *w = '\0'; return '\n'; }
    }
    if (c == EOF) return EOF;
    if (!isalpha(c)) { *w++ = c; *w = '\0'; return c; }
    *w++ = c;
    while (--lim > 0 && (isalnum(c = getchar()) || c == '_'))
        *w++ = c;
    *w = '\0';
    if (c != EOF)
        ungetc(c, stdin);
    return word[0];
}
