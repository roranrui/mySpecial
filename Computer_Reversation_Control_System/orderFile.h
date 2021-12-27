#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include "globalFile.h"
using namespace std;

#ifndef C___COMPUTER_ROOM_REVERSATION_SYSTEM_ORDERFILE_H
#define C___COMPUTER_ROOM_REVERSATION_SYSTEM_ORDERFILE_H

class OrderFile
{
public:
    // 默认构造
    OrderFile();

    // 更新预约记录
    void updateOrder();

    // 读取信息的一个过程--封装
    static void zip(map<string, string> & m, const string& info);

    // 记录预约条数
    int m_Size;

    // 记录所有预约信息的容器
    map<int, map<string, string>> m_orderData;  // 大容器记录所有预约信息条数, 小容器记录每一条预约信息的详细信息

    // 预约记录属性(日期, 时间段, 学生编号, 学生姓名, 机房编号, 预约状态)
    string date, interval, stuId, stuName, roomId, status;
};


#endif //C___COMPUTER_ROOM_REVERSATION_SYSTEM_ORDERFILE_H
