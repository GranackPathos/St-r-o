all: projet

IFLAGS= -I /usr/include/pcl-1.7/ -I /usr/include/pcl-1.7/pcl/io -I /usr/include/pcl-1.7/pcl/visualization -I /usr/include/eigen3/ -I /usr/include/vtk-5.8
LDFLAGS= -L /lib64 -l boost_thread -l boost_system -l pcl_common -l pcl_io -l pcl_visualization -l vtkCommon -l vtkFiltering -l vtkRendering

projet: main.o
	g++ -Wall main.o `pkg-config --libs opencv` $(IFLAGS) $(LDFLAGS) -o projet 
main.o: main.cpp
	g++ -Wall -c main.cpp `pkg-config --cflags opencv` $(IFLAGS) $(LDFLAGS) -o main.o

.PHONY:clean
clean: 
	rm *.o
	rm projet


