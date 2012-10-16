#include <cstdio>
#include <iostream>

using namespace std;

extern "C" {
    extern FILE *yyin;
    extern int yylex();
    extern char *yytext();
}

int main(int argc, char **argv)
{
    FILE *file;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: c2html filename\n");
        return 1;
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Unable to open file %s\n", argv[1]);
        return 1;
    }

    // Create a valid html5 doctype and wrap the whole thing in valid
    // html tags
    cout << "<!DOCTYPE html>" << endl
         << "<html>" << endl
         << "<head>" << endl
         << "\t<title>" << argv[1] << "</title>" << endl
         << "\t<link href=\"style.css\" rel=\"stylesheet\" type=\"text/css\" media=\"screen\" />"
         << "</head>" << endl
         << "<body>" << endl
         << "\t<div class=\"code\">" << endl;

    yyin = file;
    int token;
    do
    {
        token = yylex();
        if (token > 0)
        {
            cout << token << endl;
        }
    } while (token > 0);

    cout << "\t</div>" << endl
         << "</body>" << endl
         << "</html>" << endl;
}
