#include <Python.h>
#include <structmember.h>

typedef struct {
  PyObject_HEAD // no semicolon
  int number;
} Classy;

static void Classy_dealloc(Classy *self) {
  Py_TYPE(self)->tp_free((PyObject *)self);
}

static PyObject *Classy_new(PyTypeObject *type, PyObject *args,
                            PyObject *kwds) {
  Classy *self;

  self = (Classy *)type->tp_alloc(type, 0);
  if (self != NULL) {
    self->number = 0;
  }

  return (PyObject *)self;
}

static int Classy_init(Classy *self, PyObject *args, PyObject *kwds) {
  self->number = 1;
  return 0;
}

static PyMemberDef Classy_members[] = {
    {"number", T_INT, offsetof(Classy, number), 0, "classy number"},
    {NULL} /* Sentinel */
};

static PyObject *Classy_miami(Classy *self) {
  if (self->number > 1)
    self->number /= 2;

  return PyLong_FromLong((long)self->number);
}

static PyObject *Classy_new_york(Classy *self) {
  if (self->number < 1024 * 1024)
    self->number *= 2;

  return PyLong_FromLong((long)self->number);
}

static PyMethodDef Classy_methods[] = {
    {"miami", (PyCFunction)Classy_miami, METH_NOARGS, "Divides number by 2"},
    {"new_york", (PyCFunction)Classy_new_york, METH_NOARGS, "Doubles number"},
    {NULL} /* Sentinel */
};

static PyTypeObject ClassyType = {
    PyVarObject_HEAD_INIT(NULL, 0) "example.Classy",  /* tp_name */
    sizeof(Classy),                           /* tp_basicsize */
    0,                                        /* tp_itemsize */
    (destructor)Classy_dealloc,               /* tp_dealloc */
    0,                                        /* tp_print */
    0,                                        /* tp_getattr */
    0,                                        /* tp_setattr */
    0,                                        /* tp_reserved */
    0,                                        /* tp_repr */
    0,                                        /* tp_as_number */
    0,                                        /* tp_as_sequence */
    0,                                        /* tp_as_mapping */
    0,                                        /* tp_hash  */
    0,                                        /* tp_call */
    0,                                        /* tp_str */
    0,                                        /* tp_getattro */
    0,                                        /* tp_setattro */
    0,                                        /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, /* tp_flags */
    "Classy objects",                         /* tp_doc */
    0,                                        /* tp_traverse */
    0,                                        /* tp_clear */
    0,                                        /* tp_richcompare */
    0,                                        /* tp_weaklistoffset */
    0,                                        /* tp_iter */
    0,                                        /* tp_iternext */
    Classy_methods,                           /* tp_methods */
    Classy_members,                           /* tp_members */
    0,                                        /* tp_getset */
    0,                                        /* tp_base */
    0,                                        /* tp_dict */
    0,                                        /* tp_descr_get */
    0,                                        /* tp_descr_set */
    0,                                        /* tp_dictoffset */
    (initproc)Classy_init,                    /* tp_init */
    0,                                        /* tp_alloc */
    Classy_new,                               /* tp_new */
};

static struct PyModuleDef example_definition = {
    PyModuleDef_HEAD_INIT,
    "example",
    "example module containing Classy class",
    -1,
    NULL,
};

PyMODINIT_FUNC PyInit_example(void) {
  Py_Initialize();
  PyObject *m = PyModule_Create(&example_definition);

  if (PyType_Ready(&ClassyType) < 0)
    return NULL;

  Py_INCREF(&ClassyType);
  PyModule_AddObject(m, "Classy", (PyObject *)&ClassyType);

  return m;
}