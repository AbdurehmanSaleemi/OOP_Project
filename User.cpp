#include <iostream>

class Friends {
private:
    std::string friendID;

public:
    Friends(){
        friendID = "";
    }
    Friends(std::string ID){
        friendID = ID;
    }
    void setFriendId(std::string id){
        friendID = id;
    }
    std::string getFriend(){
        return friendID;
    }
};

class Page {
private:
    std::string pageTitle;
    char pagePost[50];
};

class User{
private:
    static int totalUsers;
    std::string userID;
    std::string userFirstName;
    std::string userLastName;
    Friends** userFriends;
    Page** userLikedPages;

public:
    int totalUserFriends = 0;
    int totalLikedPages = 0;
    User() {
        userFriends = new Friends * [totalUserFriends];
        for (int i = 0; i < totalUserFriends; i++){
            userFriends[i] = new Friends[totalUserFriends];
        }
        userLikedPages = new Page * [totalLikedPages];
        for (int i = 0; i < totalLikedPages; i++){
            userFriends[i] = new Friends[totalLikedPages];
        }
    }

    //User(int id, std::string fname, std)
};

int main() {
    return 0;
}