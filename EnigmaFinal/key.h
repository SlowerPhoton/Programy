#ifndef KEY_H_INCLUDED
#define KEY_H_INCLUDED

/** \brief
 *  generates the key and uploads it to the rotors and the reflector
 * \param scramblers scramblers to fill in the key
 *
 */
void generateKey(int scramblers[3+1][26]);

/** \brief
 *  uploads the key to scramblers from a file
 *  currently DISABLED
 * \param scramblers to upload the data
 *
 */
//void setKey(int scramblers[3+1][26]);

/** \brief generates a new scrambler (or the reflector)
 *
 * \param scrambler to alter data (overwrites a chosen scrambler)
 *
 */
void generateScrambler(int scramblers[3+1][26]);

#endif // KEY_H_INCLUDED
