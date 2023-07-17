/*
 * This program will validate a user's login with the Miami University
 * MySQL database. 
 * Author: Nicholas Wheeler
 */

#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <iomanip>

using std::cout;
using std::cerr;
using std::endl;
using std::string;

int main(int argc, char *argv[]) {
    // Connect to database with: database, server, userID, password
    mysqlpp::Connection conn(false); // Exceptions suppressed to keep code simple
    if(conn.connect("cse278", "localhost", "cse278", "MonSepM1am1")) {

        // Create a query
        mysqlpp::Query query = conn.query();
        query << "SELECT * FROM wheelenjUsers";

        // Check the query for correctness
        query.parse();

        // Run the query and get the result
        mysqlpp::StoreQueryResult result = query.store();

        // Variables
        int user_id;
        string user_name, user_pass;
        bool authentic = false;

        // Always check for errors
        if(result) {
            // Display header
            //cout.setf(std::ios::left);
            cout << "Content-type: text-html\n\n";
            cout << "<html><head><title>Login Validator</title><body>\n";
            //cout << "<table border=1 width=600><tr><th>ID</th><th>Username</th><th>Password</th><th>Money Held</th></tr>\n";

            // Get each row in result set, and print its contents
            for (int i = 0; i < result.num_rows(); ++i) {
                cout << "<tr><td>" << result[i]["id"] << "</td>" <<
                        "<td>" << result[i]["username"] << "</td>" <<
                        "<td>" << result[i]["password"] << "</td>" <<
                        "<td>" << result[i]["moneyHeld"] << "</td></tr>" <<
                        endl;
                   // std::setw(20) << "Password" <<
                   // std::setw(20) << "Money Held" << endl;
            }

            if (authentic) {  // Correct Login from User

            } else {  // Incorrect Login from User

            }
            cout << "</table></body></html>\n";
        } else {
            cerr << "Query failed: " << query.error() << endl;
        }
        return(0);
    } else {
        cerr << "Connection failed: " << conn.error() <<endl;
        return(1);
    }
}
