#include <Python.h>

#include <stdlib.h>
#include <stdio.h>


/**
 * print_python_list_info -  function of the prototype
 * @p: python list
 */
void print_python_list_info(PyObject *p)
{
	int x;

	printf("[*] Size of the Python List = %lu\n", Py_SIZE(p));
	printf("[*] Allocated = %lu\n", ((PyListObject *)p)->allocated);
	for (x = 0; x < Py_SIZE(p); x++)
		printf("Element %d: %s\n", x, Py_TYPE(PyList_GetItem(p, x))->tp_name);
}



