#ifndef _H_IRISSPRITEVERTEXSHADER_
#define _H_IRISSPRITEVERTEXSHADER_
#include "IrisVertexShaderBase.h"
#include "Iris2D Util/IrisSpriteShaderBuffers.h"

namespace Iris2D
{
	class IrisSpriteVertexShader : public IrisVertexShaderBase
	{
	public:
		static IrisSpriteVertexShader* Instance();

	private:
		ID3D11VertexShader* m_pVertextShader = nullptr;

		ID3DBlob* m_pBlob = nullptr;
		ID3D11InputLayout* m_pInputLayout = nullptr;

		ID3D11Buffer* m_pMatrixBuffer = nullptr;
		ID3D11Buffer* m_pViewProjectMatrixBuffer = nullptr;

	private:
		IrisSpriteVertexShader() = default;
		~IrisSpriteVertexShader() = default;

	protected:
		// ͨ�� IrisVertexShaderBase �̳�
		virtual std::wstring ShaderFileDefine() override;
		virtual std::string ShaderEntryFuncDefine() override;
		virtual std::string ShaderVersionDefine() override;
		virtual bool ShaderSubResourceDefine() override;
		virtual bool CreateShader(ID3DBlob * pBlob) override;
		virtual bool SetToContext() override;

	public:
		virtual bool CreateInputLayout() override;
		virtual ID3D11InputLayout * GetInputLayout() override;
		virtual ID3D11VertexShader * GetVertexShader() override;

		void SetViewProjectMatrix(const DirectX::XMMATRIX& mxVPMatrix);
		void SetWorldMatrix(const IrisSpriteVertexShaderBuffer& mbBuffer);

		virtual bool Release() override;
	};
}
#endif // _H_IRISSPRITESHADER_
