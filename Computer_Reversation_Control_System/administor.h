#pragma once
#include "Identity.h"
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "globalFile.h"
using namespace std;

#ifndef C___COMPUTER_ROOM_REVERSATION_SYSTEM_ADMINISTOR_H
#define C___COMPUTER_ROOM_REVERSATION_SYSTEM_ADMINISTOR_H

class Administor: public Identity
{
public:
    // 默认构造
    Administor();

    // 有参构造
    Administor(string name, string pwd);

    // 子菜单
    virtual void openMenu();

    // 添加账号
    void addAccount();

    // 查看账号
    void showAccount();

    // 查看机房信息
    void showComputer();

    // 清空预约记录
    void cleanFile();

    // 删除老师和学生账号
    void deleteAccount();

    // 初始化容器
    void initVector();

    // 初始化机房信息
    void initComputer();

    // 学生容器
    vector<Student> vStu;

    // 老师容器
    vector<Teacher> vTea;

    // 机房容器
    vector<ComputerRoom> vCom;

    // 检测重复  (id 类型)
    bool checkRepeat(basic_string<char> id, int type);

    // 仿函数 用于for_each打印信息
    void operator()(Student & s)
    {
        cout << "学号: " <<  s.m_Id << "\t姓名: " << s.m_Name << "\t密码: " << s.m_Pwd << endl;
    }

    void operator()(Teacher & t)
    {
        cout << "教职工号: " <<  t.m_EmpId << "\t姓名: " << t.m_Name << "\t密码: " << t.m_Pwd << endl;
    }

    void operator()(ComputerRoom & c)
    {
        cout << "机房编号: " << c.m_CId << "\t机房最大容量: " << c.m_Size << endl;
    }
};


#endif //C___COMPUTER_ROOM_REVERSATION_SYSTEM_ADMINISTOR_H
