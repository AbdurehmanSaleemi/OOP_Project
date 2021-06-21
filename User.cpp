//add strcpy_s in final version of code

#include <iostream>
#include <cstring>
class Friends {
private:
    char* friendID;

public:
    void init() {
        if (friendID != nullptr) {
            delete[] friendID;
        }
        friendID = new char[5];
    }
    Friends() {
        init();
    }
    Friends(char*& ID) {
        init();
        strcpy(friendID, ID);
    }
    void setFriendId(char* id) {
        init();
        strcpy(friendID, id);
    }
    char* getFriend() {
        return friendID;
    }
};

class Page {
private:
    std::string pageTitle;
    char pagePost[50];

public:
    Page() {
        pagePost[0] = '\0';
    }
    Page(std::string title, char post[]) {
        pageTitle = title;
        strcpy(pagePost, post);
    }
    void setPageTitle(std::string title) {
        pageTitle = title;
    }
    std::string getPageTitle() {
        return pageTitle;
    }
};

class User {
protected:
    static int totalUsers;
    std::string userID;
    std::string userFirstName;
    std::string userLastName;
    Friends** userFriends = new Friends * [1];
    Page** userLikedPages = new Page * [1];

public:
    int totalUserFriends = 3;
    int totalLikedPages = 3;
    void init() {
        for (int i = 0; i < totalUserFriends; i++) {
            userFriends[i] = new Friends[totalUserFriends];
        }
        for (int i = 0; i < totalLikedPages; i++) {
            userLikedPages[i] = new Page[totalLikedPages];
        }
    }
    User() {
        init();
    }

    User(std::string id, std::string fname, std::string lname, Friends** f, Page** p) {
        init();
        userID = id;
        userFirstName = fname;
        userLastName = lname;
        for (int i = 0; i < 1; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                userFriends[i][j].setFriendId(f[i][j].getFriend());
            }
        }

        for (int i = 0; i < 1; i++)
        {
            for (int j = 0; j < totalLikedPages; j++)
            {
                userLikedPages[i][j].setPageTitle(p[i][j].getPageTitle());
            }
        }
    }

    void setUser(std::string id, std::string fname, std::string lname, Friends** f, Page** p) {
        userID = id;
        userFirstName = fname;
        userLastName = lname;
        for (int i = 0; i < 1; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                userFriends[i][j].setFriendId(f[i][j].getFriend());
            }
        }
        for (int i = 0; i < 1; i++)
        {
            for (int j = 0; j < totalLikedPages; j++) {
                userLikedPages[i][j].setPageTitle(p[i][j].getPageTitle());
            }
        }
    }

    void print() {
        std::cout << "User ID = " << userID << std::endl;
        std::cout << "User First Name = " << userFirstName << std::endl;
        std::cout << "User Last Name = " << userLastName << std::endl;
        std::cout << "User Friends \n";
        for (int i = 0; i < 1; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                std::cout << userFriends[i][j].getFriend() << std::endl;
            }
        }
        std::cout << "User Pages \n";
        for (int i = 0; i < 1; i++)
        {
            for (int j = 0; j < totalLikedPages; j++)
            {
                std::cout << userLikedPages[i][j].getPageTitle() << std::endl;
            }
        }
    }

    ~User() {
        delete[] userFriends[0];
        delete[] userLikedPages[0];
    }
};

int main() {
    Page** p = new Page * [1];
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
    Friends** f = new Friends * [1];
    for (int i = 0; i < 1; i++)
    {
        f[i] = new Friends[3];
    }
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            char* p = new char[5];
            p[0] = 'u';
            p[1] = '1';
            f[i][j].setFriendId(p);
        }
    }
    User u;
    u.print();
    return 0;
}