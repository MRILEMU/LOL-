#include <iostream>
//import "dm.dll" no_namespace
#include "dm.tlh"
#include<iostream>
#include<string>
#include <fstream>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<easyx.h>
#include<stdio.h>
#include<mmsystem.h>
#include <Windows.h>
#include<conio.h>//ʹ��_getch();//��ʵ����getch();
#include <fstream>
using namespace std;
Idmsoft* GetDmObject()
{
	Idmsoft* m_dm = NULL;
	bool m_bInit = false;
	//ֱ�Ӽ���dll�������󣬱������ע���ļ�
	typedef HRESULT(_stdcall* pfnGCO)(REFCLSID, REFIID, void**);
	pfnGCO fnGCO = NULL;
	HINSTANCE hdllInst = LoadLibrary("dm.dll");
	fnGCO = (pfnGCO)GetProcAddress(hdllInst, "DllGetClassObject");
	if (fnGCO != 0)
	{
		IClassFactory* pcf = NULL;
		HRESULT hr = (fnGCO)(__uuidof(dmsoft), IID_IClassFactory, (void**)&pcf);
		if (SUCCEEDED(hr) && (pcf != NULL))
		{
			hr = pcf->CreateInstance(NULL, __uuidof(Idmsoft), (void**)&m_dm);
			if ((SUCCEEDED(hr) && (m_dm != NULL)) == FALSE)
				return NULL;

		}
		pcf->Release();
		m_bInit = true;
	}
	else
		m_bInit = false;
	return m_dm;

}
void xg()//�޸Ĵ��ڱ���
{
	HWND hnd = GetHWnd();
	SetWindowText(hnd, "��ķ");
}
int main(int argc, char** argv)
{
	Idmsoft* pDm = GetDmObject();
	DWORD pid = GetCurrentProcessId();
	int handle = (int)GetModuleHandle("dm.dll");
	//����Ϊע����
	cout << "----------------" << endl;
	cout << "��ӭʹ����ķ�ű�" << endl;
	cout << "����ϸ�Ķ��̳�" << endl;
	cout << "������ȷ�����ú�" << endl;
	cout << "----------------" << endl;
	std::system("pause");
	std::system("cls");
	//����Ϊ����
	long cz;
	string lj;
	cz=pDm->IsFileExist("mm.txt");
	if (cz == 0)
	{
		ofstream mm;
		mm.open("mm.txt", ios::out);
		cout << "��������Ӣ������/Game/Config/game.cfg��·��" << endl;
		lj = pDm->SelectFile();
		mm << lj;
		cout << "·��:" << lj << endl;
		mm.close();
		cout << "�������ǵ�һ�δ򿪽ű�,�����¿����ű�" << endl;
		system("pause");
		return 0;
	}
	ifstream mm;
	mm.open("mm.txt", ios::in);
	mm >> lj;
	mm.close();//��ȡlol·��
	cout << "�����滻game.cfg" << endl;
	BSTR bstrlj = (_bstr_t)lj.c_str();
	long cfgth=pDm->CopyFile("game.cfg", bstrlj,1);
	if (cfgth == 1)
	{
		cout << "�滻�ɹ�!"<<endl;
	}
	string yx1;
	string yx2; 
	cout << "��������ѡӢ����:";
	cin >> yx2;
	long id=pDm->Play("����˼��.wav");//��������
	initgraph(480, 640);
	xg();//�޸Ĵ�������
	setbkcolor(WHITE);
	cleardevice();
	IMAGE img;//����һ��(����)����
	IMAGE background;
	loadimage(&img, "./��ķɬͼ.jpg", 480, 640);//��һ��ͼƬ���ڹۿ���˸
	putimage(0, 0, &img);
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "����");//��������߶ȣ���ȣ�����
	settextcolor(BLUE);//����
	char arr[] = "�ű��һ���!";
	int x_buff = (300 - textwidth(arr)) / 2;//textwidth���ַ�����ռ���س���
	int y_buff = (200 - textheight(arr)) / 2;//textheight���ַ�����ռ���ظ߶�
	outtextxy(100 + x_buff, 200 + y_buff, arr);
	settextstyle(70, 0, "����");//��������߶ȣ���ȣ�����
	char arr2[] = "��ķ�ű�";
	x_buff = (300 - textwidth(arr2)) / 2;//textwidth���ַ�����ռ���س���
	y_buff = (200 - textheight(arr2)) / 2;//textheight���ַ�����ռ���ظ߶�
	outtextxy(100 + x_buff, y_buff, arr2);
	settextstyle(20, 0, "����");//��������߶ȣ���ȣ�����
	char arr3[] = "����qq3434510142\nqqȺ731334191";
	x_buff = (300 - textwidth(arr3)) / 2;//textwidth���ַ�����ռ���س���
	y_buff = (200 - textheight(arr3)) / 2;//textheight���ַ�����ռ���ظ߶�
	outtextxy(100 + x_buff, 500 + y_buff, arr3);
	long EnableMouseAccuracy(0);
	VARIANT  x1;
	VARIANT  y1;//�ű�ҳ��210,90
while1:
	cout << "while1" << endl;
	while (true)
	{
		long hwnd2 = pDm->FindWindow("RiotWindowClass", "League of Legends (TM) Client");//��ȡ������Ϣ,hwnd2,Ӣ������
		if (hwnd2 != 0)
		{
			pDm->MoveWindow(hwnd2, 0, 0);
			Sleep(25000);
			while (true)
			{
				Sleep(5000);
				hwnd2 = pDm->FindWindow("RiotWindowClass", "League of Legends (TM) Client");//��ȡ������Ϣ,hwnd2,Ӣ������
				if (hwnd2 == 0)
				{
					goto while1;
				}//960 808
				cout << "while" << endl;
				pDm->KeyPressChar("p"); 
				Sleep(300);
				pDm->KeyUpChar("p");
				Sleep(300);
				pDm->MoveTo(310,300);
				Sleep(300); 
				pDm->LeftDoubleClick();
				Sleep(300);
				pDm->MoveTo(725, 280);
				Sleep(300);
				pDm->LeftDoubleClick();
				Sleep(300);
				pDm->KeyPressChar("p");
				Sleep(300);
				pDm->KeyUpChar("p");
				Sleep(1000);
				for (int i = 0; i < 13; i++)
				{
					hwnd2 = pDm->FindWindow("RiotWindowClass", "League of Legends (TM) Client");//��ȡ������Ϣ,hwnd2,Ӣ������
					if (hwnd2 == 0)
					{
						goto while1;
					}//960 808
					pDm->KeyPressChar("space");
					Sleep(1000);
					pDm->KeyPressChar("space");
					pDm->MoveTo(990, 600);
					pDm->KeyPressChar("space");
					Sleep(1000);
					pDm->KeyPressChar("space");
					pDm->KeyPressChar("a");
					pDm->KeyPressChar("space");
					Sleep(1000);
					pDm->KeyPressChar("space");
					pDm->KeyUpChar("a");
					pDm->KeyPressChar("space");
					Sleep(7750);
					pDm->KeyPressChar("space");
					pDm->KeyUpChar("s");
					pDm->KeyPressChar("space");
					pDm->KeyPressChar("space");
					pDm->MoveTo(910, 675);
					pDm->KeyPressChar("space");
					Sleep(1000);
					pDm->KeyPressChar("space");
					pDm->KeyPressChar("a");
					pDm->KeyPressChar("space");
					Sleep(1000);
					pDm->KeyPressChar("space");
					pDm->KeyUpChar("a");
					pDm->KeyPressChar("space");
				}
				hwnd2 = pDm->FindWindow("RiotWindowClass", "League of Legends (TM) Client");//��ȡ������Ϣ,hwnd2,Ӣ������
				if (hwnd2 == 0)
				{
					goto while1;
				}//960 808
				Sleep(1000);
				pDm->MoveTo(900, 680);
				Sleep(1000);
				pDm->KeyPressChar("a");
				Sleep(1000);
				pDm->KeyUpChar("a");
				Sleep(6000);
				pDm->KeyPressChar("space");
				pDm->KeyPressChar("b");
				Sleep(1000);
				pDm->KeyUpChar("b");
				Sleep(8000);
			}
		}
		else
		{
			goto while2;
		}
	}
while2:
	cout << "while2" << endl;
	while(true)
	{			
		long f=-1;
		f = pDm->FindPic(320, 160, 520, 230, "play.bmp", "101010", 0.6, 1, &x1, &y1);
		if (f != -1)
		{
			Sleep(4000);
			pDm->MoveTo(444, 200);
			pDm->MoveTo(434, 194);
			pDm->LeftClick();
			Sleep(100);
			pDm->LeftUp();
			Sleep(1000);
			pDm->MoveTo(481, 249);
			pDm->MoveTo(480, 250);
			pDm->LeftClick();
			Sleep(100);
			pDm->LeftUp();
			Sleep(1000);
			pDm->MoveTo(857, 846);
			pDm->MoveTo(856, 845);
			pDm->LeftClick();
			Sleep(100);
			pDm->LeftUp();
			Sleep(500);
			pDm->MoveTo(843, 832);
			pDm->MoveTo(842, 831);
			pDm->LeftClick();
			Sleep(100);
			pDm->LeftUp();
		}
		long f2=-1;
		f2 = pDm->FindPic(730, 440, 890, 490, "�ٻ�ʦϿ��.bmp", "101010", 0.6, 1, &x1, &y1);
		if (f2 != -1)
		{
			pDm->MoveTo(843, 832);
			pDm->MoveTo(842, 831);
			pDm->LeftClick();
			Sleep(100);
			pDm->LeftUp();
		}
		long f3 = -1;
		f3 = pDm->FindPic(700, 800, 940, 870, "Ѱ�ҶԾ�.bmp", "101010", 0.6, 1, &x1, &y1);
		if (f3 != -1)
		{
			pDm->MoveTo(843, 832);
			pDm->MoveTo(842, 831);
			pDm->LeftClick();
			Sleep(100);
			pDm->LeftUp();
		}
		long f4 = -1;
		f4 = pDm->FindPic(858, 520, 1052, 578, "����.bmp", "101010", 0.5, 1, &x1, &y1);
		if (f4 != -1)
		{
			pDm->MoveTo(949, 714);
			pDm->MoveTo(949, 713);
			pDm->LeftClick();
			Sleep(100);
			pDm->LeftUp();
		}
		long f5 = -1;
		f5 = pDm->FindPic(820, 160, 1080, 215, "Ӣ��.bmp", "101010", 0.5, 1, &x1, &y1);
		if (f5 != -1)
		{
			Sleep(300);
			BSTR bstr1 = (_bstr_t)yx1.c_str();
			BSTR bstr2 = (_bstr_t)yx2.c_str();
			pDm->SetClipboard(bstr2);
			pDm->MoveTo(1116, 265);
			pDm->MoveTo(1115, 264);
			pDm->LeftClick();
			Sleep(100);
			pDm->LeftUp();
			Sleep(100);

			pDm->MoveTo(1234, 262);
			pDm->MoveTo(1233, 261);
			pDm->LeftClick();
			Sleep(100);
			pDm->LeftUp();
			Sleep(100);

			pDm->MoveTo(1116, 265);
			pDm->MoveTo(1115, 264);
			pDm->LeftClick();
			Sleep(100);
			pDm->LeftUp();
			Sleep(100);
			keybd_event(17, 0, 0, 0);
			Sleep(100);
			keybd_event('V', 0, 0, 0);
			Sleep(100);
			keybd_event('V', 0, KEYEVENTF_KEYUP, 0);
			keybd_event(17, 0, KEYEVENTF_KEYUP, 0);
			Sleep(300);
			pDm->MoveTo(705, 320);
			pDm->MoveTo(706, 321);
			pDm->LeftClick();
			Sleep(100);
			pDm->LeftUp();
			pDm->MoveTo(960, 765);
			pDm->MoveTo(961, 764);
			Sleep(100);
			pDm->LeftClick();
			Sleep(100);
			pDm->LeftUp();
		}

		long f6 = -1;
		f6 = pDm->FindPic(750, 810, 930, 860, "����һ��.bmp", "101010", 0.5, 1, &x1, &y1);
		if (f6 != -1)
		{
			pDm->MoveTo(850, 837);
			pDm->MoveTo(849, 840);
			pDm->LeftClick();
			Sleep(100);
			pDm->LeftUp();
		}
		long f7 = -1;
		long f8 = -1;
		f8 = pDm->FindPic(750, 810, 930, 860, "����.bmp", "101010", 0.5 , 1, &x1, &y1);
		if (f8 != -1)
		{
			pDm->MoveTo(840, 830);
			pDm->MoveTo(841, 831);
			pDm->LeftClick();
			Sleep(100);
			pDm->LeftUp();
		}
		goto while1;
	}
	return 0;//return 1234 262
}//�ű�������

//League of Legends (TM) Client
//RiotWindowClass	
