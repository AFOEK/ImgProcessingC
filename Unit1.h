//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "ImageData.h"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Graphics.hpp>
//---------------------------------------------------------------------------
class TMainFrm : public TForm
{
__published:	// IDE-managed Components
	TImage *imghsl;
	TStatusBar *SB;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall imghslMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall imghslClick(TObject *Sender);

private:	// User declarations
	cImageData *ImgProc, *OriImg;
	unsigned char red,green,blue;
	int color,tempcolor,x,y;
	short int limitbottom,limittop;
	Graphics::TBitmap *BMP;
public:		// User declarations
	__fastcall TMainFrm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainFrm *MainFrm;
//---------------------------------------------------------------------------
#endif
