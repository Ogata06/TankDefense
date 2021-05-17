#pragma once
#include "..\Actor.h"
#include "..\..\..\..\Common\Mesh\RayMesh\RayMesh.h"

class CDX9SkinMesh;
class CRotLookAtCenter;

class CPlayer
	: public CActor
{
public:
	CPlayer();
	~CPlayer();


	// �������֐�.
	virtual bool Init();
	// �X�V�֐�.
	virtual void Update( const float& deltaTime );
	// �`��֐�.
	virtual void Render();

	// �����蔻��֐�.
	virtual void Collision( CActor* pActor );

	// �����蔻��̏�����.
	virtual void InitCollision();
	// �����蔻��̍��W��A���a�Ȃǂ̍X�V.
	//	Update�֐��̍Ō�ɌĂ�.
	virtual void UpdateCollision();

protected:
	CDX9SkinMesh*	m_pSkinMesh;
	std::unique_ptr<CRotLookAtCenter>	m_pLookCamera;

	D3DXVECTOR3		m_pos;
	D3DXVECTOR3		m_Rot;
	D3DXVECTOR3		m_MoveVec3;
};