/**
    @file
    functions used to get and prepare the message
*/

#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED

/**
    asks user for the number of characters in the message
    @return number of characters in the message
*/
int getSizeOfMessage();


/**
    counts how many characters we need to add to the message in order to be a multiple of 8 characters long (64 bits)
*/
int padding(int numbersInMessage);

/**
    get the message from the user, character after character <int>
    @param message an array to store the message
    @param numbersInMessage the size of the message (in bytes)
*/
void getMessage(int message[], int numbersInMessage);

/**
    expands the message in order to be a multiple of 8 ints (bytes) long
    @n adds @c 0 in the empty indexes
*/
void messageExpand(int message[], int numbersInMessage);

#endif // MESSAGE_H_INCLUDED
