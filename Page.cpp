//Each Page has a unique ID, title,list of posts it has shared(page’s timeline)and 
// total number of people who have liked it.
#include <iostream>

class Page{
    protected:
    unsigned int uniquePageID;
    std::string pageTitle;
    std::string *pagePosts;
    unsigned int totalLikes;

    public:

    int size = 1;
    Page(){
        uniquePageID = 0;
        totalLikes = 0;
        pagePosts = new std::string[size];
    }
    Page(unsigned int ID, std::string title, std::string *post, unsigned int likes){
        pagePosts = new std::string[size];
        uniquePageID = ID;
        pageTitle = title;
        pagePosts = post;
        totalLikes = likes;
    }
    void print(){
        std::cout << uniquePageID << std::endl;
        std::cout << pageTitle << std::endl;
        for (int i = 0; i < size; i++)
        {
            std::cout << pagePosts[i] << std::endl;
        }
        std::cout << size << std::endl;
        std::cout << totalLikes << std::endl;
    }
};