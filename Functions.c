#include <stdio.h>
#include <string.h>
#include "Info.h"
#include <stdlib.h>

#define MAXBRAC 1000
char bracketschk[MAXBRAC];
int brac_index = -1;

int line_number_brac = 0;

char *keywords[32] = {"int", "char", "float", "double", "unsigned", "auto", "break", "case", "const", "continue", "default", "do", "else", "enum", "extern", "for", "goto", "if", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "void", "volatile", "while"};

char operators[17] = {'+', '-', '*', '/', '%', '>', '=', '^', '|', '?', ':', '&', '~', '!', ',', '<', '.'};

int iskeyword(char *str)
{
    for (int i = 0; i < 32; i++)
    {
        if (!strcmp(str, keywords[i]))
        {
            return 1;
        }
    }
    return 0;
}

int isoperator(char ch)
{

    for (int j = 0; j < 17; j++)
    {
        if (ch == operators[j])
        {
            return 1;
        }
    }
    return 0;
}

int skip(char ch)
{
    if (ch == '#' || ch == '/')
    {
    }
}

int isalphabet(char ch)
{
    if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
    {
        return 1;
    }
    return 0;
}

int isSymbol(char ch)
{
    if (ch == ']' || ch == '[' || ch == '{' || ch == '}' || ch == '(' || ch == ')' || ch == ';')
    {
        return 1;
    }
    return 0;
}

int isnumber(char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        return 1;
    }
    return 0;
}

int ishexdigit(char ch)
{
    if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'F') || (ch >= 'a' && ch <= 'f'))
    {
        return 1;
    }
    return 0;
}

void reportError(char *msg, int line, char ch)
{
    printf(RED "\nERROR \n" RESET);
    printf(RED "Line No %d :" RESET, line);
    printf(YELLOW "  %s  ->  %c\n" RESET, msg, ch);
    exit(1);
}

void push(char ch)
{
    if (brac_index < MAXBRAC)
    {
        bracketschk[++brac_index] = ch;
    }
}

char pop()
{
    if (brac_index >= 0)
    {
        return bracketschk[brac_index--];
    }
    else
    {
        return '\0';
    }
}

int matchBrackets(char open, char close)
{
    return ((open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']'));
}

void checkbrackets(FILE *fp)
{
    char ch;

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '#')
            skipincludes(fp);

        if (ch == '/')
            skipComment(fp);

        if (ch == '\n')
        {
            line_number_brac++;
        }

        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {

            if (brac_index < 0)
            {
                printf(RED "ERROR : \n" RESET);
                printf(RED "Line No %d : Extra Closing Bracket %c \n" RESET, line_number_brac+1, ch);
                exit(1);
            }
            char exp;
            if (bracketschk[brac_index] == '(')
                exp = ')';
            if (bracketschk[brac_index] == '{')
                exp = '}';
            if (bracketschk[brac_index] == '[')
                exp = ']';
            char open = pop();
            if (!matchBrackets(open, ch))
            {

                printf(RED "ERROR :\n" RESET);
                printf(RED "Line No %d : Mismatch Brackets -> %c (Expected '%c' )\n" RESET, line_number_brac+1, ch, exp);
                exit(1);
            }
        }
    }

    if (brac_index != -1)
    {
        printf(RED "ERROR : Unclosed Brackets Detected %c \n" RESET, bracketschk[brac_index]);
        exit(1);
    }
}

int checkExtension(char *str, char *extension)
{
    if (str[0] == '.')
    {
        return 0;
    }

    int i = strlen(str) - 1;
    int j = strlen(extension) - 1;
    while (j >= 0)
    {
        if (str[i] != extension[j])
            return 0;

        j--;
        i--;
    }
    return 1;
}