#ifndef _MODELPLUGIN_H_
#define _MODELPLUGIN_H_

#include "ModelPluginAPI.h"
#include "PluginManager/pluginBase.h"
#include "DataProperty/modelTreeItemType.h"

namespace GUI
{
	class MainWindow;
}
namespace MainWidget
{
	class PreWindow;
}

namespace ModelData
{
	class ModelDataBase;
}
namespace ProjectTree
{
	class ProjectTreeBase;
}

namespace Material
{
	class Material;
}

namespace Plugins
{
	class MODELPLUGINAPI ModelPlugin : public PluginBase
	{
		Q_OBJECT
	public:
		ModelPlugin(GUI::MainWindow* m);
		~ModelPlugin();

		//���ز��
		bool install() override;
		//ж�ز��
		bool uninstall() override;

	

	private:
		GUI::MainWindow* _mainwindow{};
		
	};
}

extern "C"
{
	void MODELPLUGINAPI Register(GUI::MainWindow* m, QList<Plugins::PluginBase*>* plugs);

	bool MODELPLUGINAPI CreateModel(int t, QPair<int,ModelData::ModelDataBase*>*);

	bool MODELPLUGINAPI CreateTree(int, GUI::MainWindow* m, QPair<int, ProjectTree::ProjectTreeBase*>*);

	//������ļ�д��
	bool MODELPLUGINAPI WriteOut(QString path, ModelData::ModelDataBase* d);
	//����ת��
	bool MODELPLUGINAPI transfer(QString);
	//�����뷽��  
	bool MODELPLUGINAPI importMeshFun(QString filename);
	//��������ķ���
	bool MODELPLUGINAPI exportMeshFun(QString, int);
	//��������
	Material::Material*  createMaterial(QString);

}


#endif