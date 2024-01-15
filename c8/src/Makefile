.PHONY: all install uninstall clean dvi tests gcov_report

all: install 
	@cd build && make 3DViewer_v1 && open 3DViewer_v1.app/Contents/MacOS/3DViewer_v1 
	@cd ..

install:
	@-mkdir build
	@cmake CMakeLists.txt -S . -B ./build

uninstall: clean
	@rm -rf build

clean:
	@-cd tests && make clean && cd ..

dvi:
	@open ../materials/dvi.pdf

dist: install
	@cd build && make dist && cd ..

tests:
	@cd tests && make tests && cd ..

gcov_report:
	@cd tests && make gcov_report && cd ..
