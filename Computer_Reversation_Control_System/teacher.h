#pragma once
#include "Identity.h"
#include "student.h"
#include <iostream>
using namespace std;


#ifndef C___COMPUTER_ROOM_REVERSATION_SYSTEM_TEACHER_H
#define C___COMPUTER_ROOM_REVERSATION_SYSTEM_TEACHER_H

class Teacher: public Identity
{
public:

    // 默认构造
    Teacher();
    // 有参构造
    Teacher(string empId, string name, string pwd);

    // 子菜单
    virtual void openMenu();

    // 查看所有预约
    void showAllOrder();

    // 审核预约
    void validOrder();

    // 职工号
    string m_EmpId;
};


#endif //C___COMPUTER_ROOM_REVERSATION_SYSTEM_TEACHER_H
