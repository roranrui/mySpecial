#include "student.h"
// 默认构造
Student::Student()
{

}

// 有参构造
Student::Student(string id, string name, string pwd)
{
    // 初始化属性
    this->m_Id = id;
    this->m_Name = name;
    this->m_Pwd = pwd;

    // 初始化机房信息
    this->initComputer();
}

// 子菜单
void Student::openMenu()
{
    cout << "欢迎学生：" << this->m_Name << "登录！" << endl;
    cout << "\t\t ----------------------------------\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          1.申请预约             |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          2.查看我的预约         |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          3.查看所有预约         |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          4.取消预约             |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          0.注销登录             |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t ----------------------------------\n\n";
    cout << "请选择您的操作： ";
}

// 申请预约
void Student::applyOrder()
{
    cout << "机房开放时间为周一至周六!" << endl;
    cout << "请输入预约申请时间: " << endl;
    cout << "\t-----------" << endl;
    cout << "\t| 1. 周一 |" << endl;
    cout << "\t| 2. 周二 |" << endl;
    cout << "\t| 3. 周三 |" << endl;
    cout << "\t| 4. 周四 |" << endl;
    cout << "\t| 5. 周五 |" << endl;
    cout << "\t| 6. 周六 |" << endl;
    cout << "\t-----------" << endl;

    int date = 0;  // 日期
    int interval = 0;  // 时间段
    int room = 0;  // 机房编号
    while (true)
    {
        cin >> date;
        if (date >= 1 && date <= 6)
        {
            break;
        }
        cout << "输入错误, 请重新输入!" << endl;
        system("pause");
        system("cls");
        return;

    }
    cout << "请输入预约时间段: " << endl;
    cout << "\t--------------------------" << endl;
    cout << "\t| 1. 上午(9:00 ~ 12:00)  |" << endl;
    cout << "\t| 2. 下午(14:00 ~ 18:00) |" << endl;
    cout << "\t--------------------------" << endl;

    while (true)
    {
        cin >> interval;
        if (interval >= 1 && interval <= 2)
        {
            break;
        }
        cout << "输入错误, 请重新输入!" << endl;
        system("pause");
        system("cls");
        return;

    }
    cout << "请选择机房: " << endl;
    cout << "\t---------------------" << endl;
    for (vector<ComputerRoom>::const_iterator it = vCom.begin(); it != vCom.end(); it++)
    {
        cout << "\t| "<< it->m_CId << "号机房容量为: " << it->m_Size << " |" << endl;
    }
    cout << "\t---------------------" << endl;
    while (true)
    {
        cin >> room;
        if (room >= 1 && room <= 6)
        {
            break;
        }
        cout << "输入错误, 请重新输入!" << endl;
        system("pause");
        system("cls");
        return;
    }

    bool ret = this->checkRepeat(date, interval, room);

    if (ret)
    {
        cout << "您的预约重复, 请重新预约!" << endl;
        system("pause");
        system("cls");
        return;
    }

    cout << "预约已提交, 正在审核中!" << endl;
    ofstream ofs(ORDER_FILE, ios::app);

    ofs << "date:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "stuId:" << this->m_Id << " ";
    ofs << "stuName:" << this->m_Name << " ";
    ofs << "roomId:" << room << " ";
    ofs << "status:" << 1 << endl;  // 1. 审核中 2. 预约成功 3. 预约失败 4. 取消预约
    ofs.close();

    OrderFile of;
    of.updateOrder();

    system("pause");
    system("cls");

}

// 查看自身预约
void Student::showMyOrder()
{
    OrderFile of;
    if (of.m_Size == 0)
    {
        cout << "无预约记录!" << endl;
        system("pause");
        system("cls");
        return;
    }

    cout << "您的预约记录如下: "  << endl << endl;
    for (int i = 0; i < of.m_Size; i++)
    {

        if (this->m_Id == of.m_orderData[i]["stuId"])  // 查到自身预约
        {
            cout << "| 预约日期: 周" << of.m_orderData[i]["date"] << " |";
            cout << " 时间段: " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << " |";
            cout << " 机房号: " << of.m_orderData[i]["roomId"] << " |";

            string status = " 当前状态: ";
            // 1. 审核中 2. 预约成功 -1. 预约失败 0 取消预约
            if (of.m_orderData[i]["status"] == "1")
            {
                status += "审核中";
            }
            else if (of.m_orderData[i]["status"] == "2")
            {
                status += "预约成功";
            }
            else if (of.m_orderData[i]["status"] == "-1")
            {
                status += "预约失败, 审核未通过";
            }
            else if (of.m_orderData[i]["status"] == "0")
            {
                status += "预约取消";
            }
            cout << status << " |" << endl;
        }
    }
    cout << endl;
    system("pause");
    system("cls");
}

// 查看所有预约
void Student::showAllOrder()
{
    OrderFile of;
    if (of.m_Size == 0)
    {
        cout << "无预约记录!" << endl;
        system("pause");
        system("cls");
        return;
    }
    cout << "机房所有预约情况如下: " << endl << endl;
    for (int i = 0; i < of.m_Size; i++)
    {
        cout << "| "<< i + 1 << "丶";
        cout << "预约日期: 周" << of.m_orderData[i]["date"] << " |";
        cout << " 时间段: " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << " |";
        cout << " 机房号: " << of.m_orderData[i]["roomId"] << " |";
        cout << " 学号: " << of.m_orderData[i]["stuId"] << " |";
        cout << " 姓名: " << of.m_orderData[i]["stuName"] << " |";
        string status = " 当前状态: ";
        // 1. 审核中 2. 预约成功 -1. 预约失败 0 取消预约
        if (of.m_orderData[i]["status"] == "1")
        {
            status += "审核中";
        }
        else if (of.m_orderData[i]["status"] == "2")
        {
            status += "预约成功";
        }
        else if (of.m_orderData[i]["status"] == "-1")
        {
            status += "预约失败, 审核未通过";
        }
        else if (of.m_orderData[i]["status"] == "0")
        {
            status += "预约取消";
        }
        cout << status << " |" << endl;
    }
    cout << endl;
    system("pause");
    system("cls");
}

// 取消预约
void Student::cancelOrder()
{
    OrderFile of;
    if (of.m_Size == 0)
    {
        cout << "无预约记录!" << endl;
        system("pause");
        system("cls");
        return;
    }

    cout << "温馨提醒: 审核中或者预约成功的记录可以取消" << endl << endl;
    vector<int> v;  // 存放在最大的记录容器中的下标
    int index = 1;  // 存放记录编号
    for (int i = 0; i < of.m_Size; i++)
    {
        // 先判断是否是自身学号
        if (this->m_Id == of.m_orderData[i]["stuId"])
        {
            // 筛选状态
            if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
            {
                v.push_back(i);
                cout << "| "<< index++ << "丶";
                cout << "预约日期: 周" << of.m_orderData[i]["date"] << " |";
                cout << " 时间段: " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << " |";
                cout << " 机房编号: " << of.m_orderData[i]["roomId"] << " |";
                string status = " 当前状态: ";
                // 1. 审核中 2. 预约成功 -1. 预约失败 0 取消预约
                if (of.m_orderData[i]["status"] == "1")
                {
                    status += "审核中";
                }
                else if (of.m_orderData[i]["status"] == "2")
                {
                    status += "预约成功";
                }
                else if (of.m_orderData[i]["status"] == "-1")
                {
                    status += "预约失败, 审核未通过";
                }
                else if (of.m_orderData[i]["status"] == "0")
                {
                    status += "预约已取消";
                }
                cout << status << " |" << endl;
            }
        }
    }
    cout << "请输入您要取消的记录, 输入0则返回上一菜单" << endl;
    int select = 0;

    while (true)
    {
        cin >> select;

        if (select >= 0 && select <= v.size())
        {
            if (select == 0)
            {
                break;
            }
            else
            {
                // 记录位置 v中select - 1;
                of.m_orderData[v[select - 1]]["status"] = "0";
                of.updateOrder();
                cout << "预约取消成功!" << endl;
                break;
            }
        }
        cout << "输入错误, 请重新输入!" << endl;
    }
    system("pause");
    system("cls");
}

// 初始化机房信息
void Student::initComputer()
{
    ifstream ifs(COMPUTER_FILE, ios::in);

    ComputerRoom com;
    while (ifs >> com.m_CId && ifs >> com.m_Size)
    {
        vCom.push_back(com);
    }
    ifs.close();

    cout << "机房的数量为: " << vCom.size() << endl;

}

// 是否重复预约
bool Student::checkRepeat(int date, int interval, int room)
{
    OrderFile of;
    if (of.m_Size == 0)
    {
        cout << "无预约记录!" << endl;
        system("pause");
        system("cls");
        return false;
    }

    // 用于判断是否重复的标志, 一旦发现自己的预约重复, 就返回true
    bool flag = false;
    for (int i = 0; i < of.m_Size; i++)
    {

        if (this->m_Id == of.m_orderData[i]["stuId"])  // 查到自身预约
        {
            // 将字符串数据转成整型
            if (atoi(of.m_orderData[i]["date"].c_str()) == date && atoi(of.m_orderData[i]["interval"].c_str()) == interval
            && atoi(of.m_orderData[i]["roomId"].c_str()) == room)
            {
                flag = true;
            }
        }
    }
    return flag;
}
