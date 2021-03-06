C2HTML
======

A project for CSE450 Compilers

The assignment is to make a syntax highlighter that creates .html files from .c files.

Dependencies
------------

This program uses Flex and Bison

About
-----

Running make will compile the program and create the *.html files for the test files: test1.c, test2.c, and test3.c

Instead of using the deprecated "<font color="..."></font>" tags, I opted to use <span> tags with classes and a simple CSS file to color the comments, strings, and keywords.  It is also possible to change the colors by just changing the CSS file.

The code will handle basic URL's starting with http://, https://, or ftp:// (all case insenstive).  It must be followed by a scheme of two words separated by a dot, and an optional number of words separated by dots.  It can have an optional port number.  Then an optional forward slash followed by any legal character in a URL.  This includes [a-zA-Z0-9~_+=&%?#.-] to handle all valid characters.  It does not check URLs for well-formedness.

Here are some URLs that won't work:
http://localhost/file.html
www.example.com (anything without the scheme portion).
file:///home/user/test.html

Here are some invalid URLs that will work:
http://www.2/bad_url&&

The code will also handle emails similarly.  It handles a sequence of valid email characters followed by an "@" followed by a domain in the form of WORD.WORD plus an arbitrary number of ".WORD"

Examples:
user@domain.com
user2.name@domain.co.uk
