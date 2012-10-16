#include <iostream>

/**
 * Here is a comment with stars and slashes*
/
// Fake block comment
 /***/
int main(int argc, char **argv) 
{
    int something = 4;
    float other = 4.2;
    char c = 'b';
    //// <p>Here is a <strong>comment</strong> with html</p>
    // http://msu.edu
    // https://msu.edu
    // http://my-website.something.com/#anchor
    // HTTP://something.com:8080/page.htm
    // ftp://example.com
    // Some invalid URLs are allowed: http://www.2/bad_url&&
    for ( int i = 0; i < something; i++)
    {
        if (other < 0)
        {
            if ( c == 'b')
            {
                while ( other < 1.0)
                {
                    c++;
                }
            }
            else
            {
                c--;
            }
        }
    }
    // The following are not valid URLs according to the rules of this program
    // www.example.com
    // bit.ly/902sfkl
    // http://invalid-domain
    // http://invalid/something/something
    return 0;
}
/* An unclosed comment shouldn't crash the whole program
