#include <stdio.h>
#include <Python.h>
/**
 * print_python_bytes - function of the prototype
 * @p: python object
 * Return: nothing
 **/
void print_python_bytes(PyObject *p)
{
char *s;
Py_ssize_t lenght, x;
printf("[.] bytes object info\n");
if (!PyBytes_Check(p))
printf("  [ERROR] Invalid Bytes Object\n");
else
{
PyBytes_AsStringAndSize(p, &s, &lenght);
printf("  size: %lu\n", lenght);
printf("  trying string: %s\n", s);
if (lenght > 10)
lenght = 10;
else
lenght++;
printf("  first %lu bytes: ", lenght);
for (x = 0; x < lenght - 1; x++)
printf("%02x ", s[x] & 0xff);
printf("%02x\n", s[lenght - 1] & 0xff);
}
}
/**
 * print_python_list - function of the prototype
 *  * @p: python object
 * Return: nothing
 **/
void print_python_list(PyObject *p)
{
Py_ssize_t x;
PyObject *in_list;
if (PyList_Check(p))
{
printf("[*] Python list info\n");
printf("[*] Size of the Python List = %lu\n", PyList_Size(p));
printf("[*] Allocated = %lu\n", ((PyListObject *)p)->allocated);
for (x = 0; x < PyList_Size(p); x++)
{
in_list = PySequence_GetItem(p, x);
printf("Element %lu: %s\n", x,
in_list->ob_type->tp_name);
if (strcmp(in_list->ob_type->tp_name, "bytes") == 0)
print_python_bytes(in_list);
}
}
}
