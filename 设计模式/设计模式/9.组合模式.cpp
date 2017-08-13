#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <list>
#include <string>
#include "util_tools.h"
using namespace std;
//组合模式 示例场景 ： 文件夹 存储文件
class BFILE
{
public:
	virtual int  addFile(BFILE* filename) = 0;
	virtual string  getname() = 0;
	virtual int  removeFile(BFILE* str) = 0;
	virtual std::list<BFILE*>* getFileList() = 0;
protected:
private:
};
//文件
class document:public BFILE
{
public:
	document(string fname)
	{
		this->m_Fname = fname;
	}
	virtual int addFile(BFILE* filename)
	{
		return -1;
	}
	virtual string getname()
	{
		return m_Fname;
	}
	virtual int removeFile(BFILE* str)
	{
		return -1;
	}
	std::list<BFILE*> *getFileList()
	{
		return NULL;
	}
protected:
private:
	string m_Fname;
};

//文件夹
class folder:public BFILE
{
public:
	folder(string name)
	{
		m_Fname = name;
	}
	virtual int addFile(BFILE* filename)
	{
		cout << "添加文件" << filename->getname().c_str() << endl;
		m_fileList.push_back(filename);
		return 0;
	}
	virtual int removeFile(BFILE* str)
	{
		m_fileList.remove(str);
		return 0;
	}
	virtual string getname()
	{
		return m_Fname;
	}
	std::list<BFILE*> *getFileList()
	{
		return &m_fileList;
	}
protected:
private:
	string m_Fname;
	std::list<BFILE*> m_fileList;
};

int main09(int args,char*argus[])
{
	//定义 一个新文件
	string stname = "test.txt";
	document* md = new document(stname);
	//定义 一个新文件夹
	string fname = "folder";
	folder* mf = new folder(fname);
	mf->addFile(md);



	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
