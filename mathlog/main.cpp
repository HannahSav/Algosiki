#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

const long long MOD = (int)(1e9)+7;
const long long ES = 313;

vector<long long> degES;

//*
long long my_hash(string str) {
  long long res = 0;
        for (char ch: str) {
        res *= ES;
    res += ch;
    res %= MOD;
  }
  return res;
}//*/
void full_deg() {
        degES.push_back(1);
  for (int i = 0; i < 1000; i++) {
        degES.push_back((degES[i] * ES) % MOD);
  }
}

struct myTree
{
        string s;
        int size;
  long long hs;
        myTree *left = NULL;
        myTree *right = NULL;

  myTree(string str) {
                s = str;
                        size = 1;
        hs = my_hash(str);
  }
};

bool eq(myTree* a, myTree* b) {
        if (a == NULL && b == NULL)
                return true;
        if (a == NULL || b == NULL)
                return false;
  return a->hs == b->hs;/*
        if (a->hs != b->hs) {
        return false;
  }
        if (a->size != b->size)
                return false;
  return a->s == b->s && eq(a->left, b->left) && eq(a->right, b->right);//*/
}

void print (myTree *tr){
        if(tr != NULL){
                if (tr->s == "->" || tr->s == "&" || tr->s == "|") {
                        cout << "(";
                }
                print(tr->left);
                cout << tr->s;
                print(tr->right);
                if (tr->s == "->" || tr->s == "&" || tr->s == "|") {
                        cout << ")";
                }
        }
}

void parse(string s1, myTree **t1){
    char c;
    int brackets = 0;
    for (int i = 0; i < s1.size(); i++) {
        c = s1[i];
        if (c == '(') brackets++;
        if (c == ')') brackets--;
        if( brackets == 0 && c == '-'){
                *t1 = new myTree("->");
                        parse(s1.substr(0, i), &((*t1)->left));
            parse(s1.substr(i + 2, s1.size() - 1), &((*t1)->right));
                                (*t1)->size = 1 + (*t1)->left->size + (*t1)->right->size;
                //(*t1)->hs = deg((*t1)->left->size)
                (*t1)->hs = int('(') * degES[(*t1)->left->size + (*t1)->right->size + 3]
                                                + ((*t1)->left->hs) * degES[(*t1)->right->size + 3]
                                                + my_hash("->") * degES[(*t1)->right->size + 1]
                                                + ((*t1)->right->hs) * degES[1]
                                                + int(')');
                (*t1)->hs %= MOD;
            return;
        }
    }
    for (int i = s1.size() - 1; i >= 0; i--) {
        c = s1[i];
        if (c == '(') brackets++;
        if (c == ')') brackets--;
        if(brackets == 0 && c == '|'){
            *t1 = new myTree("|");
            parse(s1.substr(0, i), &((*t1)->left));
            parse(s1.substr(i + 1, s1.size() - 1), &((*t1)->right));
                                (*t1)->size = 1 + (*t1)->left->size + (*t1)->right->size;
                (*t1)->hs = int('(') * degES[(*t1)->left->size + (*t1)->right->size + 2]
                                                + ((*t1)->left->hs) * degES[(*t1)->right->size + 2]
                                                + my_hash("|") * degES[(*t1)->right->size + 1]
                                                + ((*t1)->right->hs) * degES[1]
                                                + int(')');
                (*t1)->hs %= MOD;
            return;
        }
    }
    for (int i = s1.size()-1; i >= 0; i--) {
        c = s1[i];
        if (c == '(') brackets++;
        if (c == ')') brackets--;
        if(brackets == 0 && c == '&'){
            *t1 = new myTree("&");
            parse(s1.substr(0,i), &((*t1)->left));
            parse(s1.substr(i + 1, s1.size()-1), &((*t1)->right));
                                (*t1)->size = 1 + (*t1)->left->size + (*t1)->right->size;
                (*t1)->hs = int('(') * degES[(*t1)->left->size + (*t1)->right->size + 2]
                                                + ((*t1)->left->hs) * degES[(*t1)->right->size + 2]
                                                + my_hash("&") * degES[(*t1)->right->size + 1]
                                                + ((*t1)->right->hs) * degES[1]
                                                + int(')');
                (*t1)->hs %= MOD;
            return;
        }
    }
    for (int i = 0; i < s1.size(); i++) {
        c = s1[i];
        if (c == '(') brackets++;
        if (c == ')') brackets--;
        if (brackets == 0 && c == '!'){
            *t1 = new myTree("!");
            parse(s1.substr(i+1, s1.size()-1), &((*t1)->right));
                                (*t1)->size = 1 + (*t1)->right->size;
                (*t1)->hs = int('(') * degES[(*t1)->right->size + 2]
                                                + my_hash("!") * degES[(*t1)->right->size + 1]
                                                + ((*t1)->right->hs) * degES[1]
                                                + int(')');
                (*t1)->hs %= MOD;
            return;
        }
    }
    if (s1[0] == '(') {
      parse(s1.substr(1, s1.size()-2), t1);
    }
    else *t1 = new myTree(s1);
}

set<myTree*> Acs;
set<pair<int, myTree*>> Hyp;
vector<pair<int, pair<string, myTree*>>> Ans;

string remove_space(string s){
        for(int i = 0; i < s.size(); i++) {
                if(s[i] == ' ' || s[i] == '\t' || s[i] == '\r') s.erase(i,1);
        }
        return s;
}

set <string> zn = {"->", "!", "|", "&"};
map <string, myTree*> ABC;
vector<vector<int>> stringArtifacts; // факт использования, новый номер, тип строки(1-гип, 2-акс, 3-мп),родители для мп
vector<int> localVec;

bool eq_acs(myTree* a, myTree* b) {
        if (a == NULL && b == NULL)
        return true;
        if (a == NULL || b == NULL)
        return false;
        if ((zn.count(b->s) == 1) && (a->s != b->s))return false;
        if (zn.count(b->s) == 0){
                if(ABC.find(b->s)==ABC.end()) {
                        ABC.insert({b->s, a});
                        return true;
                }
                else if(eq(ABC[b->s],a)) return true;
                else  return false;
        }
        return eq_acs(a->left, b->left) && eq_acs(a->right, b->right);
}

bool check_acs(myTree* a){
        int j = 1;
        for (auto i:Acs) {
                ABC.clear();
                if(eq_acs(a, i)){
                        localVec.clear();
                        localVec.push_back(-1);
                        localVec.push_back(0);
                        localVec.push_back(2);
                        stringArtifacts.push_back(localVec);
                        Ans.push_back(make_pair(Ans.size()+1,make_pair(". Ax. sch. "+ to_string(j), a)));
                        return true;
                }
                j++;
        }
        return false;
}

bool check_same(myTree* a){
        for (auto i:Ans){
                if(eq(a, i.second.second))
                        return 0;
        }
        return 1;
}

bool check_hyp(myTree* a){
        for (auto i:Hyp)
        {
                if (eq(a, i.second)){
                        localVec.clear();
                        localVec.push_back(-1);
                        localVec.push_back(0);
                        localVec.push_back(1);
                        stringArtifacts.push_back(localVec);
                        Ans.push_back(make_pair(Ans.size()+1,make_pair(". Hypothesis "+ to_string(i.first), a)));
                        return true;
                }
        }
        return false;
}

unordered_map<long long, int> hashes, hole;


bool check_mp(myTree* a){
        if (hole.find(a->hs) != hole.end()) {
            int pos = hole[a->hs];
            if(eq(a, Ans[pos].second.second->right) && hashes.find(Ans[pos].second.second->left->hs) != hashes.end()){
                    int posj = hashes[Ans[pos].second.second->left->hs];
                    if(eq(Ans[pos].second.second->left, Ans[posj].second.second)){
                        localVec.clear();
                        localVec.push_back(-1);
                        localVec.push_back(0);
                        localVec.push_back(3);
                        localVec.push_back(Ans[pos].first);
                        localVec.push_back(Ans[posj].first);
                        stringArtifacts.push_back(localVec);
                        Ans.push_back(make_pair(Ans.size() + 1,make_pair(". M.P. ", a)));
                        return true;
                    }
            }
        }
        return false;
}

void check_parents(int i){
        //print (Ans[i-1].second.second);
        stringArtifacts[i][0] = 1;
        if(stringArtifacts[i][2] == 3){
                check_parents(stringArtifacts[i][3]);
                check_parents(stringArtifacts[i][4]);
        }
}

int main(void)
{
        full_deg();
        stringArtifacts.push_back(localVec);
        //Запишем все аксиомы
        struct myTree *acs1;
        parse("A->(B->A)", &acs1);
        Acs.insert(acs1);
        parse("(A->B)->(A->B->C)->(A->C)", &acs1);
        Acs.insert(acs1);
        parse("A->B->(A&B)", &acs1);
        Acs.insert(acs1);
        parse("(A&B)->A", &acs1);
        Acs.insert(acs1);
        parse("(A&B)->B", &acs1);
        Acs.insert(acs1);
        parse("A->(A|B)", &acs1);
        Acs.insert(acs1);
        parse("B->(A|B)", &acs1);
        Acs.insert(acs1);
        parse("(A->C)->(B->C)->((A|B)->C)", &acs1);
        Acs.insert(acs1);
        parse("(A->B)->((A->!B)->!A)", &acs1);
        Acs.insert(acs1);
        parse("!!A->A", &acs1);
        Acs.insert(acs1);

        //считаем гипотезы и саму штуку
        string myString;
        getline(cin, myString);
        //myString = remove_space(myString);
        int i=0;
        struct myTree *hyp1;
        string hyp="";
        int n = 1;
        while(myString[i] != '|' || myString[i+1] != '-'){
                if(myString[i] != ',') hyp += myString[i];
                else{
                        if(hyp!=""){
                                hyp = remove_space(hyp);
                                parse(hyp, &hyp1);
                                Hyp.insert(make_pair(n, hyp1));
                                n++;
                                i++;
                                hyp="";
                        }
                }
                i++;
        }
        hyp = remove_space(hyp);
        parse(hyp, &hyp1);
        Hyp.insert(make_pair(n, hyp1));
        //А еще утверждение считаем
        //myString = remove_space(myString);
        string ask = myString.substr(i+2);
        ask = remove_space(ask);
        struct myTree *myStringTree; //та строка, котрую мы проверяем
        bool b;
        while(getline(cin, myString)){
                //cout << 1;
                //getline(cin, myString);
                //b = true;
                //cout<< 1<< endl;
                myString = remove_space(myString);
                //cout<< 1<<endl;
                parse(myString, &myStringTree);
                if(check_same(myStringTree)) {
                        int cur_size = Ans.size();
                        if(!check_hyp(myStringTree))
                                if (!check_acs(myStringTree))
                                        if(check_mp(myStringTree) && myString==ask)
                                                break;
                        if (Ans.size() > cur_size) {
                            hashes[myStringTree->hs] = cur_size;
                            if (myStringTree->s == "->")
                                hole[myStringTree->right->hs] = cur_size;
                        }
                }

        }
        //cout<< 3<< endl;
        /*
        myString = remove_space(myString);
        parse(myString, &myStringTree);
        if(check_same(myStringTree)){
                if(!check_hyp(myStringTree))
                        if (!check_acs(myStringTree))
                                if(!check_mp(myStringTree))
                                {
                                }
        }*/
        //cout<<Ans.size()<<endl;
        //убираем лишние строки и перенумеровываем все, что можем
        if(Ans.size()>0){
                check_parents(Ans.size());
                n = 1;
                for(int i = 1; i < stringArtifacts.size(); i++){
                        if(stringArtifacts[i][0] == 1){
                                stringArtifacts[i][1] = n;
                                n++;
                        }
                }
        }
        if (Ans.size() == 0 || !eq(Ans[Ans.size()-1].second.second, myStringTree))
                cout << "Proof is incorrect";
        else{
                vector<myTree*> Hyp_vec;
                for(auto i : Hyp){
                if(i.second->s !="")
                        Hyp_vec.push_back(i.second);
                }
                for(int i = 0; i < Hyp_vec.size(); i++){
                        print(Hyp_vec[i]);
                        if(i != Hyp_vec.size()-1)
                                cout<< ",";
                        cout<<" ";
                }
                cout << "|- ";
                print(myStringTree);
                cout<< endl;
                for(int i = 0; i < Ans.size(); i++){
                        if(stringArtifacts[i+1][0] != -1){
                                cout << "[" << stringArtifacts[i+1][1] << Ans[i].second.first;
                                if(stringArtifacts[i+1][2] == 3)
                                        cout << stringArtifacts[stringArtifacts[i+1][3]][1] << ", "<< stringArtifacts[stringArtifacts[i+1][4]][1] ;
                        cout<< "] ";
                        print(Ans[i].second.second);
                        cout<< endl;
                        }
                }
        }
        return 0;
}
