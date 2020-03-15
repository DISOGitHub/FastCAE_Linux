#ifndef _GEOMETRYPARABOOLOPERATION_H_
#define _GEOMETRYPARABOOLOPERATION_H_

#include "geometryModelParaBase.h"
#include "GeometryCommand/GeoCommandBool.h"
#include <QString>

namespace Geometry
{
	class GEOMETRYAPI GeometryParaBoolOperation : public GeometryModelParaBase
	{
	public:
		GeometryParaBoolOperation();
		~GeometryParaBoolOperation() = default;

		void setInputBody1(GeometrySet* body1);
		GeometrySet* getBody1();

		void setInputBody2(GeometrySet* body2);
		GeometrySet* getBody2();

		void setType(BoolType b);
		BoolType getType();
		///����д�빤���ļ�
		QDomElement& writeToProjectFile(QDomDocument* doc, QDomElement* parent) override;
		///�ӹ����ļ���������
		virtual void readDataFromProjectFile(QDomElement* e) override;
		QString BoolTypeToString(BoolType b);
		BoolType StringToBoolType(QString s);

	private:
		BoolType _booltype;

		GeometrySet* _body1;
		GeometrySet* _body2;
	};
}


#endif