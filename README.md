# C-caesar-cypher
Implementation of the famous Caesar's cypher as a CLI tool 

Both encrypting and decrypting are supported.

Usage: 

    ccypher [options] string_to_decrypt key
    options:
        -e          Encrypts the given string instead of decrypting it
'key' is the number of letters that needs to be shifted


Example: 

    ccypher.exe "rovvy gybvn" 10
Output is:

    hello world
