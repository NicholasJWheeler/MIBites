/*
 * This program is used to validate a user's registration to
 * the MIBites application using Miami University's MySQL database.
 * Author: Nicholas Wheeler, Copyright (C) 2022
 */

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
    cout << "<html><head><title>Registration Validator</title>" << endl; 
    cout << "<link rel=\"stylesheet\" href=\"https://netdna.bootstrapcdn.com/font-awesome/4.0.3/css/font-awesome.css\">" << endl;
    cout << "<link rel=\"stylesheet\" href=\"./styles.css\">" << endl;
    cout << "<link rel=\"stylesheet\" href=\"./generalStyle.css\">" << endl;
    cout << "</head><body>" << endl;

    std::string username;
    std::string password;
    std::string email;

    if (Get.find("username")!=Get.end() && Get.find("password")!=Get.end() && Get.find("email")!=Get.end()) {
        username = Get["username"];
        password = Get["password"];
        email = Get["email"];
    }

    // Connect to database with: database, server, userID, password
    mysqlpp::Connection conn(false); // Exceptions suppressed to keep code simple
    if(conn.connect("cse278", "localhost", "cse278", "MonSepM1am1")) {

        // Create a query
        mysqlpp::Query query = conn.query();
        query << "INSERT into wheelenjUsers (username, password, email) VALUES (%0q, %1q, %2q);";

        query.parse();  // check to ensure it is correct

        // Run the query -- note INSERT does not return results so we are using SimpleResult
        //mysqlpp::SimpleResult result = query.execute();
        mysqlpp::SimpleResult result = query.execute(username, password, email);

        // HTML Formatting
        cout << "<div class=\"splash-container\">" << endl;
        cout << "<div class=\"splash\">" << endl;
        cout << "<h1>Registration Validator</h1>" << endl;
        cout << "<p class=\"splash-subhead\">Your <b>username</b> and <b>Password</b> are <u>both</u> case sensitive.<br>The <b>username</b> entered must also be <u>unique</u>!</p>" << endl;

        if(result) {
            cout << "<p>Successful account registration! Click the following button to use MIBites!</p>" << endl;
            cout << "<form action = \"home.cgi\" method = \"POST\">" << endl;
            cout << "<input type=\"hidden\" id=\"username\" name=\"username\" value=\"" << username << "\">" << endl;
            cout << "<input type = \"submit\" value = \"MIBites Home\" />" << endl;
            cout << "</form>" << endl;
        } else {
            cout << "<p>The username entered is already in use. Click the following button to return to the registration portal.</p>" << endl;
            cout << "<a href=\"./Registration.html\" class=\"pure-button pure-button-primary\">Registration Portal</a>" << endl;
        }
        return(0);
    } else {
        cerr << "Connection failed: " << conn.error() <<endl;
        return(1);
    }
    cout << "</div></div>" << endl;
    cout << "</body></html>" << endl;
}
