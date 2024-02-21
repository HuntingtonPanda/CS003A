#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>


using namespace std;

int main(int argv, char **argc)
{
    char sentence[1000];

    cout << "Type a sentence splitting punctuation, letters, and numbers:\n\n";
    cin.getline(sentence, 1000);

    char* word = strtok(sentence, " ");

    cout << "\n-------------------------------------------------------------\n\n";
    while (word != NULL) {
        
        cout << right << setw(20) << word << ": ";
        
        if (isalpha(*word))
            cout << setw(17) << "WORD\n";
        else if (isdigit(*word))
            cout << setw(17) << "NUMBER\n";
        else
            cout << setw(17) << "PUNCTUATION\n";
        
        word = strtok(NULL, " ");
    }

    return 0;
}
