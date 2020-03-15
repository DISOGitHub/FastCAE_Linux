#include "GeometryConfig.h"

namespace ConfigOption
{
	//2019.11.20 xvxinwei Geometry modeling operations sketch
	void GeometryConfig::enableGeometryModeling(bool on)
	{
		_isGeoModeling = on;
	}
	bool GeometryConfig::isGeometryModelingEnabled()
	{
		return _isGeoModeling;
	}
	void GeometryConfig::enableGeometryOperations(bool on)
	{
		_isGeoOperations = on;
	}
	bool GeometryConfig::isGeometryOperationsEnabled()
	{
		return _isGeoOperations;
	}
	void GeometryConfig::enableCreateSketch(bool on)
	{
		_isCreateSketch = on;
	}
	bool GeometryConfig::isCreateSketchEnabled()
	{
		return _isCreateSketch;
	}
	//���õ��뼸�θ�ʽ
	void GeometryConfig::setImportSuffix(QString s)
	{
		_importSuffix = s;
	}
	//��ȡ���뼸�θ�ʽ
	QString GeometryConfig::getImportSuffix()
	{
		return _importSuffix;
	}
	//���õ������θ�ʽ
	void GeometryConfig::setExportSuffix(QString s)
	{
		_exportSuffix = s;
	}
	//��ȡ�������θ�ʽ
	QString GeometryConfig::getExportSuffix()
	{
		return _exportSuffix;
	}


	void GeometryConfig::clearData()
	{
		_isCreateSketch = _isGeoModeling = _isGeoOperations = false;
		_importSuffix.clear();
		_exportSuffix.clear();
	}

	bool GeometryConfig::isGeometryEnabled()
	{
		bool in = this->isImportGeometryEnabled();
		bool ex = this->isExportGeometryEnabled();

		bool op = _isCreateSketch || _isGeoModeling || _isGeoOperations;

		return in || ex || op;
	}

	bool GeometryConfig::isImportGeometryEnabled()
	{
		return !_importSuffix.isEmpty();
	}

	bool GeometryConfig::isExportGeometryEnabled()
	{
		return !_exportSuffix.isEmpty();
	}

}