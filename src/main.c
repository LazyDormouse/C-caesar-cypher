/*
 *Implementation of Caesar's cipher
 *A command line tool that accepts the following parameters:
 *1) String to decrypt/encrypt
 *2) The key, meant as an integer indicating the shift factor
 *Prints on stdout the decrypted/encrypted string
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void decrypt(char *string, int key);
void encrypt(char *string, int key);
void usage();

int main(int argc, char *argv[])
  {
    int k, i, eflag;
    if (argc != 4)
      usage();
    else
      {
        //checking if we're encrypting the message or not, assume not
        if(strcmp("-e", argv[1]) == 0)
          eflag = 1;
        else if(strcmp("-d", argv[1]) == 0)
          eflag = 0;
        else
          {
            puts("[WARNING] invalid option detected, the string will be decrypted");
            eflag = 0;
          }
        //allocating memory for the string
        char* message = strdup(argv[2]); //message is now the string we're going to operate on
        k = atoi(argv[3]);
        //since I'm too lazy to deal with mixed case letters, we're converting
        //the whole message to lowercase
        for(i = 0; message[i]; i++)
            message[i] = tolower(message[i]);
        //if eflag is 1 encrypt the message, else decrypt it
        if(eflag == 1)
          encrypt(message, k);
        else
          decrypt(message, k);
        //done dealing with the message, let's free memory up
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
        //checking if the char we're decrypting is a space
        //if it is, leave it
        if(!isspace(string[i]))
          {
            /*
             *explaination on how the next line of code works:
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
                a--;
                if(a < 0)
                  a = 25;
              }
            //a = (((int)(strchr(alphabet, string[i]) - alphabet)) - key) % 26;
            string[i] = alphabet[a];
          }
        else
          string[i] = ' ';
      }
    puts(string);
    return;
  }

/*
 *encrypt function is basically the same as decrypt, but
 *we're adding the key instead of subtracting it.
 *if you have any doubts, look at the decrypt function
 */
void encrypt(char *string, int key)
  {
    int i, j, a, string_lenght;
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    string_lenght = strlen(string);
    for(i = 0; i < string_lenght; i++)
      {
        if(!isspace(string[i]))
          {
            a = (int)(strchr(alphabet, string[i]) - alphabet);
            for(j = 0; j < key; j++)
              {
                a++;
                if(a > 25)
                  a = 0;
              }
            string[i] = alphabet[a];
          }
        else
          string[i] = ' ';
      }
    puts(string);
    return;
  }

void usage()
  {
    puts("usage: ccypher [options] string_to_decrypt key");
    puts("\toptions:");
    puts("\t  -e, \tencrypt the given string");
    puts("\t  -d, \tdecrypt the given string");
    puts("\t  must supply one or the other");
  }
