#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
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
    std::string pagePost[5];
    std::string pageComment[3];

public:
    int cmntIndex = 0;
    int postArray = 0;
    
    Page() {
        pageID = "";
        pageTitle = "";
        for (int i = 0; i < 5; i++)
        {
            pagePost[i] = "";
        }
        cmntIndex = 0;
        postArray = 0;
    }
    void setID(std::string id) {
        pageID = id;
    }

    void setPageComment(std::string pgCmnt) {
        pageComment[cmntIndex] = pgCmnt;
        cmntIndex++;
    }

    void setPageTitle(std::string _title) {
        pageTitle = _title;
    }

    void setPagePost(std::string post) {
        pagePost[postArray] = post;
        postArray++;
    }

    std::string getPageComment(int i) {
        return pageComment[i];
    }
    std::string getPageID() {
        return pageID;
    }
    std::string getPageTitle() {
        return pageTitle;
    }
    std::string getPagePost(int i) {
        return pagePost[i];
    }

    void printPage() {
        std::cout << "--------------\n";
        std::cout << getPageID() << " " << getPageTitle() << "\n";
        for (int i = 0; i < 5; i++)
        {
            if (getPagePost(i) != "") {
                std::cout << getPagePost(i) << "\n";
            }
        }
    }
};

class Users {
private:
    std::string userId;
    std::string userFirstName;
    std::string userLastName;
    std::string usrComment[10];
    std::string userPost[5];
    Friends** userFriends;
    Page** userLikedPages;
    int totalUserFriends;
    int totalUserPages;

public:
    int j = 0, k = 0;
    int m = 0;
    int cmntIndex = 0;
    void init() {
        userFriends = new Friends * [1];
        for (int i = 0; i < 1; i++)
        {
            userFriends[i] = new Friends[10];
        }
        userLikedPages = new Page * [1];
        for (int i = 0; i < 1; i++)
        {
            userLikedPages[i] = new Page[10];
        }
        for (int i = 0; i < 5; i++) {
            userPost[i] = "";
        }
    }

    Users() {
        init();
        j = 0;
        k = 0;
        m = 0;
        cmntIndex = 0;
        totalUserFriends = 0;
        totalUserPages = 0;
    }

    void setUserId(std::string id) {
        userId = id;
    }
    void setUserFirstName(std::string fName) {
        userFirstName = fName;
    }
    void setUserLastName(std::string lName) {
        userLastName = lName;
    }
    void setUserComment(std::string cmnt) {
        usrComment[cmntIndex] = cmnt;
        cmntIndex++;
    }
    void setUserFriends(std::string friendID) {
        userFriends[0][j].setFriendId(friendID);
        j++;
        totalUserFriends++;
    }
    void setUserPages(std::string pageId) {
        userLikedPages[0][k].setID(pageId);
        k++;
        totalUserPages++;
    }

    void setUserPost(std::string post) {
        userPost[m] = post;
        m++;
    }

    std::string getUserID() {
        return userId;
    }

    std::string getUserFirstName() {
        return userFirstName;
    }
    std::string getUserLastName() {
        return userLastName;
    }
    std::string getUserPost(int k) {
        return userPost[k];
    }
    std::string getUserComment(int i) {
        return usrComment[i];
    }
    std::string getUserFriendID(int i) {
        return userFriends[0][i].getFriend();
    }
    std::string getUserPages(int i) {
        return userLikedPages[0][i].getPageID();
    }
    int getTotalFriends() {
        return totalUserFriends;
    }
    int getTotalPages() {
        return totalUserPages;
    }
    std::string getUsrPost(int i) {
        return userPost[i];
    }

    void print() {
        std::cout << userId << " " << userFirstName << " " << userLastName;
        for (int i = 0; i < 10; i++) {
            if (userFriends[0][i].getFriend() != "") {
                std::cout << " " << userFriends[0][i].getFriend();
            }
        }
        for (int i = 0; i < 10; i++) {
            if (userLikedPages[0][i].getPageID() != "") {
                std::cout << " " << userLikedPages[0][i].getPageID();
            }
        }
        std::cout << std::endl;
    }

    ~Users() {
        for (int i = 0; i < 1; i++) {
            delete[] userFriends[i];
        }
        for (int i = 0; i < 1; i++)
        {
            delete[] userLikedPages[i];
        }
    }
};

class Activity {
private:
    int activityType;
    std::string activityValue;

public:
    Activity() {
        activityType = 0;
        activityValue = "";
    }

    void setActivityType(int t) {
        activityType = t;
    }
    void setActivityValue(std::string value) {
        activityValue = value;
    }

    int getActivityType() {
        return activityType;
    }
    std::string getActivityValue() {
        return activityValue;
    }
};

class Post {
private:
    std::string postID;
    std::string date;
    std::string postContent;
    std::string UsrSharedBy;
    std::string PageSharedBy;
    std::string usrLike[10];
    std::string pageLike[10];
    Page** pageContent;
    Users** usrContent;
    Activity activity;
    //Comment commentOnPost;

public:

    int i = 0, j = 0;
    int usrC = 0, pageC = 0;
    void init() {
        postID = "";
        date = "";
        postContent = "";
        i = 0, j = 0;
        usrC = 0, pageC = 0;

        pageContent = new Page * [1];
        for (int i = 0; i < 1; i++)
        {
            pageContent[i] = new Page[5];
        }
        usrContent = new Users * [1];
        for (int i = 0; i < 1; i++)
        {
            usrContent[i] = new Users[5];
        }
    }

    Post() {
        init();
    }
    void setPostID(std::string id) {
        postID = id;
    }

    void setPostDate(std::string d) {
        date = d;
    }

    void setShareUsr(std::string shareUsr) {
        UsrSharedBy = shareUsr;
    }
    void setSharePage(std::string sharePage) {
        PageSharedBy = sharePage;
    }

    void setPageContent(std::string content) {
        pageContent[0][pageC].setPagePost(content);
        pageC++;
    }

    void setUserContent(std::string content) {
        usrContent[0][usrC].setUserPost(content);
        usrC++;
    }

    void setLikeUser(std::string usr) {
        usrLike[i] = usr;
        i++;
    }
    void setPageLike(std::string pgLike) {
        pageLike[j] = pgLike;
        j++;
    }

    void setActivtyData(int t, std::string val) {
        activity.setActivityType(t);
        activity.setActivityValue(val);
    }

    std::string getPostID() {
        return postID;
    }
    std::string getPostDate() {
        return date;
    }
    std::string getUsrLike(int m) {
        return usrLike[m];
    }
    std::string getPageLike(int n) {
        return pageLike[n];
    }
    std::string getShareUsr() {
        return UsrSharedBy;
    }
    std::string getSharePage() {
        return PageSharedBy;
    }
    std::string getUsrContent(int i) {
        return usrContent[0][i].getUserPost(i);
    }

    void print() {
        std::cout << "----------------------------------\n";
        std::cout << "ID = " << getPostID() << "\n" << "Date = " << getPostDate() << "\n";
        std::cout << "=== Post ===\n";
        for (int i = 0; i < 5; i++)
        {
            if (usrContent[0][i].getUserPost(i) != "") {
                std::cout << usrContent[0][i].getUserPost(i) << std::endl;
            }
        }
        for (int i = 0; i < 5; i++) {
            if (pageContent[0][i].getPagePost(i) != "") {
                std::cout << pageContent[0][i].getPagePost(i) << std::endl;
            }
        }
        std::cout << "Posted By = ";
        if (getSharePage() != "") {
            std::cout << getSharePage() << std::endl;
        }
        if (getShareUsr() != "") {
            std::cout << getShareUsr() << std::endl;
        }
        std::cout << "Liked By = ";
        for (int a = 0; a < 5; a++)
        {
            std::cout << getUsrLike(a) << " ";
        }
        std::cout << std::endl;
        for (int a = 0; a < 5; a++)
        {
            std::cout << getPageLike(a) << " ";
        }
        std::cout << std::endl;
    }
    ~Post() {
        for (int i = 0; i < 1; i++)
        {
            delete[] pageContent[i];
        }
        delete[] pageContent;

        for (int i = 0; i < 1; i++)
        {
            delete[] usrContent[i];
        }
        delete[] usrContent;
    }
};



class Comment {
private:
    std::string commentID;
    Page pgComment;
    Users urComment;
    std::string commentType;
    std::string idOfCommentHolder;

public:
    Comment() {
        commentID = "";
        commentType = "";
    }
    void setCommentID(std::string cId) {
        commentID = cId;
    }
    void setPageComment(std::string pageComment) {
        pgComment.setPageComment(pageComment);
    }
    void setUserComment(std::string usrC) {
        urComment.setUserComment(usrC);
    }
    void setCommentType(std::string type) {
        commentType = type;
    }
    void setIdOfHolder(std::string id) {
        idOfCommentHolder = id;
    }

    std::string getCommentHolderID() {
        return idOfCommentHolder;
    }
    std::string getCommentID() {
        return commentID;
    }
    std::string getCommentType() {
        return commentType;
    }
    std::string getCommentUsr(int i) {
        return urComment.getUserComment(i);
    }
    std::string getCommentPage(int i) {
        return pgComment.getPageComment(i);
    }

    int i = 0;
    void printComment() {
        std::cout << getCommentID() << " " << getCommentType()  << " " << urComment.getUserComment(i) << " " << pgComment.getPageComment(i) << std::endl;
        i++;
    }
    ~Comment() {}
};

class SocialMediaApp {
private:
    std::ifstream readUsers;
    std::ifstream readComments;
    std::ifstream readPage;
    std::ifstream readPosts;
    int totalUsers;
    Friends** f;
    Page* pagesOfUsers;
    Users* u;
    Comment* comment;
    Post* post;
    int gloabalIndex = 0;

public:

    int commentArray = 11;
    void extendArray(Comment*& arr, int size) {
        int newSize = size + 1;
        Comment* newArr = new Comment[newSize];
        for (int i = 0; i < size; i++)
        {
            newArr[i] = arr[i];
        }
        size = newSize;
        delete[] arr;
        arr = newArr;
    }

    void init() {
        readUsers.open("user.txt");
        readComments.open("SocialNetworkComments.txt");
        readPage.open("SocialNetworkPages.txt");
        readPosts.open("SocialNetworkPosts.txt");
        f = new Friends * [1];
        for (int i = 0; i < 1; i++)
        {
            f[i] = new Friends[9];
        }
    }

    SocialMediaApp() {
        init();
    }

    void loadPostsFromFile() {
        char seprator[35] = { 0 };
        char postID[10];
        char date[15];
        char postContent[200];
        char activityTemp[50];
        char shareBy[20];
        int actVal = 0;
        char tempStr[5];
        std::string likeBy;

        int totalPosts;
        readPosts >> totalPosts;
        post = new Post[totalPosts];

        int a = 0;
        int indexOfPost = 0;
        while (!readPosts.eof()) {
            char activityVal[20] = { 0 };
            bool check = true;
            //std::cout << "------------------------------\n";
            readPosts.ignore();
            readPosts.getline(postID, 10, '\n');
            post[indexOfPost].setPostID(postID);
            //std::cout << postID << std::endl;
            readPosts.get(date, 15);
            post[indexOfPost].setPostDate(date);
            //std::cout << date << std::endl;
            readPosts.ignore();
            readPosts.get(postContent, 200);
            readPosts.ignore();
            readPosts.get(activityTemp, 50);
            /*tempStr[0] = activityTemp[0];
            actVal = std::atoi(tempStr);
            int j = 0;
            for (int i = 2; i < strlen(activityTemp); i++)
            {
                activityVal[j] = activityTemp[i];
                j++;
            }
            std::cout << actVal << " ";
            std::cout << activityVal << std::endl;*/
            readPosts.ignore();
            readPosts.get(shareBy, 20);
            if (shareBy[0] == 'u') {
                post[indexOfPost].setShareUsr(shareBy);
                post[indexOfPost].setUserContent(postContent);
            }
            else{
                post[indexOfPost].setSharePage(shareBy);
                post[indexOfPost].setPageContent(postContent);
            }
            readPosts.ignore();
            while (check) {
                int i = 0;
                readPosts >> likeBy;
                if (likeBy == "-1") {
                    check = false;
                }
                else {
                    if (likeBy[i] == 'u') {
                        post[indexOfPost].setLikeUser(likeBy);
                        //std::cout << likeBy << " ";
                    }
                    else {
                        post[indexOfPost].setPageLike(likeBy);
                        //std::cout << likeBy << " ";
                    }
                    
                }
            }
            indexOfPost++;
        }
    }

    void loadCommentsFromFile() {
        char Cid[10];
        char postId[10];
        //std::string commentType;
        char commentType[7]{ "\0" };
        char _comment[150] = { "\0" };
        int totalComments;

        int commentIndex = 0;
        readComments >> totalComments;
        comment = new Comment[totalComments];

        while (!readComments.eof()) { 
            readComments.getline(Cid, 10, '\t');
            //std::cout << Cid;
            comment[commentIndex].setCommentID(Cid);
            readComments.getline(postId, 10, '\t');
            comment[commentIndex].setIdOfHolder(postId);
            //std::cout << " " << postId;
            readComments.getline(commentType, 7, '\t');
            comment[commentIndex].setCommentType(commentType);
            //std::cout << " " << commentType;
            readComments.getline(_comment, 150, '\n');
            //std::cout << " " << _comment << "\n";
            if (commentType[0] == 'u') {
                comment[commentIndex].setUserComment(_comment);
            }
            else if(commentType[0] == 'p'){
                comment[commentIndex].setPageComment(_comment);
            }
            commentIndex++;
        }
    }

    void loadPagesFromFile() {
        char pageID[5];
        char pageName[150] = {"0"};

        int totalPages;
        readPage >> totalPages;
        pagesOfUsers = new Page[totalPages];
        int indexOfPage = 0;

        while (!readPage.eof()) {
            readPage.getline(pageID, 5, '\t');
            pagesOfUsers[indexOfPage].setID(pageID);
            //std::cout << pageID << "\t";
            readPage.getline(pageName, 150, '\n');
            pagesOfUsers[indexOfPage].setPageTitle(pageName);
            //std::cout << pageName << std::endl;
            indexOfPage++;
        }
    }


    void loadUsersFromFile() {
        bool check = true;
        readUsers >> totalUsers;
        u = new Users[totalUsers];

        int userIndex = 0;

        int i = 0;
        int j = 0;
        int k = 0, l = 0;
        std::string usrID;
        std::string usrFname;
        std::string usrLname;
        std::string friendID;
        std::string pageID;

        while (!readUsers.eof()) {
            i = 0, j = 0, k = 0, l = 0;
            check = true;
            readUsers >> usrID;
            readUsers >> usrFname;
            readUsers >> usrLname;

            u[userIndex].setUserId(usrID);
            u[userIndex].setUserFirstName(usrFname);
            u[userIndex].setUserLastName(usrLname);

            while (check) {
                readUsers >> friendID;
                if (friendID == "-1") {
                    check = false;
                }
                if (friendID != "-1") {
                    u[userIndex].setUserFriends(friendID);
                }
            }
            check = true;
            while (check) {
                readUsers >> pageID;
                if (pageID == "-1") {
                    check = false;
                }
                else {
                    u[userIndex].setUserPages(pageID);
                }
            }
            userIndex++;
        }
    }
    void setCurrentUser(std::string usrID) {

        std::cout << "Command \t" << "set " << usrID << " current user\n";
        std::cout << "-----------------------------------\n";
        
        for (int i = 0; i < 20; i++)
        {
            if (usrID == u[i].getUserID()) {
                gloabalIndex = i;
            }
        }
        std::cout << u[gloabalIndex].getUserFirstName() << " " << u[gloabalIndex].getUserLastName() << " has successfully logged in\n";
    }

    void viewHomePage() {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Command \t" << "View Home\n";
        int index = 0;
        std::string id;
        for (int i = 0; i < u[gloabalIndex].getTotalFriends(); i++)
        {
            id = u[gloabalIndex].getUserFriendID(i);
            for (int j = 0; j < 11; j++)
            {
                if (id == post[j].getShareUsr()) {
                    viewPost(post[j].getPostID());
                }
            }
        }
        for (int i = 0; i < u[gloabalIndex].getTotalPages(); i++)
        {
            id = u[gloabalIndex].getUserPages(i);
            for (int j = 0; j < 11; j++)
            {
                if (id == post[j].getSharePage()) {
                    viewPost(post[j].getPostID());
                }
            }
        }
    }

    void likeApost(std::string postID) {
        std::cout << std::endl;
        std::cout << std::endl;
        int index = 0;
        std::cout << "Command \t" << "Like Post(" << postID << ")\n";
        for (int i = 0; i < 11; i++)
        {
            if (postID == post[i].getPostID()) {
                index = i;
            }
        }
        post[index].setLikeUser(u[gloabalIndex].getUserID());
        post[index].print();
    }

    void viewPost(std::string postID) {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Command \t" << "View Post(" << postID << ")\n";
        int indexOfComment[5] = { 0 };
        for (int i = 0; i < 11; i++)
        {
            if (postID == post[i].getPostID()) {
                post[i].print();
            }
        }

        std::string user;
        int a = 0;
        int temp = 0;
        std::cout << "Comments\n";
        for (int i = 0; i < 12; i++)
        {
            if (postID == comment[i].getCommentHolderID()) {
                indexOfComment[temp] = i;
                temp++;
            }
        }

        int tempIndex = 0;
        for (int i = 0; i < temp; i++)
        {
            a = 0;
            //searching user
            for (int j = 0; j < 20; j++)
            {
                if (comment[indexOfComment[i]].getCommentType() == u[j].getUserID()) {
                    tempIndex = j;
                }
            }
            std::cout << u[tempIndex].getUserFirstName() << " wrote : ";
            while (a < 5) {
                std::cout << comment[indexOfComment[i]].getCommentUsr(a);
                a++;
            }
            std::cout << std::endl;
        } 
    }
    
    void addComment() {
        std::cout << std::endl;
        std::cout << std::endl;
        int index = 0;
        std::string postID;
        postID = "post4";
        std::cout << "Command \t" << "Add Comnent(" << postID << ")\n";
        std::cout << "-----------------------------------\n";
        std::string userComment;
        userComment = "Good Luck for your Result";
        extendArray(comment, commentArray);
        comment[commentArray].setCommentID("c13");
        comment[commentArray].setCommentType(postID);
        comment[commentArray].setUserComment(userComment);
        comment[commentArray].printComment();

    }

    void userTimeline() {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "-----------------------------------\n";
        std::cout << u[gloabalIndex].getUserFirstName() << " " << u[gloabalIndex].getUserLastName() << " Timeline\n";
        for (int i = 0; i < 11; i++)
        {
            if (u[gloabalIndex].getUserID() == post[i].getShareUsr()) {
                viewPost(post[i].getPostID());
            }
        }
    }

    void showFriendList() {
        std::cout << std::endl;
        std::cout << "Command \t" << "Show FriendsList(" << u[gloabalIndex].getUserID() << ")\n";
        std::cout << "==========================================\n";
        std::string friendID;
        for (int i = 0; i < u[gloabalIndex].getTotalFriends(); i++)
        {
            int index = 0;
            friendID = u[gloabalIndex].getUserFriendID(i);
            for (int j = 0; j < 20; j++)
            {
                if (friendID == u[j].getUserID()) {
                    index = i;
                }
            }
            std::cout << friendID << " ";
            std::cout << u[index].getUserFirstName() << " " << u[index].getUserLastName() << std::endl;
        }
    }

    void showPage(std::string pageID) {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Command \t" << "Show Page(" << pageID << ")\n";
        std::cout << "==========================================\n";
        for (int i = 0; i < 11; i++)
        {
            if (pageID == post[i].getSharePage()) {
                viewPost(post[i].getPostID());
            }
        }
        std::cout << "==========================================\n";
    }

    void searchKeyword(std::string str) {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Users list containing " << "(" << str << ")\n";
        std::cout << std::endl;
        bool isFound = false;
        int k = 0;
        int tempCheck = 0;
        bool globalCheck = false;

        //checking firstName;


        for (int i = 0; i < 20; i++)
        {
            std::string name = u[i].getUserFirstName();
            tempCheck = 0;
            isFound = false;
            for (int j = 0; j < name.length(); j++)
            {
                if (str[k] == name[j]) {
                    for (int m = 0; m < name.length(); m++)
                    {
                        if (str[m] == name[m]) {
                            tempCheck++;
                        }
                        else {
                            break;
                        }
                    }
                }
            }
            if (tempCheck == name.length()) {
                isFound = true;
                globalCheck = true;
            }
            if (isFound) {
                std::cout << u[i].getUserFirstName() << " " << u[i].getUserLastName() << std::endl;
            }
        }
        if (globalCheck == false) {
            for (int i = 0; i < 20; i++)
            {
                std::string name = u[i].getUserLastName();
                tempCheck = 0;
                isFound = false;
                for (int j = 0; j < name.length(); j++)
                {
                    if (str[k] == name[j]) {
                        for (int m = 0; m < name.length(); m++)
                        {
                            if (str[m] == name[m]) {
                                tempCheck++;
                            }
                            else {
                                break;
                            }
                        }
                    }
                }
                if (tempCheck == name.length()) {
                    isFound = true;
                    globalCheck = true;
                }
                if (isFound) {
                    std::cout << u[i].getUserFirstName() << " " << u[i].getUserLastName() << std::endl;
                }
            }
        }
    }

    void viewPostLikes(std::string postID) {
        
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "ViewPostLikes " << "(" << postID << ")\n";
        std::cout << "==========================================\n";
        int a = 0;
        std::string temp;
        for (int i = 0; i < 11; i++)
        {
            if (postID == post[i].getPostID()) {
                for (int k = 0; k < 10; k++)
                {
                    temp = post[i].getUsrLike(k);
                    std::cout << temp << " ";
                    for (int p = 0; p < 20; p++)
                    {
                        if (temp == u[p].getUserID()) {
                            std::cout << u[p].getUserFirstName() << " " << u[p].getUserLastName() << std::endl;
                        }
                    }
                }
                
            }
        }
        std::cout << std::endl;
        std::cout << "==========================================\n";
    }

    void runApp() {
        loadUsersFromFile();
        loadCommentsFromFile();
        loadPagesFromFile();
        loadPostsFromFile();

        setCurrentUser("u7");
        viewHomePage();
        likeApost("post5");
        viewPostLikes("post5");
        addComment();
        viewPost("post4");
        userTimeline();
        showFriendList();
        showPage("p1");
        searchKeyword("Ali");
    }
    ~SocialMediaApp() {
        for (int i = 0; i < 1; i++)
        {
            delete[] f[i];
        }
        delete[] pagesOfUsers;
        delete[] u;
        delete[] post;
    }
};

int main() {
    SocialMediaApp* app = new SocialMediaApp();
    app->runApp();
    delete app;
    return 0;
}
