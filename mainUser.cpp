#include <iostream>
#include <cstring>
#include <fstream>

class Friends {
private:
    std::string friendID;

public:
    Friends() {
        friendID = "";
    }
    Friends(std::string ID) {
        friendID = ID;
    }
    void setFriendId(std::string id) {
        friendID = id;
    }
    std::string getFriend() {
        return friendID;
    }
};

class Page {
private:
    std::string pageID;
    std::string pageTitle;
    std::string pagePost;

public:
    Page() {
        pageID = "";
        pageTitle = "";
        pagePost = "";
    }
    Page(std::string id, std::string title, std::string post) {
        pageID = id;
        pageTitle = title;
        pagePost = post;
    }
    void setID(std::string id) {
        pageID = id;
    }
    void setPageData(std::string id, std::string title, std::string post) {
        pageID = id;
        pageTitle = title;
        pagePost = post;
    }
    std::string getPageID() {
        return pageID;
    }
    std::string getPageTitle() {
        return pageTitle;
    }
    std::string getPagePost() {
        return pagePost;
    }
};

class User {
private:
    std::string userID;
    std::string firstName;
    std::string LastName;
    Friends** userFriends;
    Page** userLikedPage;

public:
    void init() {
        userFriends = new Friends * [5];
        for (int i = 0; i < 5; i++)
        {
            userFriends[i] = new Friends[5];
        }
        userLikedPage = new Page * [5];
        for (int i = 0; i < 5; i++)
        {
            userLikedPage[i] = new Page[5];
        }
    }
    User() {
        std::cout << "2D Array Intialized\n";
        init();
        userID = "";
        firstName = "";
        LastName = "";
    }
    User(std::string id, std::string fname, std::string lname, Friends **f, Page** p) {
        init();
        userID = id;
        firstName = fname;
        LastName = lname;
        for(int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++)
            {
                userFriends[i][j].setFriendId(f[i][j].getFriend());
            }
        }
        for(int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++)
            {
                userLikedPage[i][j].setID(p[i][j].getPageID());
            }
        }
    }

    void setUserData(std::string id, std::string fname, std::string lname, Friends **f, Page** p) {
        int i = 0;
        int j = 0;
        userID = id;
        firstName = fname;
        LastName = lname;
        for(; i < 5; i++) {
            for (; j < 5; j++)
            {
                userFriends[i][j].setFriendId(f[i][j].getFriend());
            }
        }

        int a = 0, b = 0;
        for(; a < 5; a++){
            for (; b < 5; b++)
            {
                userLikedPage[a][b].setID(p[a][b].getPageID());
            }
        }
    }

    void setUserId(std::string id){
        userID = id;
    }

    void setFirstName(std::string fname){
        firstName = fname;
    }

    void setLastName(std::string lname){
        LastName = lname;
    }

    void setFriendId(Friends **f){
        int i = 0;
        int j = 0;
        for(; i < i + 1; i++) {
            for (; j < j + 1; j++)
            {
                if(j == 4){
                    break;
                }
                userFriends[i][j].setFriendId(f[i][j].getFriend());
            }
        }
    }

    void setPageId(Page** p){
        int a = 0, b = 0;
        for(; a + 1; a++){
            for (; b + 1; b++)
            {
                if(b == 4){
                    break;
                }
                userLikedPage[a][b].setID(p[a][b].getPageID());
            }
        }
    }

    void print() {
        std::cout << userID << std::endl;
        std::cout << firstName << std::endl;
        std::cout << LastName << std::endl;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                std::cout << userFriends[i][j].getFriend() << std::endl;
            }
        }
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                std::cout << userLikedPage[i][j].getPageID() << std::endl;
                //std::cout << userLikedPage[i][j].getPageTitle() << std::endl;
                //std::cout << userLikedPage[i][j].getPagePost() << std::endl;
            }
        }
    }

    ~User() {
        for (int i = 0; i < 1; i++)
        {   
            delete[] userFriends[i];
        }
        for (int i = 0; i < 1; i++)
        {
            delete[] userLikedPage[i];
        }
    }
};

int main() {
    std::ifstream dataRead;
    dataRead.open("Data/user.txt");

    int totalUsers;

    Friends** f;
    f = new Friends * [5];
    for (int i = 0; i < 5; i++)
    {
        f[i] = new Friends[5];
    }
    Page** p = new Page * [5];
    for (int i = 0; i < 5; i++)
    {
        p[i] = new Page[5];
    }
    bool check = true;

    dataRead >> totalUsers;
    User* u = new User[totalUsers];
    std::cout << totalUsers << std::endl;

    int userIndex = 0;

    int i = 0;
    int j = 0;
    int k = 0, l = 0;
    // char* usrID = new char[5];
    // char* usrFname = new char[15];
    // char* usrLname = new char[15];
    std::string usrID;
    std::string usrFname;
    std::string usrLname;
    std::string friendID;
    std::string pageID;

    while (!dataRead.eof()) {
        i = 0, j = 0, k = 0, l = 0;
        check = true;
        dataRead >> usrID;
        //std::cout << usrID << " ";
        dataRead >> usrFname;
        //std::cout << usrFname << " ";
        dataRead >> usrLname;
        //std::cout << usrLname << " ";

        u[userIndex].setUserId(usrID);
        u[userIndex].setFirstName(usrFname);
        u[userIndex].setLastName(usrLname);

        while (check) {
            dataRead >> friendID;
            if (friendID == "-1") {
                check = false;
            }
            while(i < i + 1){
                while(j < j + 1){
                    f[i][j].setFriendId(friendID);
                    j++;
                }
                i++;
            }
        }
        check = true;
        while (check) {
            dataRead >> pageID;
            if (pageID == "-1") {
                check = false;
            }
            //std::cout << pageID << " ";
            while(k < k + 1){
                while(l < l + 1){
                    f[k][l].setFriendId(friendID);
                    l++;
                }
                k++;
            }
        }
    }

    for (int i = 0; i < 20; i++)
    {
        u[i].print();
    }
    return 0;
}