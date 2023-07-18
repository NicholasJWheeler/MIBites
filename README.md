<h6 >
	<a href="https://github.com/NicholasJWheeler">↩ Back To Nicholas Wheeler's Profile</a>
</h6>

<h1 align="center">😋 MIBites Application</h1><br>
<table align="center">
	<tr>
		<th>
			Directory
		</th>
	</tr>
	<tr>
		<td>
			<a href="#-about-the-class">🎓  About The Class</a><br><br>
			<a href="#%E2%84%B9-about-the-application">ℹ About The Application</a><br><br>
			<a href="#-mibites-features">⭐ MIBites Features</a>
			<ul>
        <li><a href="#-html-and-css">🔩 HTML and CSS</a></li>
        <li><a href="#-mysql-and-linux-server">💽 MySQL and Linux Server</a></li>
        <li><a href="#-c-and-cgi-files">📋 C++ and CGI Files</a></li>
				<li><a href="#-user-capabilities">👨‍💻 User Capabilities</a></li>
			</ul>
		</td>
  	</tr>
	<tr>
		<td align="center">
			<a href="https://vscode.dev/github.com/NicholasJWheeler/MIBites">🔍 Check out the code that made this project possible!</a>
		</td>
	</tr>
</table><br>

## 🎓 About The Class
#### CSE278 - Systems I: Introduction to Systems Programming
I took this during my sophomore year of college in the fall of 2022. This 15-week course covered ideas that comprise different technological systems such as computer architecture and networking, through the perspective of Linux and C++ programming. The course allowed me to learn and develop skills in C++, HTML5, CSS, MySQL, sockets, networking, and debugging. The initial half of the class was focused on developing skills in the C++ language that then could be applied to projects created on a locally hosted Linux server at Miami University in the second half of the class.
<br><br><br>

## ℹ About The Application
MIBites is a web application that was created as the final project for CSE278 as a way for users to leave ratings and thoughts about local restaurants around the Miami University area. This is the first website I had created on a hosted server and the first time I connected a website to a database that could be viewed by any user. My goal was to create a Yelp-like application targeted toward Miami's students. MIBites was comprised of initial HTML pages that would prompt a user to log in or register with the application. Completion of these forms would send the data to a MySQL server that would store and check login credentials for users. Logged-in users would then navigate the web pages through CGI files displaying HTML for the website to know what to show. This allowed pages to display updated information based on what was in the MySQL database at the time, such as new restaurant reviews and ratings. The website was hosted on a section of Miami University's Linux server, and unfortunately cannot be accessed anymore as the class access has been shut down. 
<br><br><br>

## ⭐ MIBites Features
### 🔩 HTML and CSS
This project was the first time that I utilized HTML and CSS to create a professional website, and I have learned that both HTML and CSS are powerful and easy-to-use languages. My goal for this website was to maintain the theme of Miami University, so I employed color schemes and pictures to remind students of the campus. The following screenshots depict the initial HTML pages that users are greeted with when first accessing MIBites.<br><br>

![](https://github.com/NicholasJWheeler/MIBites/blob/main/Images/indexPage.png?raw=true)
<br><br>

![](https://github.com/NicholasJWheeler/MIBites/blob/main/Images/githubRegistration.png?raw=true)
<br><br>

The image above displays an example of user registration, and the "Login Portal" page is quite similar to the one shown above.
<br><br>

### 💽 MySQL and Linux Server
In order to store login information as well as the user reviews left for restaurants, a database needed to be created to accompany the application. Our professor set up a section of Miami University's Linux server to dedicate space for our MySQL database, which we could communicate with through C++ and CGI files. I created three tables to divide information throughout my database, a user information table, a reviews table, and a restaurant table. The relationship between each table can be seen in the graphic below, as well as some pictures detailing example reviews with different user logins. One example can be seen with the famous character Sonic the Hedgehog logging on to leave a review of the Red Zone restaurant.
<br><br>

![](https://github.com/NicholasJWheeler/MIBites/blob/main/Images/FINALdatabaseLinks.png?raw=true)
<br><br>

We can see here an example of some reviews from different users leaving comments and ratings for different restaurants, viewed by accessing the MySQL database.
<br><br>

![](https://github.com/NicholasJWheeler/MIBites/blob/main/Images/UpdatedReviewMySQL.png?raw=true)
<br><br>

This image displays the "wheelenjRestaurants" table that shows the average rating and number of ratings for each restaurant.
<br><br>

![](https://github.com/NicholasJWheeler/MIBites/blob/main/Images/UpdatedRestaurantRating.png?raw=true)
<br><br>

Reviews have a numerical value assigned to them out of 5 Bites (similar to a 5-star rating system). This rating system comes from the name MIBites, indicating how a user enjoyed their experience and if they would recommend eating at a specific restaurant.
<br><br>

### 📋 C++ and CGI Files
This application is primarily comprised of C++ files, with a few HTML and CSS files that initially greet the user. The C++ files were written to include CGI scripts that could update when hosted on the Linux server, and show updated HTML pages for the user to navigate. The C++ files would handle logic and communication with data from the MySQL server, and insert gathered information into HTML output that would be run by a connected CGI script from the finished CGI file. I had never created HTML files like this before, but it was interesting to see a new and creative way to write a dynamic webpage that interacts with a database without utilizing the usual option such as JavaScript. The image below shows an application diagram detailing how each page connects and how the user would navigate around the website.
<br><br>

![](https://github.com/NicholasJWheeler/MIBites/blob/main/Images/FINALwebsiteLayout.png?raw=true)
<br><br>

### 👨‍💻 User Capabilities
Overall, a user can register for an account, log into an account, write a review for a restaurant, delete one of their reviews, and view all reviews for each restaurant. Users can view what others are saying about a restaurant as well as see the average "Bites" rating to know the quality of the experience there. An example of a new user, Sonic the Hedgehog, can be seen using different MIBites pages below.<br><br>

Here Sonic has just successfully logged into MIBites and has the three options of writing, deleting, and viewing restaurant reviews.<br><br>

![](https://github.com/NicholasJWheeler/MIBites/blob/main/Images/exampleLogin.png?raw=true)
<br><br>

Since Sonic's favorite food is chili dogs, he decides to try the restaurant Red Zone as they have a wide selection of hot dog options. In the picture below Sonic can be seen leaving a review of Red Zone as well as a comment indicating the restaurant experience.<br><br>

![](https://github.com/NicholasJWheeler/MIBites/blob/main/Images/exampleReview.png?raw=true)
<br><br>

Once a review has been submitted and processed correctly, users are greeted with this screen to know that their response has been saved and updated in the system.
<br><br>

![](https://github.com/NicholasJWheeler/MIBites/blob/main/Images/SuccessfulReview.png?raw=true)
<br><br>

This project served as a great experience for me to learn the basics of creating dynamic web pages hosted on servers that can be accessed anytime. I used the idea of a restaurant review application as a proof of concept for a locally-focused application that students could use to find useful information from other students with honest feedback and opinions about food near them. I certainly would like to continue creating web applications as well as utilizing other languages in the future.

<br><br><br>

- - - -
<h6 align="center">
	<a align="center" href="#-back-to-nicholas-wheelers-profile">⬆ Back To The Top </a>
</h6>

- - - -

<h6 align="center">
	<a href="https://github.com/NicholasJWheeler">↩ Back To Nicholas Wheeler's Profile</a>
</h6>

- - - -

<h6 align="center">
  Copyright © Nicholas Wheeler 2022-2023
</h6>





