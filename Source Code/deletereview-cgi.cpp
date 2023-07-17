/*
 * This program is used to allow a validated user to delete a review
 * they wrote about one of the available restaurants in the 
 * Miami University area.
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
    cout << "<html><head><title>MIBites Review Creator</title>" << endl;
    cout << "<style>body { overflow-y: scroll;}</style>" << endl;
    cout << "<link rel=\"stylesheet\" href=\"https://netdna.bootstrapcdn.com/font-awesome/4.0.3/css/font-awesome.css\">" << endl;
    cout << "<link rel=\"stylesheet\" href=\"./styles.css\">" << endl;
    cout << "<link rel=\"stylesheet\" href=\"./generalStyle.css\">" << endl;
    cout << "</head><body>" << endl;

    std::string username;
    int userID;

    if (Get.find("username")!=Get.end()) {
        username = Get["username"];
    }
    cout << "<div class=\"splash-container\">" << endl;
    cout << "<div class=\"splash\">" << endl;
    cout << "<h1 class=\"splash-head\">MIBites Review Deletion</h1>" << endl;
    cout << "<p class=\"splash-subhead\">Please enter the number of the review you would like to delete.</p>" << endl;
    cout << "<table border=1 width=600><tr><th>Review Number</th><th>Restaurant Name</th><th>Description</th><th>Bites Rating</th></tr>" << endl;

    mysqlpp::Connection conn(false); // Exceptions suppressed to keep code simple
    if(conn.connect("cse278", "localhost", "cse278", "MonSepM1am1")) {
        // Get the user's ID number
        // Create a query
        mysqlpp::Query userInfo = conn.query();
        userInfo << "SELECT * FROM wheelenjUsers WHERE username = \'" << username << "\';";
        userInfo.parse();
        mysqlpp::StoreQueryResult userValidation = userInfo.store();
        if (userValidation) { // Get the id from the username
            for (int i = 0; i < userValidation.num_rows(); ++i) {
                userID = userValidation[i]["id"];
            }
        }

        // Get all the reviews this user has made...
        // Create a query
        mysqlpp::Query reviewsInfo = conn.query();
        reviewsInfo << "SELECT * FROM wheelenjReviews WHERE id = " << userID << ";";
        reviewsInfo.parse();
        mysqlpp::StoreQueryResult reviewTotalResult = reviewsInfo.store();
        if (reviewTotalResult) { // Get the review count from the restaurant name
            for (int i = 0; i < reviewTotalResult.num_rows(); ++i) {
                cout << "<tr><td>" << i << "</td>" <<
                        "<td>" << reviewTotalResult[i]["RName"] << "</td>" <<
                        "<td>" << reviewTotalResult[i]["Description"] << "</td>" <<
                        "<td>" << reviewTotalResult[i]["starRating"] << "</td></tr>" <<
                        endl;
            }
        }
    } else {
        cerr << "Connection failed: " << conn.error() <<endl;
        return(1);
    }

    cout << "</table>" << endl;
    cout << "<form action=\"deletereviewcheck.cgi\" id=\"usrform\" method=\"POST\">" << endl; // deletereviewcheck.cgi

    // Text field for review deletion selection
    cout << "<label for=\"choice\" class=\"form-label\">Review Number: </label>" << endl;
    cout << "<input type=\"text\" id=\"choice\" name=\"choice\" maxlength=\"3\" placeholder=\"Enter a valid number here...\"> <br />" << endl;

    // Send username
    cout << "<input type=\"hidden\" id=\"username\" name=\"username\" value=\"" << username << "\">" << endl;

    // Submit button
    cout << "<input type = \"submit\" value = \"Submit\" />" << endl;
    cout << "<br /> <br />" << endl;

    cout << "</form>" << endl;
    cout << "</div></div>" << endl;
    cout << "</body></html>" << endl;
    return(0);
}