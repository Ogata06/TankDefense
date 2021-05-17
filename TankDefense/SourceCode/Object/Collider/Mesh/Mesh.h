/**
* @file Mesh.h.
* @brief �����蔻��p���b�V���N���X.
* @author ���c���.
*/
#ifndef MESH_H
#define MESH_H

#include "..\ColliderBase.h"


/*****************************************
*	���b�V���N���X(�����蔻��p).
**/
class CMesh : public CColliderBase
{
public:
	CMesh();
	virtual ~CMesh();

	// ���b�V���̎擾.
	inline LPD3DXMESH	GetMesh() const				{ return m_pMeshForRay; }
	// ���b�V���̐ݒ�.
	inline void			SetMesh( LPD3DXMESH pMesh )	{ m_pMeshForRay = pMesh; }

	// �����ʒu�̃|���S���̒��_��������.
	HRESULT FindVerticesOnPoly( const DWORD dwPolyIndex, D3DXVECTOR3* pOutVecVertices );

private:
	LPD3DXMESH	m_pMeshForRay;	// ���C�Ƃ̓����蔻��p���b�V���I�u�W�F�N�g.
};

#endif	// #ifndef MESH_H.
