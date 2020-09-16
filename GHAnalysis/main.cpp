#include "main.h"

void main()
{
	GHAnalysis obj;  //创建解析和查询json文件的对象
	char exeFullPath[MAX_PATH]; // exe全路径
	std::string strExePath = "";
	GetModuleFileName(NULL, exeFullPath, MAX_PATH); //获取带有可执行文件名路径
	strExePath = (std::string)exeFullPath;
	int pos = strExePath.find_last_of('\\', strExePath.length());  //从后往前查找第一个“\\”的位置
	auto path = strExePath.substr(0, pos+1);  // 截取路径，返回不带有可执行文件名的路径,包含双斜杠

	printf("%s","解析中,请稍等...  1MB数据大约需要3s\n");

	//json文件名为TestJsonFile.json，并且放在项目exe同级路径
	bool init_ret = obj.Init_GHAnalysis(path + "TestJsonFile.json");   //调用初始化函数，解析数据到容器（vector）中
	if (!init_ret)
	{
		printf("%s", "解析失败！\n");	
	}
	else
	{
		printf("%s", "解析成功！\n");
		while (true)
		{
			printf("%s", "请选择查询类型：\n0:查询某用户某事件的数量，\
				   \n1:查询某项目中某事件的数量，\n2:查询某用户在某项目中某事件的数量\n");
			int inputCheckType = 0;
			scanf_s("%d", &inputCheckType);

			char userName[255];
			int projectName = 0;
			char eventTypeName[255];
			int UserEventNumber = 0;
			int UserProjectEventNumber = 0;
			int ProjectEventNumber = 0;

			switch (inputCheckType)
			{
				case 0:
					printf("%s", "请输入: 用户名\n");
					scanf_s("%s", userName,255);
					printf("%s", "请输入: 事件类型名\n");
					scanf_s("%s", eventTypeName,255);
					UserEventNumber = obj.CheckUserEventNumber(userName, eventTypeName);
					printf("数量为：%d\n\n", UserEventNumber);
					break;
				case 1:
					printf("%s", "请输入: 项目ID\n");
					scanf_s("%d", &projectName);
					printf("%s", "请输入: 事件类型名\n");
					scanf_s("%s", eventTypeName, 255);
					ProjectEventNumber = obj.CheckProjectEventNumber(projectName, eventTypeName);
					printf("数量为：%d\n\n", ProjectEventNumber);
					break;
				case 2:
					printf("%s", "请输入: 用户名\n");
					scanf_s("%s", userName, 255);
					printf("%s", "请输入: 项目ID\n");
					scanf_s("%d", &projectName);
					printf("%s", "请输入: 事件类型名\n");
					scanf_s("%s", eventTypeName, 255);
					UserProjectEventNumber = obj.CheckUserProjectEventNumber(userName, projectName, eventTypeName);
					printf("数量为：%d\n\n", UserProjectEventNumber);
					break;
				default:
					printf("%s", "输入有误，请重新输入\n\n");
					break;
			}
		}
	}
}