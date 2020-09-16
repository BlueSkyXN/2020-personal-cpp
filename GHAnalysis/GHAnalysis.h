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
	//初始化，传入json文件路径并加载,并得到vec_JsonData
	bool Init_GHAnalysis(string jsonFilePath);  

	//获取指定用户的指定事件的数量
	int CheckUserEventNumber(string strUserName, string strEventType);  

	//获取指定项目中指定事件的数量
	int CheckProjectEventNumber(int nProjectId, string strEventType);

	//获取指定用户在指定项目中指定事件的数量
	int CheckUserProjectEventNumber(string strUserName, int nProjectId, string strEventType);

	//创建一个vector<Json::Value>对象
	vector<Json::Value> vec_JsonData;  //存放解析后的json数据的容器
};
