#include <iostream>
#include "Identity.h"
#include "administor.h"
using namespace std;

void adminMenu(Identity * &admin)
{
    while (true)
    {
        admin->openMenu();

        Administor * administor = (Administor *) admin;

        // 选择
        int select = 0;
        cin >> select;

        if (select == 1)  // 添加账号
        {
//            cout << "添加账号" << endl;
            administor->addAccount();
        }
        else if (select == 2)  // 查看账号
        {
//            cout << "查看账号" << endl;
            administor->showAccount();
        }
        else if (select == 3)  // 查看机房信息
        {
//            cout << "查看机房信息" << endl;
            administor->showComputer();
        }
        else if (select == 4)  // 清空预约
        {
//            cout << "清空预约" << endl;
            administor->cleanFile();
        }
        else if (select == 5) // 删除账号
        {
//            cout << "删除账号" << endl;
            administor->deleteAccount();
        }
        else if (select == 0)  // 注销登录
        {
            delete admin;
            cout << "注销成功" << endl;
            system("pause");
            system("cls");
            break;
        }
        else
        {
            cout << "输入错误, 请重新输入!" << endl;
            system("pause");
            system("cls");
        }

    }
}

void stuMenu(Identity * &student)
{
    while (true)
    {
        // 调用学生子菜单
        student->openMenu();
        Student * stu = (Student *)student;

        int select = 0;
        cin >> select;

        if (select == 1)  // 申请预约
        {
            stu->applyOrder();
        }
        else if (select == 2)  // 查看自身预约
        {
            stu->showMyOrder();
        }
        else if (select == 3)  // 查看所有人预约
        {
            stu->showAllOrder();
        }
        else if (select == 4)  // 取消预约
        {
            stu->cancelOrder();
        }
        else if (select == 0)  // 取消登录
        {
            delete student;
            cout << "注销成功!" << endl;
            system("pause");
            system("cls");
            break;
        }
        else
        {
            cout << "输入错误, 请重新输入!" << endl;
            system("pause");
            system("cls");
        }

    }
}

void teaMenu(Identity * &teacher)
{
    while (true)
    {
        // 调用子菜单
        teacher->openMenu();

        Teacher * tea = (Teacher *)teacher;

        int select = 0;
        cin >> select;

        if (select == 1)  // 查看所有预约
        {
            tea->showAllOrder();
        }
        else if (select == 2)  // 审核预约
        {
            tea->validOrder();
        }
        else if (select == 0)  // 注销账号
        {
            delete tea;
            cout << "注销成功!" << endl;
            system("pause");
            system("cls");
            break;
        }
        else
        {
            cout << "输入错误, 请重新输入!" << endl;
            system("pause");
            system("cls");
        }
    }
}

void show_Menu()
{
    cout << "======================  欢迎来到伯乐马机房预约系统  ======================"
         << endl << endl;
    cout << "====================== 本系统由高四年级主任康托提供技术支持 ======================" << endl;
    cout << endl << "请输入您的身份" << endl;
    cout << "\t\t -------------------------------\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          1.学    生           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          2.老    师           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          3.管 理 员           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          0.退    出           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t -------------------------------\n";
    cout << "输入您的选择: ";
}


// 登录
void LoginIn(string fileName, int type)  // 文件名, 身份
{
    // 父类指针, 用于指向子类对象
    Identity * person = nullptr;

    // 读文件
    ifstream ifs(fileName, ios::in);
    if (!ifs.is_open())
    {
        cout << "信息有误, 请确认账号是否存在!" << endl;
        ifs.close();
        return;
    }

    // 接收用户的的信息
    string id;
    string name, pwd;

    // 判断身份(1学生 2教师)
    if (type == 1)
    {
        cout << "请输入你的学号: ";
        getline(cin, id);
    }
    else if (type == 2)
    {
        cout << "请输入您的职工号: ";
        getline(cin, id);
    }



    cout << "请输入用户名: ";
    getline(cin, name);
    cout << "请输入密码: ";
    getline(cin, pwd);

    // 身份验证(1学生 2教师 3管理员)
    if (type == 1)
    {
        string fId;  // 从文件中读取的id号
        string fName, fPwd;  // 从文件中获取的姓名, 密码
        while (ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            // 与用户输入的信息做对比
            if (fId == id && fName == name && fPwd == pwd)
            {
                cout << "验证登录成功!" << endl;
                system("pause");
                system("cls");
                person = new Student(id, name, pwd);

                // 进入学生端的子菜单
                stuMenu(person);
                return;
            }
        }
        cout << "验证登录失败!" << endl;
        system("pause");
        system("cls");
        return;
    }
    else if (type == 2)
    {
        string fId;  // 从文件中读取的id号
        string fName, fPwd;  // 从文件中获取的姓名, 密码
        while (ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            // 与用户输入的信息做对比
            if (fId == id && fName == name && fPwd == pwd)
            {
                cout << "验证登录成功!" << endl;
                system("pause");
                system("cls");
                person = new Teacher(id, name, pwd);

                // 进入教师端的子菜单
                teaMenu(person);
                return;
            }
        }
        cout << "验证登录失败!" << endl;
        system("pause");
        system("cls");
        return;
    }
    else if (type == 3) {
        string fName, fPwd;  // 从文件中获取的姓名, 密码
        while (ifs >> fName && ifs >> fPwd) {
            // 与用户输入的信息做对比
            if (fName == name && fPwd == pwd) {
                cout << "验证登录成功!" << endl;
                system("pause");
                system("cls");
                person = new Administor(name, pwd);

                // 进入管理端的子菜单
                adminMenu(person);
                return;
            }
        }
        cout << "验证登录失败!" << endl;
        system("pause");
        system("cls");
        return;
    }
    else
    {
        cout << "验证登录失败!" << endl;
        system("pause");
        system("cls");
        return;
    }
}


int main()
{
    int select = 0;  // 接收用户选择

    while (true)
    {
        show_Menu();
        cin >> select;
        cin.get();

        if (select == 1)  // 学生
        {
            LoginIn(STUDENT_FILE, 1);
        }
        else if(select == 2)  // 老师
        {
            LoginIn(TEACHER_FILE, 2);
        }
        else if(select == 3)  // 管理员
        {
            LoginIn(ADMIN_FILE, 3);
        }
        else if (select == 0)  // 退出
        {
            cout << "欢迎下次使用!" << endl;
            break;
        }
        else
        {
            cout << "输入有误, 请重新选择!" << endl;
            system("pause");
            system("cls");
        }
    }

    system("pause");
    return 0;
}