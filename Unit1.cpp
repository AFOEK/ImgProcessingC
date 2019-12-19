//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainFrm *MainFrm;
//---------------------------------------------------------------------------
__fastcall TMainFrm::TMainFrm(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TMainFrm::FormCreate(TObject *Sender)
{
	limittop=50; //threshold for top and bottom of image
	limitbottom=-50;
	BMP=new Graphics::TBitmap;
	BMP->LoadFromFile("Sample0.bmp");
	OriImg=new cImageData(0,0,4,pf32bit);
	OriImg->CopyFromBitmap(BMP);

	BMP->LoadFromFile("Sample1.bmp");
	ImgProc=new cImageData(0,0,4,pf32bit);
	ImgProc->CopyFromBitmap(BMP);

	ImgProc->CopyToBitmap(BMP);
	imghsl->Picture->Bitmap->Assign(BMP);
}
//---------------------------------------------------------------------------
void __fastcall TMainFrm::imghslMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	ImgProc->GetRGB(X,Y,&red,&green,&blue);
	SB->Panels->Items[0]->Text="Red :"+IntToStr(red);
	SB->Panels->Items[1]->Text="Green :"+IntToStr(green);
	SB->Panels->Items[2]->Text="Blue :"+IntToStr(blue);
}
//---------------------------------------------------------------------------
void __fastcall TMainFrm::imghslClick(TObject *Sender)
{
	unsigned char RF,RP,GF,GP,BF,BP,AF,AP; //red green blue and transparentcy value
	short int DR,DG,DB;
	bool diff;

	diff=false;
	for(y=0;y<ImgProc->Height;y++)
	{
		for(x=0;x<ImgProc->Width;x++)
		{
			ImgProc->GetARGB(x,y,&AP,&RP,&GP,&BP);
			OriImg->GetARGB(x,y,&AF,&RF,&GF,&BF);
			DR=((short)RF)-RP;
			DG=((short)GF)-GP;
			DB=((short)BF)-BP;
			if((DR<limitbottom || DR>limittop) || (DG<limitbottom || DG>limittop) || (DB<limitbottom || DB>limittop))
			{
				  diff=true;
				  ImgProc->SetARGB(x, y, 255, 0, 0, 0);
			}
		}
	}
	ImgProc->CopyToBitmap(imghsl->Picture->Bitmap);
	if (diff)
	{
		this->Caption="Berbeda";
	}
	else
	{
	 this->Caption="Sama";
	}
}
//---------------------------------------------------------------------------

