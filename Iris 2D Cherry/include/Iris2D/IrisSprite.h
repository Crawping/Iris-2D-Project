#ifndef _H_IRISSPRITE_

#include "../IrisCommon.h"
#include "Iris2D Util/IrisSpriteMatrixBuffer.h"

namespace Iris2D
{
	class IrisBitmap;
	__declspec(align(16)) 
#if ENGLISH
		/**
		* Sprite class of Iris 2D
		*
		* A sprite abustractly represents something displayed on screen, further more, a sprite usually needs a bitmap to get an image to display or sprite won't show anything.
		*
		* A sprite can control the position, the scaling size, the angle and other displaying properties for an image, and it's the most basic element of 2D games.
		*/
#elif CHINESE
		/**
		* Iris 2D Sprite ��
		*
		* һ�� Sprite ����ر�ʾ����ʾ����Ļ�ϵ��κζ�������һ���أ�һ�� Sprite һ�㶼��Ҫһ�� Bitmap ����ʾͼƬ�ȣ����򽫲���չʾ�κζ�����
		*
		* һ��������Կ�����ʾ���ݵ�λ�á����ųߴ硢�Ƕ��Լ�������ʾ���ԣ����� 2D ��Ϸ�������Ԫ�ء�
		*/
#endif
	class IrisSprite
	{
	private:

		const float c_fPI = 3.14159f;
		const float c_fArcUnit = c_fPI / 180.0f;

		IrisBitmap* m_pBitmap = nullptr;
		ID3D11Buffer* m_pVertexBuffer = nullptr;

		IrisSpriteMatrixBuffer m_mbMatrixBuffer;

		float m_fX = 0.0f;
		float m_fY = 0.0f;
		float m_fZ = 1.0f;
		float m_fAngle = 0.0f;
		float m_fZoomX = 1.0f;
		float m_fZoomY = 1.0f;

		bool m_bPositionDirtyFlag = false;
		bool m_bAngleDirtyFlag = false;
		bool m_bZoomDirtyFlag = false;

	public:
#if ENGLISH
		/**
		* Create a sprite object.
		* @return If sprite has been created successfully pointer of IrisSprite will be returned otherwise nullptr.
		*/
#elif CHINESE
		/**
		* ����һ�� Sprite ����
		* @return ��� Sprite ���󴴽��ɹ���ô��������ָ����򷵻� nullptr��
		*/
#endif
		static IrisSprite* Create();

#if ENGLISH
		/**
		* Release a sprite.
		* @param pSprite A pointer to sprite object to be released. After this function called, pointer taken will be set to nullptr.
		*/
#elif CHINESE
		/**
		* �ͷ�һ�� Sprite ����
		* @param pSprite ָ��Ҫ���ͷŵ� Sprite �����ָ�롣���ú���������֮�󣬴����ָ�뽫�ᱻ����Ϊ nullptr��
		*/
#endif
		static void Release(IrisSprite*& pSprite);

		static void InnerRelease(IrisSprite* pSprite);

	public:
		void SetBitmap(IrisBitmap* pBitmap);
		IrisBitmap* GetBitmap() const;

		void SetX(float fX);
		float GetX() const;

		void SetY(float fY);
		float GetY() const;

		void SetZ(float fZ);
		float GetZ() const;

		void SetAngle(float fAngle);
		float GetAngle() const;

		void SetRoomX(float fZoomX);
		float GetRoomX() const;

		void SetRoomY(float fZoomY);
		float GetRoomY() const;

		void Update();
		void Render();

	private:
		IrisSprite() = default;
		~IrisSprite();

		bool CreateSpriteVertexBuffer();

		void* operator new(size_t i)
		{
			return _mm_malloc(i, 16);
		}

		void operator delete(void* p)
		{
			_mm_free(p);
		}

	};
}


#endif // !_H_IRISSPRITE_
