#ifndef ETSPLUGIN_H_
#define ETSPLUGIN_H_

#include "PluginManager/pluginBase.h"
#include "ETSPluginAPI.h"

namespace GUI
{
	class MainWindow;
}

class QWidget;

namespace ETS
{
	class ETSControlPanel;

	class ETSPlugin : public Plugins::PluginBase
	{
		Q_OBJECT
	public:
		ETSPlugin(GUI::MainWindow*  m);
		~ETSPlugin();

		//���ز��
		virtual bool install() override;
		//ж�ز��
		virtual bool uninstall() override;
		//����
		virtual void reTranslate(QString lang) override;

	private:
		GUI::MainWindow* _mainWindow{};

		QWidget* _FastCAEControlPanel{};
		ETSControlPanel* _etsControlPanel{};
	};
}

extern "C"
{
	void ETSPLUGINAPI Register(GUI::MainWindow* m, QList<Plugins::PluginBase*>* plugs);
}

#endif
