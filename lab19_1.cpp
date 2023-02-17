#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename,vector<string> &names,vector<int> &scores,vector<char> &grades){
    ifstream text("name_score.txt");
    string textline;
    char name[100];
    int x,y,z;
    while(getline(text,textline)){
        char format[]="%[^:]: %d %d %d";
        sscanf(textline.c_str(),format,name,&x,&y,&z);
        names.push_back(name);
        int score = x+y+z;
        scores.push_back(score);
        grades.push_back(score2grade(score));
    }
    text.close();

}

void getCommand(string &command,string &key){
    cout << "Please input your command: ";
    char com[20],k[100];
    string text;
    getline(cin,text);
    char format[]="%s %[^\n]";
    sscanf(text.c_str(),format,com,k);
    command = com;
    key = k;
    
}

void searchName(vector<string> names,vector<int> scores,vector<char> grades,string key){
    bool check =0;
    cout << "---------------------------------\n";
    for(unsigned int i=0;i < names.size() ;i++){
       
        if(toUpperStr(names[i])==key) {
            cout << names[i] << "'s score = " << scores[i] << endl;
            cout << names[i] << "'s grade = " << grades[i] << endl;
            check = 1;
            break;
        }
        
    }
    if(!check)cout << "Cannot found.\n";
    cout << "---------------------------------\n";
    

}

void searchGrade(vector<string> names,vector<int> scores,vector<char> grades,string key){
    cout << "---------------------------------\n";
    bool check =0;
    for(unsigned int i=0;i < grades.size();i++){
        if(grades[i]==key[0]){
            cout << names[i] << " (" << scores[i] << ")" << endl;
            check = 1;
        }
        
    }
    if(!check) cout << "Cannot found.\n";
    cout << "---------------------------------\n";
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
