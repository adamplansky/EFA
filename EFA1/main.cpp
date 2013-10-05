/*
 *      author: Adam Plansky
 *      fit username: plansada
 *      created: 5.10.2013
 *      email: plansada@fit.cvut.cz
 */



#ifndef __PROGTEST__
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#endif /* __PROGTEST__ */

class InteligenceStringArray {
public:
    InteligenceStringArray();
    void Add(const string &s);
    void Delete(const string &s);
    void Print(void);
private:
    int ArraySize;
    int Length;
    string * bug_log;
    void reallocateArray(int);
   // void presunpole(int parametr);
};

InteligenceStringArray::InteligenceStringArray(){
    ArraySize = 2;
    Length = 0;
    bug_log = new string[ArraySize];
}
void InteligenceStringArray::reallocateArray(int newArraySize){
    cout << "REALUKUJU" << endl;
    string * newData = new string[newArraySize];
    for(int i = 0; i < ArraySize; i++){
        newData[i] = bug_log[i];
    }
    delete []bug_log;
    ArraySize = newArraySize;
    bug_log = newData;
}
void InteligenceStringArray::Delete(const string& s){
    
}
void InteligenceStringArray::Add(const string& s){
    if(ArraySize<=Length)reallocateArray(ArraySize*2);
    bug_log[Length++] = s;
}
void InteligenceStringArray::Print(void){
    for(int i = 0; i < Length; i++){
        cout << bug_log[i] << ", ";
    }
}


class CDatabase {
public:
    CDatabase();
    void AddBug(const string & name, const string & area);
    void DelBug(const string & name);
    void Print(ostream & os) const;
private:
    // implementation 
};

CDatabase::CDatabase() {
    InteligenceStringArray();
}

void CDatabase::AddBug(const string& name, const string& area) {

}

#ifndef __PROGTEST__

int main(void) {
//    CDatabase x1;
//    x1 . AddBug("t9 pod 23", "NSA");
//    x1 . AddBug("t9 pod 24", "FSB");
//    x1 . AddBug("t9 pod 25", "NSA");
//    x1 . Print(cout);
    InteligenceStringArray isa;
    isa.Add("ABC");
    isa.Add("ABC1");
    isa.Add("ABC2");
    isa.Add("ABC");
    isa.Add("ABC1");
    isa.Add("ABC2");
    isa.Add("ABC");
    isa.Add("ABC1");
    isa.Add("ABC2");
    isa.Print();
    return 0;
}
#endif /* __PROGTEST__ */