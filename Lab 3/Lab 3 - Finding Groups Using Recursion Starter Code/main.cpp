/*
 * Name:
 * Date Submitted:
 * Lab Section:
 * Assignment Name:
 */
 
 #include "stringset.h"
 #include <iostream>
 #include <fstream>
 
 void testStringset(Stringset& words);
 void loadStringset(Stringset& words, string filename);
 vector<string> spellcheck(const Stringset& words, string word);
 
 int main()
 {
     Stringset wordlist;
     testStringset(wordlist);
     return 0;
 }
 
 void testStringset(Stringset& words)
 {
     string choice;
     string word;
     do
     {
         cout << "I: insert word" << endl;
         cout << "F: find word" << endl;
         cout << "R: remove word" << endl;
         cout << "P: print words in stringset" << endl;
         cout << "Q: quit" << endl;
         cin >> choice;
         switch (choice[0])
         {
             case 'I':
             case 'i':
                cout << "Enter word to insert: ";
                cin >> word;
                words.insert(word);
                break;
             case 'F':
             case 'f':
                cout << "Enter word to find: ";
                cin >> word;
                if (words.find(word))
                {
                    cout << word << " in stringset" << endl;
                }
                else
                {
                    cout << word << " not in stringset" << endl;
                }
                break;
             case 'R':
             case 'r':
                cout << "Enter word to remove: ";
                cin >> word;
                words.remove(word);
                break;
             case 'P':
             case 'p':
                vector<list<string>> t = words.getTable();
                int numWords = words.getNumElems();
                int tSize = words.getSize();
                for(int i=0; i<tSize; ++i)
                {
                    list<string>::iterator pos;
                    for (pos = t[i].begin(); pos != t[i].end(); ++pos)
                    {
                        cout << *pos << endl;
                    }
                }
                cout << "Words: " << numWords << endl;
         }
     } while (choice[0] != 'Q' && choice[0] != 'q');
 }
 
 void loadStringset(Stringset& words, string filename)
 {
     ifstream file(filename);
    if (!file)
    {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string word;
    while (file >> word)
    {
        words.insert(word);
    }

    file.close();
 }
 
 vector<string> spellcheck(const Stringset& words, string word)
 {
     vector<string> alternatives;
    const string alphabet = "abcdefghijklmnopqrstuvwxyz";

    // Iterate through each character in the word
    for (size_t i = 0; i < word.length(); ++i)
    {
        // Try replacing the current character with each character from the alphabet
        for (char c : alphabet)
        {
            // Skip if the replacement character is the same as the original character
            if (c == word[i])
                continue;

            // Create a candidate word by replacing the character at position i
            string candidate = word;
            candidate[i] = c;

            // Check if the candidate word exists in the dictionary
            if (words.find(candidate))
            {
                // If found, add it to the list of alternatives
                alternatives.push_back(candidate);
            }
        }
    }

    return alternatives;
 }