#include "GHAnalysis.h"

//初始化，传入json文件路径并加载,并得到vec_JsonData
//jsonFilePath：表示需要解析的json文件的路径
bool GHAnalysis::Init_GHAnalysis(string jsonFilePath)
{
	fstream  file(jsonFilePath);//创建一个fstream文件流对象
	if (!file.is_open())  //判断文件是否被成功打开
	{
		return false;     //如果没打开返回false
	}
	string  line; //保存读入的每一行
	Json::Reader reader;
	Json::Value root;
	while (getline(file, line))//会自动把\n换行符去掉 
	{
		reader.parse(line, root);  //解析读取到的一行json数据
		vec_JsonData.push_back(root);      //将解析后的json数据存入容器中
	}
	return true;
}

//获取指定用户的指定事件的数量
//创建一个带两个参数，返回值为int的函数
//strUserName：需要查询的用户名； strEventType：需要查询的事件类型名
int GHAnalysis::CheckUserEventNumber(string strUserName, string strEventType) 
{
	int nUserEventNumber = 0;  //初始化指定用户的指定事件的数量
	for(int i = 0; i<vec_JsonData.size();i++)  //vec_JsonData.size()：获取容器大小，直到查找完容器中所有参数
	{
		//.asString():将数据转换为string类型
		if (vec_JsonData[i]["actor"]["login"].asString() == strUserName) //判断查找到的值是否与需要的数据匹配
		{
			if (vec_JsonData[i]["type"].asString() == strEventType) //判断查找到的值是否与需要的数据匹配
			{
				++nUserEventNumber;     //若满足所有条件，技术自加1
			}
		}
	}
	return nUserEventNumber;  //返回指定用户的指定事件的数量
}

//获取指定项目中指定事件的数量
//创建一个带两个参数，返回值为int的函数
//nProjectId：需要查询的项目唯一识别号（ID）； strEventType：需要查询的事件类型名
int GHAnalysis::CheckProjectEventNumber(int nProjectId, string strEventType) 
{
	int nProjectEventNumber = 0;  //初始化指定项目中指定事件的数量
	for (int i = 0; i < vec_JsonData.size();i++)  //vec_JsonData.size()：获取容器大小，直到查找完容器中所有参数
	{
		//.asInt():将数据转换为int类型
		if (vec_JsonData[i]["repo"]["id"].asInt() == nProjectId)     //判断查找到的值是否与需要的数据匹配
		{
			if (vec_JsonData[i]["type"].asString() == strEventType) //判断查找到的值是否与需要的数据匹配
			{
				++nProjectEventNumber;  //若满足所有条件，技术自加1
			}
		}
	}
	return nProjectEventNumber; //返回指定项目中指定事件的数量
}

//获取指定用户在指定项目中指定事件的数量
//创建一个带三个参数，返回值为int的函数
//strUserName：需要查询的用户名； nProjectId：需要查询的项目唯一识别号（ID）； strEventType：需要查询的事件类型名
int GHAnalysis::CheckUserProjectEventNumber(string strUserName, int nProjectId, string strEventType)
{
	int nUserProjectEventNumber = 0;  //初始化指定用户在指定项目中指定事件的数量
	for (int i = 0; i < vec_JsonData.size();i++)  //vec_JsonData.size()：获取容器大小，直到查找完容器中所有参数
	{
		if (vec_JsonData[i]["actor"]["login"].asString() == strUserName)  //判断查找到的值是否与需要的数据匹配
		{
			if (vec_JsonData[i]["repo"]["id"].asInt() == nProjectId)  //判断查找到的值是否与需要的数据匹配
			{
				if (vec_JsonData[i]["type"].asString() == strEventType)  //判断查找到的值是否与需要的数据匹配
				{
					++nUserProjectEventNumber;  //若满足所有条件，技术自加1
				}
			}
		}
	}
	return nUserProjectEventNumber; //返回指定用户在指定项目中指定事件的数量
}