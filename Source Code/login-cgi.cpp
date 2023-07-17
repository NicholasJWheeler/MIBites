/*
 * This program is used to validate a user's login to
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
    cout << "<html><head><title>Login Validator</title>" << endl; 
    cout << "<link rel=\"stylesheet\" href=\"https://netdna.bootstrapcdn.com/font-awesome/4.0.3/css/font-awesome.css\">" << endl;
    cout << "<link rel=\"stylesheet\" href=\"./styles.css\">" << endl;
    cout << "<link rel=\"stylesheet\" href=\"./generalStyle.css\">" << endl;
    cout << "</head><body>" << endl;

    std::string username;
    std::string password;

    if (Get.find("username")!=Get.end() && Get.find("password")!=Get.end()) {
        username = Get["username"];
        password = Get["password"];
    }

    // Connect to database with: database, server, userID, password
    mysqlpp::Connection conn(false); // Exceptions suppressed to keep code simple
    if(conn.connect("cse278", "localhost", "cse278", "MonSepM1am1")) {

        mysqlpp::Query query = conn.query();
        query << "SELECT username, password FROM wheelenjUsers;"; // WHERE username = '"+username+" AND password = '"+password+"';";

        // Check the query for correctness
        query.parse();

        // Run the query and get the result
        mysqlpp::StoreQueryResult result = query.store();

        // Variables
        bool authentic = false;

        // HTML Formatting
        cout << "<div class=\"splash-container\">" << endl;
        cout << "<div class=\"splash\">" << endl;
        cout << "<h1>Login Validator</h1>" << endl;
        cout << "<p class=\"splash-subhead\">Your <b>username</b> and <b>Password</b> are <u>both</u> case sensitive.</p>" << endl;


        // Always check for errors
        if(result) {
            for (int i = 0; i < result.num_rows(); ++i) {
                if (result[i]["username"] == username && result[i]["password"] == password) {
                    authentic = true;
                    break;
                }
            }

            if (authentic) {  // Correct Login from User
                cout << "<p>Successful Login! Click the following button to use MIBites!</p>" << endl;
                cout << "<form action = \"home.cgi\" method = \"POST\">" << endl;
                cout << "<input type=\"hidden\" id=\"username\" name=\"username\" value=\"" << username << "\">" << endl;
                cout << "<input type = \"submit\" value = \"MIBites Home\" />" << endl;
                cout << "</form>" << endl;
                //cout << "<a href=\"./Home.html\" class=\"pure-button pure-button-primary\">MIBites Home</a>" << endl;
                //cout << "<button value=\"Placeholder\">MIBites</button>" << endl;
            } else {  // Incorrect Login from User
                cout << "<p>Your username or password is incorrect. Click the following button to return to the login portal.</p>" << endl;
                cout << "<a href=\"./Login.html\" class=\"pure-button pure-button-primary\">Login Portal</a>" << endl;
           }
        } else {
            cout << "<p>No result found!</p>" << endl;
            cerr << "Query error: " << query.error() << endl;
        }
        return(0);
    } else {
        cerr << "Connection failed: " << conn.error() <<endl;
        return(1);
    }
    cout << "</div></div>" << endl;
    cout << "</body></html>" << endl;
}
