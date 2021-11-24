#!/bin/bash
yacc -d -o yacc.c pl0.y
lex -o p.c pl0.l 
cc -g p.c yacc.c -o p 
