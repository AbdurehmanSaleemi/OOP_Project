#include <iostream>

class User{
    protected:
    unsigned int uniqueID;
    std::string userName;

    public:
    User(){
        uniqueID = 0;
    }

    User(unsigned int id, std::string _name){
        uniqueID = id;
        userName = _name;
    }

    void setUniqueID(unsigned int id){
        uniqueID = id;
    }
    void setUserName(std::string _name){
        userName = _name;
    }
    unsigned int getUniqueID(){
        return uniqueID;
    }
    std::string getUserName(){
        return userName;
    }
};