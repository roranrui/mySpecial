#include "administor.h"

// 默认构造
Administor::Administor()
{

}

// 有参构造
Administor::Administor(string name, string pwd)
{
    this->m_Name = name;
    this->m_Pwd = pwd;
    this->initVector();
    this->initComputer();
}

// 子菜单
void Administor::openMenu()
{
    cout << "欢迎管理员："<<this->m_Name << "登录！" << endl;
    cout << "\t\t ---------------------------------\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          1.添加账号            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          2.查看账号            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          3.查看机房            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          4.清空预约            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          5.删除账号            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          0.注销登录            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t ---------------------------------\n\n";
    cout << "请选择您的操作： ";
}

// 添加账号
void Administor::addAccount() {
    cout << "请输入添加账号的类型:" << endl;
    cout << "\t-----------" << endl;
    cout << "\t| 1. 学生 |" << endl;
    cout << "\t| 2. 老师 |" << endl;
    cout << "\t-----------" << endl;
    string fileName;  // 操作的文件名
    string tip, errortip;  // 提示信息

    ofstream ofs;

    int select = 0;
    cin >> select;

    while (true)
    {
        if (select == 1)  // 添加学生账号且不允许重名
        {
            fileName = STUDENT_FILE;
            tip = "请输入学号: ";
            errortip = "学号重复, 请重新输入!";
            break;
        }
        else if (select == 2)  // 添加教师账号且不允许重名
        {
            fileName = TEACHER_FILE;
            tip = "请输入教师职工号: ";
            errortip = "教职工号重复, 请重新输入!";
            break;
        }
        else
        {
            cout << "输入有误请重新输入!" << endl;
            system("pause");
            system("cls");
            break;
        }
    }

        ofs.open(fileName, ios::out | ios::app);
        string id;
        string name, pwd;
        cout << tip;

         while (true)
         {
             cin >> id;
             bool ret = checkRepeat(id, select);
             if (ret)  // 有重复
             {
                cout << errortip << endl;
             }
             else
             {
                 break;
             }
         }



        cout << "请输入姓名: ";
        cin >> name;

        cout << "请输入密码: ";
        cin >> pwd;

        // 添加数据
        ofs << endl << id << " " << name << " " << pwd << " " << endl;
        cout << "添加成功!" << endl;

        system("pause");
        system("cls");

        ofs.close();

        // 初始化文件
        this->initVector();
}

// 查看账号
void Administor::showAccount()
{
    cout << "请选择查看的内容" << endl;
    cout << "\t------------------" << endl;
    cout << "\t| 1.查看所有学生 |" << endl;
    cout << "\t| 2.查看所有老师 |" << endl;
    cout << "\t------------------" << endl;

    int select = 0;
    cin >> select;

    while (true)
    {
        if (select == 1)
        {
            // 查看学生
            cout << "所有学生信息如下: " << endl;
            cout << "\t| ";
            for_each(vStu.begin(), vStu.end(),Administor());
            cout << " |" << endl;
            break;
        }
        else if (select == 2)
        {
            // 查看老师
            cout << "所有老师信息如下: " << endl;
            cout << "\t| ";
            for_each(vTea.begin(), vTea.end(),Administor());
            cout << " |" << endl;
            break;
        }
        else
        {
            cout << "输入错误, 请重新输入!" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
    system("pause");
    system("cls");
}

// 查看机房信息
void Administor::showComputer()
{
    cout << "机房信息如下: " << endl;
    for_each(vCom.begin(), vCom.end(), Administor());
    system("pause");
    system("cls");
}

// 清空预约记录
void Administor::cleanFile()
{
    cout << "请确认是否要清空文件" << endl;
    cout << "\t-----------" << endl;
    cout << "\t| 1. 确认 |" << endl;
    cout << "\t| 2. 取消 |" << endl;
    cout << "\t-----------" << endl;

    int select = 0;
    cin >> select;

    while (true)
    {
        if (select == 1)
        {
            ofstream ofs(ORDER_FILE, ios::trunc);
            ofs.close();

            cout << "清空成功!" << endl;
            system("pause");
            system("cls");
            return;
        }
        else if (select == 2)
        {
            system("pause");
            system("cls");
            return;
        }
        else
        {
            cout << "输入错误, 请重新选择!" << endl;
            system("pause");
            system("cls");
            return;
        }

    }


}

// 删除老师和学生账号
void Administor::deleteAccount()
{
    cout << "请确认是否要清空所有账号信息" << endl;
    cout << "\t-----------" << endl;
    cout << "\t| 1. 确认 |" << endl;
    cout << "\t| 2. 取消 |" << endl;
    cout << "\t-----------" << endl;

    int select = 0;
    cin >> select;

    while (true)
    {
        if (select == 1)
        {
            cout << "请选择要清空的文件: " << endl;
            cout << "\t1. 学生账号" << endl;
            cout << "\t2. 老师账号" << endl;
            cout << "\t0. 取消" << endl;

            int choice = 0;
            cin >> choice;

            while (true)
            {
                if (choice == 1)
                {
                    ofstream ofs(STUDENT_FILE, ios::trunc);
                    ofs.close();

                    cout << "学生账号清空成功!" << endl;
                    system("pause");
                    system("cls");
                    return;
                }
                else if (choice == 2)
                {
                    ofstream ofs(STUDENT_FILE, ios::trunc);
                    ofs.close();

                    cout << "老师账号清空成功!" << endl;
                    system("pause");
                    system("cls");
                    return;
                }
                else if (choice == 0)
                {
                    return;
                }
                else
                {
                    cout << "输入错误, 请重新选择!" << endl;
                    system("pause");
                    system("cls");
                    return;
                }

            }
        }
        else if (select == 2)
        {
            system("pause");
            system("cls");
            return;
        }
        else
        {
            cout << "输入错误, 请重新选择!" << endl;
            system("pause");
            system("cls");
            return;
        }
    }


}

// 初始化容器
void Administor::initVector()
{
    vStu.clear(), vTea.clear();  // 确保容器为空
    // 读取学生信息
    ifstream ifs(STUDENT_FILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败!" << endl;
        return;
    }

    Student s;
    while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
    {
        vStu.push_back(s);
    }
    cout << "当前学生数量为: " << vStu.size() << endl;
    ifs.close();

    // 读取老师信息
    ifs.open(TEACHER_FILE, ios::in);
    Teacher t;
    while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
    {
        vTea.push_back(t);
    }
    cout << "当前老师数量为: " << vTea.size() << endl;
    ifs.close();
}

// 初始化机房信息
void Administor::initComputer()
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

// 检测重复  (id, 类型)
bool Administor::checkRepeat(string id, int type)
{
    if (type == 1) // 学生
    {
        for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
        {
            if (id == it->m_Id)
            {
                return true;
            }
        }
    }
    else if (type == 2)
    {
        for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
        {
            if (id == it->m_EmpId)
            {
                return true;
            }
        }
    }
    return false;
}