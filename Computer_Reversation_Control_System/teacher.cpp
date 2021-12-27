#include "teacher.h"
// 默认构造
Teacher::Teacher()
{

}

// 有参构造
Teacher::Teacher(string empId, string name, string pwd)
{
    // 初始化属性
    this->m_EmpId = empId;
    this->m_Name = name;
    this->m_Pwd = pwd;
}

// 子菜单
void Teacher::openMenu()
{
    cout << "欢迎教师：" << this->m_Name << "登录！" << endl;
    cout << "\t\t ----------------------------------\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|          1.查看所有预约          |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|          2.审核预约              |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|          0.注销登录              |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t ----------------------------------\n";
    cout << "请选择您的操作： " << endl;
}

// 查看所有预约
void Teacher::showAllOrder()
{
    Student s;
    s.showAllOrder();
}

// 审核预约
void Teacher::validOrder()
{
    OrderFile of;
    if (of.m_Size == 0)
    {
        cout << "无预约记录!" << endl;
        system("pause");
        system("cls");
        return;
    }

    vector<int> v;  // 用于存放审核记录的容器
    int index = 0;  // 预约记录的序号
    cout << "待审核的预约记录如下: " << endl << endl;

    for (int i = 0; i < of.m_Size; i++)
    {
        if (of.m_orderData[i]["status"] == "1")
        {
            v.push_back(i);
            cout << ++index << "丶";
            cout << "预约日期: 周" << of.m_orderData[i]["date"] << " |";
            cout << " 时间段: " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << " |";
            cout << " 机房编号: " << of.m_orderData[i]["roomId"] << " |";
            cout << " 学号: " << of.m_orderData[i]["stuId"] << " |";
            cout << " 姓名: " << of.m_orderData[i]["stuName"] << " |";
            string status = " 当前状态: ";
            cout << status << "审核中" << endl;
        }
    }
    cout << endl;

    cout << "请输入要审核的预约记录, 输入0可以返回上一级"  << endl;
    int select = 0;
    int ret = 0;  // 接收预约结果

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
                cout << "请输入审核结果: " << endl;
                cout << "\t-----------" << endl;
                cout << "\t| 1.通过  |" << endl;
                cout << "\t| 2.不通过|" << endl;
                cout << "\t-----------" << endl;
                cin >> ret;

                if (ret == 1)  // 通过
                {
                    of.m_orderData[v[select - 1]]["status"] = "2";
                }
                else  // 不通过
                {
                    of.m_orderData[v[select - 1]]["status"] = "-1";
                }
                of.updateOrder();  // 过呢更新记录
                cout << "审核完毕" << endl;
                break;
            }
        }
        cout << "输入有误, 请重新输入!" << endl;
    }
    system("pause");
    system("cls");
}