/*
 * This program is used to allow a validated user to write a review
 * about one of the available restaurants in the Miami University area.
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

    if (Get.find("username")!=Get.end()) {
        username = Get["username"];
    }
    cout << "<div class=\"splash-container\">" << endl;
    cout << "<div class=\"splash\">" << endl;
    cout << "<h1 class=\"splash-head\">MIBites Review Writer</h1>" << endl;
    cout << "<p class=\"splash-subhead\">Please fill out the form to submit a review for a restaurant on MIBites!</p>" << endl;

    cout << "<form action=\"newreviewcheck.cgi\" id=\"usrform\" method=\"POST\">" << endl;
    
    // Restaurant Buttons
    // Pulley Diner
    cout << "<label class=\"container\"><p>Pulley Diner</p>" << endl;
    cout << "<input type=\"radio\" checked=\"checked\" name=\"radio\" value=\"Pulley Diner\">" << endl;
    cout << "<span class=\"checkmark\"></span>" << endl;
    cout << "</label>" << endl;

    // Paesano's Pasta House
    cout << "<label class=\"container\"><p>Paesano\'s Pasta House</p>" << endl;
    cout << "<input type=\"radio\" checked=\"checked\" name=\"radio\" value=\"Paesanos Pasta House\">" << endl;
    cout << "<span class=\"checkmark\"></span>" << endl;
    cout << "</label>" << endl;

    // Redzone
    cout << "<label class=\"container\"><p>Redzone</p>" << endl;
    cout << "<input type=\"radio\" checked=\"checked\" name=\"radio\" value=\"Redzone\">" << endl;
    cout << "<span class=\"checkmark\"></span>" << endl;
    cout << "</label>" << endl;

    // Cafe Lux
    cout << "<label class=\"container\"><p>Cafe Lux</p>" << endl;
    cout << "<input type=\"radio\" checked=\"checked\" name=\"radio\" value=\"Cafe Lux\">" << endl;
    cout << "<span class=\"checkmark\"></span>" << endl;
    cout << "</label>" << endl;

    // Description
    cout << "<textarea class=\"review-box\" rows=\"4\" cols=\"50\" name=\"Description\" form=\"usrform\" placeholder=\"Write review here... (300 character max)\" maxlength=\"300\"></textarea>" << endl;

    // Bites Rating Buttons
    // 1 Bite
    cout << "<label class=\"container\"><p>1 Bite</p>" << endl;
    cout << "<input type=\"radio\" checked=\"checked\" name=\"bites\" value=1>" << endl;
    cout << "<span class=\"checkmark\"></span>" << endl;
    cout << "</label>" << endl;

    // 2 Bites
    cout << "<label class=\"container\"><p>2 Bites</p>" << endl;
    cout << "<input type=\"radio\" checked=\"checked\" name=\"bites\" value=2>" << endl;
    cout << "<span class=\"checkmark\"></span>" << endl;
    cout << "</label>" << endl;

    // 3 Bites
    cout << "<label class=\"container\"><p>3 Bites</p>" << endl;
    cout << "<input type=\"radio\" checked=\"checked\" name=\"bites\" value=3>" << endl;
    cout << "<span class=\"checkmark\"></span>" << endl;
    cout << "</label>" << endl;

    // 4 Bites
    cout << "<label class=\"container\"><p>4 Bites</p>" << endl;
    cout << "<input type=\"radio\" checked=\"checked\" name=\"bites\" value=4>" << endl;
    cout << "<span class=\"checkmark\"></span>" << endl;
    cout << "</label>" << endl;

    // 5 Bites
    cout << "<label class=\"container\"><p>5 Bites</p>" << endl;
    cout << "<input type=\"radio\" checked=\"checked\" name=\"bites\" value=5>" << endl;
    cout << "<span class=\"checkmark\"></span>" << endl;
    cout << "</label>" << endl;

    // Send username
    cout << "<input type=\"hidden\" id=\"username\" name=\"username\" value=\"" << username << "\">" << endl;

    // Submit button
    cout << "<input type = \"submit\" value = \"Submit\" />" << endl;
    cout << "<br /> <br />" << endl;

    cout << "</form>" << endl;
    cout << "</div></div>" << endl;
    cout << "</body></html>" << endl;
}