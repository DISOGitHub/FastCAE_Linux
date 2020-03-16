#ifndef GEOMETRYWIDGET_H
#define GEOMETRYWIDGET_H

//#include "moduleBaseAPI.h"
#include <QTreeWidget>

class QTreeWidgetItem;

namespace DataProperty
{
	class DataBase;
}
namespace Geometry
{
	class GeometryData;
	class GeometrySet;
	class GeometryDatum;
}
namespace GUI
{
	class MainWindow;
}

// namespace GenerateGeometry
// {
// 	class GenerateGeometry;
// }

// namespace GeometryWidget
// {
// 	class GeometryDialogFactory;
// }

namespace MainWidget
{
	class PreWindow;

	class /*MODULEBASEAPI*/ GeometryTreeWidget : public QTreeWidget
	{
		Q_OBJECT
	public:
		GeometryTreeWidget(GUI::MainWindow* m, QWidget* parent = nullptr);
		~GeometryTreeWidget();
		//ע�Ὺ�ſ��ýӿ�
		void registerEnabledModule();

	signals:
		//������ʾ״̬
		void updateDisplay(int index, bool visable);
		//�Ƴ���index������
		void removeGeoData(int index);
		//��ʾ����
		void disPlayProp(DataProperty::DataBase* pops);
		//����action״̬
		void updateActionStates();
		//ͨ��������ͳһ�ӿ���ʾ��ģ̬�Ի���
		void showGeoDialog(QDialog*);
		//��������
		void highLightGeometrySet(Geometry::GeometrySet*, bool);
 
		//�������
		void clearHighLight();

	public slots:
	    //������
		void updateTree();
		//��굥���¼�
		void singleClicked(QTreeWidgetItem*, int);
		//�����ǰ����
		void removeData();
		void changeName();
		void slot_datumPlaneRename();
		void slot_removeDatum();
		void preWindowOpened(MainWidget::PreWindow* p);
		void preWindowClosed();
		//�༭��ǰ��״
		void editGeometry();
		//����ȫ��
		void hideAll();
		//��ʾȫ��
		void showAll();
		//�ڵ�״̬�ı�
		void itemStatesChanged(QTreeWidgetItem*, int);

	private:
		void contextMenuEvent(QContextMenuEvent *event) override;
		bool isGeometryEditable();


	private:
		GUI::MainWindow* _mainWindow{};
		QTreeWidgetItem* _root{};
		QTreeWidgetItem* _datumroot{};
		Geometry::GeometryData* _data{};
		QTreeWidgetItem* _currentItem{};
	
		PreWindow* _preWindow{};


	};

}


#endif
