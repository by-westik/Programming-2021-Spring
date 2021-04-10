#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


bool isOperator(char cym){
    string operators = "+-*/";
    for(int i = 0; i < 4; i++){
        if(cym == operators[i]){
            return true;
        }
    }
    return false;
};

bool isDigit(string str)
{
    return all_of(str.begin(), str.end(), ::isdigit);
}

int getNextVariable(string str){
    if(isDigit(str)){
        return stoi(str);
    }
    string res;
    if(str[0] == '(') {
        int brackets = 1;
        int i = 0;
        for (i = 1; i < str.length() && brackets > 0; i++) {
            if (str[i] == '(') {
                brackets++;
            } else if (str[i] == ')') {
                brackets--;
            }
        }
        res = str.substr(0, i);
    }
    if(res.empty()){
        res = str;
    }
    string operators = "+-*/";
    int index = res.find_first_of(operators, 0);
    if(index != -1){
        return stoi(res.substr(0, index));
    }
    return -1;
};

char getNextOperator(string str){
    string operators = "+-*/";
    int ans = str.find_first_of(operators, 0);
    if(ans != -1){
        return str[ans];
    }
    return 'n';
}

class Item{
public:
    int number;
    bool isOperator;
    string type;
    Item *left;
    Item *right;
    Item(int _number = 0, bool _isOperator = false, string _type = "", Item *_left = NULL, Item *_right = NULL)
    :number(_number)
    ,isOperator(_isOperator)
    ,type(_type)
    ,left(_left)
    ,right(_right)
    {
    };
};

void createTree(string str, Item &createdTree){
    cout << str << endl;
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    str.erase(remove(str.begin(), str.end(), '\t'), str.end());
    cout << str << endl;
  /*  if(str.empty()){
        return false;
    }*/
    int i = 0;
    int nextVar = getNextVariable(str.substr(0, str.length()));
 /*   if(nextVar == 'n'){
        return false;
    }*/
    i += (to_string(nextVar)).length();
   /* if(i == str.length()){
        return false;
    }*/
    string oper;
    oper.push_back(getNextOperator(str.substr(i,str.length() - i)));
   /* if(oper = 'n') {
        return false;
    }*/
  //  Item tree(0, true, to_string(oper), NULL, NULL);
    Item *left = new Item(nextVar, false, "exit", NULL, NULL);
   // tree.left = &left;
    int rightVariable = getNextVariable(str.substr(i + 1, str.length() - i - 1));
    Item *right = new Item(rightVariable, false, "exit", NULL, NULL);
  //
    Item tree(0, true, oper, NULL, NULL);
    tree.right = right;
    tree.left = left;
    createdTree = tree;
}
//Пока в дерево получается преобразовать формулы типа "1 + 2" "123/11" и тд. Это просто попытка 
int main() {
    string str;
    cout << "Vvedite formulu" << endl;
    getline(cin, str);
    Item tree(0, false, "", NULL, NULL);
    createTree(str, tree);
    cout << "type = " << tree.type << endl;
    cout << "left value = " << tree.left->number << endl;
    cout << "right value = " << tree.right->number << endl;
    return 0;
}
