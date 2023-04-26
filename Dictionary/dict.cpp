#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

void makeDictionaryFile()
{
    ofstream dictionaryFile("dictionary.txt");
    dictionaryFile.close();
}

void inputWordToDictionary(string word, string meaning)
{
    ifstream dictionaryFile("dictionary.txt");
    bool found = false;
    string line;
    while (getline(dictionaryFile, line))
    {
        stringstream ss(line);
        string currentWord;
        getline(ss, currentWord, ':');
        if (currentWord == word)
        {
            found = true;
            break;
        }
    }
    dictionaryFile.close();
    if (!found)
    {
        ofstream dictionaryFile("dictionary.txt", ios::app);
        dictionaryFile << word << ":" << meaning << endl;
        dictionaryFile.close();
        cout << "The word is added to the dictionary successfully" << endl;
    }
    else
    {
        cout << "The word is already exists in your dictionary" << endl;
    }
}


void findWordInDictionary(string word)
{
    ifstream dictionaryFile("dictionary.txt");
    string line;
    bool found = false;
    while (getline(dictionaryFile, line))
    {
        stringstream ss(line);
        string currentWord;
        getline(ss, currentWord, ':');
        if (currentWord == word)
        {
            string currentMeaning;
            getline(ss, currentMeaning);
            cout << currentMeaning << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "The word is not found in the  dictionary" << endl;
    }
    dictionaryFile.close();
}

void deleteWordFromDictionary(string word)
{
    ifstream dictionaryFile("dictionary.txt");
    ofstream tempFile("temp.txt");
    string line;
    bool found = false;
    while (getline(dictionaryFile, line))
    {
        stringstream ss(line);
        string currentWord;
        getline(ss, currentWord, ':');
        if (currentWord != word)
        {
            tempFile << line << endl;
        }
        else
        {
            found = true;
        }
    }
    if (found)
    {
        cout << "The word is sucessfully removed from the dictionary" << endl;
    }
    else
    {
        cout << "The word is not found in the  dictionary" << endl;
    }
    dictionaryFile.close();
    tempFile.close();
    remove("dictionary.txt");
    rename("temp.txt", "dictionary.txt");
}

int main()
{
    int option;
    string word, meaning;
    do
    {
        cout << "\nDictionary Generator Tool where we can easily Add , search and remove word from the dictionary" << endl;
        cout << "1. Create your Dictionary File" << endl;
        cout << "2. Add Word to your Dictionary file" << endl;
        cout << "3. Search Word in your  Dictionary file" << endl;
        cout << "4. Remove Word from your Dictionary file" << endl;
        cout << "5. Exit from the Dictionary file" << endl;
        cout << "Enter your option from the Above mentioned : ";
        cin >> option;
        switch (option)
        {
        case 1:
            makeDictionaryFile();
            cout << "Your Dictionary file is created successfully" << endl;
            break;
        case 2:
            cout << "Enter your word: ";
            cin >> word;
            cout << "Enter the meaning of the word: ";
            cin.ignore();
            getline(cin, meaning);
            inputWordToDictionary(word, meaning);
            cout << "The word is  added to the  dictionary successfully" << endl;
            break;
        case 3:
            cout << "Enter your word: ";
            cin >> word;
            findWordInDictionary(word);
            break;
        case 4:
            cout << "Enter your word: ";
            cin >> word;
            deleteWordFromDictionary(word);
            break;
        case 5:
            cout << "Exit from the dictionary ..." << endl;
            break;
        default:
            cout << "Invalid word.....not found " << endl;
        }
    } while (option != 5);
    return 0;
}
