vpath %.cpp lib:.
vpath %.o lib:.
CC = g++
CXXFLAGS = -Iinclude

static_ofiles := BMICalculator.o BMIRecordManager.o clock.o divider.o
dynamic_cpps := BMILogSort.cpp UserManagement.cpp UserMenu.cpp BMILogs.cpp
libs := libbmi.so libbmi.a
main: $(libs)
	$(CC) -o $@ main.cpp -L. $(libs) -Iinclude
libbmi.a: $(static_ofiles)
	ar rcs $@ $^
libbmi.so: $(dynamic_cpps) 
	$(CC) -o $@ -fPIC -shared $^ -Iinclude
$(static_ofiles): %.o : %.cpp 

install:
	sudo cp libbmi.so /usr/lib/

.PHONY: clean 
clean:
	-sudo rm /usr/lib/libbmi.so
	-$(RM) main
	-$(RM) *.o
	-$(RM) lib/*.o
	-$(RM) *.a *.so
