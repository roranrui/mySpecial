#pragma once
#include <iostream>
using namespace std;



#ifndef C___COMPUTER_ROOM_REVERSATION_SYSTEM_IDENTITY_H
#define C_COMPUTER_ROOM_REVERSATION_SYSTEM_IDENTITY_H

// 创建身份基类
class Identity
{
public:
    // 子菜单
    virtual void openMenu() = 0;

    // 用户名
    string m_Name;

    // 密码
    string m_Pwd;
};


#endif //C___COMPUTER_ROOM_REVERSATION_SYSTEM_IDENTITY_H
