// This is my test program
// It has urls: http://www.example.com/index.htm which are simple
// Here is a more complex url : http://example.com/~user/page+view?id=1#bottom

int main(int argc, char **argv)
{
    /*
     * A block comment with extra asterisks
     * Also urls: http://en.wikipedia.org/wiki/Flex_lexical_analyser
     * FUN!!
     */
    int i = 0;
    if (i < 1)
    {
        char c = 'a';
    }

    char something = 'y';
    while (something != '\n')
    {
        switch (something)
        {
        case '*':
            i = 1;
            break;
        case '%':
            i = 2;
            break;
        }
        int z = 0;
        do 
        {
            z++;
        } while ( z < 2 );
    }

    string s = "This is a string";

    string s2 = "Bob said, \"I'm using quotes\"";

    return i;
}
