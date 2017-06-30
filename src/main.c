/*
 *Implementation of Caesar's cipher
 *A command line tool that accepts the following parameters:
 *1) String to decrypt
 *2) The key, meant as an integer indicating the shift factor
 *Prints on stdout the decrypted string
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void decrypt(char *string, int key);

int main(int argc, char *argv[])
  {
    int k, i;
    if (argc != 3)
      printf("usage:\n %s string_to_decrypt key ", argv[0]);
    else
      {
        //Allocating memory for the string we need to decrypt
        char* message = strdup(argv[1]); //message is now the string we're going to operate on
        k = atoi(argv[2]);
        //since I'm too lazy to deal with mixed case letter, we're converting
        //the whole message to lowercase
        for(i = 0; message[i]; i++)
            message[i] = tolower(message[i]);
        decrypt(message, k);
        //done decrypting the message, let's free memory up
        free(message);
      }
    return 0;
  }

void decrypt(char *string, int key)
  {
    int i, j, a, string_lenght;
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    string_lenght = strlen(string);
    for(i = 0; i < string_lenght; i++)
      {
        //Checking if the char we're decrypting is a space
        //if it is, leave it
        if(!isspace(string[i]))
          {
            /*
             *Explaination on how the next line of code works:
             *lmao i dunno it's black magic
             *jokes aside, strchr finds which position on the alphabet the
             *letter to be decrypted is located at. Then it substracts
             *the key in order to find where the decrypted letter is
             *in the alphabet
             */
            a = (int)(strchr(alphabet, string[i]) - alphabet);
            //next for loop is basically "a = a - key;", but
            //it checks alphabet array's bounds so it doesn't go
            //below 0 or over 25
            for(j = 0; j < key; j++)
              {
                if(a < 0)
                  a = 25;
                a = a - 1;
              }
            //a = (((int)(strchr(alphabet, string[i]) - alphabet)) - key) % 26;
            string[i] = alphabet[a];
          }
        else
          string[i] = ' ';
      }
    puts("output :");
    puts(string);
    return;
  }
