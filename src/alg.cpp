// Copyright 2022 CheginArtyom
#include <string>
#include <map>
#include "tstack.h"

std::string infx2pstfx(std::string inf) {
  T_Stack<char, 20> map_Stack;
    std::string line;
    std::map<char, int> map;
    map['('] = 0;
    map[')'] = 0;
    map['+'] = 1;
    map['-'] = 1;
    map['*'] = 2;
    map['/'] = 2;
    for (char ch : inf) {
        if (map.find(ch) == map.end()) {
            line += ch;
            line += ' ';
        } else {
            if (ch == ')') {
                while (map_Stack.get() != '(') {
                    line += map_Stack.get();
                    line += ' ';
                    map_Stack.pop();
                }
                map_Stack.pop();
            } else if (ch == '(' || map_Stack.isEmpty()) {
                map_Stack.push(ch);
            } else if (map[ch] > map[map_Stack.get()]) {
                map_Stack.push(ch);
            } else {
                while (!map_Stack.isEmpty() && map[map_Stack.get()] >= map[ch]) {
                    line += map_Stack.get();
                    line += ' ';
                    map_Stack.pop();
                }
                map_Stack.push(ch);
            }
        }
    }
    while (!map_Stack.isEmpty()) {
        line += map_Stack.get();
        line += ' ';
        map_Stack.pop();
    }
    line.pop_back();
    return line;
  }

int eval(std::string line) {
  T_Stack<int, 20> answ_Stack;
  std::string map = "+-*/";
  for (char ch : line) {
    if (ch == ' ') continue;
    std::size_t op = map.find(ch);
    if (op == std::string::npos) {
      answ_Stack.push(ch & 0xF);
    } else {
      int arg2 = answ_Stack.get();
      answ_Stack.pop();
      int arg1 = answ_Stack.get();
      answ_Stack.pop();
      int result;
      switch (map[op]) {
      case '+':
        result = arg1 + arg2;
        break;
      case '-':
        result = arg1 - arg2;
        break;
      case '*':
        result = arg1 * arg2;
        break;
      case '/':
        result = arg1 / arg2;
        break;
      }
            answ_Stack.push(result);
        }
    }
    return answ_Stack.get();  return 0;
}
