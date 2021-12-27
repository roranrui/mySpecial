#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "Identity.h"
#include "computerRoom.h"
#include "globalFile.h"
#include "orderFile.h"
using namespace std;

#ifndef C___COMPUTER_ROOM_REVERSATION_SYSTEM_STUDENT_H
#define C___COMPUTER_ROOM_REVERSATION_SYSTEM_STUDENT_H

class Student: public Identity
{
public:
    // 默认构造
    Student();

    // 有参构造
    Student(string id, string name, string pwd);

    // 子菜单
    virtual void openMenu();

    // 申请预约
    void applyOrder();

    // 查看自身预约
    void showMyOrder();

    // 查看所有预约
    void showAllOrder();

    // 取消预约
    void cancelOrder();

    // 初始化机房信息
    void initComputer();

    // 是否重复预约
    bool checkRepeat(int date, int interval, int room);

    // 学生学号
    string m_Id;

    // 机房容器
    vector<ComputerRoom> vCom;
};

#endif //C___COMPUTER_ROOM_REVERSATION_SYSTEM_STUDENT_H
