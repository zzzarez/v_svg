rm /Projects/v_svg/MakeSo/v_svg.d
rm /Projects/v_svg/MakeSo/v_svg.o
rm /Projects/v_svg/MakeSo/v_svg.so
cd /Projects/v_svg/MakeSo
make
cp /Projects/v_svg/MakeSo/v_svg.so  /Projects/Make/Platform/V_Objects/v_svg.so
cd ..
/Projects/Make/Platform/epl_web test_svg_transport.epl