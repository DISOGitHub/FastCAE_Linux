#ifndef _GEOMETRYPARAFACE_H_
#define _GEOMETRYPARAFACE_H_

#include "geometryModelParaBase.h"
#include <QString>
#include <QMultiHash>
#include "geometry/geometrySet.h"

class GeometrySet;
class vtkActor;
class TopoDS_Shape;

namespace Geometry
{
	class GEOMETRYAPI GeometryParaFace : public GeometryModelParaBase
	{
	public:
		GeometryParaFace();
		~GeometryParaFace() = default;

		void setName(QString name);
		QString getName();

		void setShapeHash(QMultiHash<Geometry::GeometrySet*, int> shapehash);
		QMultiHash<Geometry::GeometrySet*, int> getShapeHash();
/*

		void setEdges(int s);
		int getEdges();*/

		void setActor(QList<vtkActor*> a);
		QList<vtkActor*> getActor();
		///����д�빤���ļ�
		QDomElement& writeToProjectFile(QDomDocument* doc, QDomElement* parent) override;
		///�ӹ����ļ���������
		virtual void readDataFromProjectFile(QDomElement* e) override;

	private:
		QString _name{};
	
		QMultiHash<Geometry::GeometrySet*, int> _shapeHash;
		QList<vtkActor*> _actor;
		int _edges;
	};
}


#endif