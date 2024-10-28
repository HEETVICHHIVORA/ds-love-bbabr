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
      
      if(word.length()==0){
        root->terminal= true ;
        return  ;
      }
      char ch = word[0];
      int index = ch -'a';
      tnode* child ;
      if(root->children[index ]!=NULL){
        // present 
        child = root->children[index];
      }
      else{
        // absent 
        child = new tnode (ch);
        root->children[index] = child ;
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
    tnode* child ;
    int index = ch-'a';
    if(root->children[index]!=NULL){
        child= root->children [index];
        
    }
    else{
        return ;
    }
 deleteword(child,word.substr(1));
   

}

int main (){
      tnode * root = new tnode ('-');
insert(root, "paras");
insert(root, "param");
insert(root, "saas"); 
insert(root, "pras");
insert(root, "veet");
insert(root, "vt");
insert(root, "heet");
insert(root, "oeet");
insert(root, "oat");
cout<<"done inserting"<<endl;
// deleteword(root,"cater");
// if(search(root,"cater")){
//     cout<<"yes"<<endl;
// }
// else{
//     cout<<"no"<<endl;
// }
}