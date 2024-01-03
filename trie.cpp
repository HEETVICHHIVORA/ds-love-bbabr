#include<iostream>
using namespace std ;
class tnode {
    public :
    char value ;
    tnode* children [26];
    bool terminal ;
    tnode(char val){
        this->value = val;
        for(int i=0;i<26;i++){
            children[i]=NULL;

        }
    this->terminal=false;
    }
};
void insert (tnode* root,string word ){
      // base case 
      cout<<"recieved "<<word<< " fore insert" <<endl;
      if(word.length()==0){
        root->terminal= true ;
        return  ;
      }
      char ch = word[0];
      int index = ch ='a';
      tnode* child ;
      if(root->children[index ]!=NULL){
        // present 
        child = root->children[index];
      }
      else{
        // absent 
        child = new tnode (ch);
        root->children[index] = child ;


//recursion 

      }
      insert(child,word.substr(1));
}
bool search(tnode* root ,string word){
    if(word.length()==0){
        return root->terminal;
    }
    char ch = word [0];
    int index = ch - 'a';
    tnode * child ;
    if(root->children[index]!=NULL){
        child = root->children[index];
    }
    else{
        return false;
    }
    bool recursionkaans  = search(child,word.substr(1));
    return recursionkaans;
}
void deleteword(tnode* root ,string word ){
    if(word.length()==0){
        root->terminal=false;
        return  ;
    }
    char ch = word[0];
    int index = ch-'a';
    if(root->children[index]!=NULL){
        child= root->children ;
        
    }

}
int main (){
      tnode * root = new tnode ('-');
insert(root, "cater");
insert(root, "care");
insert(root, "con"); 
insert(root, "lover");
insert(root, "Loved");
insert(root, "Load");
insert(root, "lov");
insert(root, "bat");
insert(root, "cat");
insert(root, "car");

}