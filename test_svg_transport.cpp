#include "v_transport.h"

int  main() {
    V_SVGTrans* SVGTrans;
    EL_UINT* buffer = (EL_UINT*)malloc(512 * 512 * 4);
    SVGTrans->renderToBitmapSO(buffer, "/Projects/v_svg/11.svg", 512, 512, 1111111);
    stbi_write_png("test_png.png", 512, 512, 4, (const void*)buffer, 0);
    return 0;

}
