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

int isletter(char c);
char* encrypt_decrypt(char *string, int key, int encrypt);
void usage();

int main(int argc, char *argv[])
  {
    int k, i, eflag;
    // check if 4 arguments and correct encrypt/decrypt options were given
    if ((argc != 4) || !((strcmp("-e", argv[1]) == 0) || (strcmp("-d", argv[1]) == 0)))
      usage(argv[0]);
    else
      {
        //checking if we're encrypting the message or not
        if(strcmp("-e", argv[1]) == 0)
          eflag = 1;
        else if(strcmp("-d", argv[1]) == 0)
          eflag = 0;
        //allocating memory for the string
        char* message = strdup(argv[2]); //message is now the string we're going to operate on
        k = atoi(argv[3]);
        // converting the whole message to lowercase
        for(i = 0; message[i]; i++)
            message[i] = tolower(message[i]);
        //if eflag is 1 encrypt the message, else decrypt it
        puts(encrypt_decrypt(message, k, eflag));
        //done dealing with the message, let's free memory up
        free(message);
      }
    return 0;
  }

int isletter(char c)
  {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    int isletter = 0;
    for(int i = 0; i < strlen(alphabet); i++)
      {
        if(c == alphabet[i])
          isletter = 1;
      }
    return isletter;
  }

char* encrypt_decrypt(char *string, int key, int encrypt)
  {
    int i, j, a;
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    for(i = 0; i < strlen(string); i++)
      {
        //checking if the char we're decrypting is a letter
        //if it is not, it is left as it is
        if(isletter(string[i]))
          {
            /*
             *strchr finds which position on the alphabet the
             *letter to be decrypted is located at. Then it substracts
             *the key in order to find where the decrypted letter is
             *in the alphabet
             */
            a = (int)(strchr(alphabet, string[i]) - alphabet);

            // checking the flag provided to see whether we should encrypt or decrypt
            if(encrypt == 0)
                a = (a + key) % 26;
            else if(encrypt == 1)
                a = (a - key) % 26;

            string[i] = alphabet[a];
          }
      }
    return string;
  }

void usage(char* program_name)
  {
    printf("usage: %s [options] string_to_decrypt key\n", program_name);
    puts("\toptions:");
    puts("\t  -e, \tencrypt the given string");
    puts("\t  -d, \tdecrypt the given string");
    puts("\t  must supply one or the other");
  }
