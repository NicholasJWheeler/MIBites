/*
 * This program is used to validate a user's new review they submit to
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
    cout << "<html><head><title>Review Validator</title>" << endl; 
    cout << "<link rel=\"stylesheet\" href=\"https://netdna.bootstrapcdn.com/font-awesome/4.0.3/css/font-awesome.css\">" << endl;
    cout << "<link rel=\"stylesheet\" href=\"./styles.css\">" << endl;
    cout << "<link rel=\"stylesheet\" href=\"./generalStyle.css\">" << endl;
    cout << "</head><body>" << endl;

    std::string username;
    std::string rName;
    std::string desc;
    std::string bitesString;
    int bites;

    if (Get.find("username")!=Get.end() && Get.find("radio")!=Get.end() && Get.find("bites")!=Get.end() && Get.find("Description")!=Get.end()) {
        username = Get["username"];
        rName = Get["radio"];
        bitesString = Get["bites"];
        bites = stoi(bitesString);
        desc = Get["Description"];
    }

    // Connect to database with: database, server, userID, password
    mysqlpp::Connection conn(false); // Exceptions suppressed to keep code simple
    if(conn.connect("cse278", "localhost", "cse278", "MonSepM1am1")) {

        // Create a query
        mysqlpp::Query userInfo = conn.query();
        userInfo << "SELECT * FROM wheelenjUsers WHERE username = \'" << username << "\';";

        userInfo.parse();
        mysqlpp::StoreQueryResult userValidation = userInfo.store();

        // Variables
        int userID;
        int totalRestReviews;
        int currentBites;
        double totalBites = 0.0;
        double avgBites;

        if (userValidation) { // Get the id from the username
            for (int i = 0; i < userValidation.num_rows(); ++i) {
                userID = userValidation[i]["id"];
            }
        }

        // Create a query
        mysqlpp::Query query = conn.query();
        query << "INSERT into wheelenjReviews (Description, starRating, id, RName) VALUES (%0q, %1, %2, %3q);";

        query.parse();  // check to ensure it is correct

        // Run the query -- note INSERT does not return results so we are using SimpleResult
        //mysqlpp::SimpleResult result = query.execute();
        mysqlpp::SimpleResult result = query.execute(desc, bites, userID, rName);

        // HTML Formatting
        cout << "<div class=\"splash-container\">" << endl;
        cout << "<div class=\"splash\">" << endl;
        cout << "<h1>Review Validator</h1>" << endl;

        if(result) {

            // Update the total number of reviews for the chosen restaurant
            // Create a query
            mysqlpp::Query restInfo = conn.query();
            restInfo << "SELECT * FROM wheelenjRestaurants WHERE RName = \'" << rName << "\';";
            restInfo.parse();
            mysqlpp::StoreQueryResult reviewCountResult = restInfo.store();

            if (reviewCountResult) { // Get the review count from the restaurant name
                for (int i = 0; i < reviewCountResult.num_rows(); ++i) {
                    totalRestReviews = reviewCountResult[i]["numRatings"];
                }
            }
            totalRestReviews = totalRestReviews + 1;

            // Get the total number of bites to calculate the average for the chosen restaurant
            // Create a query
            mysqlpp::Query reviewsInfo = conn.query();
            reviewsInfo << "SELECT * FROM wheelenjReviews WHERE RName = \'" << rName << "\';";
            reviewsInfo.parse();
            mysqlpp::StoreQueryResult reviewTotalResult = reviewsInfo.store();
            if (reviewTotalResult) { // Get the review count from the restaurant name
                for (int i = 0; i < reviewTotalResult.num_rows(); ++i) {
                    currentBites = reviewTotalResult[i]["starRating"];
                    totalBites = totalBites + currentBites; // Total all of the review scores
                }
            }

            avgBites = totalBites / totalRestReviews; // Find the average overall restaurant rating

            // Update the restaurant's statistics with the new calculated review info
            // Create a query
            mysqlpp::Query update = conn.query();
            update << "UPDATE wheelenjRestaurants SET avgRating = " << avgBites << ", numRatings = " << totalRestReviews << " WHERE RName = \'" << rName << "\';";
            update.parse();
            mysqlpp::SimpleResult updateResult = update.execute();

            if (updateResult) {
                cout << "<p>Restaurant data has been updated!</p>" << endl;
            } else {
                cout << "<p>An error occured when updating restaurant data.</p>" << endl;
            }

            cout << "<p>Successful review creation! Click the following button to return to the MIBites homepage!</p>" << endl;
            cout << "<form action = \"home.cgi\" method = \"POST\">" << endl;
            cout << "<input type=\"hidden\" id=\"username\" name=\"username\" value=\"" << username << "\">" << endl;
            cout << "<input type = \"submit\" value = \"MIBites Home\" />" << endl;
            cout << "</form>" << endl;
        } else {
            cout << "<p>An error occured when submitting your review. Please try again.</p>" << endl;
            cout << "<form action = \"home.cgi\" method = \"POST\">" << endl;
            cout << "<input type=\"hidden\" id=\"username\" name=\"username\" value=\"" << username << "\">" << endl;
            cout << "<input type = \"submit\" value = \"MIBites Home\" />" << endl;
            cout << "</form>" << endl;
        }
        return(0);
    } else {
        cerr << "Connection failed: " << conn.error() <<endl;
        return(1);
    }
    cout << "</div></div>" << endl;
    cout << "</body></html>" << endl;
}