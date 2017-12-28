#include <Python.h>

static PyObject *pants(PyObject *self, PyObject *args) {
  int input;
  if (!PyArg_ParseTuple(args, "i", &input)) {
    return NULL;
  }

  return PyLong_FromLong((long)input * (long)input);
}

static PyMethodDef example_methods[] = {
    {"pants", pants, METH_VARARGS, "Returns a square of an integer"},
    {NULL, NULL, 0, NULL},
};

static struct PyModuleDef example_definition = {
    PyModuleDef_HEAD_INIT,
    "example",
    "example module containing pants() function",
    -1,
    example_methods,
};

PyMODINIT_FUNC PyInit_example(void) {
  Py_Initialize();
  PyObject *m = PyModule_Create(&example_definition);

  return m;
}