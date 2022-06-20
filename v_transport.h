//include cpp library for transport to elastic
#include "v_svg.h"

//////////////////////////// SO -> Elastic transport ////////////////////
#ifdef _WIN
#include <windows.h>
#else
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#define V_SVGTrans_API extern "C"
typedef uint64_t EL_UINT;
#endif
typedef struct Binary_Methods_STRUC {
    char* Name;
    void                  (*Method)(EL_UINT** Adr, EL_UINT NumOfOpr, EL_UINT* DataSeg);
}Binary_Methods_STRUC;
typedef struct ELAST_FUNC {
    char* Name;
    void    (*Func)();
}ELAST_FUNC;
typedef EL_UINT(*GetFuncOffFT)(EL_UINT* Body, char* FuncName);
typedef EL_UINT(*CallFuncFT)(EL_UINT* Body, EL_UINT  FileInd, EL_UINT Off, EL_UINT** Parms, EL_UINT ParmCount);
typedef EL_UINT(*GetFileIndFT)();
typedef EL_UINT* (*ConstructProc)();
GetFuncOffFT GetFuncOff;
CallFuncFT   CallFuncOff;
GetFileIndFT GetFileIndOff;
//static Bitmap bitmap;
// Class V_SVGTrans for transoport renderToBitmapSO to Elastic
class V_SVGTrans {
public:
    V_SVGTrans();
    EL_UINT          FileInd;
    EL_UINT* Body;
    EL_UINT          GetInitialNumberOff;
    EL_UINT          bIs2;
    //Bitmap  renderToBitmap(std::uint32_t width = 0, std::uint32_t height = 0, std::uint32_t backgroundColor = 0x00000000);
     //void render(Bitmap bitmap, const Matrix& matrix = Matrix{}, std::uint32_t backgroundColor = 0x00000000) const;
    void renderToBitmapSO(EL_UINT* buf, char* filename, std::uint32_t width = 0, std::uint32_t height = 0, std::uint32_t backgroundColor = 0x00000000) {
        auto document = Document::loadFromFile(filename);
        Bitmap bitmap = document->renderToBitmap(width, height, backgroundColor);
        //bitmap.convertToRGBA();
        //printf("filename:  %s\n", filename);

        //const void* data = bitmap.data();

        //printf("data p so %p\n", &buf);
        //printf("data p so %d\n", &buf);
        //printf("data p so %s\n", typeid(&buf).name());

        memmove(buf, bitmap.data(), width * height * 4);
        //buf = bitmap.data();

        //printf("data p so %p\n", buf);
        //printf("data p so %d\n", buf);
        //printf("data p so %s\n", typeid(buf).name());


        //char datafs = (char)bitmap.data();
        //printf("bufsize:  %d\n", sizeof(width * height * 4));

        //printf("data p so %p\n", data);
        //printf("data p so %d\n", data);
        //printf("data p so %s\n", typeid(data).name());

        //printf("size w x so: %d x %d \n", int(bitmap.width()), int(bitmap.height()));

        //buf = malloc(int(bitmap.width()) * int(bitmap.height()) * 4);

        //buf = data;

        stbi_write_png("test_png_from_h.png", int(bitmap.width()), int(bitmap.height()), 4, (const void*)buf, 0);

        // if (!document)  printf ("Error svg document. Filename : %s",filename); 
    }
    //EL_UINT   Print(char* Str, EL_UINT Len) {
    //    printf("the string: %s, of length: %d, is test2: %d\n", Str, Len, bIs2);
    //}
    //EL_UINT   Print2(EL_UINT D1, EL_UINT D2) {
    //    EL_UINT D3 = 0;
    //    if (GetInitialNumberOff != NULL && GetInitialNumberOff != -1) {
    //        D3 = CallFuncOff(Body, FileInd, GetInitialNumberOff, 0, 0);
    //    }
    //    printf("the sum is %d\n", D1 + D2 + D3 + bIs2);
    //}
};

void V_SVGTrans_Init(EL_UINT** Adr, EL_UINT NumOfOpr, EL_UINT* DataSeg)
{
    V_SVGTrans* Class;
    EL_UINT* Ptr;
    EL_UINT* Body;
    Body = (EL_UINT*)Adr[2];
    Class = (V_SVGTrans*)Adr[2][2];
    Class->Body = Body;
    Class->GetInitialNumberOff = GetFuncOff(Body, "GetInitialNumber");
    Class->FileInd = GetFileIndOff();
}
void V_SVGTrans_renderToBitmapSO(EL_UINT** Adr, EL_UINT NumOfOpr, EL_UINT* DataSeg)
{
    V_SVGTrans* Class;
    EL_UINT* Ptr;
    Class = (V_SVGTrans*)Adr[2][2];
    Ptr = (EL_UINT*)Adr[4 + 0];
    Class->renderToBitmapSO((EL_UINT *)Ptr[0], (char*)Ptr[0], Ptr[1], Ptr[2], Ptr[3]);

}
//void V_SVGTrans_Test1(EL_UINT** Adr, EL_UINT NumOfOpr, EL_UINT* DataSeg)
//{
//    V_Test* Class;
//    EL_UINT* Ptr;
//    Class = (V_Test*)Adr[2][2];
//    Ptr = (EL_UINT*)Adr[4 + 0];
//    Class->Print((char*)Ptr[1], Ptr[0]);
//
//}
//void V_Test_Test2(EL_UINT** Adr, EL_UINT NumOfOpr, EL_UINT* DataSeg)
//{
//    V_Test* Class;
//    EL_UINT* Ptr;
//    EL_UINT* Ptr2;
//    Class = (V_Test*)Adr[2][2];
//    Ptr = (EL_UINT*)Adr[4 + 0];
//    Ptr2 = (EL_UINT*)Adr[4 + 1];
//    Class->Print2(Ptr[0], Ptr2[0]);
//}
Binary_Methods_STRUC V_SVGTrans_STRUC_Methods[] =
{
    "int Init", &V_SVGTrans_Init,
    //    "int Test1 string ptr", &V_Test_Test1,
    //    "int Test2 int ptr int ptr", &V_Test_Test2,
        "int renderToBitmapSO int ptr int ptr int ptr",&V_SVGTrans_renderToBitmapSO,
        NULL
};
//Binary_Methods_STRUC V_Test2_STRUC_Methods[] =
//{
//    "int Init", &V_Test_Init,
//    "int Test1 string ptr", &V_Test_Test1,
//    "int Test2 int ptr int ptr", &V_Test_Test2,
//    NULL
//};
Binary_Methods_STRUC* MethodStrucTable[] = {
V_SVGTrans_STRUC_Methods,
//V_Test2_STRUC_Methods,
NULL
};

const char* Tbl[] = { "V_SVGTrans" };
V_SVGTrans::V_SVGTrans() {
    GetInitialNumberOff = 0;
    //bIs2 = false;
}
EL_UINT* V_SVGTrans_Construct()
{
    V_SVGTrans* SVGTrans;
    SVGTrans = new V_SVGTrans;
    return (EL_UINT*)SVGTrans;
}
//EL_UINT* V_Test2_Construct()
//{
//
//    V_Test* Test;
//    Test = new V_Test;
//    Test->bIs2 = true;
//    printf("bIs2 = true\n");
//    return (EL_UINT*)Test;
//}
//
V_SVGTrans_API Binary_Methods_STRUC** Init(const char*** Names, ELAST_FUNC* FuncTable) {
    Names[0] = Tbl;
    for (int i = 0; ; i++) {
        if (FuncTable[i].Name == NULL)break;
        if (strcmp(FuncTable[i].Name, "GetFuncOff") == 0) {
            GetFuncOff = (GetFuncOffFT)FuncTable[i].Func;
        }
        else if (strcmp(FuncTable[i].Name, "CallFunc") == 0) {
            CallFuncOff = (CallFuncFT)FuncTable[i].Func;
        }
        else if (strcmp(FuncTable[i].Name, "GetFileInd") == 0) {
            GetFileIndOff = (GetFileIndFT)FuncTable[i].Func;
        }

    }
    return MethodStrucTable;
}



V_SVGTrans_API ConstructProc GetConstructor(EL_UINT i) {
    if (i == 0)return V_SVGTrans_Construct;
    /*return V_Test2_Construct;*/
}

//////////////////////////// SO -> Elastic transport ////////////////////
 /*class TTest : public V_Test {
    public:
        int  SeedS;
  }*/

  //
  //int main() {
  //    V_Test* Test;
  //    Test = new V_Test;
  //
  //    //V_Test* TTest;
  //    Test->renderToBitmapSO("/Projects/Make/Platform/11.svg", 512, 512, 1111111);
  //    return 0;
  //}
