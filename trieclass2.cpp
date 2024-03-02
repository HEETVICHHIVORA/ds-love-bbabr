#include<iostream>
#include<vector>
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
void findpre(tnode* root,string input,vector<string>& ans){
        

}

int main (){
      tnode * root = new tnode ('-');
insert(root, "cater");
insert(root, "care");
insert(root, "con"); 
insert(root, "lover");
insert(root, "loved");
insert(root, "load");
insert(root, "lov");
insert(root, "bat");
insert(root, "cat");
insert(root, "car");
cout<<"done inserting"<<endl;
string input = "c";
vector<string> ans ;
findpre(root,input,ans);
for(auto i: ans){
    cout<<i<<" ";
}
cout<<endl;
deleteword(root,"cater");
if(search(root,"cater")){
    cout<<"yes"<<endl;
}
else{
    cout<<"no"<<endl;
}
}