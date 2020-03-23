export PATH=/opt/Qt5.4.2/5.4/gcc_64/bin/:$PATH

cd PluginComplex 
qmake -o Makefile ComplexPlugin.pro
make ver=release

cd ../PluginCustomizer 
qmake -o Makefile pluginCustomizer.pro
make ver=release

#cd ../PluginETS 
#qmake -o Makefile ETSPlugin.pro
#make ver=release

#cd ../PluginHull  
#qmake -o Makefile HullCutPlugin.pro
#make ver=release

cd ../PluginMachinery 
qmake -o Makefile MachineryPlugin.pro
make ver=release

#cd ../PluginModel
#qmake -o Makefile pluginModel.pro
#make ver=release

