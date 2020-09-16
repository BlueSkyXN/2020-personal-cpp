#pragma once
#include <atlstr.h>
#include <string>  
#include <vector>  
#include <list>
#include<iostream>
#include<fstream>

#include "assertions.h" 
#include "autolink.h"  
#include "config.h" 
#include "features.h" 
#include "forwards.h" 
#include "reader.h" 
#include "value.h" 
#include "json.h" 
#include "version.h" 
#include "writer.h" 
#include "json_tool.h" 
using namespace std;

class GHAnalysis
{
public:
	GHAnalysis() {}
	~GHAnalysis() {}
public:
	//��ʼ��������json�ļ�·��������,���õ�vec_JsonData
	bool Init_GHAnalysis(string jsonFilePath);  

	//��ȡָ���û���ָ���¼�������
	int CheckUserEventNumber(string strUserName, string strEventType);  

	//��ȡָ����Ŀ��ָ���¼�������
	int CheckProjectEventNumber(int nProjectId, string strEventType);

	//��ȡָ���û���ָ����Ŀ��ָ���¼�������
	int CheckUserProjectEventNumber(string strUserName, int nProjectId, string strEventType);

	//����һ��vector<Json::Value>����
	vector<Json::Value> vec_JsonData;  //��Ž������json���ݵ�����
};
