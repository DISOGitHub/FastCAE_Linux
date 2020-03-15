#ifndef _BCBASE_H_
#define _BCBASE_H_

#include "BCBaseAPI.h"
#include "DataProperty/DataBase.h"
#include "BCType.h"

namespace MeshData
{
	class MeshData;
	class MeshSet;
}

namespace BCBase
{


	class BCBASEAPI BCBase : public DataProperty::DataBase
	{
	public:
		BCBase();
		~BCBase() = default;
		//��������
		virtual void copy(DataBase* data) override;
		//�����������ID
		void setMeshSetID(int id);
		//��ȡ�������ID
		int getMeshSetID();
		//��ȡ�����������
		QString getMeshSetName();
		//��ȡ�������
		MeshData::MeshSet* getMeshSet();
		//���ñ߽���������
		void setType(BCType t);
		//��ȡ�߽�����
		BCType getType();

		virtual QDomElement& writeToProjectFile(QDomDocument* doc, QDomElement* parent) override;
		virtual void readDataFromProjectFile(QDomElement* ele) override;

	protected:
		BCType _type{ None };
		int _meshSetID{ -1 };
		 
		MeshData::MeshSet* _set{};
		MeshData::MeshData* _mesh{};

	};
}

#endif 