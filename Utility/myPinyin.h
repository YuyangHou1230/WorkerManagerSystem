/*
0. ���ܰ������Զ����������е�[��,��]������תƴ����һ��һ������ĸ+ȫƴ����������תƴ����һ�Զ࣬����ĸ+ȫƴ����
1. �汾��V1.0   ���ڣ�2019��06��06��
2. ���飺
	https://blog.csdn.net/weixin_38887369/article/details/91047524   // ����Դ��Ŀ����
	https://blog.csdn.net/weixin_38887369                            // 
3. ��Ȩ���� qq:2271590144,����
4. ʹ������:c++,ʹ�ÿ⣺qt
5. qt��ֻʹ���� qstring qstringlist qvector������㲻��ʹ��qt,ֱ��ʹ�ñ�׼��c++Ҳ�ɣ�ֻ��Ҫ�����ٵĸĶ�
   ���ʹ�ñ�׼��c++��,�Ķ����£�
   qstring     -> string
   qstringlist -> vector<string>
   qvector     -> vector
   a. cpp�ļ��еĴ����300������,���ԸĶ�����
   b. [vector,qvector],[string,qstring] �����ƶȼ��ߣ��ܶຯ������һ���ģ����Ը�����Ҳ����
   c. ʹ�ñ�׼��stringЧ�ʻ����
6. ʵ�����ò��ԣ�
	a. �Ѿ����ã�ûʲô����
	b. �ٶȲ��ԣ�������win10ϵͳ + i5-8265U + ���߳��� + ÿ��3���� ���ֲܴڵ��ٶȲ��Խ������
	   getComPingyinForStr() => 50 ��/ms
	   getNamePingyin()      => 100��/ms
7. ʹ�÷���������ֱ�ӿ����ļ���.h�ļ�����ע�� �� ��������ҳ�濪�����ڶ�������ַ 
*/
#pragma once

#include <qstring.h>
#include <qstringlist.h>
#include <qvector.h>


/*
0. vs2017��Ĭ�ϱ��벻��utf-8�������qt��IDE�༭����Ҫ��䣻�����vs�Ͽ������Ҳ���qt,Ҳ����Ҫ���
1. ������vs2017��ʹ��qt, ���û����䣬��QString str="����"; str���������
2. �����Ҫʹ��CString ,���Լ��Բ�...
*/
#pragma execution_character_set("utf-8") // 

// ����-ƴ��
struct hanziTableS
{
	// ƴ��
	QString first_py;  // ����ĸ
	QString full_py;   // ȫƴ

	// ����
	QString hanzis;
};

// �������Ϸ���
struct lastNameTableS
{
	QString hanzi;
	QString pinyi;
};

// ���ö�����
struct multiToneWordTableS
{
	QString hanzi;
	QString pinyi;
};


// ----- �ⲿʹ�� ----- //

/* 
0. ��ȡ���ƴ��(һ���ܶԶ�),��������
1. eg: 
	getComPingyinForStr("���",fristPy,fullPy);    // fristPy =  "jg xg jh xh"  , fullPy =  "jiegong xiegong jiehong xiehong"
	getComPingyinForStr("���",fristPy,fullPy);    // fristPy =  "cc zc cz zz"  , fullPy =  "chacha zhacha chazha zhazha"
	getComPingyinForStr("ξ����",fristPy,fullPy);  // fristPy =  "wcm ycm"  , fullPy =  "weichimeng yuchimeng"
	getComPingyinForStr("��ʯ",fristPy,fullPy);    // fristPy =  "ld ls"  , fullPy =  "lidan lishi"
	getComPingyinForStr("С��",fristPy,fullPy);    // fristPy =  "xm"  , fullPy =  "xiaoming"
*/
int getComPingyinForStr(const QString& inStr, QString& outFrist_py, QString& outFull_py);//ok
/*
0. ���ա������ֱ�תƴ�����ϸ��һһ��Ӧ�������ں���ǿתƴ��
1. ʹ���ˣ�������������ֿ� + �����ֳ��ö����ֿ� + ȫ�ֿ�
2. eg:
	str = getNamePingyin("��",true);   // str => "chun"
	str = getNamePingyin("��",false);  // str => "chun"
	
	str = getNamePingyin("��",true);   // str => "xie"
	str = getNamePingyin("��",false);  // str => "jie"
	
	str = getNamePingyin("��",true);   // str => "zhai"
	str = getNamePingyin("��",false);  // str => "di"

	str = getNamePingyin("��",true);   // str => "can"
	str = getNamePingyin("��",false);  // str => "can"

	str = getNamePingyin("����",true);   // str => "chanyu"
	str = getNamePingyin("����",false);  // str => "danyu"
*/
QString getNamePingyin(const QString& inStr, bool isLastName);//
/*
0. �Զ��з� �ա���
1. ����ֻ��Ӧ����ͨ�ĸ��գ������֣�������ڸ��ձ���û���ҵ�����: ���� = ��fullName.size() == 4�� ? fullName��ǰ�������ַ� �� fullName�ĵ�һ���ַ�
2. ��ע���ٶȵ����ϻ�����70�����������90�������Ǻ��Ե�������������ϣ�Ҳ��Ҫ��Ϊ���վ��������֣�(���й������������ϡ����ܴ����1���)
   ���磺���������ϡ����¾��ޡ�ť��»��ɫ�ϡ����꣨�Ҽ����ܶ�������ģ�
3. eg:
	QString names = {"����̫һ ξ��С�� �Ⲩ ���� �ձ��� ��˧ ���� ���� ����ʿ��ȱ�� ������ �ջ���ķ �Ϲ���"};
	QStringList nameList = names.split(" ");
	for (size_t i = 0; i < nameList.size(); i++)
	{
		QString full, fist, last;
		full = nameList[i];

		myNameSplit(full, last, fist);
		last = getNamePingyin(last, true);
		fist = getNamePingyin(fist, false);

		qout << full + " : " + last + "  " + fist << endl;
	}
	// ���
	"����̫һ : donghuang  taiyi"
	"ξ��С�� : yuchi  xiaobai"
	"�Ⲩ : xie  bo"
	"���� : bu  ai"
	"�ձ��� : yan  biyu"
	"��˧ : gou  shuai"
	"���� : yang  honggei"
	"���� : lv  bu"
	"����ʿ��ȱ�� : ya  lishiduoquede"
	"������ : qin  huangpu"
	"�ջ���ķ : juhua  lamu"
	"�Ϲ��� : shangguan  wan"
*/
void myNameSplit(const QString& inFullName, QString& outLastName, QString& outFirstName);


// ----- �ڲ���ʹ�� ----- //

/*
0. ��ȡһ�����ֵġ����С�ƴ��(����ĸ��ȫƴ)
1. ʹ���ֿ� �� hanziTables[]
2. �������Ϊ�գ���������͵��ڿ�
3. �������Ϊ�������ַ����򷵻غ�����һ��
4. inWord ֻ������һ�����֣����򷵻�-1
5. eg:
   getAllPingyinForWord("��",fristPy,fullPy); // fristPy => {"g","j"} , fullPy => {"gou","ju"}
   getAllPingyinForWord("��",fristPy,fullPy); // fristPy => {"l"}     , fullPy => {"long"}
*/
int getAllPingyinForWord(const QString& inWord, QStringList& outFrist_py, QStringList& outFull_py); // ok

/*
0. ��ȡһ���ֵ�ƴ��,����Ƕ����ַ��س��ö���
1. ƫ�������ķ���ƫ��,���������ϵķ���ƫ��
2. �������Ϊ�գ���������͵��ڿ�
3. ʹ���ֿ⣺multiToneWordTable[]�������ֿ⣩+ hanziTables[]��ȫ�ֿ⣩
4. �������Ϊ�������ַ����򷵻غ�����һ��
5. �����ֵ�ȡ��������multiToneWordTable[]
6. inWord ֻ������һ�����֣�����ֱ�ӷŻ���������
7. eg:
   str = getNoRepeatPingyinForWord("��"); // str => "da"
   str = getNoRepeatPingyinForWord("��"); // str => "jie"
   str = getNoRepeatPingyinForWord("ʯ"); // str => "shi"
*/
QString getNoRepeatPingyinForWord(const QString& inWord);//ok