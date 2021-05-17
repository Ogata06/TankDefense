#include "Mesh.h"

CMesh::CMesh()
	: m_pMeshForRay	( nullptr )
{
}

CMesh::~CMesh()
{
	m_pMeshForRay = nullptr;
}

// �����ʒu�̃|���S���̒��_��������.
HRESULT CMesh::FindVerticesOnPoly( const DWORD dwPolyIndex, D3DXVECTOR3* pOutVecVertices )
{
	// ���_���Ƃ̃o�C�g�����擾.
	DWORD dwStrid		= m_pMeshForRay->GetNumBytesPerVertex();
	// ���_�����擾.
	DWORD dwVertexAmt	= m_pMeshForRay->GetNumVertices();
	// �ʐ����擾.
	DWORD dwPolyAmt		= m_pMeshForRay->GetNumFaces();

	WORD* pwPoly = nullptr;

	// �C���f�b�N�X�o�b�t�@�����b�N(�ǂݍ��݃��[�h).
	m_pMeshForRay->LockIndexBuffer( D3DLOCK_READONLY, (VOID**)&pwPoly );
	BYTE* pbVertices	= nullptr;	// ���_(�o�C�g��).
	FLOAT* pfVerTices	= nullptr;	// ���_(FLOAT�^).
	LPDIRECT3DVERTEXBUFFER9 VB = nullptr;	// ���_�o�b�t�@.
	m_pMeshForRay->GetVertexBuffer( &VB );	// ���_���̎擾.

	// ���_�o�b�t�@�̃��b�N.
	if( SUCCEEDED( VB->Lock( 0, 0, (VOID**)&pbVertices, 0 ) ) ){
		for( int i = 0; i < 3; i++ ){
			// �|���S���̒��_��3�ڂ��擾.
			pfVerTices
				= (FLOAT*)( &pbVertices[dwStrid*pwPoly[dwPolyIndex * 3 + i]] );
			pOutVecVertices[i].x = pfVerTices[0];
			pOutVecVertices[i].y = pfVerTices[1];
			pOutVecVertices[i].z = pfVerTices[2];
		}

		m_pMeshForRay->UnlockIndexBuffer();
		VB->Unlock();
	}
	SAFE_RELEASE( VB );

	return S_OK;
}