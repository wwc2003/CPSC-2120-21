/*
 * Name:
 * Date Submitted:
 * Assignment Name:
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> loadWordlist(string filename);

/*Implement the following function:
  anagram() takes a word (string) and a wordlist of all words (vector of strings)
  and builds a dictionary/map where the key is a specific number of times each
  letter occurs in a word and the associated value is a vector of strings
  containing all words using those letters (anagrams).
  The value returned is a vector of strings containing the corresponding
  set of anagrams
*/
vector<string> anagram(string word, vector<string> wordlist);
/*
int main()
{
    vector<string> words;
    vector<string> anagrams;
    string inputWord;
    words=loadWordlist("wordlist.txt");
    cout << "Find single-word anagrams for the following word: ";
    cin >> inputWord;
    anagrams = anagram(inputWord, words);
    for (int i=0; i<anagrams.size(); i++)
    {
        cout << anagrams[i] << endl;
    }
    return 0;
}
*/ 
vector<string> loadWordlist(string filename)
{
    vector<string> words;
    ifstream inFile;
    string word;
    inFile.open(filename);
    if(inFile.is_open())
    {
        while(getline(inFile,word))
        {
            if(word.length() > 0)
            {
                words.push_back(word);
            }
        }
        inFile.close();
    }
    return words;
}

//Implement this function
vector<string> anagram(string word, vector<string> wordlist)
{
    char recurrLet = NULL;
    string testWord = word;
    vector<string> spell;
    vector<string> newSpell;
    int match = 0;

    for(string fileWord : wordlist){
        if(testWord.size() == word.size()){
            for(int i = 0; i < word.size(); i++){
                for(int j = 0; j < word.size(); j++){
                    if(testWord[0] == fileWord[j]){
                        testWord.erase(0,1);
                    }
                }
            }

            if(testWord.size() == 0 && fileWord.size() == word.size()){
                spell.push_back(fileWord);
            }

            testWord = word;
        }
    }

    for(int i = 0; i < word.size(); i++){
        for(int j = i + 1; j < word.size(); j++)
        {
            if(word[i] == word[j]){
                recurrLet = word[i];
                break;
            }
        }
    }

    if(recurrLet != NULL){
        vector<string> newSpell;

        for(string w : spell){
            for(int i = 0; i < w.size(); i++){
                for(int j = i + 1; j < w.size(); j++){
                    if(w[i] == w[j] && w[i] == recurrLet){
                        newSpell.push_back(w);
                    }
                }
            }
        }

        for(string t : newSpell){
            spell.push_back(t);
            cout << "run" << endl;
        }

        return newSpell;
    }

    return spell;
}