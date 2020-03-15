#include "ProjectTree/ProjectTreeWithBasicNode.h"
#include "ProjectTreeExtendAPI.h"

class QMenu;

namespace ProjectTree
{
	class PROJECTTREEEXTENDAPI ProjectTreeExtend :public ProjectTreeWithBasicNode
	{
		Q_OBJECT
	public:
		ProjectTreeExtend(GUI::MainWindow* mainwindow);
		~ProjectTreeExtend();

	protected:
		//����Ҽ��¼�
		virtual void contextMenu(QMenu* menu) override;
		//�����������¼�
		virtual void singleClicked() override;
		//������˫���¼�
		virtual void doubleClicked() override;
		//������
		virtual void createTree(QTreeWidgetItem* root, GUI::MainWindow* mainwindow) override;
		//������������
		virtual void updateMeshSubTree() override;

	};


}