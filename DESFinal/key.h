/**
    @file
    functions used to get and prepare the key
*/

#ifndef KEY_H_INCLUDED
#define KEY_H_INCLUDED

#include <iostream>;

/**
    gets string from the user and calls keyTo8Bytes to convert it into key
    @param key array to save the key
    @param keySize to pass the pleaded keySize (8 for DES, 24 for TDES)
    @callergraph
*/
void getKey(int key[], size_t keySize);

/**
    converts a string to 8-byte key
    @param keyWord the string to be converted
    @param key array of 8 bytes to save the key
    @param keySize to pass the pleaded keySize (8 for DES, 24 for TDES)
*/
void keyTo8Bytes(std::string keyWord, int key[], size_t keySize);

#endif // KEY_H_INCLUDED
