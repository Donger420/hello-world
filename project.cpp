#include <utility>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <string>

using std::sort;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::ifstream;
using std::for_each;
using std::fixed;
using std::string;
using std::find;
using std::to_string;
using std::pair; using std::make_pair;

void print_vect (string i) {
  cout << i << ", ";
}



int main() {
    ifstream fin;
    fin.open("common_passwords.txt");
    cout << "Give me a password: ";
    string password;
    cin >> password;
    //password = "catsnake";
    string pass_set;
    vector<string> vect;
    while(!fin.eof()) {
        if (fin >> pass_set){
            vect.push_back(pass_set);
        }
    sort(vect.begin(),vect.end());
    }
    vector<pair<string,int>> pair_vect;
    for(int i = 0; i < static_cast<int>(vect.size()); i++) {
        int count = 0;
        string temp = vect[i];
        if(temp.length() < password.length()){
            for(int n = 0; n < static_cast<int>(temp.size()); n++){
                if(temp[n] != password[n])
                count++;
            }
                count = count + (password.length() - temp.length());
        }
        else{
            for(int n = 0; n < static_cast<int>(password.size()); n++){
                if(temp[n] != password[n])
                count++;
            }
            count = count + (temp.length() - password.length());
        }
        pair<string, int> temp_pair = make_pair(temp,count);
        pair_vect.push_back(temp_pair);
    }
    int diff_num = 0;
    pair<string,int> tem;
    vector<string> out_vect;
    for(int j = 0; j < 10; j++){
        for(int i = 0; i < static_cast<int>(pair_vect.size()); i++) {
            tem = pair_vect[i];
            if (tem.second == j){
                out_vect.push_back(tem.first);
            }
        }
        if (out_vect.empty() == false){
            diff_num = j;
            break;
        }
    }
    int out_num = diff_num;
    cout << "You provided a password of " << password << endl << 
    "The most similar passwords to " << password << " are:" << endl;
    for_each(out_vect.begin(),out_vect.end(), print_vect);
    cout << endl << "All of which are " << out_num << " character(s) different.";
}
