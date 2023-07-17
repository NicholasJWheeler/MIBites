/*
 * This program is used to allow an authenticated user to use
 * the MIBites application while interacting with Miami University's 
 * MySQL database.
* Author: Nicholas Wheeler, Copyright (C) 2022
 */
// cout << "<!--This website template was taken from \"https://purecss.io/layouts/marketing/\" 
// and is able to be used due to its free use agreement. 
// Adapted and edited for programming assignment 4 for the MIBites application. 
// Author: Nicholas Wheeler (2022)-->" << endl;
#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
#include <string>
#include <iostream>
#include "getpost.h"

using namespace std;

int main(int argc, char* argv[]) {

    map<string,string> Get;
    initializePost(Get);
    cout << "Content-type: text/html" << endl << endl;
    cout << "<html><head><title>MIBites</title>" << endl; 
    cout << "<link rel=\"stylesheet\" href=\"https://netdna.bootstrapcdn.com/font-awesome/4.0.3/css/font-awesome.css\">" << endl;
    cout << "<link rel=\"stylesheet\" href=\"./styles.css\">" << endl;
    cout << "<link rel=\"stylesheet\" href=\"./generalStyle.css\">" << endl;
    cout << "</head><body>" << endl;

    std::string username;

    if (Get.find("username")!=Get.end()) {
        username = Get["username"];
    }

    cout << "<div class=\"splash-container\">" << endl;
    cout << "<div class=\"splash\">" << endl;
    cout << "<h1 class=\"splash-head\">MIBites Home</h1>" << endl;
    cout << "<p class=\"splash-subhead\">Welcome <b>" << username << "</b>!</p>" << endl;
    cout << "<p class=\"splash-subhead\">Please select one of the following application functions</p>" << endl;

    // Function 1
    cout << "<form action = \"newreview.cgi\" method = \"POST\">" << endl;
    cout << "<input type=\"hidden\" id=\"username\" name=\"username\" value=\"" << username << "\">" << endl;
    cout << "<input type = \"submit\" value = \"Write A Review\" />" << endl;
    cout << "</form> <br />" << endl;

    // Function 2
    cout << "<form action = \"deletereview.cgi\" method = \"POST\">" << endl;
    cout << "<input type=\"hidden\" id=\"username\" name=\"username\" value=\"" << username << "\">" << endl;
    cout << "<input type = \"submit\" value = \"Delete A Review\" />" << endl;
    cout << "</form> <br />" << endl;

    // Function 3
    cout << "<form action = \"viewreviews.cgi\" method = \"POST\">" << endl;
    cout << "<input type=\"hidden\" id=\"username\" name=\"username\" value=\"" << username << "\">" << endl;
    cout << "<input type = \"submit\" value = \"View All Reviews\" />" << endl;
    cout << "</form> <br />" << endl;

    cout << "</div>" << endl;
    cout << "</div>" << endl;
    cout << "</body></html>" << endl;

}