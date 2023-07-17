/*
 * This program is used to allow a validated user to view all reviews
 * for each restaurant on the MIBites application.
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
    cout << "<html><head><title>MIBites Restaurant Reviews</title>" << endl;
    cout << "<style>body { overflow-y: scroll;}</style>" << endl;
    cout << "<link rel=\"stylesheet\" href=\"https://netdna.bootstrapcdn.com/font-awesome/4.0.3/css/font-awesome.css\">" << endl;
    cout << "<link rel=\"stylesheet\" href=\"./styles.css\">" << endl;
    cout << "<link rel=\"stylesheet\" href=\"./generalStyle.css\">" << endl;
    cout << "</head><body>" << endl;

    std::string username;
    std::string reviewerName = "dummy";
    int currUserID;
    int tempUserID;
    double redzoneAvg, pulleyAvg, cafeluxAvg, paesanosAvg;

    if (Get.find("username")!=Get.end()) {
        username = Get["username"];
    }
    cout << "<div class=\"splash-container\">" << endl;
    cout << "<div class=\"splash\">" << endl;
    cout << "<h1 class=\"splash-head\">MIBites Restaurant Reviews</h1>" << endl;
    cout << "<p class=\"splash-subhead\"><u>Pulley Diner</u></p>" << endl;
    

    mysqlpp::Connection conn(false); // Exceptions suppressed to keep code simple
    if(conn.connect("cse278", "localhost", "cse278", "MonSepM1am1")) {

        // Create a query to find the restaurant average ratings
        // Create query
        mysqlpp::Query restaurantsInfo = conn.query();
        restaurantsInfo << "SELECT * FROM wheelenjResturants;";
        restaurantsInfo.parse();
        mysqlpp::StoreQueryResult restaurantsResult = restaurantsInfo.store();

        if (restaurantsResult) {  // Get each restaurant's average
            cafeluxAvg = restaurantsResult[0]["avgRating"];
            paesanosAvg = restaurantsResult[1]["avgRating"];
            pulleyAvg = restaurantsResult[2]["avgRating"];
            redzoneAvg = restaurantsResult[3]["avgRating"];
        }

        // Create a query to find the username from given id
        // Create query
        mysqlpp::Query usersInfo = conn.query();
        usersInfo << "SELECT * FROM wheelenjUsers;";
        usersInfo.parse();
        mysqlpp::StoreQueryResult usersResult = usersInfo.store();

        // Get all the reviews this for Pulley Diner
        // Create a query
        mysqlpp::Query pulleyInfo = conn.query();
        pulleyInfo << "SELECT * FROM wheelenjReviews WHERE RName = \'Pulley Diner\';";
        pulleyInfo.parse();
        mysqlpp::StoreQueryResult pulleyResult = pulleyInfo.store();

        //cout << "<p class=\"splash-subhead\">Overall rating: " << pulleyAvg << " Bites</p>" << endl;
        cout << "<img src=\"./images/pulley-diner.jpg\" style=\"padding-bottom: 30px\" alt=\"PulleyDinerPhoto\">" << endl;
        cout << "<br />" << endl;

        // Pulley Diner Table
        cout << "<table border=1 width=600><tr><th>Reviewer</th><th>Restaurant Name</th><th>Description</th><th>Bites Rating</th></tr>" << endl;

        if (pulleyResult) { // Get all reviews from Pulley Diner
            for (int i = 0; i < pulleyResult.num_rows(); ++i) {
                currUserID = pulleyResult[i]["id"]; // Get the reviewer's ID number
                for (int j = 0; j < usersResult.num_rows(); j++) { // Match the corresponding ID to the username
                    tempUserID = usersResult[j]["id"];
                    if (currUserID == tempUserID) {
                        reviewerName = (string) usersResult[j]["username"];
                    }
                }
                cout << "<tr><td>" << reviewerName << "</td>" <<
                        "<td>" << pulleyResult[i]["RName"] << "</td>" <<
                        "<td>" << pulleyResult[i]["Description"] << "</td>" <<
                        "<td>" << pulleyResult[i]["starRating"] << "</td></tr>" <<
                        endl;
            }
        } else {
            cout << "<p>Unable to generate Pulley Diner results!</p>" << endl;
        }

        cout << "</table><br /> <br />" << endl; // End Pulley Diner Table

        cout << "<p class=\"splash-subhead\"><u>Redzone</u></p>" << endl;
        //cout << "<p class=\"splash-subhead\">Overall rating: " << redzoneAvg << " Bites</p>" << endl;
        cout << "<img src=\"./images/redzone.jpg\" style=\"width:80%; padding-bottom: 30px\" alt=\"RedzonePhoto\">" << endl;
        cout << "<br />" << endl;

        // Get all the reviews for Redzone
        // Create a query
        mysqlpp::Query redzoneInfo = conn.query();
        redzoneInfo << "SELECT * FROM wheelenjReviews WHERE RName = \'Redzone\';";
        redzoneInfo.parse();
        mysqlpp::StoreQueryResult redzoneResult = redzoneInfo.store();

        // Redzone Table
        cout << "<table border=1 width=600><tr><th>Reviewer</th><th>Restaurant Name</th><th>Description</th><th>Bites Rating</th></tr>" << endl;

        if (redzoneResult) { // Get all reviews from Redzone
            for (int i = 0; i < redzoneResult.num_rows(); ++i) {
                currUserID = redzoneResult[i]["id"]; // Get the reviewer's ID number
                for (int j = 0; j < usersResult.num_rows(); j++) { // Match the corresponding ID to the username
                    tempUserID = usersResult[j]["id"];
                    if (currUserID == tempUserID) {
                        reviewerName = (string) usersResult[j]["username"];
                    }
                }
                cout << "<tr><td>" << reviewerName << "</td>" <<
                        "<td>" << redzoneResult[i]["RName"] << "</td>" <<
                        "<td>" << redzoneResult[i]["Description"] << "</td>" <<
                        "<td>" << redzoneResult[i]["starRating"] << "</td></tr>" <<
                        endl;
            }
        } else {
            cout << "<p>Unable to generate Redzone results!</p>" << endl;
        }

        cout << "</table><br /> <br />" << endl; // End Redzone Table

        cout << "<p class=\"splash-subhead\"><u>Cafe Lux</u></p>" << endl;
        //cout << "<p class=\"splash-subhead\">Overall rating: " << cafeluxAvg << " Bites</p>" << endl;
        cout << "<img src=\"./images/cafelux.jpg\" style=\"width:80%; padding-bottom: 30px\" alt=\"CafeLuxPhoto\">" << endl;
        cout << "<br />" << endl;

        // Get all the reviews for Cafe Lux
        // Create a query
        mysqlpp::Query cafeluxInfo = conn.query();
        cafeluxInfo << "SELECT * FROM wheelenjReviews WHERE RName = \'Cafe Lux\';";
        cafeluxInfo.parse();
        mysqlpp::StoreQueryResult cafeluxResult = cafeluxInfo.store();

        // Cafe Lux Table
        cout << "<table border=1 width=600><tr><th>Reviewer</th><th>Restaurant Name</th><th>Description</th><th>Bites Rating</th></tr>" << endl;

        if (cafeluxResult) { // Get all reviews from Cafe Lux
            for (int i = 0; i < cafeluxResult.num_rows(); ++i) {
                currUserID = cafeluxResult[i]["id"]; // Get the reviewer's ID number
                for (int j = 0; j < usersResult.num_rows(); j++) { // Match the corresponding ID to the username
                    tempUserID = usersResult[j]["id"];
                    if (currUserID == tempUserID) {
                        reviewerName = (string) usersResult[j]["username"];
                    }
                }
                cout << "<tr><td>" << reviewerName << "</td>" <<
                        "<td>" << cafeluxResult[i]["RName"] << "</td>" <<
                        "<td>" << cafeluxResult[i]["Description"] << "</td>" <<
                        "<td>" << cafeluxResult[i]["starRating"] << "</td></tr>" <<
                        endl;
            }
        } else {
            cout << "<p>Unable to generate Cafe Lux results!</p>" << endl;
        }

        cout << "</table><br /> <br />" << endl; // End Cafe Lux Table

        cout << "<p class=\"splash-subhead\"><u>Paesano's Pasta House</u></p>" << endl;
        //cout << "<p class=\"splash-subhead\">Overall rating: " << paesanosAvg << " Bites</p>" << endl;
        cout << "<img src=\"./images/paesanos.jpg\" style=\"width:80%; padding-bottom: 30px\" alt=\"Paesano\'sPhoto\">" << endl;
        cout << "<br />" << endl;

        // Get all the reviews for Paesano's
        // Create a query
        mysqlpp::Query paesanosInfo = conn.query();
        paesanosInfo << "SELECT * FROM wheelenjReviews WHERE RName = \'Paesanos Pasta House\';";
        paesanosInfo.parse();
        mysqlpp::StoreQueryResult paesanosResult = paesanosInfo.store();

        // Cafe Lux Table
        cout << "<table border=1 width=600><tr><th>Reviewer</th><th>Restaurant Name</th><th>Description</th><th>Bites Rating</th></tr>" << endl;

        if (paesanosResult) { // Get all reviews from Paesano's
            for (int i = 0; i < paesanosResult.num_rows(); ++i) {
                currUserID = paesanosResult[i]["id"]; // Get the reviewer's ID number
                for (int j = 0; j < usersResult.num_rows(); j++) { // Match the corresponding ID to the username
                    tempUserID = usersResult[j]["id"];
                    if (currUserID == tempUserID) {
                        reviewerName = (string) usersResult[j]["username"];
                    }
                }
                cout << "<tr><td>" << reviewerName << "</td>" <<
                        "<td>" << paesanosResult[i]["RName"] << "</td>" <<
                        "<td>" << paesanosResult[i]["Description"] << "</td>" <<
                        "<td>" << paesanosResult[i]["starRating"] << "</td></tr>" <<
                        endl;
            }
        } else {
            cout << "<p>Unable to generate Paesano's results!</p>" << endl;
        }

        cout << "</table> <br /> <br />" << endl; // End Paesano's Table

    } else {
        cerr << "Connection failed: " << conn.error() <<endl;
        return(1);
    }

    cout << "<form action=\"home.cgi\" id=\"usrform\" method=\"POST\">" << endl; // deletereviewcheck.cgi

    // Send username
    cout << "<input type=\"hidden\" id=\"username\" name=\"username\" value=\"" << username << "\">" << endl;

    // Submit button
    cout << "<input type = \"submit\" value = \"Home\" />" << endl;
    cout << "<br /> <br />" << endl;

    cout << "</form>" << endl;
    cout << "</div></div>" << endl;
    cout << "</body></html>" << endl;
    return(0);
}