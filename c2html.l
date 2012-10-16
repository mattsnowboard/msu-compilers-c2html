%x COMMENT BLOCKCOMMENT STRING

%{
//
// C++ HTML "Pretty Print"
//
%}
%%

<INITIAL,BLOCKCOMMENT,STRING>"\n" {
    printf("<br />\n");
}

"{"[:space:]*"\n"? {
    printf("%s<ul>", yytext);
}

"}" {
    printf("</ul>%s", yytext);
}

<INITIAL,COMMENT,BLOCKCOMMENT,STRING>"<" {
    fputs("&lt;", stdout);
}

<INITIAL,COMMENT,BLOCKCOMMENT,STRING>">" {
    fputs("&gt;", stdout);
}

"\"" {
    printf("<span class=\"string\">%s", yytext);
    BEGIN(STRING);
}
<STRING>"\\\\"*"\"" {
    printf("%s</span>", yytext);
    BEGIN(INITIAL);
}
<STRING><<EOF>> {
    printf("%s</span>", yytext);
    BEGIN(INITIAL);
}
<STRING>. {
    printf("%s", yytext);
}
<STRING>"\\\\"*"\\\"" {
    printf("%s", yytext);
}


"int"|"float"|"char"|"while"|"if"|"else"|"do"|"switch"|"case"|"return" {
    printf("<span class=\"keyword\">%s</span>", yytext);
}

"//" {
    printf("<span class=\"comment\">%s", yytext);
    BEGIN(COMMENT);
}
<COMMENT>. {
    printf("%s", yytext);
}
<COMMENT>\n {
    printf("</span><br />%s", yytext);
    BEGIN(INITIAL);
}

"/*" {
    printf("<span class=\"comment\">%s", yytext);
    BEGIN(BLOCKCOMMENT);
}
<BLOCKCOMMENT>. {
    printf("%s", yytext);
}
<BLOCKCOMMENT>"*/" {
    printf("%s</span>", yytext);
    BEGIN(INITIAL);
}
<BLOCKCOMMENT><<EOF>> {
    printf("%s</span>", yytext);
    BEGIN(INITIAL);
}

<COMMENT,BLOCKCOMMENT>
([hH][Tt][Tt][Pp][Ss]?|[Ff][Tt][Pp])"://"([a-zA-Z0-9]+[a-zA-Z0-9-]*\.)([a-zA-Z0-9-]*\.)*([a-zA-Z0-9])+(":"[0-9]+)?("/"?([a-zA-Z0-9~_+=&%?#.-])*)* {
    printf("<a href=\"%s\">%s</a>", yytext, yytext);
}
<COMMENT,BLOCKCOMMENT>
[a-zA-Z0-9!#$%&'*+/=?^_`{|}~-]+[a-zA-Z0-9!#$%&'*+/=?^_`{|}~.-]*"@"([a-zA-Z0-9]+[a-zA-Z0-9-]*\.)([a-zA-Z0-9-]*\.)*([a-zA-Z0-9])+ {
    printf("<a href=\"mailto:%s\">%s</a>", yytext, yytext);
}

%%
int yywrap()
{
    return 1;
}
