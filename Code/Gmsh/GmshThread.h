#ifndef _GMSHTHREAD_H_
#define _GMSHTHREAD_H_

#include <QThread>
#include <QList>
#include <QMultiHash>
#include <QString>
#include <QProcess>
#include "DataProperty/DataBase.h"

namespace GUI
{
	class MainWindow;
}

namespace MainWidget
{
	class PreWindow;
}

namespace ModuleBase
{
	class ProcessBar;
}

namespace Py
{
	class PythonAagent;
}

namespace Gmsh
{
	class GmshModule;

	class GMshPara
	{
	public:
		int _dim{ -1 };
		QList<int> _solidList{};
		QMultiHash<int, int> _surfaceHash{};
		QString _elementType{};
		int _elementOrder{ -1 };
		int _method{ -1 };
		double _sizeFactor{ 0.0 };
		double _minSize{ 0.0 };
		double _maxSize{ 0.0 };
		bool _geoclean{ false };
		int _smoothIteration{ 0 };

	};

	class GmshThread : public DataProperty::DataBase
	{
		Q_OBJECT
	public:
		GmshThread(GUI::MainWindow* mw, MainWidget::PreWindow* pre, GmshModule* mod, int dim);
		~GmshThread();

		//���ò���
		void setPara(GMshPara*  para);

		//׷��ʵ��
		void appendSolid(int id);
		void setSolid(QList<int> s);
		//׷������
		void appendSurface(int geo, int face);
		void setSurface(QMultiHash<int, int> s);
		//���õ�Ԫ����
		void setElementType(QString t);
		//���õ�Ԫ�״�
		void setElementOrder(int order);
		//���������ʷַ���
		void setMethod(int m);
		//���óߴ�����
		void setSizeFactor(double f);
		//������С�ߴ�
		void setMinSize(double min);
		//�������ߴ�
		void setMaxSize(double max);
		//�����Ƿ���м�������
		void isCleanGeo(bool c);
		//���ù⻬��������
		void setSmoothIteration(int it);

		void run();
		void stop();

	signals:
		void threadFinished(GmshThread* t);
		void sendMessage(QString);

	private slots:
	   void processFinished(int, QProcess::ExitStatus);
		void readProcessOutput();

	private:
		void mergeGeometry();
		void initGmshEnvoirment();
		void submitParaToGmsh();
		void generate();
		void readMesh();

		

	private:
		GUI::MainWindow* _mainwindow{};
		MainWidget::PreWindow* _preWindow{};
		GmshModule* _gmshModule{};

		QProcess _process{};
		ModuleBase::ProcessBar* _processBar{};

		int _dim{ -1 };
		
		QList<int> _solidList{};
		QMultiHash<int, int> _surfaceHash{};
		QString _elementType{};
		int _elementOrder{ -1 };
		int _method{ -1 };
		double _sizeFactor{ 0.0 };
		double _minSize{ 0.0 };
		double _maxSize{ 0.0 };
		bool _geoclean{ false };
		int _smoothIteration{ 0 };
	};

}


#endif