/* A lexical analyzer system for simple
arithmetic expressions */
#include <stdio.h>
#include <ctype.h>

/* Global declarations */
/* Variables */
int charClass;


//  if given this:  (sum + 47) / total
char lexeme[100]; // <-- [(,s,u,m,+,4,7,),/,t,o,t,a,l] This array is actually a whole string. According to c/c++ this will be treated as both a whole null-terminated string and a list of characters
char nextChar;
int lexLen; //<- initialize lexlen to keep trak of the length of the whole input from txt
int token;
int nextToken;
FILE *in_fp, *fopen();


/* Function declarations */
void addChar();
void getChar();
void getNonBlank();


// update for lab2 
// function declartions for expr, term, and factor
/* Parsing functions declarations */
void expr();
void term();
void factor();
int lex();


/* Character classes */
#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99


/* Token codes */
#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26


// update main function to call expr() function

/******************************************************/
/* main driver */
int main()
{
      /* Open the input data file and process its contents */
      if ((in_fp = fopen("front.txt", "r")) == NULL)
            printf("ERROR - cannot open front.in \n");
      else
      {
            getChar();
            do
            {
                  lex();
            } while (nextToken != EOF);
            

      }
      return 0;
}


/*****************************************************/
/* lookup - a function to lookup operators and parentheses
and return the token */
int lookup(char ch)
{
      switch (ch)
      {
      case '(':
            addChar();
            nextToken = LEFT_PAREN;
            break;
      case ')':
            addChar();
            nextToken = RIGHT_PAREN;
            break;
      case '*':
            addChar();
            nextToken = MULT_OP;
            break;
      case '/':
            addChar();
            nextToken = DIV_OP;
            break;
      case '+':
            addChar();
            nextToken = ADD_OP;
            break;
      case '-':
            addChar();
            nextToken = SUB_OP;
            break;
      case '=':
            addChar();
            nextToken = ASSIGN_OP;
            break;
      }

      return nextToken;
}

/*****************************************************/
/* addChar - a function to add nextChar to lexeme */
void addChar()
{
      if (lexLen <= 98)
      {
            // At the start of the program
            // lexLen = 0 that was assigned on lex function
            // when we are her
            // We are actually doing this:
            lexeme[lexLen++] = nextChar; // ex) when lexLen = 0  than, lexeme[0] = "("
            // After assigning "(" into the zero position the ++ (post i-increment) on lexLen++ will update the Lexlen
            // After assinging to 0 position the "lexLen" will become, in this case, were we will store the next character
            // However, since c/c++ are known for null terminated string. Than we need to create a null value after this added character
            lexeme[lexLen] = 0; // -> lexeme[1] =0

            // So at the first itration the lexeme array would look like this
            // lexeme[100] = ["(",0]
            // c/c++ treats this array as an array of chracters
      }
      else
            printf("Error - lexeme is too long \n");
}



/*****************************************************/
/* getChar - a function to get the next character of
input and determine its character class */
void getChar()
{
      if ((nextChar = getc(in_fp)) != EOF)
      {
            if (isalpha(nextChar))
                  charClass = LETTER;
            else if (isdigit(nextChar))
                  charClass = DIGIT;

            else
                  charClass = UNKNOWN;
      }
      else
            charClass = EOF;
}



/*****************************************************/
/* getNonBlank - a function to call getChar until it
returns a non-whitespace character */
void getNonBlank()
{
      // ignoring white characters
      while (isspace(nextChar))
            getChar();
}
/*
*****************************************************/
/* lex - a simple lexical analyzer for arithmetic
expressions */

int lex()
{
      lexLen = 0;    // length of lexeme
      getNonBlank(); //

      switch (charClass)
      {
      /* Parse identifiers */
      case LETTER:
            addChar();
            getChar();
            while (charClass == LETTER || charClass == DIGIT)
            {
                  addChar();
                  getChar();
            }
            nextToken = IDENT;
            break;
      case DIGIT:

            addChar();
            getChar();
            while (charClass == DIGIT)
            {
                  addChar();
                  getChar();
            }
            nextToken = INT_LIT;
            break;

      case UNKNOWN:
            lookup(nextChar);
            getChar();

            break;
      /* EOF */
      // handles the end-of-file character
      case EOF:
            nextToken = EOF; // <-- this assigns -1 as token for EOF
            lexeme[0] = 'E';
            lexeme[1] = 'O';
            lexeme[2] = 'F';
            lexeme[3] = 0; // Null-terminate the string
            break;
      } /* End of switch */
      printf("Next token is: %d, Next lexeme is %s\n", nextToken, lexeme);
      return nextToken;
} /* End of function lex */




void expr() 
{
    printf("Enter <expr>\n");
    // Parses strings in the language generated by the rule:
    // <expr> -> <term> {(+ | -) <term>}
    // This function parses the first term and then, as long as the next token is 
    // either a '+' or '-', it gets the next token and parses the next term.
    
    
    
    
    // code here
    printf("Exit <expr>\n");
}

void term() 
{
    printf("Enter <term>\n");
    // Parses strings in the language generated by the rule:
    // <term> -> <factor> {(* | /) <factor>}
    // This function parses the first factor and then, as long as the next token is 
    // either '*' or '/', it gets the next token and parses the next factor.
    
    
    
    
    
    // code here
    printf("Exit <term>\n");
}

void factor() 
{
    printf("Enter <factor>\n");
    // Parses strings in the language generated by the rule:
    // <factor> -> id | int_constant | ( <expr> )
    // This function determines which right-hand side to parse: a variable, a constant,
    // or an expression within parentheses. It includes syntax error checks for 
    // unmatched parentheses or unexpected tokens.
    
    
    
    // code here
    printf("Exit <factor>\n");
}
