#include <iostream>
#include <cstring>
#include <fstream>

class Friends {
private:
    char* friendID;

public:
    void init() {
        friendID = new char[5];
    }
    Friends() {
        init();
    }
    Friends(char*& ID) {
        init();
        for (int i = 0; i < 10; i++)
        {
            friendID[i] = ID[i];
        }
    }
    void setFriendId(char*& id) {
        init();
        for (int i = 0; i < 10; i++)
        {
            friendID[i] = id[i];
        }
    }
    char* getFriend() {
        return friendID;
    }
};

class Page {
private:
    char* pageID;
    char* pageTitle;
    char* pagePost;

public:
    void init() {
        pageID = new char[5];
        pageTitle = new char[50];
        pagePost = new char[70];
    }
    Page() {
        init();
    }
    Page(char* id, char* title, char* post) {
        init();
        // strcpy_s(pageID, 5, id);
        // strcpy_s(pageTitle, 50, title);
        // strcpy_s(pagePost, 70, post);
    }
    void setID(char*& id) {
        //strcpy_s(pageID, 5, id);
    }
    void setPageData(char*& id, char*& title, char*& post) {
        init();
        // strcpy_s(pageID, 5, id);
        // strcpy_s(pageTitle, 50, title);
        // strcpy_s(pagePost, 70, post);
    }
    char* getPageID() {
        return pageID;
    }
    char* getPageTitle() {
        return pageTitle;
    }
    char* getPagePost() {
        return pagePost;
    }
};

class User {
private:
    char* userID;
    char* firstName;
    char* LastName;
    Friends** userFriends;
    Page** userLikedPage;

public:
    void init() {
        userID = new char[3];
        firstName = new char[15];
        LastName = new char[15];
        userFriends = new Friends * [1];
        for (int i = 0; i < 1; i++)
        {
            userFriends[i] = new Friends[5];
        }
        userLikedPage = new Page * [1];
        for (int i = 0; i < 1; i++)
        {
            userLikedPage[i] = new Page[5];
        }
    }
    User() {
        init();
    }
    User(char* id, char* fname, char* lname, Friends **f, Page** p) {
        init();
        // strcpy_s(userID, 3, id);
        // strcpy_s(firstName, 15, fname);
        // strcpy_s(LastName, 15, lname);
        for (int i = 0; i < 1; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                char* friendID = new char[3];
                friendID = f[i][j].getFriend();
                userFriends[i][j].setFriendId(friendID);
                delete[] friendID;
            }
        }
        for (int i = 0; i < 1; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                char* id = new char[5];
                char* title = new char[50];
                char* post = new char[70];
                // strcpy_s(id, 5, p[i][j].getPageID());
                // strcpy_s(title, 50, p[i][j].getPageTitle());
                // strcpy_s(post, 70, p[i][j].getPagePost());
                userLikedPage[i][j].setPageData(id,title, post);
                delete[] title;
                delete[] post;
            }
        }
    }

    void setUserData(char* id, char* fname, char* lname, Friends** f, Page** p) {
        init();
        // strcpy_s(userID, 3, id);
        // strcpy_s(firstName, 15, fname);
        // strcpy_s(LastName, 15, lname);
        for (int i = 0; i < 1; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                char* friendID = new char[3];
                friendID = f[i][j].getFriend();
                userFriends[i][j].setFriendId(friendID);
                delete[] friendID;
            }
        }
        for (int i = 0; i < 1; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                char* id = new char[5];
                char* title = new char[50];
                char* post = new char[70];
                // strcpy(id, 5, p[i][j].getPageID());
                // strcpy(title, 50, p[i][j].getPageTitle());
                // strcpy(post, 70, p[i][j].getPagePost());
                userLikedPage[i][j].setPageData(id, title, post);
                delete[] title;
                delete[] post;
            }
        }
    }
    void print() {
        std::cout << userID << std::endl;
        std::cout << firstName << std::endl;
        std::cout << LastName << std::endl;
        for (int i = 0; i < 1; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                std::cout << userFriends[i][j].getFriend() << std::endl;
            }
        }
        for (int i = 0; i < 1; i++)
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
        delete[] userID;
        delete[] firstName;
        delete[] LastName;
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
    //char* p = new char[3];
    //p[0] = 'u';
    //p[1] = '1';
    //p[2] = '\0';
    //char fname[] = "Abdurehman";
    //char lname[] = "Saleemi";
    //char* fn = new char[15];
    //char* ln = new char[15];
    //strcpy_s(fn, 15, fname);
    //strcpy_s(ln, 15, lname);

    //Friends** f;
    //f = new Friends * [1];
    //for (int i = 0; i < 1; i++)
    //{
    //    f[i] = new Friends[5];
    //}
    //for (int i = 0; i < 1; i++)
    //{
    //    for (int j = 0; j < 5; j++)
    //    {
    //        char* p = new char[5];
    //        p[0] = 'u';
    //        p[1] = '1';
    //        p[2] = '\0';
    //        f[i][j].setFriendId(p);
    //        delete[] p;
    //    }
    //}

    //Page** page;
    //page = new Page * [1];
    //for (int i = 0; i < 1; i++)
    //{
    //    page[i] = new Page[5];
    //}
    //for (int i = 0; i < 1; i++)
    //{
    //    for (int j = 0; j < 5; j++)
    //    {
    //        char _tite[] = "AlJazeera";
    //        char post_[] = "Today Pakistan Stock Market went up by 500 points";
    //        char* title = new char[50];
    //        char* post = new char[70];
    //        strcpy_s(title, 50, _tite);
    //        strcpy_s(post, 70, post_);
    //        page[i][j].setPageData(title, post);
    //        delete[] title;
    //        delete[] post;
    //    }
    //}

   /* User u(p, fn, ln, f, page);
    u.print();*/
    std::ifstream dataRead;
    dataRead.open("Data/user.txt");

    int totalUsers;

    Friends** f;
    f = new Friends * [20];
    for (int i = 0; i < 1; i++)
    {
        f[i] = new Friends[5];
    }
    Page** p = new Page * [20];
    for (int i = 0; i < 1; i++)
    {
        p[i] = new Page[5];
    }
    bool check = true;

    dataRead >> totalUsers;
    User* u = new User[totalUsers];
    std::cout << totalUsers << std::endl;

    int i = 0;
    int j = 0;
    char* usrID = new char[5];
    char* usrFname = new char[15];
    char* usrLname = new char[15];
    std::string friendID;
    std::string pageID;

    while (!dataRead.eof()) {
        check = true;
        dataRead.getline(usrID, 5, ' ');
        std::cout << usrID << " ";
        dataRead.getline(usrFname, 15, ' ');
        std::cout << usrFname << " ";
        dataRead.getline(usrLname, 15, ' ');
        std::cout << usrLname << " ";
        while (check) {
            dataRead >> friendID;
            if (friendID == "-1") {
                check = false;
            }
            std::cout << friendID << " ";
        }
        check = true;
        while (check) {
            dataRead >> pageID;
            if (pageID == "-1") {
                check = false;
            }
            std::cout << pageID << " ";
        }
        //std::cout << std::endl;
    }
    return 0;
}