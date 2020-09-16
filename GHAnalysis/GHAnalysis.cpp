#include "GHAnalysis.h"

//��ʼ��������json�ļ�·��������,���õ�vec_JsonData
//jsonFilePath����ʾ��Ҫ������json�ļ���·��
bool GHAnalysis::Init_GHAnalysis(string jsonFilePath)
{
	fstream  file(jsonFilePath);//����һ��fstream�ļ�������
	if (!file.is_open())  //�ж��ļ��Ƿ񱻳ɹ���
	{
		return false;     //���û�򿪷���false
	}
	string  line; //��������ÿһ��
	Json::Reader reader;
	Json::Value root;
	while (getline(file, line))//���Զ���\n���з�ȥ�� 
	{
		reader.parse(line, root);  //������ȡ����һ��json����
		vec_JsonData.push_back(root);      //���������json���ݴ���������
	}
	return true;
}

//��ȡָ���û���ָ���¼�������
//����һ������������������ֵΪint�ĺ���
//strUserName����Ҫ��ѯ���û����� strEventType����Ҫ��ѯ���¼�������
int GHAnalysis::CheckUserEventNumber(string strUserName, string strEventType) 
{
	int nUserEventNumber = 0;  //��ʼ��ָ���û���ָ���¼�������
	for(int i = 0; i<vec_JsonData.size();i++)  //vec_JsonData.size()����ȡ������С��ֱ�����������������в���
	{
		//.asString():������ת��Ϊstring����
		if (vec_JsonData[i]["actor"]["login"].asString() == strUserName) //�жϲ��ҵ���ֵ�Ƿ�����Ҫ������ƥ��
		{
			if (vec_JsonData[i]["type"].asString() == strEventType) //�жϲ��ҵ���ֵ�Ƿ�����Ҫ������ƥ��
			{
				++nUserEventNumber;     //���������������������Լ�1
			}
		}
	}
	return nUserEventNumber;  //����ָ���û���ָ���¼�������
}

//��ȡָ����Ŀ��ָ���¼�������
//����һ������������������ֵΪint�ĺ���
//nProjectId����Ҫ��ѯ����ĿΨһʶ��ţ�ID���� strEventType����Ҫ��ѯ���¼�������
int GHAnalysis::CheckProjectEventNumber(int nProjectId, string strEventType) 
{
	int nProjectEventNumber = 0;  //��ʼ��ָ����Ŀ��ָ���¼�������
	for (int i = 0; i < vec_JsonData.size();i++)  //vec_JsonData.size()����ȡ������С��ֱ�����������������в���
	{
		//.asInt():������ת��Ϊint����
		if (vec_JsonData[i]["repo"]["id"].asInt() == nProjectId)     //�жϲ��ҵ���ֵ�Ƿ�����Ҫ������ƥ��
		{
			if (vec_JsonData[i]["type"].asString() == strEventType) //�жϲ��ҵ���ֵ�Ƿ�����Ҫ������ƥ��
			{
				++nProjectEventNumber;  //���������������������Լ�1
			}
		}
	}
	return nProjectEventNumber; //����ָ����Ŀ��ָ���¼�������
}

//��ȡָ���û���ָ����Ŀ��ָ���¼�������
//����һ������������������ֵΪint�ĺ���
//strUserName����Ҫ��ѯ���û����� nProjectId����Ҫ��ѯ����ĿΨһʶ��ţ�ID���� strEventType����Ҫ��ѯ���¼�������
int GHAnalysis::CheckUserProjectEventNumber(string strUserName, int nProjectId, string strEventType)
{
	int nUserProjectEventNumber = 0;  //��ʼ��ָ���û���ָ����Ŀ��ָ���¼�������
	for (int i = 0; i < vec_JsonData.size();i++)  //vec_JsonData.size()����ȡ������С��ֱ�����������������в���
	{
		if (vec_JsonData[i]["actor"]["login"].asString() == strUserName)  //�жϲ��ҵ���ֵ�Ƿ�����Ҫ������ƥ��
		{
			if (vec_JsonData[i]["repo"]["id"].asInt() == nProjectId)  //�жϲ��ҵ���ֵ�Ƿ�����Ҫ������ƥ��
			{
				if (vec_JsonData[i]["type"].asString() == strEventType)  //�жϲ��ҵ���ֵ�Ƿ�����Ҫ������ƥ��
				{
					++nUserProjectEventNumber;  //���������������������Լ�1
				}
			}
		}
	}
	return nUserProjectEventNumber; //����ָ���û���ָ����Ŀ��ָ���¼�������
}