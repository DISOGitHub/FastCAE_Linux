#ifndef PREWINDOW_H
#define PREWINDOW_H

#include "mainWidgetsAPI.h"
#include "moduleBase/graph3DWindow.h"
#include "moduleBase/ModuleType.h"
#include <QList>

namespace MeshData
{
	class MeshData;
}
namespace Geometry
{
	class GeometryData;
	class GeometrySet;
	class GeometryDatum;
}

namespace ModelData
{
	class ModelDataSingleton;
}

namespace GUI
{
	class MainWindow;
}

class vtkActor;
class TopoDS_Shape;

namespace MainWidget
{
	class GeometryViewProvider;
	class SketchViewProvider;

	enum DisplayModel
	{
		Node,
		WireFrame,
		Surface,
		SurfaceWithEdge,
	};
	

	class MAINWIDGETSAPI PreWindow :public ModuleBase::Graph3DWindow
	{
		Q_OBJECT
	public:
		PreWindow(GUI::MainWindow* mw, int id = -1, ModuleBase::GraphWindowType type = ModuleBase::GraphWindowType::PreWindows);
		~PreWindow();
		
		Geometry::GeometrySet* getSelectedGeoSet();
		//��ȡѡ��ļ���
		QMultiHash<Geometry::GeometrySet*, int> getGeoSelectItems();
		//�����Ѿ�ѡ��ļ���
		void setGeoSelectItems(QMultiHash<Geometry::GeometrySet*, int> items);
	
	
	signals:
		//�ر�
		void closed();
		//��ʾ������״
		void showGeoSet(Geometry::GeometrySet* set);
		//�Ƴ�������״����ʾ
		void removeGemoActors(Geometry::GeometrySet* set);
		//��ʾ��׼
		void showDatum(Geometry::GeometryDatum*);
		//�Ƴ����λ�׼��ʾ
		void removeGeoDatumActors(Geometry::GeometryDatum*);
		//����ѡ��ģʽ
		void setGeoSelectMode(int);
		//ѡ��ļ���Ԫ��
		void selectGeoActorShape(vtkActor* ac, int shape, Geometry::GeometrySet* set);
		//����������ȾԪ��
		void updateMeshActorSig();
		

	public slots:
	    //����ѡ��ģʽ
	    void setSelectModel(int mode) override;
		//���ò�ͼ����
		void setSketchType(ModuleBase::SketchType t);
		//����������Ⱦ
		void updateMeshActor();
		//���¼�����Ⱦ
		void updateGeometryActor();
		//������и�������
		void clearAllHighLight();

	private:
		void removeMeshActors();
		void updateDisplayModel();

	private slots:
		void updateGeoDispaly(int index, bool display);
		void updateMeshDispaly(int index, bool display);
		void removeGemoActor(const int index);
		void removeMeshActor(const int index);
		//ѡ��Geometry
		void setDisplay(QString m) override;

		void updateGraphOption() override;
		void startSketch(bool start, double* loc, double* dir);

	private:
		QList<vtkActor*> _meshActors{};
		//QList<vtkActor*> _geometryActors{};
		MeshData::MeshData* _meshData{};
		Geometry::GeometryData* _geometryData{};

		ModelData::ModelDataSingleton* _modelData{};
		int _selectedGeoIndex{ -1 };
		DisplayModel _displayModel{ SurfaceWithEdge };

		GeometryViewProvider* _geoProvider{};
		SketchViewProvider* _sketchProvider{};

	};
}

#endif
