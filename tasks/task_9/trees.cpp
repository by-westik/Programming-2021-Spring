#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

string getNextVariable(string str);
bool isDigit(string str);
string getNextOperator(string str);

class Node{
public:
    string type;
    vector <Node*> childs[2];
    string value;
    Node(string _type, string _value)
    :type(move(_type))
    ,value(move(_value))
    {
    };
};

Node *parseString(string str){
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    str.erase(remove(str.begin(), str.end(), '\t'), str.end());
    if(str.empty()){
        return NULL;
    };
    vector <int> separatorIndexes = {-1};
    Node *tree = new Node("terminate", str);
    for(int i = (str[0] != '-') ? 0 : 1; i < str.length(); i++){
        string nextVar = getNextVariable(str.substr(i, str.length()));
        if(nextVar.empty()){
            return NULL;
        };
        i += nextVar.length();
        if(i == str.length()){
            break;
        };
        string operand = getNextOperator(str.substr(i, str.length()));
        if(operand == "n"){
            break;
        };
        map <string, int> typesEnum;
        typesEnum.insert(std::pair<string, int> ("*", 1));
        typesEnum.insert(std::pair<string, int> ("/", 2));
        typesEnum.insert(std::pair<string, int> ("-", 3));
        typesEnum.insert(std::pair<string, int> ("+", 4));
        typesEnum.insert(std::pair<string, int> ("terminate", -1000));
        typesEnum.insert(std::pair<string, int> ("brackets", -1000));
        
        if((typesEnum.find(operand) -> second) > (typesEnum.find(tree -> type) -> second)){
            tree -> type = operand;
            separatorIndexes.clear();
            separatorIndexes.push_back(-operand.length());
            separatorIndexes.push_back(i);
        };
    };
    if(tree -> type == "terminate"){
        int firstNonMinusIndex = (str[0] != '-') ? 0 : 1;
        if(str[firstNonMinusIndex] == '('){
            Node *child = parseString(str.substr(firstNonMinusIndex + 1, str.length() - 2));
            if(!child){
                return NULL;
            };
            tree -> childs -> clear();
            tree -> childs -> push_back(child);
            tree -> type = "brackets";
        };

        if(str[0] == '-'){
            Node *child = new Node(tree -> type, tree -> value.substr(1, str.length()));
            for(int i = 0; i < tree -> childs -> size(); i++){
                child -> childs -> push_back(tree -> childs -> at(i));
            };
            tree -> childs -> clear();
            tree -> childs -> push_back(child);
            tree -> type = "-";
        }
        return tree;
    };
    
    separatorIndexes.push_back(tree -> value.length());
    if(separatorIndexes.size() == 2){
        tree -> childs -> push_back(parseString(tree -> value.substr(separatorIndexes[0] + tree -> type.length(), separatorIndexes[1])));
        return tree;
    };
    Node *middle = parseString(tree -> value.substr(separatorIndexes[0] + tree -> type.length(), separatorIndexes[1]));

    for(int i = 2; i < separatorIndexes.size(); ++i){
        int left = separatorIndexes[i - 1] + 1, right = separatorIndexes[i];
        Node *insideTree = parseString(tree -> value.substr(left, right));
        Node *temporary = new Node(tree -> type, tree -> value.substr(0, right));
        temporary -> childs -> push_back(middle);
        temporary -> childs -> push_back(insideTree);
        middle = temporary;
    };

    return middle;
};

string getStringFromTree(Node *tree){
    if(tree -> type == "terminate"){
        return tree -> value;
    };
    if(tree -> type == "brackets"){
        return "(" + tree -> childs -> at(0) -> value + ")";
    };
    string res;
    for(int i = 0; i < (tree -> childs -> size()); i++){
        res += getStringFromTree(tree -> childs -> at(i)) + ((i + 1 < tree -> childs -> size()) ? tree -> type : "");
    };
    return res;
};

int calculate(Node *node){
    if(node -> type == "terminate"){
        return stoi(node -> value);
    };
    int result = 0;
    if(node -> type == "+"){
        result += calculate(node -> childs -> at(0)) + calculate(node -> childs -> at(1));
    } else if(node -> type == "-"){
        if(node -> childs -> size() == 2){
            result += calculate(node -> childs -> at(0)) - calculate(node -> childs -> at(1));
        } else if(node -> childs -> size() == 1){
            result += -(calculate(node -> childs -> at(0)));
        }
    } else if(node -> type == "*"){
        result += calculate(node -> childs -> at(0)) * calculate(node -> childs -> at(1));
    } else if(node -> type == "/"){
        result += calculate(node -> childs -> at(0)) / calculate(node -> childs -> at(1));
    } else if(node -> type == "brackets"){
        for(int i = 0; i < node -> childs -> size(); i++){
            result += calculate(node -> childs -> at(i));
        };
    };
    return result;
};

int main(){
    cout << "Введите выражение" << endl;
    string str;
    getline(cin, str);
    Node *tree = NULL;
    tree = parseString(str);
    cout << "STR = " << getStringFromTree(tree) << " = " << calculate(tree) << endl;
    return 0;
};

bool isDigit(string str){
    return all_of(str.begin(), str.end(), ::isdigit);
};

string getNextVariable(string str){
    if(str.empty()){
        return "";
    }
    if(isDigit(str)){
        return str;
    }
    string res = str;
    if(str[0] == '(') {
        int brackets = 1;
        int i;
        for (i = 1; i < str.length() && brackets > 0; i++) {
            if (str[i] == '(') {
                brackets++;
            } else if (str[i] == ')') {
                brackets--;
            }
        }
        return str.substr(0, i);
    }
    string operators = "+-*/";
    int index = res.find_first_of(operators, 0);
        if(index != -1){
        return res.substr(0, index);
    }
    return "";
};

string getNextOperator(string str){
    string operators = "+-*/";
    int ans = str.find_first_of(operators, 0);
    if(ans != -1){
        return string (1, str[ans]);
    }
    return "n";
}
