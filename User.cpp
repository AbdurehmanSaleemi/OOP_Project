#include <iostream>
#include <cstring>
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

public:
    Page(){
        pagePost[0] = '\0';
    }
    Page(std::string title, char post[]){
        pageTitle = title;
        strcpy(pagePost, post);
    }
    void setPageTitle(std::string title){
        pageTitle = title;
    }
    std::string getPageTitle(){
        return pageTitle;
    }
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

    User(std::string id, std::string fname, std::string lname, Friends** f, Page** p){
        userFriends = new Friends * [totalUserFriends];
        for (int i = 0; i < totalUserFriends; i++){
            userFriends[i] = new Friends[totalUserFriends];
        }
        userLikedPages = new Page * [totalLikedPages];
        for (int i = 0; i < totalLikedPages; i++){
            userFriends[i] = new Friends[totalLikedPages];
        }
        userID = id;
        userFirstName = fname;
        userLastName = lname;
        for (int i = 0; i < 1; i++)
        {
            for (int j = 0; j < totalUserFriends; j++)
            {
                userFriends[i][j] = f[i][j];   
            }
        }
        for (int i = 0; i < 1; i++)
        {
            for (int j = 0; j < totalLikedPages; j++)
            {
                userLikedPages[i][j] = p[i][j];   
            }
        }
    }

    void setUser(std::string id, std::string fname, std::string lname, Friends** f, Page** p){
        userFriends = new Friends * [totalUserFriends];
        for (int i = 0; i < totalUserFriends; i++){
            userFriends[i] = new Friends[totalUserFriends];
        }
        userLikedPages = new Page * [totalLikedPages];
        for (int i = 0; i < totalLikedPages; i++){
            userFriends[i] = new Friends[totalLikedPages];
        }
        userID = id;
        userFirstName = fname;
        userLastName = lname;
        for (int i = 0; i < 1; i++)
        {
            for (int j = 0; j < totalUserFriends; j++)
            {
                userFriends[i][j] = f[i][j];   
            }
        }
        for (int i = 0; i < 1; i++)
        {
            for (int j = 0; j < totalLikedPages; j++)
            {
                userLikedPages[i][j] = p[i][j];   
            }
        }
    }

    void print(){
        std::cout << "User ID = " << userID << std::endl;
        std::cout << "User First Name = " << userFirstName << std::endl;
        std::cout << "User Last Name = " << userLastName << std::endl;
        std::cout << "User Friends \n";
        for (int i = 0; i < 1; i++)
        {
            for (int j = 0; j < totalUserFriends; j++)
            {
                std::cout << userFriends[i][j].getFriend() << std::endl;
            }
        }
        for (int i = 0; i < 1; i++)
        {
            for (int j = 0; j < totalLikedPages; j++)
            {
                std::cout << userLikedPages[i][j].getPageTitle() << std::endl;
            } 
        }   
    }
};

int main() {
    Page **p = new Page*[1];
    for (int i = 0; i < 1; i++)
    {
        p[i] = new Page[3];
    }
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            p[i][j].setPageTitle("AlJazeera");
        }
    }
    Friends** f = new Friends*[1];
    for (int i = 0; i < 1; i++)
    {
        f[i] = new Friends[3];
    }
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            f[i][j].setFriendId("u1");
        }
    }
    User u;
    u.totalLikedPages = 3;
    u.totalUserFriends = 3;
    u.setUser("u1", "Saad", "Abad", f, p);
    u.print();
    return 0;
}