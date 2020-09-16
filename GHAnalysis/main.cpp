#include "main.h"

void main()
{
	GHAnalysis obj;  //���������Ͳ�ѯjson�ļ��Ķ���
	char exeFullPath[MAX_PATH]; // exeȫ·��
	std::string strExePath = "";
	GetModuleFileName(NULL, exeFullPath, MAX_PATH); //��ȡ���п�ִ���ļ���·��
	strExePath = (std::string)exeFullPath;
	int pos = strExePath.find_last_of('\\', strExePath.length());  //�Ӻ���ǰ���ҵ�һ����\\����λ��
	auto path = strExePath.substr(0, pos+1);  // ��ȡ·�������ز����п�ִ���ļ�����·��,����˫б��

	printf("%s","������,���Ե�...  1MB���ݴ�Լ��Ҫ3s\n");

	//json�ļ���ΪTestJsonFile.json�����ҷ�����Ŀexeͬ��·��
	bool init_ret = obj.Init_GHAnalysis(path + "TestJsonFile.json");   //���ó�ʼ���������������ݵ�������vector����
	if (!init_ret)
	{
		printf("%s", "����ʧ�ܣ�\n");	
	}
	else
	{
		printf("%s", "�����ɹ���\n");
		while (true)
		{
			printf("%s", "��ѡ���ѯ���ͣ�\n0:��ѯĳ�û�ĳ�¼���������\
				   \n1:��ѯĳ��Ŀ��ĳ�¼���������\n2:��ѯĳ�û���ĳ��Ŀ��ĳ�¼�������\n");
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
					printf("%s", "������: �û���\n");
					scanf_s("%s", userName,255);
					printf("%s", "������: �¼�������\n");
					scanf_s("%s", eventTypeName,255);
					UserEventNumber = obj.CheckUserEventNumber(userName, eventTypeName);
					printf("����Ϊ��%d\n\n", UserEventNumber);
					break;
				case 1:
					printf("%s", "������: ��ĿID\n");
					scanf_s("%d", &projectName);
					printf("%s", "������: �¼�������\n");
					scanf_s("%s", eventTypeName, 255);
					ProjectEventNumber = obj.CheckProjectEventNumber(projectName, eventTypeName);
					printf("����Ϊ��%d\n\n", ProjectEventNumber);
					break;
				case 2:
					printf("%s", "������: �û���\n");
					scanf_s("%s", userName, 255);
					printf("%s", "������: ��ĿID\n");
					scanf_s("%d", &projectName);
					printf("%s", "������: �¼�������\n");
					scanf_s("%s", eventTypeName, 255);
					UserProjectEventNumber = obj.CheckUserProjectEventNumber(userName, projectName, eventTypeName);
					printf("����Ϊ��%d\n\n", UserProjectEventNumber);
					break;
				default:
					printf("%s", "������������������\n\n");
					break;
			}
		}
	}
}