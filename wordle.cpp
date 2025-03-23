# include <iostream> // in/out functions like cout
# include <string> // library to work with strings
# include <fstream> // library to work with files
# include <sstream>

using namespace std;

string verify(string guess, string chosen_word) {
    string clean_guess = guess.substr(0, 5); // if the user enters a word with more than 5 letters
    
    // transform the guessed word in uppercase
    for(char &c : clean_guess){ // like "for char in clean_guess" and we're accessing each character by reference
        c = toupper(c);
    }
    
    // compare the letters
    char teste;
    string palavra = "aaaaa";
    for(int a = 0; a <= 4; a++){
        for(int b = 0; b <= 4; b++){
            if(clean_guess[a] == chosen_word[b]){
                if(a == b){
                    teste = clean_guess[a];
                    break;
                }else{
                    teste = tolower(clean_guess[a]);
                    break;
                }
            }else{
                teste = '*';
            } 
        }
        palavra[a] = teste;
    }
    return palavra;
}

void check(string output, string chosen_word, int tries){
    if(output == chosen_word){
        cout << "GANHOU!" << endl;  // can't be this way
    }else{
        if(tries == 5){
            cout << "PERDEU!" << endl;
        }
    }
}

int main(){
    
    ifstream words_file ("palavras.txt"); // Input File STREAM
    
    if (!words_file){
        cerr << "Error oppening the file" << endl;  // Console ERRor (standard error stream). writes immediately without buffering
        return 1; // Exit with error code
    }
    
    // getting the amount of words in the file and transforming it into an integer
    string amount;
    getline(words_file, amount);
    int number_of_words = stoi(amount); // stoi stands for String TO Integer
    
    // reading the key word from the user
    int key;
    cin >> key;
    
    // looping through the file and saving the key'th one in the chosen_word variable
    string chosen_word;
    for(int i = 0; i<key; i++){
        getline(words_file, chosen_word);
    }
    
    int tries = 0;
    while(tries <= 5){
        string guess;
        cin >> guess;
        
        string output = verify(guess, chosen_word);
        cout << output << endl;
        check(output, chosen_word, tries);
        tries ++;
    }
    words_file.close();
    return 0;
}