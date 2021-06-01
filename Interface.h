#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <cmath>
#include <sstream>
#include <vector>
#include "Controller.h"
class Interface
{
    friend class Controller;
public:
    int id;
    bool write_log;
    Interface(int id, bool write_log, Controller* c);
    int run();
    string com(string main);
    int command(stringstream *ss);
    void log(const string& s);
    void show(const string& s);
private:
    Controller *cc;
    ofstream logger;
    string log_file_name;
};