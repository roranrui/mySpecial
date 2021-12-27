#include "orderFile.h"

// 默认构造
OrderFile::OrderFile()
{
    ifstream ifs(ORDER_FILE, ios::in);

    this->m_Size = 0;

    while (ifs >> this->date && ifs >> this->interval && ifs >> this->stuId
    && ifs >> this->stuName && ifs >> this->roomId && ifs >> this->status)
    {
        // test
//        cout << this->date << endl;
//        cout << this->interval << endl;
//        cout << this -> stuId << endl;
//        cout << this -> stuName << endl;
//        cout << this ->roomId << endl;
//        cout << this -> status << endl;
//        cout << endl;
        map<string, string> m;
        zip(m, this->date);
        zip(m, this->interval);
        zip(m, this->stuId);
        zip(m, this->stuName);
        zip(m, this->roomId);
        zip(m, this->status);

        // 放入大容器中
        this->m_orderData.insert(make_pair(this->m_Size, m));
        this->m_Size++;
    }
    ifs.close();


    // test
//    for (map<int, map<string, string>>::const_iterator it = this->m_orderData.begin(); it != this-> m_orderData.end(); it++)
//    {
//        cout << "第" << it->first << "条" << endl;
//        cout << "value: " << endl;
//        for (map<string, string>::const_iterator mit = it->second.begin(); mit !=it->second.end(); mit++)
//        {
//            cout << " mkey: " << mit->first << "\t mvalue: " << mit->second << " ";
//        }
//        cout << endl;
//    }
}

// 更新预约记录
void OrderFile::updateOrder()
{
    if (this->m_Size == 0)
    {
        return;
    }

    ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
    for (int i = 0; i < this -> m_Size; i++) {
        ofs << "date:" << this->m_orderData[i]["date"] << " ";
        ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
        ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
        ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
        ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
        ofs << "status:" << this->m_orderData[i]["status"] << endl;
    }
    ofs.close();

}

// 读取信息的一个过程--封装
void OrderFile::zip(map<string, string> & m, const string & info)
{
    string key;
    string value;
    // eg: date:123
    int pos = info.find(':');  // 4
    if (pos != -1)
    {
        key = info.substr(0, pos);
        value = info.substr(pos + 1, info.size() - pos -1);  // 结束位置 size - pos -1 = 8-4-1
        m.insert(make_pair(key, value));
    }
}
