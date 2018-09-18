
#include "Scene.h"
#include <string>
class CTextBox;
class CSetting :
	public CScene
{
private:
	CTextBox* pTextBox;

	float DeltaTime=0;
	int Frame=0;

	std::wstring strTexture;
	std::wstring strSprite;


	bool bEditTextModePressed=false;

public:
	CSetting();
	virtual ~CSetting();

	virtual void Update(float fDeltaTime) override;


	virtual void Render() override;

};
