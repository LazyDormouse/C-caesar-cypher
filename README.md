# C-caesar-cypher
Implementation of the famous Caesar's cypher as a CLI tool 

Both encrypting and decrypting are supported.

Usage: 

    ccypher [options] string_to_decrypt key
      options:
          -e,   encrypt the given string
          -d,   decrypt the given string
'key' is the number of letters that needs to be shifted


Example: 

    ccypher.exe -d "rovvy gybvn" 10
Output is:

    hello world

Compiled exe for Windows/Mac/Linux available [here](http://www.mediafire.com/file/6o5y0celltf27g5/ccypher.exe)
