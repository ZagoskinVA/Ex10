// Copyright 2021 ccc

#include "postfix.h"
#include "MyStack.h"

std::string infix2postfix(std::string inf)
{
 MyStack<char> operators(400);
 std::string post = "";
 char sumb = '\0';
 for (int i = 0; i < inf.length(); i++) 
 {
  if (inf[i] == '(')
   operators.push(inf[i]);
  else if (inf[i] == ')') {
   while (!operators.isEmpty()) {
    sumb = operators.pop();
    if (sumb == '(')
     break;
    post += sumb;
   }
  }
  else if (inf[i] == '+' || inf[i] == '-') {
   while (!operators.isEmpty()) {
    if (operators.get() == '(') {
     break;
    }
    post += operators.pop();
   }
   operators.push(inf[i]);
  }
  else if (inf[i] == '*' || inf[i] == '/') {
   while (!operators.isEmpty()) {
    char sb = operators.get();
    if (sb == '+' || sb == '-' || sb == '(') {
     break;
    }
    post += operators.pop();
   }
   operators.push(inf[i]);
  }
  else {
   post += inf[i];
  }
 }
 while (!operators.isEmpty()) {
  post += operators.pop();
 }
 std::string result = "";
 result += post[0];
 for (int i = 1; i < post.length(); i++) {
  if (post[i] == ' ' && post[i - 1] == ' ' &&
   post[i + 1] > 47 && post[i + 1] < 58) {
   continue;
  }
  else if ((post[i] == '+' || post[i] == '-' || post[i] == '/' || post[i] == '*') &&
   (post[i + 1] == '+' || post[i + 1] == '-' 
    || post[i + 1] == '/' || post[i + 1] == '*')) {
   result += post[i];
   result += ' ';
  }
  else if (post[i] > 47 && post[i] < 58 &&
   (post[i + 1] == '+' || post[i + 1] == '-' 
    || post[i + 1] == '/' || post[i + 1] == '*')) {
   result += post[i];
   result += ' ';
  }
  else{
   result += post[i];
   }
 }
 return result;
}
